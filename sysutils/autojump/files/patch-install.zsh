--- ./install.zsh.orig	2010-10-01 10:49:18.000000000 -0400
+++ ./install.zsh	2011-12-03 23:25:09.000000000 -0500
@@ -39,19 +39,21 @@
 
 echo "Installing main files to ${prefix} ..."
 
-sudo mkdir -p ${prefix}/share/autojump/
-sudo mkdir -p ${prefix}/bin/
-sudo mkdir -p ${prefix}/share/man/man1/
-sudo cp icon.png ${prefix}/share/autojump/
-sudo cp jumpapplet ${prefix}/bin/
-sudo cp autojump ${prefix}/bin/
-sudo cp autojump.1 ${prefix}/share/man/man1/
+mkdir -p ${prefix}/share/autojump/
+mkdir -p ${prefix}/bin/
+mkdir -p ${prefix}/man/man1/
+cp icon.png ${prefix}/share/autojump/
+cp autojump.bash ${prefix}/share/autojump/
+cp autojump.zsh ${prefix}/share/autojump/
+cp jumpapplet ${prefix}/bin/
+cp autojump ${prefix}/bin/
+cp autojump.1 ${prefix}/man/man1/
 
 # autocompletion file in the first directory of the FPATH variable
 fail=true
 for f in $fpath
 do
-    sudo cp _j $f && fail=false && break
+    cp _j $f && fail=false && break
 done
 if $fail
 then
@@ -60,32 +60,3 @@
 else
     echo "Installed autocompletion file to $f"
 fi
-
-if [ -d "/etc/profile.d" ]; then
-    sudo cp autojump.zsh /etc/profile.d/
-    sudo cp autojump.sh /etc/profile.d/
-    echo "Remember to add the line" 
-    echo "    source /etc/profile.d/autojump.zsh"
-    echo "or"
-    echo "    source /etc/profile"
-    echo "to your ~/.zshrc if it's not there already"
-    echo
-    echo "You need to source your ~/.zshrc (source ~/.zshrc) before you can start using autojump."
-else
-    echo "Your distribution does not have a /etc/profile.d directory, the default that we install one of the scripts to. Would you like us to copy it into your ~/.zshrc file to make it work? (If you have done this once before, delete the old version before doing it again.) [y/n]"
-    read ans
-    if [ ${#ans} -gt 0 ]; then
-	if [ $ans = "y" -o $ans = "Y" -o $ans = "yes" -o $ans = "Yes" ]; then
-	    echo "" >> ~/.zshrc
-	    echo "#autojump" >> ~/.zshrc
-	    cat autojump.zsh >> ~/.zshrc
-            echo "Done!"
-            echo
-            echo "You need to source your ~/.zshrc (source ~/.zshrc) before you can start using autojump."
-	else
-	    echo "Then you need to put autojump.zsh, or the code from it, somewhere where it will get read. Good luck!"
-	fi
-    else
-    	    echo "Then you need to put autojump.zsh, or the code from it, somewhere where it will get read. Good luck!"
-    fi
-fi
