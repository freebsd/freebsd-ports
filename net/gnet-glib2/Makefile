# New ports collection makefile for:   gnet
# Version required:    1.0.1
# Date created:        16 February 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	gnet-1.0.1
CATEGORIES=	net
MASTER_SITES=	http://www.eecs.umich.edu/~dhelder/misc/gnet/src/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	glib12.3:${PORTSDIR}/devel/glib12

GLIB_CONFIG=	${LOCALBASE}/bin/glib12-config

USE_LIBTOOL=	yes
CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}"

.include <bsd.port.mk>
