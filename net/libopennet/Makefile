PORTNAME=	libopennet
PORTVERSION=	0.9.9
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.rkeene.org/files/oss/libopennet/ \
		http://www.cs.nctu.edu.tw/~gslin/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for opening files over a network
WWW=		https://www.rkeene.org/oss/libopennet/

LICENSE=	LGPL21 GPLv2 # net.c header mentions GPL
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
PLIST_SUB=	PORTVERSION=${PORTVERSION}
USES=		gmake
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopennet.so

.include <bsd.port.mk>
