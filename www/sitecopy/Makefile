# New ports collection makefile for:	sitecopy
# Version required:	0.3.2
# Date created:		15 January 1999
# Whom:			nik
#
# $Id: Makefile,v 1.1.1.1 1999/01/16 00:25:54 nik Exp $
#

DISTNAME=	sitecopy-0.3.2
CATEGORIES=	www
MASTER_SITES=   http://www.lyra.org/sitecopy/
DISTFILES=	sitecopy-0.3.0.tar.gz

PATCH_SITES=	http://www.lyra.org/sitecopy/
PATCHFILES=	sitecopy-0.3.0-0.3.2.patch.gz
PATCH_DIST_STRIP=

MAINTAINER=     nik@FreeBSD.ORG

USE_GMAKE=	yes
DIST_SUBDIR=	sitecopy
WRKSRC=		${WRKDIR}/sitecopy-0.3.0
FETCH_BEFORE_ARGS=	-b

MAN1=		sitecopy.1
MANCOMPRESSED=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sitecopy ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sitecopy.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
