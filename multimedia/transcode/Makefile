# New ports collection makefile for:   transcode
# Date created: 	17 December 2001
# Whom: 		Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	transcode
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.theorie.physik.uni-goettingen.de/~ostreich/transcode/pre/
DISTNAME=	${PORTNAME}-${PORTVERSION}pre1
EXTRACT_SUFX=	.tgz

MAINTAINER=	hendrik@scholz.net

.if !defined(WITHOUT_LAME)
BUILD_DEPENDS+= mp3rtp:${PORTSDIR}/audio/lame-devel
CONFIGURE_ARGS+= --with-lame
PLIST_SUB+=	WITH_LAME=""
.else
PLIST_SUB+=	WITH_LAME="@comment "
.endif
.if defined(WITH_LIBDV)
BUILD_DEPENDS+= encodedv:${PORTSDIR}/graphics/libdv
CONFIGURE_ARGS+= --with-dv --with-dv-includes=${LOCALBASE} --with-dv-libs=${LOCALBASE}
PLIST_SUB+=	WITH_LIBDV=""
.else
PLIST_SUB+=	WITH_LIBDV="@comment "
.endif
.if defined(WITH_LIBA52)
BUILD_DEPENDS+= a52dec:${PORTSDIR}/audio/liba52
CONFIGURE_ARGS+= --with-a52
PLIST_SUB+=	WITH_LIBA52=""
.else
PLIST_SUB+=	WITH_LIBA52="@comment "
.endif
.if defined(WITH_NASM)
BUILD_DEPENDS+= nasm:${PORTSDIR}/devel/nasm
.endif
.if !defined(WITHOUT_AVIFILE)
BUILD_DEPENDS+= avifile-config:${PORTSDIR}/graphics/avifile
CONFIGURE_ARGS+= --enable-avifile6
.endif

LIB_DEPENDS+= lthread.2:${PORTSDIR}/devel/linuxthreads:install

USE_GLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS=-L${LOCALBASE}/lib CFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include"

pre-extract:
.if defined(WITHOUT_LAME)
	@${ECHO_MSG}
	@${ECHO_MSG} "You disabled lame support !"
.else
	@${ECHO_MSG}
	@${ECHO_MSG} "lame support is enabled. Disable with WITHOUT_LAME"
	LAME= true
.endif
.if !defined(WITH_LIBDV)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable libdv support by defining WITH_LIBDV"
.else
	@${ECHO_MSG}
	@${ECHO_MSG} "You enabled libdv support by defining WITH_LIBDV"
.endif
.if !defined(WITH_LIBA52)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable liba52 support by defining WITH_LIBDV"
.else
	@${ECHO_MSG}
	@${ECHO_MSG} "You enabled liba52 support by defining WITH_LIBDV"
.endif
.if defined(WITHOUT_AVIFILE)
	@${ECHO_MSG}
	@${ECHO_MSG} "You disabled avifile support !"
.else
	@${ECHO_MSG}
	@${ECHO_MSG} "avifile support is enabled. Disable with WITHOUT_AVIFILE"
.endif(WITH_AVIFILE)

.if !defined(WITH_NASM)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable the nasm dependent moduley by defining WITH_NASM"
.else
	@${ECHO_MSG}
	@${ECHO_MSG} "You enabled nsdm support by defining WITH_NASM"
.endif(WITH_NASM)

.include <bsd.port.mk>
