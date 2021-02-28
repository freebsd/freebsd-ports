# $FreeBSD$

PORTNAME=	gstat_exporter
PORTVERSION=	20191119
CATEGORIES=	net-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lapo@lapo.it
COMMENT=	Prometheus exporter for gstat data

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_FreeBSD_11=	needs "gstat -C", available since FreeBSD 12.0

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.7.1:net-mgmt/py-prometheus-client@${PY_FLAVOR}

USES=		python:3.6+

USE_GITHUB=	yes
GH_ACCOUNT=	tykling
GH_PROJECT=	gstat_exporter
GH_TAGNAME=	3c1858a52544b2eec56f5470e4042a7171e5448a

NO_BUILD=	yes
NO_ARCH=	yes

USE_RC_SUBR=	gstat_exporter
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

PLIST_FILES=	bin/${PORTNAME}.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${STAGEDIR}${PREFIX}/bin
	${REINPLACE_CMD} -i '' -e "1i\\${.newline}#!${PYTHON_CMD}" ${STAGEDIR}${PREFIX}/bin/${PORTNAME}.py

.include <bsd.port.mk>
