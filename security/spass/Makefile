# $FreeBSD$

PORTNAME=	spass
PORTVERSION=	3.0
PORTREVISION=	13
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure password generator with a true random number generator

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/format.hpp:devel/boost-libs
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	guyru
GH_TAGNAME=	cb0de64

USES=		cmake compiler:c++11-lang

CMAKE_ARGS=	-DWITH_ALSA:BOOL=off -DWITH_OSS:BOOL=on

PLIST_FILES=	bin/spass

.include <bsd.port.mk>
