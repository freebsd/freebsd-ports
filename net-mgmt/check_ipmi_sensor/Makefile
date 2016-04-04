# $FreeBSD$

PORTNAME=	check_ipmi_sensor
PORTVERSION=	3.10
DISTVERSIONPREFIX=v
CATEGORIES=	net-mgmt

MAINTAINER=	sergey_zaikov@rambler.ru
COMMENT=	Nagios/Icinga plugin to check IPMI sensors

LICENSE=	GPLv3

RUN_DEPENDS=	p5-IPC-Run>=0:devel/p5-IPC-Run \
		ipmi-raw:sysutils/freeipmi

NO_BUILD=	yes

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	thomas-krenn
GH_PROJECT=	check_ipmi_sensor_v3
SHEBANG_FILES=	check_ipmi_sensor
PLIST_FILES=	libexec/nagios/check_ipmi_sensor

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_ipmi_sensor ${STAGEDIR}${PREFIX}/libexec/nagios/

.include <bsd.port.mk>
