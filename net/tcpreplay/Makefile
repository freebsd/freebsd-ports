# New ports collection makefile for:   tcpreplay
# Date created:        2 November 2000
# Whom:                cnh@ivmg.net
#
# $FreeBSD$
#

PORTNAME=		tcpreplay
PORTVERSION=		1.0.1
CATEGORIES=		net
MASTER_SITES=		http://www.anzen.com/research/nidsbench/

MAINTAINER=		ports@freebsd.org

BUILD_DEPENDS=		${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

USE_AUTOCONF=		yes
GNU_CONFIGURE=		yes
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude */libpcap-* --exclude */Libnet-*

MAN8=			tcpreplay.8

.include <bsd.port.mk>
