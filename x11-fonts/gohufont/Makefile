# $FreeBSD$

PORTNAME=	gohufont
PORTVERSION=	2.1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://font.gohu.org/

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Monospace bitmap font well suited for programming and terminal use

LICENSE=	WTFPL
LICENSE_NAME=	Do What The Fuck You Want To Public License, Version 2
LICENSE_FILE=	${WRKSRC}/COPYING-LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		fonts
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
