# ex:ts=8
# Ports collection makefile for:	libharu
# Date created:			Jun 15, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libharu
PORTVERSION=	2.2.1
CATEGORIES=	print
MASTER_SITES=	http://libharu.org/files/

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Haru Free PDF Library

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-png=${LOCALBASE}
CFLAGS+=	-I${LOCALBASE}/include
USE_LDCONFIG=	yes

SOVERSION=	2
PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		SOVERSION=${SOVERSION}

post-install:
	${LN} -s ${PREFIX}/lib/libhpdf-${PORTVERSION}.so \
		${PREFIX}/lib/libhpdf.so.${SOVERSION}

.include <bsd.port.mk>
