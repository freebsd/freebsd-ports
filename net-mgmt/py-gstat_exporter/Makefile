PORTNAME=	gstat_exporter
DISTVERSION=	0.2.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net-mgmt python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lapo@lapo.it
COMMENT=	Prometheus exporter for gstat data
WWW=		https://github.com/tykling/gstat_exporter

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.7.1:net-mgmt/py-prometheus-client@${PY_FLAVOR}

USES=		python
USE_RC_SUBR=	gstat_exporter

NO_ARCH=	yes
NO_BUILD=	yes

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

PLIST_FILES=	bin/${PORTNAME}.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${STAGEDIR}${PREFIX}/bin
	${REINPLACE_CMD} -i '' -e "1i\\${.newline}#!${PYTHON_CMD}" ${STAGEDIR}${PREFIX}/bin/${PORTNAME}.py

.include <bsd.port.mk>
