# New ports collection makefile for:    freefonts
# Version required:     0.10
# Date created:         Thu Aug  1 21:32:14 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.1.1.1 1996/08/16 13:38:33 erich Exp $
#

DISTNAME=	freefonts-0.10
CATEGORIES+=	x11
MASTER_SITES=	ftp://scam.xcf.berkeley.edu/pub/gimp/

MAINTAINER=	erich@FreeBSD.org

NO_WRKSUBDIR=	yes
USE_X11=	yes

post-install:
	@cat ${PKGDIR}/DESCR

.include <bsd.port.mk>
