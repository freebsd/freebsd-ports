*** krusader/VFS/arc_vfs.cpp.orig	Mon Apr 15 20:51:37 2002
--- krusader/VFS/arc_vfs.cpp	Thu Oct 24 12:01:13 2002
***************
*** 814,821 ****
      group = temp.mid(temp.find('/')+1,temp.length()).toInt();
      size = nextWord(line).toLong();
      temp = nextWord(line);
!     dateTime = temp.mid(8,2)+"/"+temp.mid(5,2)+"/"+temp.mid(2,2)+
!                        " "+nextWord(line).left(5);
      name = nextWord(line,'\n');
      if( name.contains(" -> ") ){
        link = true;
--- 814,822 ----
      group = temp.mid(temp.find('/')+1,temp.length()).toInt();
      size = nextWord(line).toLong();
      temp = nextWord(line);
!     dateTime = nextWord(line) + "/" + month2Qstring(temp) + "/";
!     temp = nextWord(line);
!     dateTime += nextWord(line) + " " + temp;
      name = nextWord(line,'\n');
      if( name.contains(" -> ") ){
        link = true;
