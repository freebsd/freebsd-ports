# New ports collection makefile for:    freefonts
# Date created:         Thu Aug  1 21:32:14 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	freefonts
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/fonts/

MAINTAINER=	olgeni@FreeBSD.org

RESTRICTED=	"see accompanying .license files"
NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

post-install:
	${RM} ${PREFIX}/lib/X11/fonts/freefont/fonts.dir.orig
	@${CAT} ${DESCR}

.include <bsd.port.mk>
