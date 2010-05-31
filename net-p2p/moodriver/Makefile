# New ports collection makefile for:	moodriver
# Date created:				2006-07-24
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	moodriver
PORTVERSION=	0.20.1
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	http://files.backtrace.info/releases/moodriver/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	C++ museekd client library

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-pkgconfig-dir=${PREFIX}/libdata/pkgconfig
USE_GETTEXT=	yes
USE_GNOME=	glib20 pkgconfig
USE_LDCONFIG=	yes

.include <bsd.port.mk>
