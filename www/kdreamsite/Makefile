# New ports collection makefile for:	KDreamSite
# Version required:	0.2
# Date created:		12 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	kdreamsite-0.2
CATEGORIES=	www kde
MASTER_SITES=	http://neptune.spaceports.com/%7Eatnet/files/

MAINTAINER=	andrews@technologist.com

LIB_DEPENDS=	kdeui.3:${PORTSDIR}/x11/kdelibs11/

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400004
BROKEN=		"obsolete compiler"
.endif

.include <bsd.port.post.mk>
