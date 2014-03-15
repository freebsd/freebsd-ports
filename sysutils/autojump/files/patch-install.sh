--- ./install.sh.orig	2010-10-01 10:49:18.000000000 -0400
+++ ./install.sh	2011-12-03 23:04:22.000000000 -0500
@@ -15,7 +15,7 @@
 #You should have received a copy of the GNU General Public License
 #along with autojump.  If not, see <http://www.gnu.org/licenses/>.
 
-function show_help {
+show_help() {
         echo "sudo ./install.sh [--prefix /usr/local]"
 }
 
@@ -41,56 +41,12 @@ done
 echo "Installing to ${prefix} ..."
 
 # INSTALL AUTOJUMP
-sudo mkdir -p ${prefix}/share/autojump/
-sudo mkdir -p ${prefix}/bin/
-sudo mkdir -p ${prefix}/share/man/man1/
-sudo cp icon.png ${prefix}/share/autojump/
-sudo cp jumpapplet ${prefix}/bin/
-sudo cp autojump ${prefix}/bin/
-sudo cp autojump.1 ${prefix}/share/man/man1/
-
-if [ -d "/etc/profile.d" ]; then
-    sudo cp autojump.bash /etc/profile.d/
-    sudo cp autojump.sh /etc/profile.d/
-
-    # Make sure that the code we just copied has been sourced.
-    # check if .bashrc has sourced /etc/profile or /etc/profile.d/autojump.bash
-    if [ `grep -c "^[[:space:]]*source\|\. /etc/profile(\.d/autojump\.bash)[[:space:]]*$" ~/.bashrc` -eq 0 ]; then
-        echo "Your .bashrc doesn't seem to source /etc/profile or /etc/profile.d/autojump.bash"
-        echo "Adding the /etc/profile.d/autojump.bash to your .bashrc"
-        echo "" >> ~/.bashrc
-        echo "# Added by autojump install.sh" >> ~/.bashrc
-        echo "source /etc/profile.d/autojump.bash" >> ~/.bashrc
-    fi
-    echo "Done!"
-    echo
-    echo "You need to source your ~/.bashrc (source ~/.bashrc) before you can start using autojump."
-else
-    echo "Your distribution does not have a /etc/profile.d directory, the default that we install one of the scripts to. Would you like us to copy it into your ~/.bashrc file to make it work? (If you have done this once before, delete the old version before doing it again.) [y/n]"
-    read ans
-    if [ ${#ans} -gt 0 ]; then
-	     if [ $ans = "y" -o $ans = "Y" -o $ans = "yes" -o $ans = "Yes" ]; then
-
-                # Answered yes. Go ahead and add the autojump code
-	        echo "" >> ~/.bashrc
-	        echo "#autojump" >> ~/.bashrc
-	        cat autojump.bash | grep -v "^#" >> ~/.bashrc
-
-                # Since OSX uses .bash_profile, we need to make sure that .bashrc is properly sourced.
-                # Makes the assumption that if they have a line: source ~/.bashrc or . ~/.bashrc, that
-                # .bashrc has been properly sourced and you don't need to add it.
-                OS=`uname`
-                if [ $OS == 'Darwin' -a `grep -c "^[[:space:]]*source\|\. ~/\.bashrc[[:space:]]*$" ~/.bash_profile` -eq 0 ]; then
-                    echo "You are using OSX and your .bash_profile doesn't seem to be sourcing .bashrc"
-                    echo "Adding source ~/.bashrc to your bashrc"
-                    echo -e "\n# Get the aliases and functions" >> ~/.bash_profile
-                    echo -e "if [ -f ~/.bashrc ]; then\n  . ~/.bashrc\nfi" >> ~/.bash_profile
-                fi
-                echo "You need to source your ~/.bashrc (source ~/.bashrc) before you can start using autojump."
-	     else
-	         echo "Then you need to put autojump.sh, or the code from it, somewhere where it will get read. Good luck!"
-	     fi
-    else
-        echo "Then you need to put autojump.sh, or the code from it, somewhere where it will get read. Good luck!"
-    fi
-fi
+mkdir -p ${prefix}/share/autojump/
+mkdir -p ${prefix}/bin/
+mkdir -p ${prefix}/man/man1/
+cp icon.png ${prefix}/share/autojump/
+cp autojump.bash ${prefix}/share/autojump/
+cp autojump.zsh ${prefix}/share/autojump/
+cp jumpapplet ${prefix}/bin/
+cp autojump ${prefix}/bin/
+cp autojump.1 ${prefix}/man/man1/
