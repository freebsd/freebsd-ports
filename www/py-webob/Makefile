# $FreeBSD$

PORTNAME=	webob
PORTVERSION=	1.2.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYDISTUTILS_PKGNAME}-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	WSGI request and response Python object

LICENSE=	MIT

PYDISTUTILS_PKGNAME=	WebOb
PYDISTUTILS_PKGVERSION=	${DISTVERSION}
# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

USES=		zip

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	DOCS TESTS

TESTS_DESC=	Run tests with Nose

NO_STAGE=	yes
.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
PYDISTUTILS_BUILD_TARGET+=	build_sphinx -a -E

post-install:
	@cd ${WRKSRC}/build/sphinx/html && \
	${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MTESTS}
BUILD_DEPENDS+=	nosetests:${PORTSDIR}/devel/py-nose
PYDISTUTILS_BUILD_TARGET+=	nosetests
.endif

.include <bsd.port.post.mk>
