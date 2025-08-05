PORTNAME=	cppman
PORTVERSION=	0.5.9
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	C++ 98/11/14/17/20 manual pages on the terminal
WWW=		https://github.com/aitjcize/cppman

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.13.3:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=1.1:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>=5.3.2:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.17.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}soupsieve>=2.6:www/py-soupsieve@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.13.1:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webencodings>=0.5.1:converters/py-webencodings@${PY_FLAVOR} \
		vim:editors/vim \
		bash:shells/bash

USES=		python shebangfix

USE_PYTHON=	autoplist concurrent distutils

SHEBANG_FILES=	bin/cppman \
		cppman/lib/pager.sh

NO_ARCH=	yes

PORTDOCS=	AUTHORS ChangeLog README.rst

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
