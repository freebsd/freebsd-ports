# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	graphillion
PORTVERSION=	0.94
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Fast, lightweight graphset operation library in Python

LICENSE=	MIT

USE_GITHUB=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

GH_ACCOUNT=	takemaru
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	2c77c8d

PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_PKGNAME=	Graphillion
PYEASYINSTALL_ARCHDEP=	yes

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
