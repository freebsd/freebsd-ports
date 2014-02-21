# Created by: jamrich.majo@gmail.com
# $FreeBSD$

PORTNAME=	nagios-check_cpu_usage
PORTVERSION=	1.0
CATEGORIES=	net-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nagios plug-in to check CPU usage

NO_BUILD=	yes

PLIST_DIRSTRY=	libexec/nagios
PLIST_FILES=	libexec/nagios/check_cpu_usage

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${.CURDIR}/src/check_cpu_usage \
		${STAGEDIR}${PREFIX}/libexec/nagios

.include <bsd.port.mk>
