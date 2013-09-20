# Created by: Thomas Sandford <freebsduser@paradisegreen.co.uk>
# $FreeBSD$

PORTNAME=	reed-solomon
PORTVERSION=	4.0
CATEGORIES=	math
MASTER_SITES=	http://www.ka9q.net/code/fec/

MAINTAINER=	freebsduser@paradisegreen.co.uk
COMMENT=	A Reed-Solomon CODEC library

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKEFILE=	makefile

MAN3=		rs.3

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/makefile.in

.include <bsd.port.mk>
