*** krusader/MountMan/kmountman.cpp.orig	Sun Jul 28 22:36:55 2002
--- krusader/MountMan/kmountman.cpp	Thu Oct 24 12:01:13 2002
***************
*** 176,182 ****
    --i; fstab.close();  // finished with it
    for (j=0; j<=i; ++j) {
    	if (temp[0][j]=="" || temp[0][j]=="tmpfs" || temp[0][j]=="none" || temp[0][j]=="proc" ||
!         temp[0][j]=="swap" || temp[1][j]=="proc" || temp[1][j]=="/dev/pts" ||	
          temp[1][j]=="swap" || temp[4][j]=="supermount") continue;
    	++noOfFilesystems;
    }
--- 176,182 ----
    --i; fstab.close();  // finished with it
    for (j=0; j<=i; ++j) {
    	if (temp[0][j]=="" || temp[0][j]=="tmpfs" || temp[0][j]=="none" || temp[0][j]=="proc" ||
!         temp[0][j]=="swap" || temp[1][j]=="procfs" || temp[1][j]=="/dev/pts" || // FreeBSD: procfs instead of proc
          temp[1][j]=="swap" || temp[4][j]=="supermount") continue;
    	++noOfFilesystems;
    }
***************
*** 203,220 ****
      }
    }
  	kdDebug() << "Mt.Man: found the followning:\n" << forDebugOnly << "Trying DF..." << endl;
  	return true;
  }
  
  // run DF process and when it finishes, catch output with "parseDfData"
  ///////////////////////////////////////////////////////////////////////
  void KMountMan::updateFilesystems() {
!   // create the "df -P -T" process
    tempFile = new KTempFile();
    tempFile->setAutoDelete(true);
    dfProc.clearArguments();
    dfProc.setExecutable("df");
!   dfProc << "-T" << "-P" << ">" << tempFile->name();
    connect(&dfProc, SIGNAL(processExited(KProcess *)), this,
            SLOT(finishUpdateFilesystems()));
    dfProc.start(KProcess::NotifyOnExit);
--- 203,267 ----
      }
    }
  	kdDebug() << "Mt.Man: found the followning:\n" << forDebugOnly << "Trying DF..." << endl;
