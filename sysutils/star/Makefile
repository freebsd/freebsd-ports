# New ports collection makefile for:	star
# Version required:	1,0
# Date created:		Thu May  1 20:28:44 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.3 1997/05/19 18:00:38 andreas Exp $
#

DISTNAME=	star-1.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/star/

#PATCH_SITES=	${MASTER_SITES}
#PATCHFILES=	star-1.0.patch-1 star-1.0.patch-2

MAINTAINER=	andreas@FreeBSD.org

USE_GMAKE=	yes
MAKE_ENV=	MAKEPROG=gmake
MAN1=		star.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/star/OBJ/i386-freebsd-cc/star ${PREFIX}/bin
	ln -sf ${PREFIX}/bin/star ${PREFIX}/bin/ustar
	${INSTALL_MAN} ${WRKSRC}/star/star.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
