# ex:ts=8
# Ports collection makefile for:	libfame
# Date created:			Mar 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libfame
PORTVERSION=	0.9.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fame

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A video encoding library

USE_INC_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN3=	fame_close.3 fame_encode_frame.3 fame_get_object.3 fame_init.3 \
	fame_open.3 fame_register.3 fame_unregister.3 fame_encode_slice.3 \
	fame_start_frame.3 fame_end_frame.3

OPTIONS=	SSE "SSE optimized routines" off \
		MMX "MMX optimized routines" on

.include <bsd.port.pre.mk>

.if defined(WITH_SSE)
CONFIGURE_ARGS+=	--enable-sse
.endif

.if defined(WITHOUT_MMX)
CONFIGURE_ARGS+=	--disable-mmx
.endif

.include <bsd.port.post.mk>
