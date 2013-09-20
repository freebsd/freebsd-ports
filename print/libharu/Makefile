# Created by: ijliao
# $FreeBSD$

PORTNAME=	libharu
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://libharu.org/files/

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Haru Free PDF Library

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-png=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15
USE_LDCONFIG=	yes

SOVERSION=	2
PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		SOVERSION=${SOVERSION}

NO_STAGE=	yes
post-install:
	${LN} -s ${PREFIX}/lib/libhpdf-${PORTVERSION}.so \
		${PREFIX}/lib/libhpdf.so.${SOVERSION}

.include <bsd.port.mk>
