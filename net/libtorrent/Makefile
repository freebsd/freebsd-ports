# New ports collection makefile for:	libtorrent
# Date created:				Jan 07 2005
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	libtorrent
PORTVERSION=	0.4.5
CATEGORIES=	net
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/

MAINTAINER=	flz@xbsd.org
COMMENT=	BitTorrent Library written in C++

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl \
		sigc-2.0.0:${PORTSDIR}/devel/libsigc++20

USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.4
.endif

pre-everything::
.if !defined(WITH_CLIENT) && ${OSVERSION} >= 500000
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_CLIENT to build libtorrent client'
	@${ECHO_MSG} '===>'
.endif

post-patch:
	@${REINPLACE_CMD} -e "s#\(pkgconfigdir =\).*#\1 ${PREFIX}/libexec/pkgconfig#" \
			${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s#-Wall -O3 -g#${CFLAGS} -fpermissive#" \
			${WRKSRC}/client/Makefile2
# uphold CXXFLAGS
	@${REINPLACE_CMD} -E \
			-e 's#^(CXXFLAGS[[:space:]]*=[[:space:]]*).*-O.*$$#\1${CXXFLAGS}#' \
			-e 's#^(CFLAGS[[:space:]]*=[[:space:]]*).*-O.*$$#\1${CFLAGS}#' \
			${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.if defined(WITH_CLIENT)
.if ${OSVERSION} < 500000
BROKEN=		"Client doesn't compile on 4.x"
.endif

PLIST_FILES=	bin/rtorrent

post-build:
	@(cd ${WRKSRC}/client; make -f Makefile2)

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/client/rtorrent ${PREFIX}/bin
.endif

.include <bsd.port.post.mk>
