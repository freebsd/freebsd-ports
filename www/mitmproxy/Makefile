# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	mitmproxy
PORTVERSION=	2.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www python

MAINTAINER=	gaod@hychen.org
COMMENT=	SSL-capable man-in-the-middle proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=6.2:devel/py-click@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blinker>=1.4:devel/py-blinker@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}construct28>=2.8:devel/py-construct28@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=1.3:security/py-cryptography@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cssutils>=1.0.1:www/py-cssutils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html2text>=2016.1.8:textproc/py-html2text@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>=1.6.5:security/py-passlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.1.9:devel/py-pyasn1@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=16.0:security/py-openssl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.1.3:devel/py-pyparsing@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.9.1:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.13.2:devel/py-ruamel.yaml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=4.3:www/py-tornado@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=1.3.1:devel/py-urwid@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchdog>=0.8.3:devel/py-watchdog@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}brotli>=0.5.1:archivers/py-brotli@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=1.5.4:devel/py-sortedcontainers@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyperclip>=1.5.22:devel/py-pyperclip@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hyperframe>=5.0.0:www/py-hyperframe@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kaitaistruct>=0.6:devel/py-kaitaistruct@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsbeautifier>=1.6.3:devel/py-jsbeautifier@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h2>=3.0.0:www/py-h2@${FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist optsuffix
NO_ARCH=	yes
USE_GITHUB=	yes

post-extract:
	@${REINPLACE_CMD} -e 's/brotlipy/brotli/' -e 's/, <.*",/",/' ${WRKSRC}/setup.py

.include <bsd.port.mk>
