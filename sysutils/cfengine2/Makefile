# New ports collection makefile for:	cfengine2
# Date created:		2002-07-29
# Whom:			fanf@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cfengine
PORTVERSION=	2.1.16
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.iu.hio.no/pub/cfengine/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	A systems administration tool for networks

USE_OPENSSL=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-berkeleydb=${LOCALBASE} --with-docs

.if !defined(NOPORTDOCS)
INFO=		cfengine-Anomalies cfengine-Reference cfengine-Tutorial
.endif

MAN8=		cfagent.8 cfengine.8 cfenvd.8 cfenvgraph.8 cfetoolcheck.8 \
		cfetoolcreate.8 cfetooldump.8 cfetoolgraph.8 cfetoolimport.8 \
		cfetoolinfo.8 cfetoolupdate.8 cfexecd.8 cfkey.8 \
		cfrun.8 cfservd.8 cfshow.8

WITH_BDB_VER?=	42

.if ${WITH_BDB_VER} == 42
LIB_DEPENDS+=	db-4.2.2:${PORTSDIR}/databases/db42
CPPFLAGS+=	-I${LOCALBASE}/include/db42
LDFLAGS+=	-L${LOCALBASE}/lib/db42 -ldb-4.2
.elif ${WITH_BDB_VER} == 41
LIB_DEPENDS+=	db41.1:${PORTSDIR}/databases/db41
CPPFLAGS+=	-I${LOCALBASE}/include/db41
LDFLAGS+=	-L${LOCALBASE}/lib/db41 -ldb41
.else
IGNORE=		WITH_BDB_VER must be 41 or 42
.endif

.include <bsd.port.mk>
