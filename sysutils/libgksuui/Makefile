# New ports collection makefile for:   libgksuui1.0
# Date created:        2 October 2004
# Whom:                Jesse van den Kieboom <troplosti@orcaweb.cjb.net>
#
# $FreeBSD$
#

PORTNAME=	libgksuui
PORTVERSION=	1.0.7
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://people.debian.org/~kov/gksu/old_stuff/libgksuui1.0/
DISTNAME=	${PORTNAME}1.0-${PORTVERSION}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	A graphical fronted to su library

USE_GNOME=	gtk20 pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-gtk-doc=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
