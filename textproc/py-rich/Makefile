PORTNAME=	rich
PORTVERSION=	14.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Rich text and beautiful formatting in the terminal
WWW=		https://github.com/Textualize/rich

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown-it-py>=2.2.0:textproc/py-markdown-it-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.13.0:textproc/py-pygments@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist pep517 pytest
USE_GITHUB=	yes

GH_ACCOUNT=	Textualize

# poetry-core will process .gitignore when git is present, and fail to
# create a wheel because the 'work' directory is listed there.

BINARY_ALIAS=	git=false

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0.0<5.0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
