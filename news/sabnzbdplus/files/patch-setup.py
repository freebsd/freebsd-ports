*** setup.py.orig	Sat Mar  4 13:16:01 2006
--- setup.py	Sat Mar 18 21:59:59 2006
***************
*** 15,20 ****
        license = 'Academic Free License 2.1',
!       data_files = [('/usr/share/doc/SABnzbd-' + sabnzbd.__version__,
!                              ['SABnzbd.ini.sample', 'README.txt', 'LICENSE.txt',
                                'TODO.txt', 'CHANGELOG.txt', 'UPGRADE.txt']),
!                     ('/usr/share/doc/SABnzbd-' + sabnzbd.__version__ + '/templates',
                               ['templates/default.css', 'templates/history.tmpl',
--- 15,21 ----
        license = 'Academic Free License 2.1',
!       data_files = [('share/doc/SABnzbd',
!                              ['README.txt', 'LICENSE.txt',
                                'TODO.txt', 'CHANGELOG.txt', 'UPGRADE.txt']),
!                     ('share/SABnzbd',['SABnzbd.ini.sample']),
!                     ('share/SABnzbd' + '/templates',
                               ['templates/default.css', 'templates/history.tmpl',
