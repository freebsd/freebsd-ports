# New ports collection makefile for:	KMud
# Date created:		31 Oct 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	kmud
PORTVERSION=	0.4.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kmud.de/pub/kmud/

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11
BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT=		yes

.include <bsd.port.mk>
