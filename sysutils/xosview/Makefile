# New ports collection makefile for:	xosview
# Version required:	1.6.1.a
# Date created:		19 Nov 1997
# Whom:			Brian Handy <handy@physics.montana.edu>
#
# $Id: Makefile,v 1.10 1998/12/27 08:28:01 obrien Exp $
#

DISTNAME=	xosview-1.6.1.a
CATEGORIES=	sysutils
MASTER_SITES=	http://lore.ece.utexas.edu/~bgrayson/xosview/ \
		http://lambic.physics.montana.edu/xosview/

MAINTAINER=	handy@physics.montana.edu

FETCH_BEFORE_ARGS=	-b
USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
MAN1=		xosview.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 300006
BROKEN=	"DK_NDRIVE undefined"
.endif

.include <bsd.port.post.mk>
