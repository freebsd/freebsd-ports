# New ports collection makefile for:   C++ Sockets
# Date created:                Sat Jan 15 16:17:20 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Sockets
PORTVERSION=	2.1.4
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.alhem.net/Sockets/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ wrapper for BSD-style sockets

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
USE_GMAKE=	yes
USE_OPENSSL=	yes
WITH_OPENSSL_BASE=	yes

post-patch:
# PREFIX safeness
# CXX safeness
# CXXFLAGS safeness
	@${REINPLACE_CMD} -E \
		-e 's|-O2||' \
		-e 's|^PREFIX.+$$|PREFIX=${PREFIX}|' \
		-e 's|^INCLUDE.+$$|INCLUDE=-I. -I${OPENSSLINC}|' \
		-e 's|g\+\+|${CXX}|' \
		${BUILD_WRKSRC}/${MAKEFILE}
# fix StdLog.h location
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 5 -x \
		${REINPLACE_CMD} -E \
		-e 's|"StdLog.h"|<StdLog.h>|'

	@${REINPLACE_CMD} -e 's#pthread#(unsigned long)pthread#g' \
		${WRKSRC}/Utility.cpp

.include <bsd.port.mk>
