# $FreeBSD$

PORTNAME=	webob
PORTVERSION=	1.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	WebOb-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	WSGI request and response Python object

LICENSE=	MIT

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE= DOCS TESTS

PORTDOCS=	*

USES=		python
USE_PYTHON=	distutils autoplist

TESTS_BUILD_DEPENDS=	nosetests:devel/py-nose
TESTS_DESC=	Run tests with Nose

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PYDISTUTILS_BUILD_TARGET+=	build_sphinx -a -E

post-install:
	@(cd ${WRKSRC}/build/sphinx/html && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -and ! -name objectiv.inv")
.endif

.if ${PORT_OPTIONS:MTESTS}
PYDISTUTILS_BUILD_TARGET+=	nosetests
.endif

.include <bsd.port.mk>
