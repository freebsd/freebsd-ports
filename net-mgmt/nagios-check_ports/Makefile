# Created by: Anders Troback
# $FreeBSD$

PORTNAME=	check_ports
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://code.adminlife.net/check_ports/files/
PKGNAMEPREFIX=	nagios-

MAINTAINER=	freebsd@troback.com
COMMENT=	Nagios Plugin to monitor your FreeBSD Ports

RUN_DEPENDS=	portaudit:${PORTSDIR}/ports-mgmt/portaudit

NO_BUILD=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_ports ${PREFIX}/libexec/nagios/

.include <bsd.port.post.mk>
