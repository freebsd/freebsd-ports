# New ports collection makefile for:	vbidecode
# Version required:	1.1.3
# Date created:		Mon June 8 15:11:00 BST 1999
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $Id: Makefile,v 1.2 1999/06/07 22:23:36 roger Exp $
#

DISTNAME=	videotext-0.6.971023
CATEGORIES=	misc
MASTER_SITES=	http://elektra.e-technik.uni-ulm.de/~mbuck/download/

MAINTAINER=	roger@freebsd.org

LIB_DEPENDS=	gif.3:${PORTSDIR}/graphics/giflib \
		png.3:${PORTSDIR}/graphics/png \
		xview.3:${PORTSDIR}/x11-toolkits/xview

USE_GMAKE=	yes
MAN1=		videotext.1 tunerctl.1

.include <bsd.port.mk>
