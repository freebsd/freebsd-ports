# New ports collection makefile for:   tcpreplay
# Date created:        2 November 2000
# Whom:                cnh@ivmg.net
#
# $FreeBSD$
#

PORTNAME=	tcpreplay
PORTVERSION=	1.4.6
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	smace@FreeBSD.org
COMMENT=	A tool to replay saved packet capture files

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet-devel

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-libnet=${LOCALBASE}

MAN1=		capinfo.1 tcpprep.1 pcapmerge.1
MAN8=		tcpreplay.8

.include <bsd.port.mk>
