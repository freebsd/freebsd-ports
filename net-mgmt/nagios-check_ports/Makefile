# Created by: Anders Troback
# $FreeBSD$

PORTNAME=	check_ports
PORTVERSION=	0.7
CATEGORIES=	net-mgmt
PKGNAMEPREFIX=	nagios-

MAINTAINER=	ryanrfrederick@gmail.com
COMMENT=	monitor FreeBSD ports for updates or vulnerabilities

USE_GITHUB=	yes
GH_ACCOUNT=	rfrederick
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	7cee15a

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
RUN_DEPENDS=	portaudit:${PORTSDIR}/ports-mgmt/portaudit
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_ports ${STAGEDIR}${PREFIX}/libexec/nagios/

.include <bsd.port.post.mk>
