# ex:ts=8
# Ports collection makefile for:	libfame
# Date created:			Mar 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libfame
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF/fame/${PORTNAME}/${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A video encoding library

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN3=	fame_close.3 fame_encode_frame.3 fame_get_object.3 fame_init.3 \
	fame_open.3 fame_register.3 fame_unregister.3 fame_encode_slice.3 \
	fame_start_frame.3 fame_end_frame.3

OPTIONS=	SSE "SSE optimized routines (no effect in this release)" off \
		MMX "MMX optimized routines" on

.include <bsd.port.pre.mk>

.if defined(WITH_SSE)
CONFIGURE_ARGS+=	--enable-sse
.endif

.if defined(WITHOUT_MMX)
CONFIGURE_ARGS+=	--disable-mmx
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
