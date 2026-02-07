PORTNAME=	manpageblog
DISTVERSION=	1.4
CATEGORIES=	www
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	se@FreeBSD.org
COMMENT=	Simple and static blog generator in manpage design
WWW=		https://github.com/gyptazy/manpageblog

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown-it-py>=3.0.0:textproc/py-markdown-it-py@${PY_FLAVOR}

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	gyptazy

SHEBANG_FILES=	${WRKSRC}/manpageblog

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		${INSTALL_DATA} ${WRKSRC}/blog.conf ${STAGEDIR}${EXAMPLESDIR}
		cd ${WRKSRC} && ${COPYTREE_SHARE} content ${STAGEDIR}${EXAMPLESDIR}
		cd ${WRKSRC} && ${COPYTREE_SHARE} _assets ${STAGEDIR}${EXAMPLESDIR}
		cd ${WRKSRC} && ${COPYTREE_SHARE} _templates ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
