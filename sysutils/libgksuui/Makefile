# New ports collection makefile for:   libgksuui1.0
# Date created:        2 October 2004
# Whom:                Jesse van den Kieboom <troplosti@orcaweb.cjb.net>
#
# $FreeBSD$
#

PORTNAME=	libgksuui
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://people.debian.org/~kov/gksu/libgksuui1.0/
DISTNAME=	${PORTNAME}1.0-${PORTVERSION}

MAINTAINER=	troplosti@orcaweb.cjb.net
COMMENT=	A graphical fronted to su library

USE_X_PREFIX=	yes
USE_GNOME=	gtk20 pkgconfig
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-gtk-doc=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
