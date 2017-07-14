# $FreeBSD$

PORTNAME=	signon
PORTVERSION=	8.58
CATEGORIES=	sysutils kde
MASTER_SITES=	https://gitlab.com/${GL_ACCOUNT}/${GL_PROJECT}/repository/archive${EXTRACT_SUFX}?ref=${GL_TAGNAME}&num;/ \
		LOCAL/tcberner/${GL_ACCOUNT}/
PKGNAMESUFFIX=	-qt5
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	D-Bus service performing user authentication

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext pathfix pkgconfig python qmake tar:bz2
USE_QT5=	core dbus gui network sql testlib xml \
		buildtools_build qmake_build

# gitlab variables
GL_ACCOUNT=	accounts-sso
GL_PROJECT=	signond
GL_TAGNAME=	aa1bcf3c9218addbdb376a40151b689409046125
WRKSRC=		${WRKDIR}/${GL_PROJECT}-${GL_TAGNAME}-${GL_TAGNAME}

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
