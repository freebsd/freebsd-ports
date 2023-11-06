PORTNAME=	netmap
PORTVERSION=	0.1.3
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/NetMap%20${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Make a graphical representation of the surrounding network
WWW=		https://netmap.sourceforge.net/

LICENSE=	GPLv2

RUN_DEPENDS=	dot:graphics/graphviz

USES=		gmake

PLIST_FILES=	bin/makelist bin/netmap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/makelist/makelist ${WRKSRC}/netmap/netmap ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
