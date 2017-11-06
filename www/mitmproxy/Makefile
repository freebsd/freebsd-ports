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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=6.2:devel/py3-click \
		${PYTHON_PKGNAMEPREFIX}blinker>=1.4:devel/py-blinker \
		${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi \
		${PYTHON_PKGNAMEPREFIX}construct28>=2.8:devel/py-construct28 \
		${PYTHON_PKGNAMEPREFIX}cryptography>=1.3:security/py-cryptography \
		${PYTHON_PKGNAMEPREFIX}cssutils>=1.0.1:www/py-cssutils \
		${PYTHON_PKGNAMEPREFIX}html2text>=2016.1.8:textproc/py-html2text \
		${PYTHON_PKGNAMEPREFIX}passlib>=1.6.5:security/py-passlib \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.1.9:devel/py-pyasn1 \
		${PYTHON_PKGNAMEPREFIX}openssl>=16.0:security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.1.3:devel/py-pyparsing \
		${PYTHON_PKGNAMEPREFIX}requests>=2.9.1:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.13.2:devel/py-ruamel.yaml \
		${PYTHON_PKGNAMEPREFIX}tornado>=4.3:www/py-tornado \
		${PYTHON_PKGNAMEPREFIX}urwid>=1.3.1:devel/py-urwid \
		${PYTHON_PKGNAMEPREFIX}watchdog>=0.8.3:devel/py-watchdog \
		${PYTHON_PKGNAMEPREFIX}brotli>=0.5.1:archivers/py-brotli \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=1.5.4:devel/py-sortedcontainers \
		${PYTHON_PKGNAMEPREFIX}pyperclip>=1.5.22:devel/py-pyperclip \
		${PYTHON_PKGNAMEPREFIX}hyperframe>=5.0.0:www/py-hyperframe \
		${PYTHON_PKGNAMEPREFIX}kaitaistruct>=0.6:devel/py-kaitaistruct \
		${PYTHON_PKGNAMEPREFIX}jsbeautifier>=1.6.3:devel/py-jsbeautifier \
		${PYTHON_PKGNAMEPREFIX}h2>=3.0.0:www/py-h2

BROKEN=		fails in dependency check: mitmproxy-2.0.1 depends on package: py36-blinker>=1.4 - not found

USES=		python:3.5+
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes
USE_GITHUB=	yes

post-extract:
	@${REINPLACE_CMD} -e 's/brotlipy/brotli/' -e 's/, <.*",/",/' ${WRKSRC}/setup.py

.include <bsd.port.mk>
