PORTNAME=	maltrail
DISTVERSION=	0.86
CATEGORIES=	security python

MAINTAINER=	m.muenz@gmail.com
COMMENT=	Malicious traffic detection system, utilizing public (black)lists
WWW=		https://github.com/stamparm/maltrail

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pcapy-ng>=0:net/py-pcapy-ng@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python:run

USE_GITHUB=	yes
GH_ACCOUNT=	stamparm

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
		${MKDIR} ${STAGEDIR}${DATADIR} && \
		${MV} ${WRKSRC}/maltrail.conf ${WRKSRC}/maltrail.conf.sample
		(cd ${WRKSRC} && ${COPYTREE_SHARE} "*" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
