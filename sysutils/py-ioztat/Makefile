PORTNAME=	ioztat
DISTVERSION=	2.0.1
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tom@hur.st
COMMENT=	Storage load analysis tool for OpenZFS

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sysctl>0:devel/py-sysctl@${PY_FLAVOR}

USES=		python:3.7+,run shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	jimsalterjrs
GH_TAGNAME=	v${DISTVERSION}

USE_PYTHON=	concurrent flavors

SHEBANG_FILES=	${PORTNAME}
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		man/man8/${PORTNAME}.8.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