+ 
+ 
+   // FreeBSD problem: df does not retrive fs type.
+   // Workaround: execute mount -p and merge result.
+ 
+   KShellProcess proc;
+   proc << "mount -p";
+ 
+   // connect all outputs to collectOutput, to be displayed later
+   connect(&proc,SIGNAL(receivedStdout(KProcess*, char*, int)),
+           this,SLOT(collectOutput(KProcess*, char*,int)));
+   // launch
+   clearOutput();
+   if (!proc.start(KProcess::Block,KProcess::Stdout)) {
+     KMessageBox::error(0,
+       i18n("Unable to execute 'mount -p' !!!"));
+       return true;
+   }
+ 
+   QString str = getOutput();
+ 	QTextStream t2(str, IO_ReadOnly);
+   while (!t2.atEnd()) {
+     s = t2.readLine();
+     s = s.simplifyWhiteSpace(); // remove TABs
+     if (s==QString::null || s=="") continue;  // skip empty lines in fstab
+     // temp[0]==name, temp[1]==type, temp[2]==mount point, temp[3]==options
+     // temp[4] is reserved for special cases, right now, only for supermount
+     QString temp0=nextWord(s,' ');
+     QString temp2=nextWord(s,' ');
+     QString temp1=nextWord(s,' ');
+     QString temp3=nextWord(s,' ');
+ 		if (temp0=="" || temp2=="/proc" || temp2=="/dev/pts" ||
+   			temp2=="swap" || temp0=="none" || temp0=="procfs" ||
+         temp0=="swap" || location(temp0)) continue;
+     else {
+ 	    fsData* system=new fsData();
+ 	    system->setName(temp0);
+   	  system->setType(temp1);
+    	  system->setMntPoint(temp2);
+   	  system->supermount=false;
+   	  system->options=temp3;
+   	  filesystems.append(system);
+       ++noOfFilesystems;
+ 			kdWarning() << "Mt.Man: filesystem [" << temp0 << "] found by mount -p is unlisted in /etc/fstab." << endl;
+     }
+   }
+ 
  	return true;
  }
  
  // run DF process and when it finishes, catch output with "parseDfData"
  ///////////////////////////////////////////////////////////////////////
  void KMountMan::updateFilesystems() {
!   // create the "df" process // FreeBSD: df instead of df -T -P
    tempFile = new KTempFile();
    tempFile->setAutoDelete(true);
    dfProc.clearArguments();
    dfProc.setExecutable("df");
!   dfProc << ">" << tempFile->name(); // FreeBSD: df instead of df -T -P
    connect(&dfProc, SIGNAL(processExited(KProcess *)), this,
            SLOT(finishUpdateFilesystems()));
    dfProc.start(KProcess::NotifyOnExit);
***************
*** 244,250 ****
  fsData* KMountMan::location(QString name) {
    fsData* it;
    for (it=filesystems.first() ; (it!=0) ; it=filesystems.next())
!    if (followLink(it->name())==followLink(name)) break;
    return it;
  }
  
--- 291,300 ----
  fsData* KMountMan::location(QString name) {
    fsData* it;
    for (it=filesystems.first() ; (it!=0) ; it=filesystems.next())
!   {
!    if (followLink(it->name())==followLink(name)) break; 
!    if (name.left(2) == "//" && !strcasecmp(followLink(it->name()).latin1(), followLink(name).latin1())) break; // FreeBSD: ignore case due to smbfs mounts
!   }
    return it;
  }
  
***************
*** 336,341 ****
--- 386,392 ----
      temp=nextWord(s,' ');
      // avoid adding unwanted filesystems to the list
      if (temp=="tmpfs") continue;
+     if (temp == "procfs") continue;// FreeBSD: ignore procfs
      temp=followLink(temp);  // make sure DF gives us the true device and not a link
      fsData* loc=location(temp); // where is the filesystem located in our list?
      if (loc==0) {
***************
*** 347,361 ****
  			else loc->setName("/dev/"+temp);
  			newFS=true;
      }
!     temp=nextWord(s,' ');   // catch the TYPE
      // is it supermounted ?
!     if (temp=="supermount") loc->supermount=true;
!     loc->setType(temp);
!     if (loc->type()!=temp) {
!     	kdWarning() << "Mt.Man: according to DF, filesystem [" << loc->name() <<
!     				 "] has a different type from what's stated in /etc/fstab." << endl;
!       loc->setType(temp);  // DF knows best
!     }
      temp=nextWord(s,' ');
      loc->setTotalBlks(temp.toLong());
      temp=nextWord(s,' ');
--- 398,412 ----
  			else loc->setName("/dev/"+temp);
  			newFS=true;
      }
!     //    temp=nextWord(s,' ');   // catch the TYPE // FreeBSD: different df output
      // is it supermounted ?
!     //if (temp=="supermount") loc->supermount=true;
!     //loc->setType(temp);
!     //if (loc->type()!=temp) {
!     //	kdWarning() << "Mt.Man: according to DF, filesystem [" << loc->name() <<
!     //				 "] has a different type from what's stated in /etc/fstab." << endl;
!     //  loc->setType(temp);  // DF knows best
!     //}
      temp=nextWord(s,' ');
      loc->setTotalBlks(temp.toLong());
      temp=nextWord(s,' ');
***************
*** 389,395 ****
    	Operational=Ready=false;
  		return;										 // if something went wrong, bail out!
  	} else Operational=true;     // mountman is alive but not yet ready
! 	updateFilesystems();         // use the output of "DF -T -P" to update data
  }
  
  void KMountMan::collectOutput(KProcess *p, char *buffer,int buflen) {
--- 440,446 ----
    	Operational=Ready=false;
  		return;										 // if something went wrong, bail out!
  	} else Operational=true;     // mountman is alive but not yet ready
