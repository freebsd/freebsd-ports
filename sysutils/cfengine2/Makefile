# New ports collection makefile for:	cfengine2
# Date created:		2002-07-29
# Whom:			fanf@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cfengine
PORTVERSION=	2.1.20
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.iu.hio.no/pub/cfengine/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	A systems administration tool for networks

USE_BDB=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-berkeleydb=${LOCALBASE} --with-docs
CPPFLAGS+=	-I${BDB_INCLUDE_DIR}
LDFLAGS+=	-L${BDB_LIB_DIR} -l${BDB_LIB_NAME}

.if !defined(NOPORTDOCS)
INFO=		cfengine-Anomalies cfengine-Reference cfengine-Tutorial
.endif

MAN8=		cfagent.8 cfengine.8 cfenvd.8 cfenvgraph.8 cfetoolcheck.8 \
		cfetoolcreate.8 cfetooldump.8 cfetoolgraph.8 cfetoolimport.8 \
		cfetoolinfo.8 cfetoolupdate.8 cfexecd.8 cfkey.8 \
		cfrun.8 cfservd.8 cfshow.8

.include <bsd.port.mk>
