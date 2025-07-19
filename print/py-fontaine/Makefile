PORTNAME=	fontaine
PORTVERSION=	1.4.0
PORTREVISION=	4
CATEGORIES=	print python
MASTER_SITES=	https://www.freedesktop.org/software/fontconfig/release/:fontconfig
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	fontconfig-${FONTCONFIG_VER}.tar.xz:fontconfig

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Font analysis tool for determining character/glyph support
WWW=		https://github.com/googlefonts/pyfontaine

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>=0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>=0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyicu>=0:devel/py-pyicu@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>=0:devel/py-tabulate@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

FONTCONFIG_VER=	2.15.0

USE_GITHUB=	yes
GH_ACCOUNT=	googlefonts
GH_PROJECT=	pyfontaine

post-patch:
	@${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${WRKSRC}/setup.py
	@${LN} -s ${WRKSRC}/../fontconfig-${FONTCONFIG_VER}/fc-lang ${WRKSRC}/fontaine/charsets/fontconfig/fc-lang

.include <bsd.port.mk>
