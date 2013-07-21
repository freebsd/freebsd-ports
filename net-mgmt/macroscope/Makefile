# Created by: Dukashvili Guram <white_raven@users.berlios.de>
# $FreeBSD$

PORTNAME=		macroscope
PORTVERSION=		1.0.3787
PORTREVISION=	6
CATEGORIES=		net-mgmt
MASTER_SITES=		ftp://ftp.berlios.de/pub/macroscope/ \
			http://white-raven.pisem.net/

MAINTAINER=		white_raven@users.berlios.de
COMMENT=		User and IP traffic management with Web interface

LIB_DEPENDS=		lzo2:${PORTSDIR}/archivers/lzo2 \
			odbc:${PORTSDIR}/databases/unixODBC \
			pcap:${PORTSDIR}/net/libpcap \
			gd:${PORTSDIR}/graphics/gd

USE_RC_SUBR=		${PORTNAME}
USE_BZIP2=		yes
USE_DOS2UNIX=		yes
USES=			cmake

OPTIONS_DEFINE=	FIREBIRD DOCS #MYSQL
OPTIONS_DEFAULT=	FIREBIRD

.include <bsd.port.pre.mk>

.if ! ${PORT_OPTIONS:MDOCS}
CMAKE_ARGS+=		-DCMAKE_NOT_INSTALL_DOC:BOOL=ON
.endif

# ${WRKSRC}/include/adicpp/myapi appears to be hardcoded for MySQL 5.0
# Disable option completely until support for later versions added
# Firebird 2.0 support doesn't build on amd64, so version 2.5 is required
#.if ${PORT_OPTIONS:MMYSQL}
#WANT_MYSQL_VER=	50
#USE_MYSQL=		yes
#.endif

.if ${PORT_OPTIONS:MFIREBIRD}
WITH_FIREBIRD_VER=	25
USE_FIREBIRD=		yes
.endif

.if ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=	Does not compile on this architecture
.endif

.include <bsd.port.post.mk>
