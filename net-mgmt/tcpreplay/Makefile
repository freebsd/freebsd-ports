# New ports collection makefile for:   tcpreplay
# Date created:        2 November 2000
# Whom:                cnh@ivmg.net
#
# $FreeBSD$
#

PORTNAME=	tcpreplay
PORTVERSION=	1.3.b5
DISTNAME=	tcpreplay-1.3-beta5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	smace@FreeBSD.org

LIB_DEPENDS=    redblack:${PORTSDIR}/devel/libredblack
BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-libnet=${PREFIX} --with-libredblack=${PREFIX}

USE_AUTOCONF=	yes

MAN1=		capinfo.1 tcpprep.1
MAN8=		tcpreplay.8

.include <bsd.port.mk>
