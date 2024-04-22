PORTNAME=	pypowerwall
PORTVERSION=	0.7.12
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Python interface for Tesla Powerwall and solar power data
WWW=		https://github.com/jasonacox/pypowerwall

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}googleapis-common-protos>0:devel/py-googleapis-common-protos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.21.0:www/py-requests@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}googleapis-common-protos>0:devel/py-googleapis-common-protos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.21.0:www/py-requests@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist distutils
SHEBANG_FILES=	proxy/server.py proxy/transform.py

USE_RC_SUBR=	${PORTNAME}_proxy

USE_GITHUB=	yes
GH_ACCOUNT=	jasonacox

# disable cloud support for the moment (additional deps needed--teslapy)
post-patch:
	@${REINPLACE_CMD} -E -e '/teslapy/d' ${WRKSRC}/setup.py
	@${RM} ${WRKSRC}/pypowerwall/cloud.py
	@${TOUCH} ${WRKSRC}/pypowerwall/cloud.py

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${RM} ${WRKSRC}/proxy/Dockerfile
	(cd ${WRKSRC}/proxy && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
