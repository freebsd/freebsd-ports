# New ports collection makefile for:   tcpreplay
# Date created:        2 November 2000
# Whom:                cnh@ivmg.net
#
# $FreeBSD$
#

PORTNAME=	tcpreplay
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://synfin.net/aturner/tcpreplay/

PATCH_SITES=	http://synfin.net/aturner/tcpreplay/
PATCHFILES=	tcpreplay-adt9.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	redblack:${PORTSDIR}/devel/libredblack
BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-libnet=${PREFIX} --with-libredblack=${PREFIX}

USE_AUTOCONF=	yes

MAN8=		tcpreplay.8 tcpprep.8

.include <bsd.port.mk>
