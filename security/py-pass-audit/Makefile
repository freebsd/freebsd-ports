PORTNAME=	pass-audit
PORTVERSION=	1.1
CATEGORIES=	security
MASTER_SITES=	https://github.com/roddhjav/${PORTNAME}/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Extension to audit your password-store password repository

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zxcvbn>0:security/py-zxcvbn@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zxcvbn>0:security/py-zxcvbn@${PY_FLAVOR} \
		password-store>=1.7.3_1:sysutils/password-store

USES=		python:3.4+ shebangfix
USE_PYTHON=	distutils

NO_ARCH=	yes
NO_BUILD=	yes

SHEBANG_FILES=	${WRKSRC}/pass_audit/__main__.py

post-patch:
	@${REINPLACE_CMD} -e 's:\<python3\>:${PYTHON_CMD}:g' ${WRKSRC}/audit.bash

pre-install:
	${INSTALL_MAN} ${WRKSRC}/pass-audit.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/pass-audit.1
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/libexec/password-store/extensions
	${INSTALL_SCRIPT} ${WRKSRC}/audit.bash \
		${STAGEDIR}${LOCALBASE}/libexec/password-store/extensions/audit.bash
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completion/pass-audit.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/pass-audit
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/completion/pass-audit.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_pass-audit

.include <bsd.port.mk>
