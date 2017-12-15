# $FreeBSD$

PORTNAME=	afew
DISTVERSION=	1.2.0
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	seschwar@gmail.com
COMMENT=	Initial tagging script for notmuch mail

LICENSE=	ISCL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}notmuch>=0:mail/py-notmuch@${FLAVOR} \
	notmuch:mail/notmuch

USES=		python
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${FLAVOR}
MANPAGES_PLIST_FILES=	man/man1/afew.1.gz

NO_ARCH=	yes

post-build-MANPAGES-on:
	${MAKE} -C ${WRKSRC}/docs SPHINXBUILD=sphinx-build-${PYTHON_VER} man

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/docs/build/man/afew.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}subprocess32>=0:devel/py-subprocess32
.endif

.include <bsd.port.post.mk>