! 	updateFilesystems();         // use the output of "DF" to update data // FreeBSD: df instead of df -T -P
  }
  
  void KMountMan::collectOutput(KProcess *p, char *buffer,int buflen) {
***************
*** 523,535 ****
      KMessageBox::information(0,i18n("Error ejecting device ! You need to have 'eject' in your path."),i18n("Error"),"CantExecuteEjectWarning");
  }
  
  // returns true if the path is an ejectable mount point (at the moment CDROM)
  bool KMountMan::ejectable(QString path) {
!   fsData* it;
!   for (it=filesystems.first() ; (it!=0) ; it=filesystems.next())
!     if (it->mntPoint()==path &&
!         (it->type()=="iso9660" || followLink(it->name()).left(2)=="cd"))
!       return true;
    return false;
  }
  
--- 574,587 ----
      KMessageBox::information(0,i18n("Error ejecting device ! You need to have 'eject' in your path."),i18n("Error"),"CantExecuteEjectWarning");
  }
  
+ 
  // returns true if the path is an ejectable mount point (at the moment CDROM)
  bool KMountMan::ejectable(QString path) {
!   //fsData* it;// FreeBSD: no eject command
!   //for (it=filesystems.first() ; (it!=0) ; it=filesystems.next())
!   //  if (it->mntPoint()==path &&
!   //      (it->type()=="iso9660" || followLink(it->name()).left(2)=="cd"))
!   //    return true;
    return false;
  }
  
***************
*** 537,544 ****
  statsCollector::statsCollector(QString path, QObject *caller): QObject() {
    QString stats;
    connect(this, SIGNAL(gotStats(QString)), caller, SLOT(gotStats(QString)));
!   if (path.left(5)=="/proc") { // /proc is a special case - no volume information
!     stats=i18n("No space information on a [proc]");
      emit gotStats(stats);
      return;
    }
--- 589,596 ----
  statsCollector::statsCollector(QString path, QObject *caller): QObject() {
    QString stats;
    connect(this, SIGNAL(gotStats(QString)), caller, SLOT(gotStats(QString)));
!   if (path.left(11)=="/dev/procfs") { // /dev/procfs is a special case - no volume information FreeBSD: procfs instead of proc
!     stats=i18n("No space information on a [procfs]"); // FreeBSD: procfs instead of proc
      emit gotStats(stats);
      return;
    }
***************
*** 571,577 ****
    QString s;
    s = t.readLine();  // read the 1st line - it's trash for us
    s = t.readLine();  // this is the important one!
!   data->setName(KMountMan::nextWord(s,' '));
    data->setType(KMountMan::nextWord(s,' '));
    data->setTotalBlks( KMountMan::nextWord(s,' ').toLong() );
    data->setUsedBlks( KMountMan::nextWord(s,' ').toLong() );
--- 623,629 ----
    QString s;
    s = t.readLine();  // read the 1st line - it's trash for us
    s = t.readLine();  // this is the important one!
! //  data->setName(KMountMan::nextWord(s,' ')); FreeBSD: different df output format
    data->setType(KMountMan::nextWord(s,' '));
    data->setTotalBlks( KMountMan::nextWord(s,' ').toLong() );
    data->setUsedBlks( KMountMan::nextWord(s,' ').toLong() );
***************
*** 587,593 ****
    KShellProcess dfProc;
    QString tmpFile = krApp->getTempFile();
  
!   dfProc << "df" << "-T" << "-P" << "\""+path+"\"" << ">" << tmpFile;
    dfProc.start(KProcess::Block);
    parseDf(tmpFile, data);
    QDir().remove(tmpFile);
--- 639,645 ----
    KShellProcess dfProc;
    QString tmpFile = krApp->getTempFile();
  
!   dfProc << "df" << "\""+path+"\"" << ">" << tmpFile; // FreeBSD: df instead of df -T -P
    dfProc.start(KProcess::Block);
    parseDf(tmpFile, data);
    QDir().remove(tmpFile);
