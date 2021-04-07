PORTNAME=	spass
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2-5
DISTVERSIONSUFFIX=	-gd38d173
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Secure password generator with a true random number generator

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/format.hpp:devel/boost-libs
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

USES+=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	guyru

CMAKE_ARGS=	-DWITH_ALSA:BOOL=off -DWITH_OSS:BOOL=on

PLIST_FILES?=	bin/spass

# Disable the Qt5 GUI if we build the master port
.if !defined(PKGNAMESUFFIX)
CMAKE_ARGS+=	-DWITH_GUI:BOOL=off
.endif

.include <bsd.port.mk>
