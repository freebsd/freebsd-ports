# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	check_netsnmp
PORTVERSION=	1.0
CATEGORIES=	net-mgmt
MASTER_SITES=	# none
PKGNAMEPREFIX=	nagios-
DISTFILES=	# none

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Nagios plug-in to get some common NetSNMP-exported information

RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/utils.pm:${PORTSDIR}/net-mgmt/nagios-plugins \
		p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP

USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes
PLIST_FILES=	libexec/nagios/check_netsnmp %%DOCSDIR%%/check_netsnmp.html
PLIST_DIRS=	%%DOCSDIR%%

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${FILESDIR}/check_netsnmp ${STAGEDIR}${PREFIX}/libexec/nagios
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/check_netsnmp.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
