# $FreeBSD$

PORTNAME=	bwping
PORTVERSION=	1.9
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	oleg.derevenetz@gmail.com
COMMENT=	Tool to measure bandwidth and RTT between two hosts using ICMP

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_FILES=	sbin/bwping man/man8/bwping.8.gz

OPTIONS_DEFINE=	IPV6

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ENV+=	ac_cv_ipv6=yes
PLIST_FILES+=	sbin/bwping6 man/man8/bwping6.8.gz
.else
CONFIGURE_ENV+=	ac_cv_ipv6=no
.endif

.include <bsd.port.mk>
