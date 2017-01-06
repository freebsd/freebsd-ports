# $FreeBSD$

PORTNAME=	spass
PORTVERSION=	3.0
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure password generator with a true random number generator

LICENSE=	GPLv3

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	${LOCALBASE}/include/boost/format.hpp:devel/boost-libs
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libboost_program_options.so:devel/boost-libs

BROKEN_sparc64=	cannot link with boost

USE_GITHUB=	yes
GH_ACCOUNT=	guyru
GH_TAGNAME=	cb0de64

USES=		cmake
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/spass

.include <bsd.port.mk>
