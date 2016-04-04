# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	check_netsnmp
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	# none
PKGNAMEPREFIX=	nagios-
DISTFILES=	# none

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Nagios plug-in to get some common NetSNMP-exported information

RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/utils.pm:net-mgmt/nagios-plugins \
		p5-Net-SNMP>=0:net-mgmt/p5-Net-SNMP

USES=		perl5 shebangfix
USE_PERL5=	run
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_FILES=	libexec/nagios/check_netsnmp %%DOCSDIR%%/check_netsnmp.html
SUB_FILES=	check_netsnmp
SUB_LIST=	PERL="${perl_CMD}"

do-extract:
	@${MKDIR} ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKDIR}/check_netsnmp ${STAGEDIR}${PREFIX}/libexec/nagios
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/check_netsnmp.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
