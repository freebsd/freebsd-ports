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

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.if defined(WITH_SSE)
CONFIGURE_ARGS+=	--enable-sse
.endif

.if defined(WITHOUT_MMX)
CONFIGURE_ARGS+=	--disable-mmx
.endif

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN3=	fame_close.3 fame_encode_frame.3 fame_get_object.3 fame_init.3 \
	fame_open.3 fame_register.3 fame_unregister.3 fame_encode_slice.3 \
	fame_start_frame.3 fame_end_frame.3

pre-everything::
.if !defined(WITH_SSE)
	@${ECHO_MSG} " You can enable SSE optimized routines by defining WITH_SSE."
	@${ECHO_MSG} ""
.endif

.if !defined(WITHOUT_MMX)
	@${ECHO_MSG} " You can disable MMX optimized routines by defining WITHOUT_MMX."
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
