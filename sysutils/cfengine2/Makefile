# New ports collection makefile for:	cfengine2
# Date created:		2002-07-29
# Whom:			fanf@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cfengine2
PORTVERSION=	2.1.10
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.iu.hio.no/pub/cfengine/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	cfengine-${PORTVERSION}

MAINTAINER=	paul@aps.org
COMMENT=	A systems administration tool for networks

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-berkeleydb=${LOCALBASE} --with-docs
USE_REINPLACE=	yes

INFO=		cfengine-Anomalies cfengine-Reference cfengine-Tutorial
MAN8=		cfengine.8 cfagent.8 cfenvd.8 cfenvgraph.8 cfexecd.8 cfkey.8 \
			cfrun.8 cfservd.8

WITH_BDB_VER?=	42

.if ${WITH_BDB_VER} == 42
BDBLIB=		db-4.2.2
BDBVERSION=	db-4.2
.elif ${WITH_BDB_VER} == 41
BDBLIB=		db41.1
BDBVERSION=	db41
.else
.error WITH_BDB_VER must be 41 or 42
.endif

LIB_DEPENDS+=	${BDBLIB}:${PORTSDIR}/databases/db${WITH_BDB_VER}

post-patch:
	@${REINPLACE_CMD} 's|-ldb|-l${BDBVERSION}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
