# Ports collection Makefile for:	smurflog
# Version required:			1.0
# Date created:				7/06/1998
# Whom:					nectar@FreeBSD.ORG
#
# $Id: Makefile,v 1.2 1998/07/26 18:30:31 obrien Exp $
#

DISTNAME=	smurflog-1.0
CATEGORIES=	net security
MASTER_SITES=	http://www.sy.net/security/

MAINTAINER=	nectar@FreeBSD.ORG

WRKSRC=		${WRKDIR}/SmurfLog-1.0

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.smurflog

.include <bsd.port.mk>
