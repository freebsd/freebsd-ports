# New ports collection makefile for:	xosview
# Version required:	1.6.1.a
# Date created:		19 Nov 1997
# Whom:			Brian Handy <handy@physics.montana.edu>
#
# $Id: Makefile,v 1.7 1998/08/24 01:13:55 steve Exp $
#

DISTNAME=	xosview-1.6.1.a
CATEGORIES=	sysutils x11
MASTER_SITES=	http://lore.ece.utexas.edu/~bgrayson/xosview/ \
		http://lambic.physics.montana.edu/xosview/

MAINTAINER=	handy@physics.montana.edu

FETCH_BEFORE_ARGS=	-b
USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
MAN1=		xosview.1

BROKEN_ELF=	DK_NDRIVE undefined

.include <bsd.port.mk>
