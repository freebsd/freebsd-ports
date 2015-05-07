# Created by: Anders Troback
# $FreeBSD$

PORTNAME=	check_ports
PORTVERSION=	0.7.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net-mgmt
PKGNAMEPREFIX=	nagios-

MAINTAINER=	ryanrfrederick@gmail.com
COMMENT=	monitor FreeBSD ports for updates or vulnerabilities

USE_GITHUB=	yes
GH_ACCOUNT=	rfrederick

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_ports ${STAGEDIR}${PREFIX}/libexec/nagios/

.include <bsd.port.mk>
