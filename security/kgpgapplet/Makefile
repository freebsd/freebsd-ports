# New ports collection makefile for:   kgpg
# Date created:                         04 Dec 2002
# Whom:                                 Rick Fournier <rick@help-desk.ca>
#
# $FreeBSD$
#

PORTNAME=	kgpgapplet
PORTVERSION=	0.1.3
CATEGORIES=	security kde
MASTER_SITES=	http://devel-home.kde.org/~kgpg/src/

MAINTAINER=	rick@help-desk.ca

RUN_DEPENDS=	kgpg:${PORTSDIR}/security/kgpg

WRKSRC=		${WRKDIR}/kgpgapplet

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_KDEBASE_VER=	3

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
