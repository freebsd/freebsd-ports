# Created by: steinex
# $FreeBSD$

PORTNAME=	check_ice
PORTVERSION=	1.5
CATEGORIES=	net-mgmt
MASTER_SITES=	http://nognu.de/s/FreeBSD/distfiles/
PKGNAMEPREFIX=	nagios-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nagios plug-in to check a shoutcast or icecast server

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-11-26

do-build:
	cd ${WRKSRC}; \
	${CC} ${CFLAGS} check_ice.c -o check_ice

do-install:
	@${MKDIR} ${PREFIX}/libexec/nagios
	@${INSTALL_PROGRAM} ${WRKSRC}/check_ice ${PREFIX}/libexec/nagios/check_ice

.include <bsd.port.mk>
