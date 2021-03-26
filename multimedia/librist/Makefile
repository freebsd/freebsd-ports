# $FreeBSD$

PORTNAME=	librist
DISTVERSION=	0.2.0-RC5.20210325
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for Reliable Internet Stream Transport (RIST) protocol

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcjson.so:devel/libcjson

USES=		localbase meson pkgconfig
USE_GITLAB=	yes
USE_LDCONFIG=	yes

GL_SITE=	https://code.videolan.org
GL_ACCOUNT=	rist
GL_COMMIT=	24ae978bcacf6a998aa3f2b605690f7d774f9c83

MESON_ARGS=	-Duse_mbedtls=false # mbedcrypto needs to be ported

.include <bsd.port.mk>
