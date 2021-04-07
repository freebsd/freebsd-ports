PORTNAME=	afew
DISTVERSION=	3.0.1
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Initial tagging script for Notmuch mail

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dkimpy>0:mail/py-dkimpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}notmuch>0:mail/py-notmuch@${PY_FLAVOR} \
		notmuch:mail/notmuch

USES=		python:3.6+
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

OPTIONS_DEFINE=	MANPAGES DOCS
OPTIONS_DEFAULT=	MANPAGES

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
MANPAGES_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
MANPAGES_PLIST_FILES=	man/man1/afew.1.gz

PORTDOCS=	*

post-build-MANPAGES-on:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py build_sphinx -b man

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/build/sphinx/man/afew.1 ${STAGEDIR}${PREFIX}/man/man1

post-build-DOCS-on:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py build_sphinx -b html

post-install-DOCS-on:
	cd ${WRKSRC}/build/sphinx/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	@${RM} ${STAGEDIR}${DOCSDIR}/.buildinfo

.include <bsd.port.mk>
