# New ports collection makefile for:    freefonts
# Date created:         Thu Aug  1 21:32:14 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	freefonts
PORTVERSION= 	0.10
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/fonts/

MAINTAINER=	ports@FreeBSD.org

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
