PORTNAME=	css-parser
PORTVERSION=	1.1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	CSS related utilities (parsing, serialization, etc) for python
WWW=		https://github.com/ebook-utils/css-parser

LICENSE=	GPL-3.0-only LGPL-3.0-only
LICENSE_COMB=	multi
LICENSE_FILE_GPL-3.0-only=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL-3.0-only=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	ebook-utils
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} '/^license =/d' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
