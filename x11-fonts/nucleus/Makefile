# New ports collection makefile for:	nucleus
# Date created:				Sat Aug 12 15:02:03 CEST 2000
# Whom:					olgeni@uli.it
#
# $FreeBSD$
#

PORTNAME=	nucleus
PORTVERSION=	0.77
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://dreamer.nitro.dk/linux/lfp/

MAINTAINER=	olgeni@FreeBSD.org

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
.endif

post-install:
	@${CAT} ${DESCR}

.include <bsd.port.post.mk>
