*** /tmp/duplicity-0.4.0/setup.py	Sat Nov 30 23:41:29 2002
--- setup.py	Wed Jun 11 20:31:32 2003
***************
*** 9,14 ****
--- 9,18 ----
  	print "Sorry, duplicity requires version 2.2 or later of python"
  	sys.exit(1)
  
+ LOCALBASE = os.environ.get("LOCALBASE", "/usr/local")
+ include_dirs = ['%s/include' % LOCALBASE]
+ library_dirs = ['%s/lib/' % LOCALBASE]
+ 
  setup(name="duplicity",
  	  version=version_string,
  	  description="Untrusted backup using rsync algorithm",
***************
*** 19,28 ****
  	  package_dir = {"duplicity": "src"},
  	  ext_modules = [Extension("duplicity._librsync",
  							   ["_librsyncmodule.c"],
! 							   libraries=["rsync"])],
! 	  scripts = ['rdiffdir', 'duplicity'],
! 	  data_files = [('share/man/man1', ['duplicity.1', 'rdiffdir.1']),
! 					('share/doc/duplicity-%s' % version_string,
! 					 ['COPYING', 'README', 'CHANGELOG'])])
  
  
--- 23,32 ----
  	  package_dir = {"duplicity": "src"},
  	  ext_modules = [Extension("duplicity._librsync",
  							   ["_librsyncmodule.c"],
! 							   libraries=["rsync"],
!                                                            include_dirs=include_dirs,
!                                                            library_dirs=library_dirs)],
! 	  scripts = ['rdiffdir', 'duplicity']
! )
  
  
