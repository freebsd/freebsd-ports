# $FreeBSD$

PORTNAME=	gohufont
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://font.gohu.org/

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Monospace bitmap font well suited for programming and terminal use

LICENSE=	WTFPL
LICENSE_NAME=	Do What The Fuck You Want To Public License, Version 2
LICENSE_FILE=	${WRKSRC}/COPYING-LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

FONTDIR=	lib/X11/fonts/${PORTNAME}
NO_BUILD=	yes
PLIST_SUB=	FONTDIR=${FONTDIR}

do-install:
	${MKDIR} ${STAGEDIR}${LOCALBASE}/${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${STAGEDIR}${LOCALBASE}/${FONTDIR}

.include <bsd.port.mk>
