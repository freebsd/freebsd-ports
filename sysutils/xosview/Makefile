# New ports collection makefile for:	xosview
# Version required:	1.6.2.a
# Date created:		19 Nov 1997
# Whom:			Brian Handy <handy@physics.montana.edu>
#
# $Id: Makefile,v 1.11 1998/12/29 00:15:34 asami Exp $
#

DISTNAME=	xosview-1.6.2.a
CATEGORIES=	sysutils
MASTER_SITES=	http://lore.ece.utexas.edu/~bgrayson/xosview/ \
		http://lambic.physics.montana.edu/xosview/

MAINTAINER=	handy@physics.montana.edu

FETCH_BEFORE_ARGS=	-b
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
MAN1=		xosview.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 300006
BROKEN=	"DK_NDRIVE undefined"
.endif

.include <bsd.port.post.mk>
