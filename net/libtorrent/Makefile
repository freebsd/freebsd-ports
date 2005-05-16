# New ports collection makefile for:	libtorrent
# Date created:				Jan 07 2005
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	libtorrent
PORTVERSION=	0.6.2
CATEGORIES=	net
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/

MAINTAINER=	flz@FreeBSD.org
COMMENT=	BitTorrent Library written in C++

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20

USE_GCC=	3.4
USE_GNOME=	pkgconfig gnomehack
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_INC_LIBTOOL_VER=	13
CONFIGURE_ARGS=	--disable-debug
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's/-O3/${CFLAGS}/' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/malloc\.h/d' ${WRKSRC}/src/utils/sha_fast.cc

.include <bsd.port.mk>
