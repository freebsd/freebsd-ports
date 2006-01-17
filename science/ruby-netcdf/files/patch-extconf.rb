--- extconf.rb.orig	Thu Jun 23 09:20:15 2005
+++ extconf.rb	Tue Jan 17 13:36:39 2006
@@ -105,9 +105,6 @@
       newmkfl.puts("")         
       newmkfl.puts("test: all")            # insert the "test" target
       newmkfl.puts("\t\t@cd test && ruby test.rb && echo 'test did not fail :-p (please ignore the warnings)' && cd ..") 
-   when /lib\/netcdf/
-      line = line.chomp! + "/"
-      newmkfl.puts(line)
    else
       newmkfl.puts(line)
    end
