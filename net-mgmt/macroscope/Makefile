# New ports collection makefile for:	macroscope
# Date created:		2007-05-14
# Whom:			Dukashvili Guram <white_raven@users.berlios.de>
#
# $FreeBSD$
#

PORTNAME=	macroscope
PORTVERSION=	1.0.2108
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.berlios.de/pub/macroscope/ \
		http://white-raven.pisem.net/

MAINTAINER=	white_raven@users.berlios.de
COMMENT=	User and IP traffic management with Web interface

OPTIONS=	MYSQL		"With MySQL support" on \
		FIREBIRD	"With Firebird support" off

USE_BZIP2=	yes
USE_RC_SUBR=	macroscope

BUILD_DEPENDS+=	cmake:${PORTSDIR}/devel/cmake
LIB_DEPENDS+=	lzo2:${PORTSDIR}/archivers/lzo2 \
		odbc:${PORTSDIR}/databases/unixODBC \
		pcap:${PORTSDIR}/net/libpcap

CMAKE_ARGS=	-DCMAKE_BUILD_TYPE:STRING=Release \
		-DCMAKE_C_COMPILER:STRING="${CC}" \
		-DCMAKE_C_FLAGS:STRING="${CFLAGS}" \
		-DCMAKE_CXX_COMPILER:STRING="${CXX}" \
		-DCMAKE_CXX_FLAGS:STRING="${CXXFLAGS}" \
		-DCMAKE_INSTALL_PREFIX=${PREFIX}

.include <bsd.port.pre.mk>

.if defined(NOPORTDOCS)
CMAKE_ARGS+=	-DCMAKE_NOT_INSTALL_DOC:BOOL=ON
.endif

.if defined(WITHOUT_MYSQL)
USE_MYSQL=	yes
.endif

.if defined(WITH_FIREBIRD)
LIB_DEPENDS+=	fbclient:${PORTSDIR}/databases/firebird-client
.endif

do-configure:
	@(cd ${WRKSRC}; \
	${LOCALBASE}/bin/cmake ${CMAKE_ARGS} .)

.include <bsd.port.post.mk>
