# $FreeBSD$

PORTNAME=	mqttwarn
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6-367
DISTVERSIONSUFFIX=	-gc28e1d3
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Subscribe to MQTT topics and notify pluggable services

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paho-mqtt>=0:net/py-paho-mqtt@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}supervisor>=0:sysutils/py-supervisor@${FLAVOR}

USES=		python:2.7 shebangfix
USE_PYTHON=	flavors
SHEBANG_REGEX=	'.*\.py$$'
USE_GITHUB=	yes
GH_ACCOUNT=	jpmens

#NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

USERS=		mqttwarn
GROUPS=		mqttwarn

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|MQTTWARN_LIBDIR|${PYTHON_SITELIBDIR}/${PORTNAME}/lib/|g' ${WRKSRC}/mqttwarn.ini.sample

do-build:
	(cd ${WRKSRC} && ${PYTHON_CMD} -m compileall .)

do-install:
	${MKDIR} ${STAGEDIR}/var/log/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/mqttwarn.py ${STAGEDIR}${PREFIX}/sbin/mqttwarn
	(cd ${WRKSRC}/etc      && ${COPYTREE_SHARE} . ${STAGEDIR}${ETCDIR})
	(cd ${WRKSRC}/services && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/lib/services)
	${CP} ${WRKSRC}/mqttwarn.ini.sample ${STAGEDIR}${ETCDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
