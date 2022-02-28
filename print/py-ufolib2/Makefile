# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	ufolib2
PORTVERSION=	0.13.0
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ufoLib2-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	UFO font processing library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=20.1.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=4.0.0:print/py-fonttools@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	LXML
LXML_DESC=	XML support

LXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

post-patch:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include <bsd.port.post.mk>
