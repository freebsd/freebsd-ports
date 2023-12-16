PORTNAME=	pass-audit
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://github.com/roddhjav/${PORTNAME}/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Extension to audit your password-store password repository
WWW=		https://github.com/roddhjav/pass-audit

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zxcvbn>0:security/py-zxcvbn@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zxcvbn>0:security/py-zxcvbn@${PY_FLAVOR} \
		password-store>=1.7.3_1:sysutils/password-store

USES=		python shebangfix
USE_PYTHON=	distutils

NO_ARCH=	yes
NO_BUILD=	yes

SHEBANG_FILES=	${WRKSRC}/pass_audit/__main__.py

post-patch:
	@${REINPLACE_CMD} -e 's:%%PREFIX%%:${PREFIX}:g' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's:\<python3\>:${PYTHON_CMD}:g' ${WRKSRC}/audit.bash

.include <bsd.port.mk>
