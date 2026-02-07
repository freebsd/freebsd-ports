PORTNAME=	smartypants
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2
CATEGORIES=	textproc
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Translate plain ASCII punctuation into smart typographic HTML
WWW=		https://github.com/leohemsted/smartypants.py

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	leohemsted
GH_PROJECT=	${PORTNAME}.py
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
