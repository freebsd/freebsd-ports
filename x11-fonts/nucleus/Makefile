# New ports collection makefile for:	nucleus
# Date created:				Sat Aug 12 15:02:03 CEST 2000
# Whom:					olgeni@uli.it
#
# $FreeBSD$
#

PORTNAME=	nucleus
PORTVERSION=	0.77
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xfonts

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Another font package for X

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

post-install:
	@${CAT} ${DESCR}

.include <bsd.port.mk>
