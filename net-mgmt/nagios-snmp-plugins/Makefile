# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nagios-snmp-plugins
PORTVERSION=	1.3.1
CATEGORIES=	net-mgmt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Additional SNMP plugins for Nagios

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp

GNU_CONFIGURE=	yes
USES=		autoreconf gmake perl5 localbase
OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	glensc

PORTDOCS=	README NEWS

CONFIGURE_ARGS=	--bindir=${PREFIX}/libexec/nagios \
		--sysconfdir=${PREFIX}/etc/nagios

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/nagios/nagios-snmp-plugins.cfg \
		${STAGEDIR}${PREFIX}/etc/nagios/nagios-snmp-plugins.cfg.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
