*** helpers/basic_auth/SMB/smb_auth.sh.orig	Thu Feb 26 20:58:22 2004
--- helpers/basic_auth/SMB/smb_auth.sh	Thu Feb 26 20:59:45 2004
***************
*** 17,22 ****
--- 17,24 ----
  # along with this program; if not, write to the Free Software
  # Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  
+ SAMBAPREFIX=${SAMBAPREFIX:-%%LOCALBASE%%}
+ 
  read DOMAINNAME
  read PASSTHROUGH
  read NMBADDR
