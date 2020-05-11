# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	cloud_sptheme
PORTVERSION=	1.10.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sphinx theme

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${PY_SPHINX} \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-fulltoc>=1.1:textproc/py-sphinxcontrib-fulltoc@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
PYDISTUTILS_BUILDARGS=	build_sphinx -E

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/build/sphinx/ && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
