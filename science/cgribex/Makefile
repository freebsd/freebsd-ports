# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cgribex
PORTVERSION=	1.7.5
CATEGORIES=	science
MASTER_SITES=	https://code.zmaw.de/attachments/download/12689/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight GRIBEX in C with portable Fortran interface

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjasper.so:graphics/jasper \
		libsz.so:science/szip

CONFIGURE_ARGS=	--with-jasper=${LOCALBASE} \
		--with-szlib=${LOCALBASE}
CPPFLAGS+=	-DgFortran
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		libtool

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcgribex.so.0.0.0

.include <bsd.port.mk>
