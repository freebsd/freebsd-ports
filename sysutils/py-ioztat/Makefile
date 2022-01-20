PORTNAME=	ioztat
DISTVERSION=	1.1.0
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tom@hur.st
COMMENT=	Storage load analysis tool for OpenZFS

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sysctl>0:devel/py-sysctl@${PY_FLAVOR}

USES=		python:3.6+,run shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	jimsalterjrs
GH_TAGNAME=	v${DISTVERSION}

USE_PYTHON=	concurrent flavors

SHEBANG_FILES=	${PORTNAME}
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
