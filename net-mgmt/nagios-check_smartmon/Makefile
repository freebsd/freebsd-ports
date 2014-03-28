# Created by: steinex
# $FreeBSD$

PORTNAME=	check_smartmon
PORTVERSION=	20100318
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://nognu.de/s/FreeBSD/distfiles/
PKGNAMEPREFIX=	nagios-

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Nagios plug-in to get status from smartmontools

RUN_DEPENDS=	${LOCALBASE}/sbin/smartctl:${PORTSDIR}/sysutils/smartmontools

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_smartmon \
		${STAGEDIR}${PREFIX}/libexec/nagios

.include <bsd.port.mk>
