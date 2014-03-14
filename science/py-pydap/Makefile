# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	pydap
PORTVERSION=	3.1.1
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pydap-${PORTVERSION}

MAINTAINER=	xmj@chaot.net
COMMENT=	Implementation of the Opendap/DODS protocol

LICENSE=	MIT

BUILD_DEPENDS=	paver:${PORTSDIR}/devel/py-paver \
		${PYNUMPY}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httplib2>0:${PORTSDIR}/www/py-httplib2 \
		${PYTHON_PKGNAMEPREFIX}Genshi>0:${PORTSDIR}/textproc/py-genshi \
		${PYTHON_PKGNAMEPREFIX}Paste>0:${PORTSDIR}/www/py-paste \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>0:${PORTSDIR}/www/py-pastedeploy \
		${PYTHON_PKGNAMEPREFIX}PasteScript>0:${PORTSDIR}/www/py-pastescript \
		${PYNUMPY}

OPTIONS_DEFINE=	DOCS

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Pydap
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_NOEGGINFO=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	* .buildinfo

.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	sphinx-build:${PORTSDIR}/textproc/py-sphinx \
	${PYTHON_PKGNAMEPREFIX}coards>0:${PORTSDIR}/science/py-coards \
	${PYTHON_PKGNAMEPREFIX}pygments>0:${PORTSDIR}/textproc/py-pygments

PYDISTUTILS_BUILD_TARGET+=	build_sphinx

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/build/sphinx/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
