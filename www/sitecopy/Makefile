# New ports collection makefile for:	sitecopy
# Version required:	0.4.0
# Date created:		15 January 1999
# Whom:			nik
#
# $Id: Makefile,v 1.3 1999/02/24 21:45:33 nik Exp $
#

DISTNAME=	sitecopy-0.4.0
CATEGORIES=	www
MASTER_SITES=   http://www.lyra.org/sitecopy/

MAINTAINER=     nik@FreeBSD.ORG

USE_GMAKE=	yes
FETCH_BEFORE_ARGS=	-b

MAN1=		sitecopy.1
MANCOMPRESSED=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sitecopy ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sitecopy.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
