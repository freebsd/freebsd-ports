# Created by: Anders Troback
# $FreeBSD$

PORTNAME=	check_ports
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	net-mgmt
PKGNAMEPREFIX=	nagios-

MAINTAINER=	ryanrfrederick@gmail.com
COMMENT=	monitor FreeBSD ports for updates or vulnerabilities

USE_GITHUB=	yes
GH_ACCOUNT=	rfrederick
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	4e039d7

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_ports ${STAGEDIR}${PREFIX}/libexec/nagios/

.include <bsd.port.mk>
