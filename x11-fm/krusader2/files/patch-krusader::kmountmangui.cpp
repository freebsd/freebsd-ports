*** krusader/MountMan/kmountmangui.cpp.orig	Mon Apr 15 20:49:42 2002
--- krusader/MountMan/kmountmangui.cpp	Thu Oct 24 12:42:12 2002
***************
*** 70,76 ****
    // connections
    connect(mountList,SIGNAL(doubleClicked(QListViewItem *)),this,
            SLOT(doubleClicked(QListViewItem*)));
!   connect(mountList,SIGNAL(rightButtonClicked(QListViewItem *, const QPoint &, int)),
            this, SLOT(clicked(QListViewItem*)));
    connect(mountList,SIGNAL(clicked(QListViewItem *)), this,
            SLOT(changeActive(QListViewItem *)));
--- 70,76 ----
    // connections
    connect(mountList,SIGNAL(doubleClicked(QListViewItem *)),this,
            SLOT(doubleClicked(QListViewItem*)));
!   connect(mountList,SIGNAL(rightButtonPressed(QListViewItem *, const QPoint &, int)),
            this, SLOT(clicked(QListViewItem*)));
    connect(mountList,SIGNAL(clicked(QListViewItem *)), this,
            SLOT(changeActive(QListViewItem *)));
