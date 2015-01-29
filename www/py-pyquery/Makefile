# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyquery
PORTVERSION=	1.2.9
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Jquery-like library for python

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssselect>=0.6.1:${PORTSDIR}/www/py-cssselect \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.1:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2.2:${PORTSDIR}/www/py-webob
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssselect>=0.6.1:${PORTSDIR}/www/py-cssselect \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.1:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2.2:${PORTSDIR}/www/py-webob

DOCS_BUILD_DEPENDS+=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS

USES=		python zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PYDISTUTILS_BUILD_TARGET+=	build_sphinx -a -E

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/build/sphinx/html && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! -name .buildinfo -or ! -name objects.inv")
.endif

.include <bsd.port.mk>
