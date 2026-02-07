PORTNAME=	reed-solomon
PORTVERSION=	4.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.ka9q.net/code/fec/

MAINTAINER=	freebsduser@paradisegreen.co.uk
COMMENT=	Reed-Solomon CODEC library
WWW=		http://www.ka9q.net/code/fec/

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		gmake
USE_LDCONFIG=	yes
MAKEFILE=	makefile

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/makefile.in

.include <bsd.port.mk>
