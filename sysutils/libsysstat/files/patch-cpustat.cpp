--- cpustat.cpp.orig	2021-04-07 06:58:34 UTC
+++ cpustat.cpp
@@ -22,16 +22,65 @@
 **  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **
 ** END_COMMON_COPYRIGHT_HEADER */
-
-
 #include <unistd.h>
-
 #include "cpustat.h"
+#ifdef HAVE_SYSCTL_H
+extern "C"
+{
+    #include <stdlib.h>
+    #include <limits.h>
+    #include <string.h>
+    #include <sys/resource.h> /* CPUSTATES */
+
+    #include <sys/types.h>
+    #include <sys/sysctl.h>
+}
+#endif
 #include "cpustat_p.h"
 
 
 namespace SysStat {
+#ifdef HAVE_SYSCTL_H
+char *GetFirstFragment(char *string, const char *delim)
+{
+    char *token = NULL;
 
+    token = strsep(&string, delim);
+    if (token != NULL)
+    {
+        /* We need only the first fragment, so no loop! */
+        return token;
+    }
+    else
+        return NULL;
+}
+
+int GetCpu(void)
+{
+    static int mib[] = { CTL_HW, HW_NCPU };
+    int buf;
+    size_t len = sizeof(int);
+
+    if (sysctl(mib, 2, &buf, &len, NULL, 0) < 0)
+        return 0;
+    else
+        return buf;
+}
+
+/* Frequence is in MHz */
+ulong CpuStatPrivate::CurrentFreq(QString mSource)
+{
+    ulong freq=0;
+    size_t len = sizeof(freq);
+    int i = mSource.mid(3).toInt();
+    if (sysctl(mib2[i],4,&freq, &len, NULL, 0) < 0) {
+    	perror("sysctl");
+        return 0;
+    }
+    else
+        return freq;
+}
+#endif
 CpuStatPrivate::CpuStatPrivate(CpuStat *parent)
     : BaseStatPrivate(parent)
     , mMonitoring(CpuStat::LoadAndFrequency)
@@ -39,7 +88,17 @@ CpuStatPrivate::CpuStatPrivate(CpuStat *parent)
     mSource = defaultSource();
 
     connect(mTimer, SIGNAL(timeout()), SLOT(timeout()));
-
+#ifdef HAVE_SYSCTL_H
+    size_t flen=2;
+    size_t alen=4;
+    sysctlnametomib("kern.cp_times",mib0,&flen);
+    sysctlnametomib("kern.cp_time",mib1,&flen);
+    int ncpu = GetCpu();
+    for (int i=0;i<ncpu;i++) {
+    QString cpu_sysctl_name = QString::fromLatin1("dev.cpu.%1.freq").arg(i);
+    sysctlnametomib(cpu_sysctl_name.toStdString().c_str(),mib2[i],&alen);
+    }
+#endif
     mUserHz = sysconf(_SC_CLK_TCK);
 
     updateSources();
@@ -47,6 +106,51 @@ CpuStatPrivate::CpuStatPrivate(CpuStat *parent)
 
 void CpuStatPrivate::addSource(const QString &source)
 {
+#ifdef HAVE_SYSCTL_H
+            char buf[1024];
+            char *tokens, *t;
+            ulong min = 0, max = 0;
+            size_t len = sizeof(buf);
+
+            /* The string returned by the dev.cpu.0.freq_levels sysctl
+             * is a space separated list of MHz/milliwatts.
+             */
+            if (source != QStringLiteral("cpu") && source.midRef(3).toInt() >-1) {
+
+                if (sysctlbyname(QString::fromLatin1("dev.cpu.%1.freq_levels").arg(source.midRef(3).toInt()).toStdString().c_str(), buf, &len, NULL, 0) < 0)
+                    return;
+            }
+            t = strndup(buf, len);
+            if (t == NULL)
+            {
+                free(t);
+                return;
+            }
+            while ((tokens = strsep(&t, " ")) != NULL)
+            {
+                char *freq;
+                ulong res;
+
+                freq = GetFirstFragment(tokens, "/");
+                if (freq != NULL)
+                {
+                    res = strtoul(freq, &freq, 10);
+                    if (res > max)
+                    {
+                        max = res;
+                    }
+                    else
+                    {
+                        if ((min == 0) || (res < min))
+                            min = res;
+                    }
+               	}
+
+            }
+
+            free(t);
+            mBounds[source] = qMakePair(min, max);
+#else
     bool ok = false;
 
     uint min = readAllFile(qPrintable(QString::fromLatin1("/sys/devices/system/cpu/%1/cpufreq/scaling_min_freq").arg(source))).toUInt(&ok);
@@ -56,11 +160,35 @@ void CpuStatPrivate::addSource(const QString &source)
         if (ok)
             mBounds[source] = qMakePair(min, max);
     }
+#endif
 }
 
 void CpuStatPrivate::updateSources()
 {
     mSources.clear();
+#ifdef HAVE_SYSCTL_H
+    mBounds.clear();
+    int cpu;
+
+    cpu = GetCpu();
+    mSources.append(QString::fromLatin1("cpu"));
+    for (int i =0;i<cpu;i++)
+    {
+        mSources.append(QString::fromLatin1("cpu%1").arg(i));
+        addSource(QString::fromLatin1("cpu%1").arg(i));
+    }
+    long max=0;
+    long min=0;
+    for (Bounds::ConstIterator I = mBounds.constBegin(); I != mBounds.constEnd(); ++I)
+    {
+        min += mBounds[I.key()].first;
+        max += mBounds[I.key()].second;
+
+    }
+
+    mBounds[QStringLiteral("cpu")] = qMakePair(min,max);
+#else
+
 #if (QT_VERSION >= QT_VERSION_CHECK(5,15,0))
     const QStringList rows = readAllFile("/proc/stat").split(QLatin1Char('\n'), Qt::SkipEmptyParts);
 #else
@@ -110,6 +238,7 @@ void CpuStatPrivate::updateSources()
                 addSource(QString::fromLatin1("cpu%1").arg(number));
         }
     }
