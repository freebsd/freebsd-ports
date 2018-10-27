# Created by: ijliao
# $FreeBSD$

PORTNAME=	libfame
PORTVERSION=	0.9.1
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	SF/fame/${PORTNAME}/${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Video encoding library

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	MMX
OPTIONS_DEFAULT=MMX

MMX_CONFIGURE_ENABLE=	mmx

.include <bsd.port.options.mk>
.if ${ARCH} == "i386"
MAKE_ARGS=	CFLAGS="${CLFAGS}" CC="${CC}"
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|AC_DEFUN(AM_PATH_LIBFAME|AC_DEFUN([AM_PATH_LIBFAME]|g' \
		${WRKSRC}/libfame.m4 ${WRKSRC}/libfame.m4.in

.include <bsd.port.mk>
