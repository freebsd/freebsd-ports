# Created by: Brian Feldman & Matt Heckaman

PORTNAME=	base
PORTVERSION=	1.9.0
PORTREVISION=	4
CATEGORIES=	net-im
PKGNAMEPREFIX=	licq-
PKGNAMESUFFIX=	${SOCKS_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Popular ICQ-compatible plugin-based program

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs

BROKEN_FreeBSD_11_powerpc64=	fails to pass tests
BROKEN_FreeBSD_12_powerpc64=	fails to pass tests
BROKEN_sparc64=		fails to link

USES=		cmake:noninja iconv ssl
USE_CXXSTD=	c++98
USE_GITHUB=	yes
GH_ACCOUNT=	licq-im
GH_PROJECT=	licq
GH_TAGNAME=	f271d55
WRKSRC_SUBDIR=	licq
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

LICQ_PORT?=	net-im/licq

.include <bsd.port.options.mk>

pre-configure:
	${REINPLACE_CMD} -e 's=!/bin/bash=!${LOCALBASE}/bin/bash=' \
		${WRKSRC}/bin/sidclean.sh

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/licq
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sidclean.sh ${STAGEDIR}${PREFIX}/bin/sidclean.bash

.include <bsd.port.mk>
