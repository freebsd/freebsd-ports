# Created by: Brian Feldman & Matt Heckaman
# $FreeBSD$

PORTNAME=	base
PORTVERSION=	${LICQ_VER}
PORTREVISION=	1
CATEGORIES=	net-im
PKGNAMESUFFIX=	${SOCKS_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A popular ICQ-compatible plugin-based program

LIB_DEPENDS=	libboost_regex.so:${PORTSDIR}/devel/boost-libs

LICENSE=	GPLv2

USE_GCC=	yes
USES=		cmake iconv
WRKSRC=		${WRKDIR}/${DISTNAME}
LICQ_PORT?=	net-im/licq

# workaround for installed autoconf/automake
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib ${ICONV_LIB} -Wl,--export-dynamic
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-Wl,--export-dynamic

OPTIONS_DEFINE=	OPENSSL
OPTIONS_DEFAULT=OPENSSL

OPENSSL_USE=	OPENSSL=yes
OPENSSL_CONFIGURE_ON=	--with-openssl-inc=${OPENSSLINC} --with-openssl-lib=${OPENSSLLIB}

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
