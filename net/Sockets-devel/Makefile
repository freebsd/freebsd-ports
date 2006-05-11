# New ports collection makefile for:	C++ Sockets devel
# Date created:		Sun Sep 25 20:27:06 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Sockets
PORTVERSION=	1.9.9
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.alhem.net/Sockets/
PKGNAMESUFFIX?=	-devel

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A C++ wrapper for BSD-style sockets

USE_GMAKE=	yes
USE_OPENSSL=	yes
WITH_OPENSSL_BASE=	yes
MAKE_ENV=	CXX="${CXX}"

post-patch:
# PREFIX safeness
# CXX safeness
# CXXFLAGS safeness
# rename files to -devel
	@${REINPLACE_CMD} -E \
		-e 's|-O2||' \
		-e 's|^PREFIX.+$$|PREFIX=${PREFIX}|' \
		-e 's|^INCLUDE.+$$|INCLUDE=-I. -I${OPENSSLINC}|' \
		-e 's|g\+\+|${CXX}|' \
		-e 's|libSockets.a|libSockets-devel.a|' \
		-e 's|libSocketsEx.a|libSocketsEx-devel.a|' \
		-e 's|Sockets-config|Sockets-devel-config|' \
		-e 's|include/Sockets|include/Sockets-devel|' \
		${BUILD_WRKSRC}/${MAKEFILE}
# fix StdLog.h location
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 5 -x \
		${REINPLACE_CMD} -E \
			-e 's|"StdLog.h"|<StdLog.h>|'

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE= FreeBSD prior to 500000 does not support uuid(3) required\
	for building
.endif

.include <bsd.port.post.mk>
