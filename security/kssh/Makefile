# New ports collection makefile for:	kssh
# Date created:		19 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	kssh
PORTVERSION=	0.2
CATEGORIES=	security
MASTER_SITES=	http://people.FreeBSD.org/~will/distfiles/

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11
BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
USE_QT=		yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" --datadir="${LOCALBASE}"
CONFIGURE_ENV=	KDEDIR="${LOCALBASE}"

.include <bsd.port.mk>
