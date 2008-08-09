.if defined(KDE4_L10N)
USE_BZIP2=	yes
USE_QT_VER=	4                                                                                                                                                    
QT_COMPONENTS=	uic moc qmake rcc xml
USE_GETTEXT= 	yes
USE_KDE4=       kdelibs kdeprefix automoc4
USE_CMAKE= yes
MASTER_SITES?=   ${MASTER_SITE_KDE}                                                                                                                                    
MASTER_SITE_SUBDIR?=    stable/${PORTVERSION}/src/kde-l10n/
DIST_SUBDIR?=   KDE
.endif
