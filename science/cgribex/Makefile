# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cgribex
PORTVERSION=	1.6.3
CATEGORIES=	science
MASTER_SITES=	https://code.zmaw.de/attachments/download/7200/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight GRIBEX in C with portable Fortran interface

LICENSE=	GPLv2

LIB_DEPENDS=	libjasper.so:graphics/jasper \
		libsz.so:science/szip

CONFIGURE_ARGS=	--with-jasper=${LOCALBASE} \
		--with-szlib=${LOCALBASE}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		libtool

#post-install:
#	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcgribex.so.0.0.0

.include <bsd.port.mk>
