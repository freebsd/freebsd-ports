# $FreeBSD$

PORTNAME=	bwping
PORTVERSION=	1.11
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

IPV6_CONFIGURE_ENV=	ac_cv_ipv6=yes
IPV6_CONFIGURE_ENV_OFF=	ac_cv_ipv6=no
IPV6_PLIST_FILES=	sbin/bwping6 man/man8/bwping6.8.gz

.include <bsd.port.mk>
