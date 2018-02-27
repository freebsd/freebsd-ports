# $FreeBSD$

CATEGORIES=	mail python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python interface for the Notmuch email search and tagging library

LIB_DEPENDS=	libnotmuch.so:mail/notmuch

USES=		python
USE_PYTHON=	autoplist distutils

MASTERDIR=	${.CURDIR}/../notmuch
NO_ARCH=	yes
PORTDOCS=	python/
WRKSRC_SUBDIR=	bindings/python

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

do-build-DOCS-on:
	@${MAKE_CMD} -C ${WRKSRC}/docs html

do-install-DOCS-on:
	cd ${WRKSRC}/docs/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/python
	@${RM} ${STAGEDIR}${DOCSDIR}/python/.buildinfo

.include "${MASTERDIR}/Makefile"
