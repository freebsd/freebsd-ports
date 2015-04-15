# Created by: Brian Feldman & Matt Heckaman
# $FreeBSD$

PORTNAME=	base
PORTVERSION=	${LICQ_VER}
PORTREVISION=	1
CATEGORIES=	net-im
PKGNAMESUFFIX=	${SOCKS_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Popular ICQ-compatible plugin-based program

LIB_DEPENDS=	libboost_regex.so:${PORTSDIR}/devel/boost-libs

LICENSE=	GPLv2

USES=		cmake iconv
WRKSRC=		${WRKDIR}/${DISTNAME}
LICQ_PORT?=	net-im/licq

CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-DGTEST_USE_OWN_TR1_TUPLE

OPTIONS_DEFINE=	NLS OPENSSL
OPTIONS_DEFAULT=OPENSSL

OPENSSL_USE=	OPENSSL=yes

.include <bsd.port.options.mk>

.include "${PORTSDIR}/${LICQ_PORT}/Makefile.inc"

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DENABLE_NLS:BOOL=OFF
PLIST_SUB+=	NLS="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e 's=!/bin/bash=!${LOCALBASE}/bin/bash=' \
		${WRKSRC}/bin/sidclean.sh

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/licq
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sidclean.sh ${STAGEDIR}${PREFIX}/bin/sidclean.bash

.include <bsd.port.mk>
