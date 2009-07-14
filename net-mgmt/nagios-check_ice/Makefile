# New ports collection makefile for:	nagios-check_ice
# Date created:				2009-07-11
# Whom:					steinex
#
# $FreeBSD$

PORTNAME=	check_ice
PORTVERSION=	1.5
CATEGORIES=	net-mgmt
MASTER_SITES=	http://nognu.de/s/FreeBSD/distfiles/
PKGNAMEPREFIX=	nagios-

MAINTAINER=	steinex@nognu.de
COMMENT=	Nagios plug-in to check a shoutcast or icecast server

do-build:
	cd ${WRKSRC}; \
	${CC} ${CFLAGS} check_ice.c -o check_ice

do-install:
	@${MKDIR} ${PREFIX}/libexec/nagios
	@${INSTALL_PROGRAM} ${WRKSRC}/check_ice ${PREFIX}/libexec/nagios/check_ice

.include <bsd.port.mk>
