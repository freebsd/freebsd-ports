# New ports collection makefile for:    freefonts
# Version required:     0.10
# Date created:         Thu Aug  1 21:32:14 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.4 1997/11/30 19:19:41 vanilla Exp $
#

DISTNAME=	freefonts-0.10
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/fonts/

MAINTAINER=	erich@FreeBSD.org

NO_WRKSUBDIR=	yes
USE_X11=	yes

post-install:
	@cat ${PKGDIR}/DESCR

.include <bsd.port.mk>
