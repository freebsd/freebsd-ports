# New ports collection makefile for:    mpegedit
# Version required:     2.2
# Date created:         Thu Aug  1 10:50:57 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	mpegedit_v2.2
PKGNAME=	mpegedit-2.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.demon.co.uk/pub/unix/tools/

MAINTAINER=	erich@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/include/pbmplus.h:${PORTSDIR}/graphics/netpbm

.include <bsd.port.pre.mk>
.if ${OSVERSION} > 400002 && ${OSVERSION} < 400012
BROKEN=		won\'t build with egcs compiler
.endif

USE_X_PREFIX=	yes
USE_GMAKE=	yes

.include <bsd.port.post.mk>
