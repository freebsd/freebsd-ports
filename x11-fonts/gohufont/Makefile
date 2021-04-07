PORTNAME=	gohufont
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://font.gohu.org/

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Monospace bitmap font well suited for programming and terminal use

LICENSE=	WTFPL
LICENSE_FILE=	${WRKSRC}/COPYING-LICENSE

USES=		fonts
NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
