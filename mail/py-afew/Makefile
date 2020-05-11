# $FreeBSD$

PORTNAME=	afew
DISTVERSION=	1.3.0
PORTREVISION=	3
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/afewmail/${PORTNAME}/commit/
PATCHFILES=	1d290ab4d631fdcec60b79fd3a4f873e774adac2.patch:-p1 # fix of the documentation build

MAINTAINER=	seschwar@gmail.com
COMMENT=	Initial tagging script for Notmuch mail

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dkimpy>0:mail/py-dkimpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}notmuch>0:mail/py-notmuch@${PY_FLAVOR} \
		notmuch:mail/notmuch

USES=		python
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

OPTIONS_DEFINE=	MANPAGES DOCS
OPTIONS_DEFAULT=	MANPAGES

DOCS_BUILD_DEPENDS=	${PY_SPHINX}
MANPAGES_BUILD_DEPENDS=	${PY_SPHINX}
MANPAGES_PLIST_FILES=	man/man1/afew.1.gz

PORTDOCS=	*

post-build-MANPAGES-on:
	@${MAKE_CMD} -C ${WRKSRC}/docs SPHINXBUILD=sphinx-build-${PYTHON_VER} man

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/docs/build/man/afew.1 ${STAGEDIR}${PREFIX}/man/man1

post-build-DOCS-on:
	@${MAKE_CMD} -C ${WRKSRC}/docs SPHINXBUILD=sphinx-build-${PYTHON_VER} html

post-install-DOCS-on:
	cd ${WRKSRC}/docs/build/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	@${RM} ${STAGEDIR}${DOCSDIR}/.buildinfo

.include <bsd.port.mk>
