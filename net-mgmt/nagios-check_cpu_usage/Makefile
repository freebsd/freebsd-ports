# New ports collection makefile for:	nagios-check_cpu_usage
# Date created:				2010-11-23
# Whom:					jamrich.majo@gmail.com
#
# $FreeBSD$
#

PORTNAME=	nagios-check_cpu_usage
PORTVERSION=	1.0
CATEGORIES=	net-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	jamrich.majo@gmail.com
COMMENT=	Nagios plug-in to check CPU usage

NO_BUILD=	yes

PLIST_DIRSTRY=	libexec/nagios
PLIST_FILES=	libexec/nagios/check_cpu_usage

do-install:
	@${MKDIR} ${PREFIX}/libexec/nagios
	@${INSTALL_SCRIPT} ${.CURDIR}/src/check_cpu_usage ${PREFIX}/libexec/nagios

.include <bsd.port.mk>
