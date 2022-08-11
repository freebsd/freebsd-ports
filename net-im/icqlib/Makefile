PORTNAME=	icqlib
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library required by kicq (not libicq)

USES=		gmake libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libicq.so

.include <bsd.port.mk>
