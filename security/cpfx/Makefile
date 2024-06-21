PORTNAME=	cpfx
DISTVERSION=	g20240515
CATEGORIES=	security
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	PFX decoder for CryptoPro GOST R 34.10-2012 implementation
WWW=		https://github.com/li0ard/cpfx

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygost>=5.11:security/pygost@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyderasn>=9.3:devel/pyderasn@${PY_FLAVOR}

PLIST_FILES=	bin/cpfx.py bin/schemas.py
USES=		python

USE_PYTHON=	flavors
USE_GITHUB=	yes

GH_ACCOUNT=	li0ard
GH_TAGNAME=	c177c69

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
		@cd ${WRKSRC} && \
		${REINPLACE_CMD} $$'1s,^,#!${PYTHON_CMD}\\n,' cpfx.py && \
		${INSTALL_SCRIPT} cpfx.py schemas.py ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
