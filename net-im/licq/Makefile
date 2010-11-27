# New ports collection makefile for:    licq
# Date created:                         2 July 1998
# Whom:                                 Brian Feldman & Matt Heckaman
#
# $FreeBSD$
#

PORTNAME=	base
PORTVERSION=	${LICQ_VER}
CATEGORIES=	net-im
PKGNAMESUFFIX=	${SOCKS_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A popular ICQ-compatible plugin-based program

.if defined(WITH_SOCKS)
BUILD_DEPENDS=	${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
.endif
LIB_DEPENDS=	boost_regex.4:${PORTSDIR}/devel/boost-libs

LICENSE=	GPLv2

USE_ICONV=	yes
USE_CMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
LICQ_PORT?=	net-im/licq

# workaround for installed autoconf/automake
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib -liconv -Wl,--export-dynamic
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-Wl,--export-dynamic

.if defined(WITH_SOCKS)
SOCKS_SUFFIX=	-socks
CONFIGURE_ARGS+=--enable-socks5
CONFIGURE_ARGS+=--with-socks5-inc=${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFLICTS?=	licq-base-1.*
BROKEN=		does not compile
.else
CONFLICTS?=	licq-base-socks-1.*
.endif

.if !defined(WITHOUT_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl-inc=${OPENSSLINC}
CONFIGURE_ARGS+=--with-openssl-lib=${OPENSSLLIB}
.endif

.if defined(WITHOUT_NLS)
CMAKE_ARGS+=	-DENABLE_NLS:BOOL=OFF
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

pre-configure:
	${REINPLACE_CMD} -e 's=!/bin/bash=!${LOCALBASE}/bin/bash=' \
		${WRKSRC}/bin/sidclean.sh

post-install:
	@${MKDIR} ${PREFIX}/lib/licq
	@${CAT} ${PKGMESSAGE}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sidclean.sh ${PREFIX}/bin/sidclean.bash

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/${LICQ_PORT}/Makefile.inc"

.include <bsd.port.post.mk>
