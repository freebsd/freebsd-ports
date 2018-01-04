# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pdagent-integrations
PORTVERSION=	1.4
DISTVERSIONPREFIX=v
CATEGORIES=	net-mgmt python

MAINTAINER=	feld@FreeBSD.org
COMMENT=	PagerDuty integrations for monitoring monitoring tools

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdagent>0:net-mgmt/py-pdagent

USES=	python:2.7 shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	PagerDuty

SHEBANG_FILES=	bin/*

SUB_FILES=	pagerduty-icinga2.conf pkg-message

NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} 's|/usr/share/pdagent-integrations/bin|${PREFIX}/bin|g' ${WRKSRC}/pagerduty_nagios.cfg ${WRKSRC}/conf.d/sensu_pagerduty_handler.json

do-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/pd-nagios ${STAGEDIR}${LOCALBASE}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/pd-sensu ${STAGEDIR}${LOCALBASE}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/pd-zabbix ${STAGEDIR}${LOCALBASE}/bin
	${INSTALL_DATA} ${WRKSRC}/conf.d/sensu_pagerduty_handler.json ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/pagerduty_nagios.cfg ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/pagerduty-icinga2.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
