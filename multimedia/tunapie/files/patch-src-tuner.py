--- src/tuner.py	Wed Jan 10 00:41:00 2007
+++ src/tuner.py.port	Mon Jan 29 11:29:36 2007
@@ -266,26 +266,27 @@
     preffile.write("max streams to display="+str(int(maxd))+'\n')
     preffile.write("font size="+str(int(fontsize))+'\n')
 
-def readprefs(home,rdir,shoutice,maxd,fontsize):
+def readprefs(home,media,video,term,rip,rdir,shoutice,maxd,fontsize):
     try: preffile=open(home+'/.tunapie/prefs','r')
     except IOError:
-        return "","","","",rdir,shoutice,maxd,fontsize
+        return media,video,term,rip,rdir,shoutice,maxd,fontsize
     preferences=preffile.read().split('\n')
-    returnvals=[]
+    returnvals={'audioplayer':media,'videoplayer':video,'xterm':term,\
+		'streamripper':rip,'ripdirectory':rdir,'icecast(0)/shoutcast(1)':shoutice,\
+		'max streams to display':maxd,'font size':fontsize}
     for i in preferences:
-        try:returnvals.append(i.split("=")[1])
-        except IndexError: pass
-    if len(returnvals)<8:
-        return media,video,term,rip,rdir,shoutice,maxd,fontsize
-    return(returnvals[0],returnvals[1],returnvals[2],returnvals[3],\
-            returnvals[4],returnvals[5],returnvals[6], returnvals[7])
+        try:returnvals[i.split("=")[0]]=i.split("=")[1]
+        except (IndexError,KeyError): pass
+    return(returnvals['audioplayer'],returnvals['videoplayer'],returnvals['xterm'],\
+	   returnvals['streamripper'],returnvals['ripdirectory'],returnvals['icecast(0)/shoutcast(1)'],\
+	   returnvals['max streams to display'], returnvals['font size'])
                 
 def recordselection(terminal,args):
     player=popen2.Popen4(terminal+' '+args)
     return player.pid
 
 def adultset():
-    try: adultconfig=open('/etc/tunapie.config')
+    try: adultconfig=open('%%PREFIX%%/etc/tunapie.config')
     except IOError: return 0
     setadult=adultconfig.readline()
     return int(setadult)
