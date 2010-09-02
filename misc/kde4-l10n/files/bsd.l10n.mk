.if defined(KDE4_L10N)
MASTER_SITES?=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR?=	${KDE4_BRANCH}/${PORTVERSION}/src/kde-l10n/
PKGNAMEPREFIX=	${KDE4_L10N:S/@/_/}-
DISTNAME=	${PORTNAME}-${KDE4_L10N}-${PORTVERSION}
DIST_SUBDIR?=	KDE/kde-l10n

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	uic_build moc_build qmake_build rcc_build xml
USE_GETTEXT=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4
USE_CMAKE=	yes

.endif
