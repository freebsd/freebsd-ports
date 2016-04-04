# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	pydap
PORTVERSION=	3.1.1
PORTREVISION=	2
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pydap-${PORTVERSION}

MAINTAINER=	xmj@chaot.net
COMMENT=	Implementation of the Opendap/DODS protocol

LICENSE=	MIT

BROKEN=		does not build
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-04-15

BUILD_DEPENDS=	paver:devel/py-paver \
		${PYNUMPY}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httplib2>0:www/py-httplib2 \
		${PYTHON_PKGNAMEPREFIX}Genshi>0:textproc/py-genshi \
		${PYTHON_PKGNAMEPREFIX}Paste>0:www/py-paste \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>0:www/py-pastedeploy \
		${PYTHON_PKGNAMEPREFIX}PasteScript>0:www/py-pastescript \
		${PYNUMPY}

OPTIONS_DEFINE=	DOCS

USES=		python
USE_PYTHON=	distutils autoplist

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	* .buildinfo

.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	sphinx-build:textproc/py-sphinx \
	${PYTHON_PKGNAMEPREFIX}coards>0:science/py-coards \
	${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments

PYDISTUTILS_BUILD_TARGET+=	build_sphinx

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/build/sphinx/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
