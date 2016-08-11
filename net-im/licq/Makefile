# Created by: Brian Feldman & Matt Heckaman
# $FreeBSD$

PORTNAME=	base
PORTVERSION=	${LICQ_VER}
PORTREVISION=	2
CATEGORIES=	net-im
PKGNAMESUFFIX=	${SOCKS_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Popular ICQ-compatible plugin-based program

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs

USES=		cmake iconv
USE_OPENSSL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
LICQ_PORT?=	net-im/licq

CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-DGTEST_USE_OWN_TR1_TUPLE

OPTIONS_DEFINE=	NLS GPGME
OPTIONS_DEFAULT=GPGME
OPTIONS_SUB=yes
GPGME_DESC=	Build support for gpgme
NLS_USES=	gettext
NLS_CMAKE_OFF=	-DENABLE_NLS:BOOL=OFF

GPGME_LIB_DEPENDS=	libgpgme.so:security/gpgme \
			libassuan.so:security/libassuan \
			libgpg-error.so:security/libgpg-error

.include <bsd.port.options.mk>

.include "${PORTSDIR}/${LICQ_PORT}/Makefile.inc"

pre-configure:
	${REINPLACE_CMD} -e 's=!/bin/bash=!${LOCALBASE}/bin/bash=' \
		${WRKSRC}/bin/sidclean.sh

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/licq
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sidclean.sh ${STAGEDIR}${PREFIX}/bin/sidclean.bash

.include <bsd.port.mk>
