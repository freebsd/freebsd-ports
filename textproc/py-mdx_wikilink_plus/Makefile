PORTNAME=	mdx_wikilink_plus
DISTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts wikilinks to relative links
WWW=		https://github.com/neurobin/mdx_wikilink_plus

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>=2.6:textproc/py-markdown@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils unittest

NO_ARCH=	yes

.include <bsd.port.mk>
