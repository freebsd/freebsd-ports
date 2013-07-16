# $FreeBSD$

PORTNAME=	spass
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Secure password generator with a true random number generator

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/boost/format.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	asound:${PORTSDIR}/audio/alsa-lib \
		boost_program_options:${PORTSDIR}/devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	guyru
GH_TAGNAME=	cb0de64
GH_COMMIT=	cb0de64

USES=		cmake
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/spass

.include <bsd.port.mk>
