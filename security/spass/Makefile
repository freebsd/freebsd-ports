# $FreeBSD$

PORTNAME=	spass
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://cloud.github.com/downloads/guyru/spass/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Secure password generator with a true random number generator

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/boost/format.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	asound:${PORTSDIR}/audio/alsa-lib \
		boost_program_options:${PORTSDIR}/devel/boost-libs

USE_CMAKE=	yes
USE_BZIP2=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/spass

MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
