# Created by: ijliao
# $FreeBSD$

PORTNAME=	libfame
PORTVERSION=	0.9.1
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	SF/fame/${PORTNAME}/${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Video encoding library

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	SSE MMX
OPTIONS_DEFAULT=	MMX

SSE_DESC=	SSE optimized routines (no effect in this release)

SSE_CONFIGURE_ON=	--enable-sse
MMX_CONFIGURE_ON=	--enable-mmx

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} \
		-e 's|AC_DEFUN(AM_PATH_LIBFAME|AC_DEFUN([AM_PATH_LIBFAME]|g' \
		${WRKSRC}/libfame.m4 ${WRKSRC}/libfame.m4.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfame-0.9.so.1

.include <bsd.port.mk>
