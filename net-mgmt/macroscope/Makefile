# New ports collection makefile for:	macroscope
# Date created:		2007-05-14
# Whom:			Dukashvili Guram <white_raven@users.berlios.de>
#
# $FreeBSD$
#

PORTNAME=		macroscope
PORTVERSION=		1.0.3787
PORTREVISION=	2
CATEGORIES=		net-mgmt
MASTER_SITES=		ftp://ftp.berlios.de/pub/macroscope/ \
			http://white-raven.pisem.net/
DISTNAME=		${PORTNAME}-${PORTVERSION}

MAINTAINER=		white_raven@users.berlios.de
COMMENT=		User and IP traffic management with Web interface

LIB_DEPENDS=		lzo2:${PORTSDIR}/archivers/lzo2 \
			odbc:${PORTSDIR}/databases/unixODBC \
			pcap:${PORTSDIR}/net/libpcap \
			gd:${PORTSDIR}/graphics/gd

USE_RC_SUBR=		${PORTNAME}
USE_BZIP2=		yes
USE_DOS2UNIX=		yes
USE_CMAKE=		yes

OPTIONS=		MYSQL		"With MySQL support" on \
			FIREBIRD	"With Firebird support" off

.include <bsd.port.pre.mk>

.if defined(NOPORTDOCS)
CMAKE_ARGS+=		-DCMAKE_NOT_INSTALL_DOC:BOOL=ON
.endif

.if !defined(WITHOUT_MYSQL)
WANT_MYSQL_VER=		50
USE_MYSQL=		yes
.endif

.if !defined(WITHOUT_FIREBIRD)
WITH_FIREBIRD_VER=	2
USE_FIREBIRD=		yes
.endif

.include "${PORTSDIR}/Mk/bsd.database.mk"

.if ${ARCH} == "sparc64"
BROKEN=	Does not compile
.endif

.include <bsd.port.post.mk>
