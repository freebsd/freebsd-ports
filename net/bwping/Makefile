# $FreeBSD$

PORTNAME=	bwping
PORTVERSION=	1.6
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	oleg.derevenetz@gmail.com
COMMENT=	Tool to measure bandwidth and RTT between two hosts using ICMP

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
MAN8=		bwping.8 bwping6.8

PLIST_FILES=	sbin/bwping sbin/bwping6

post-install:
	@${CHMOD} 4555 ${PREFIX}/sbin/bwping ${PREFIX}/sbin/bwping6

.include <bsd.port.mk>
