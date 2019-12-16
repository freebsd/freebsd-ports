# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	Genshi
PORTVERSION=	0.7.3
CATEGORIES=	textproc www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Toolkit for generation of output for the web

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	BABEL
BABEL_DESC=	I18n support through the Babel plugin

BABEL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=0.8:devel/py-babel@${PY_FLAVOR}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} < 3.3
post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/genshi/*.so
.else
NO_ARCH=	yes
.endif

.include <bsd.port.post.mk>
