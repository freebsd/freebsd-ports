# New ports collection makefile for:	cfengine2
# Date created:		2002-07-29
# Whom:			fanf@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cfengine2
PORTVERSION=	2.1.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.iu.hio.no/pub/cfengine/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	cfengine-${PORTVERSION}

MAINTAINER=	paul@aps.org
COMMENT=	A systems administration tool for networks

LIB_DEPENDS=	db4:${PORTSDIR}/databases/db4

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-berkeleydb=${LOCALBASE}

INFO=		cfengine-Anomalies cfengine-Reference cfengine-Tutorial
MAN8=		cfengine.8 cfagent.8 cfenvd.8 cfenvgraph.8 cfexecd.8 cfkey.8 \
			cfrun.8 cfservd.8

.include <bsd.port.mk>
