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

OPTIONS_DEFINE=	MYSQL FIREBIRD DOCS
MYSQL_DESC=	With MySQL support
FIREBIRD_DESC=	With Firebird support
OPTIONS_DEFAULT=	MYSQL

.include <bsd.port.pre.mk>

.if ! ${PORT_OPTIONS:MDOCS}
CMAKE_ARGS+=		-DCMAKE_NOT_INSTALL_DOC:BOOL=ON
.endif

.if ${PORT_OPTIONS:MMYSQL}
WANT_MYSQL_VER=		50
USE_MYSQL=		yes
.endif

.if ${PORT_OPTIONS:MFIREBIRD}
WITH_FIREBIRD_VER=	2
USE_FIREBIRD=		yes
.endif

.include "${PORTSDIR}/Mk/bsd.database.mk"

.if ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=	Does not compile on this architecture
.endif

.include <bsd.port.post.mk>
