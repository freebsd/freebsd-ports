# New ports collection makefile for:	apc
# Version required:	1.0
# Date created:		May 1 1997
# Whom:			Eric A. Griff <eagriff@global2000.net>
#
# $Id: Makefile,v 1.8 1998/12/07 20:46:36 billf Exp $
#

DISTNAME=	apc-1.0
CATEGORIES= 	math
MASTER_SITES= 	http://members.global2000.net/~eagriff/

MAINTAINER= 	eagriff@global2000.net

LIB_DEPENDS=	xforms.0:${PORTSDIR}/x11-toolkits/xforms

# depends on xforms
ONLY_FOR_ARCHS=	i386

USE_X_PREFIX=	yes
MAN1=		apc.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>
