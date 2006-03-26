*** setup.py.orig	Fri Mar 24 23:26:24 2006
--- setup.py	Fri Mar 24 23:27:22 2006
***************
*** 15,20 ****
        license = 'Academic Free License 2.1',
!       data_files = [('share/doc/SABnzbd-' + sabnzbd.__version__,
!                      ['SABnzbd.ini.sample', 'README.txt', 'LICENSE.txt',
!                       'TODO.txt', 'CHANGELOG.txt', 'UPGRADE.txt']),
!                     ('share/SABnzbd-' + sabnzbd.__version__ + '/templates',
                               ['templates/default.css', 'templates/history.tmpl',
--- 15,21 ----
        license = 'Academic Free License 2.1',
!       data_files = [('share/doc/SABnzbd',
!                              ['README.txt', 'LICENSE.txt',
!                               'TODO.txt', 'CHANGELOG.txt', 'UPGRADE.txt']),
!                     ('share/SABnzbd',['SABnzbd.ini.sample']),
!                     ('share/SABnzbd' + '/templates',
                               ['templates/default.css', 'templates/history.tmpl',
