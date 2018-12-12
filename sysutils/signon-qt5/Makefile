# $FreeBSD$

PORTNAME=	signon
PORTVERSION=	8.58
PORTREVISION=	1
CATEGORIES=	sysutils kde
PKGNAMESUFFIX=	-qt5
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	D-Bus service performing user authentication

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang gettext pathfix pkgconfig python qmake \
		qt:5 tar:bz2
USE_QT=		core dbus gui network sql testlib xml \
		buildtools_build qmake_build

# gitlab variables
USE_GITLAB=	yes
GL_ACCOUNT=	accounts-sso
GL_PROJECT=	signond
GL_COMMIT=	aa1bcf3c9218addbdb376a40151b689409046125

OPTIONS_DEFINE=	DOCS

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
