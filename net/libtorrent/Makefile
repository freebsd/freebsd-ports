# New ports collection makefile for:	libtorrent
# Date created:				Jan 07 2005
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	libtorrent
PORTVERSION=	0.5.4
CATEGORIES=	net
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/

MAINTAINER=	flz@FreeBSD.org
COMMENT=	BitTorrent Library written in C++

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20

USE_GCC=	3.4
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_INC_LIBTOOL_VER=	13
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e "s#\(pkgconfigdir =\).*#\1 ${PREFIX}/libdata/pkgconfig#" \
			${WRKSRC}/Makefile.in
# uphold CXXFLAGS
	@${REINPLACE_CMD} -E \
			-e 's#^(CXXFLAGS[[:space:]]*=[[:space:]]*).*-O.*$$#\1${CXXFLAGS}#' \
			-e 's#^(CFLAGS[[:space:]]*=[[:space:]]*).*-O.*$$#\1${CFLAGS}#' \
			${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
