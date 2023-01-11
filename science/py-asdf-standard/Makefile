PORTNAME=	asdf-standard
PORTVERSION=	1.0.3
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	asdf_standard-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ASDF Standard schemas
WWW=		https://github.com/asdf-format/asdf-standard

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.8+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30900
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-resources>=3:devel/py-importlib-resources@${PY_FLAVOR}
.endif

post-patch:
	@${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${FILESDIR}/setup.py > ${WRKSRC}/setup.py

.include <bsd.port.post.mk>
