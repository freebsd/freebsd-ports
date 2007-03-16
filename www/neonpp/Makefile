# New ports collection makefile for:	neonpp
# Date created:				2006-10-06
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	neonpp
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://files.beep-media-player.org/releases/neonpp/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	novel

MAINTAINER=	novel@FreeBSD.org
COMMENT=	C++ wrapper library for neon

LIB_DEPENDS=	sigc-2.0.0:${PORTSDIR}/devel/libsigc++20 \
		neon.26:${PORTSDIR}/www/neon

BROKEN=		does not build with www/neon 0.26.x

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-pkgconfig-dir=${PREFIX}/libdata/pkgconfig
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
