PORTNAME=	pdagent-integrations
PORTVERSION=	1.6.2
DISTVERSIONPREFIX=v
CATEGORIES=	net-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	PagerDuty integrations for monitoring monitoring tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdagent>0:net-mgmt/py-pdagent@${PY_FLAVOR}

USES=		python:3.7+ shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	PagerDuty

SHEBANG_FILES=	bin/*

SUB_FILES=	pagerduty-icinga2.conf pkg-message

NO_ARCH=	yes
NO_BUILD=	yes
PORTDOCS=	*-testing.txt
EXAMPLES=	conf.d/sensu_pagerduty_handler.json \
		pagerduty_nagios.cfg

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${REINPLACE_CMD} 's|/usr/share/pdagent-integrations/bin|${PREFIX}/bin|g' ${WRKSRC}/pagerduty_nagios.cfg ${WRKSRC}/conf.d/sensu_pagerduty_handler.json

do-install:
	(cd ${WRKSRC}/bin ; ${INSTALL_SCRIPT} * ${STAGEDIR}${PREFIX}/bin)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
