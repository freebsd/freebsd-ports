# New ports collection makefile for:   gksu
# Date created:        2 October 2004
# Whom:                Jesse van den Kieboom <troplosti@orcaweb.cjb.net>
#
# $FreeBSD$
#

PORTNAME=	gksu
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://people.debian.org/~kov/gksu/gksu1.2/

MAINTAINER=	troplosti@orcaweb.cjb.net
COMMENT=	Graphical frontend to su

LIB_DEPENDS=	gksu1.2.0:${PORTSDIR}/sysutils/libgksu \
		gksuui1.0.0:${PORTSDIR}/sysutils/libgksuui

USE_X_PREFIX=	yes
USE_GNOME=	gtk20 pkgconfig gnomeprefix gnomehack
USE_LIBTOOL_VER=15
USE_GETOPT_LONG=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gksu.1 gksuexec.1

.include <bsd.port.mk>
