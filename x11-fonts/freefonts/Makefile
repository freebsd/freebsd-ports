# New ports collection makefile for:    freefonts
# Version required:     0.10
# Date created:         Thu Aug  1 21:32:14 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.6 1998/08/05 09:31:42 asami Exp $
#

DISTNAME=	freefonts-0.10
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/fonts/

MAINTAINER=	erich@FreeBSD.org

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

post-install:
	@cat ${PKGDIR}/DESCR

.include <bsd.port.mk>
