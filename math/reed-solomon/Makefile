# New ports collection makefile for:	reed-solomon
# Date created:		29 Jun 2005
# Whom:			Thomas Sandford <freebsduser@paradisegreen.co.uk>
#
# $FreeBSD$
#

PORTNAME=	reed-solomon
PORTVERSION=	4.0
CATEGORIES=	math
MASTER_SITES=	http://www.ka9q.net/code/fec/

MAINTAINER=	freebsduser@paradisegreen.co.uk
COMMENT=	A Reed-Solomon CODEC library

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
MAKEFILE=	makefile

MAN3=		rs.3

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/makefile.in

.include <bsd.port.mk>
