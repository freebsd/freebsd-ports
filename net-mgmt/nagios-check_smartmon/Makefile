# New ports collection makefile for:	nagios-check_smartmon
# Date created:				2009-07-10
# Whom:					steinex
#
# $FreeBSD$

PORTNAME=	check_smartmon
PORTVERSION=	20060324
CATEGORIES=	net-mgmt
MASTER_SITES=	http://nognu.de/s/FreeBSD/distfiles/
PKGNAMEPREFIX=	nagios-

MAINTAINER=	steinex@nognu.de
COMMENT=	Nagios plug-in to get status from smartmontools

RUN_DEPENDS=	${LOCALBASE}/sbin/smartctl:${PORTSDIR}/sysutils/smartmontools

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_smartmon ${PREFIX}/libexec/nagios

.include <bsd.port.mk>