+#endif
 }
 
 CpuStatPrivate::~CpuStatPrivate() = default;
@@ -136,6 +265,113 @@ void CpuStatPrivate::recalculateMinMax()
 
 void CpuStatPrivate::timeout()
 {
+#ifdef HAVE_SYSCTL_H
+            if ( (mMonitoring == CpuStat::LoadOnly)
+              || (mMonitoring == CpuStat::LoadAndFrequency) )
+            {
+                int cpuNumber=0;
+                long *cp_times=0;
+
+                if(mSource!=QLatin1String("cpu"))
+                {
+                    size_t cp_size = sizeof(long) * CPUSTATES * GetCpu();
+                    cp_times = (long *)malloc(cp_size);
+                    cpuNumber = mSource.midRef(3).toInt();
+                    if (sysctl(mib0,2, cp_times, &cp_size, NULL, 0) < 0)
+                        free(cp_times);
+                } else {
+                    size_t cp_size = sizeof(long)*CPUSTATES;
+                    cp_times = (long *)malloc(cp_size);
+                    if(sysctl(mib1,2,cp_times,&cp_size,NULL,0) < 0)
+                    {
+                        perror("sysctl");
+                        free(cp_times);
+                    }
+                }
+                Values current;
+                current.user = static_cast<ulong>(cp_times[CP_USER+cpuNumber*CPUSTATES]);
+                current.nice = static_cast<ulong>(cp_times[CP_NICE+cpuNumber*CPUSTATES]);
+                current.system = static_cast<ulong>(cp_times[CP_SYS+cpuNumber*CPUSTATES]);
+                current.idle = static_cast<ulong>(cp_times[CP_IDLE+cpuNumber*CPUSTATES]);
+                current.other = static_cast<ulong>(cp_times[CP_INTR+cpuNumber*CPUSTATES]);
+                current.total = current.user + current.nice + current.system+current.idle+current.other;
+                float sumDelta = static_cast<float>(current.total - mPrevious.total);
+                if ((mPrevious.total != 0) && ((sumDelta < mIntervalMin) || (sumDelta > mIntervalMax)))
+                {
+                    if (mMonitoring == CpuStat::LoadAndFrequency) 
+		            {
+                        float freqRate = 1.0;
+                        ulong freq = CurrentFreq(mSource);
+				
+                        	if (mSource == QLatin1String("cpu")) {
+                                freq=0;
+                                for (Bounds::ConstIterator I = mBounds.constBegin(); I != mBounds.constEnd(); ++I) {
+                                    if (I.key() != QStringLiteral("cpu"))
+                                    {
+                                        freq += CurrentFreq(I.key());
+                                    }
+                                }
+                            }
+
+                        if (freq > 0)
+                       	{
+                        freqRate = static_cast<float>(freq) / static_cast<float>(mBounds[mSource].second);
+                        emit update(0.0, 0.0, 0.0, 0.0, static_cast<float>(freqRate), freq);
+                        }
+                    } else {
+                        emit update(0.0, 0.0, 0.0, 0.0);
+			        }
+                    mPrevious.clear();
+                } else {
+                        if (mMonitoring == CpuStat::LoadAndFrequency)
+                    {
+                        float freqRate = 1.0;
+                        ulong freq = CurrentFreq(mSource);
+				
+                        if (freq > 0)
+                        {
+					        if (mSource == QLatin1String("cpu")) {
+                                freq=0;
+                                for (Bounds::ConstIterator I = mBounds.constBegin(); I != mBounds.constEnd(); ++I) {
+                                    if (I.key() != QStringLiteral("cpu"))
+                                    {
+                                        freq += CurrentFreq(I.key());
+                                    }
+                        }
+                        }
+		                freqRate = static_cast<float>(freq) / static_cast<float>(mBounds[mSource].second);
+                           emit update(
+                               static_cast<float>(current.user   - mPrevious.user  ) / sumDelta,
+                               static_cast<float>(current.nice   - mPrevious.nice  ) / sumDelta,
+                               static_cast<float>(current.system - mPrevious.system) / sumDelta,
+                               static_cast<float>(current.other  - mPrevious.other ) / sumDelta,
+                               static_cast<float>(freqRate),
+                               freq);
+
+                        }
+                    }
+                        else
+                        {
+                            emit update(
+                                static_cast<float>(current.user   - mPrevious.user  ) / sumDelta,
+                                static_cast<float>(current.nice   - mPrevious.nice  ) / sumDelta,
+                                static_cast<float>(current.system - mPrevious.system) / sumDelta,
+                                static_cast<float>(current.other  - mPrevious.other ) / sumDelta);
+                        }
+
+                    mPrevious = current;
+                }
+                free(cp_times);
+            }
+            else
+            {
+                ulong freq = 0;
+
+                freq = CurrentFreq(mSource);
+                if (freq > 0)
+                    emit update(freq);
+            }
+#else
     if ( (mMonitoring == CpuStat::LoadOnly)
       || (mMonitoring == CpuStat::LoadAndFrequency) )
     {
@@ -246,7 +482,7 @@ void CpuStatPrivate::timeout()
                     mPrevious = current;
                 }
             }
-        }
+        //}
     }
     else
     {
@@ -278,6 +514,7 @@ void CpuStatPrivate::timeout()
         }
         emit update(freq);
     }
+#endif
 }
 
 QString CpuStatPrivate::defaultSource()
