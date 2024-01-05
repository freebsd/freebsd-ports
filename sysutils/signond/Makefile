PORTNAME=	signon
DISTVERSION=	8.61
CATEGORIES=	sysutils kde
PKGNAMESUFFIX=	-${FLAVOR}
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	D-Bus service performing user authentication
WWW=		https://gitlab.com/accounts-sso/signond

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		compiler:c++11-lang gettext gl pathfix pkgconfig python qmake \
		qt:${FLAVOR:S/qt//} tar:bz2
USE_GL=		gl
_USE_QT_qt5=	core dbus gui network sql testlib xml \
		buildtools:build qmake:build
_USE_QT_qt6=	base
USE_QT=		${_USE_QT_${FLAVOR}}

# gitlab variables
USE_GITLAB=	yes
GL_ACCOUNT=	nicolasfella
GL_PROJECT=	signond
GL_TAGNAME=	c8ad98249af541514ff7a81634d3295e712f1a39

OPTIONS_DEFINE=	DOCS

PLIST_SUB=	QT_VER=${FLAVOR:S/qt//}

pre-configure:
	#make it find qdbusxml2ccp (as ${QT_BINDIR} is not in PATH)
	${REINPLACE_CMD} -e 's,qdbusxml2cpp,${QT_BINDIR}/qdbusxml2cpp,' \
		${WRKSRC}/src/signond/signond.pro
	#correctly install signond.conf
	${REINPLACE_CMD} -e '/conf_file.path/ s,/etc/,${LOCALBASE}/etc/,' \
		${WRKSRC}/src/signond/signond.pro
	#find moved signond.conf
	${REINPLACE_CMD} -e 's,/etc,${LOCALBASE}/etc,' \
		${WRKSRC}/src/signond/signondaemon.cpp

.include <bsd.port.mk>
