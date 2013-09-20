# Created by: jamrich.majo@gmail.com
# $FreeBSD$

PORTNAME=	nagios-check_hdd_health
PORTVERSION=	1.1
CATEGORIES=	net-mgmt
MASTER_SITES=	# No distfile
DISTFILES=	# No distfile

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nagios plug-in to check HDD health from S.M.A.R.T

RUN_DEPENDS=	smartmontools>=0:${PORTSDIR}/sysutils/smartmontools

NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/libexec/nagios
	@${INSTALL_SCRIPT} ${.CURDIR}/src/check_hdd_health ${PREFIX}/libexec/nagios

.include <bsd.port.mk>
