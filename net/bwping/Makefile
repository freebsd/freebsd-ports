# Ports collection makefile for:  bwping
# Date created:			  Fri Aug 29 2008
# Whom:				  Oleg Derevenetz (oleg@vsi.ru)
#
# $FreeBSD$
#

PORTNAME=	bwping
PORTVERSION=	1.1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	oleg.derevenetz@gmail.com
COMMENT=	A tool to measure bandwidth and RTT between two hosts using ICMP

PLIST_FILES=	sbin/bwping

GNU_CONFIGURE=	yes
MAN8=		bwping.8

post-install:
	@${STRIP_CMD} ${PREFIX}/sbin/bwping
	@${CHMOD} 4555 ${PREFIX}/sbin/bwping

.include <bsd.port.mk>
