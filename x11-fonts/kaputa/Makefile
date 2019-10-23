# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kaputa
DISTVERSION=	1.000
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.kaputa.com/slword/
DISTNAME=	${PORTNAME}unicode
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Free Unicode font for Sinhala script

LICENSE=	UNKNOWN
LICENSE_NAME=	unknown
LICENSE_TEXT=	The exact license is unknown.\
		The FAQ at http://www.kaputa.com/slword/help.htm says that\
		those fonts are free to use.
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	${FONTSDIR}/kaputaunicode.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/kaputaunicode.ttf \
		${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
