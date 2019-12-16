# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	mitmproxy
PORTVERSION=	4.0.4
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	www python

MAINTAINER=	gaod@hychen.org
COMMENT=	SSL-capable man-in-the-middle proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=6.2:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blinker>=1.4:devel/py-blinker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2015.11.20.1:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wsproto>=0.11.0:net/py-wsproto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ldap3>=2.5:net/py-ldap3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>=1.6.5:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.3.1<0.5:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=17.5:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.1.3:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.13.2:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=4.3<5.2:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=2.0.1:devel/py-urwid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}brotli>=0.7.0:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=1.5.4:devel/py-sortedcontainers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyperclip>=1.6.0:devel/py-pyperclip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hyperframe>=5.1.0<6:www/py-hyperframe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kaitaistruct>=0.7<0.9:devel/py-kaitaistruct@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h2>=3.0.1<4:www/py-h2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=2.1.4:security/py-cryptography@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils autoplist noflavors
USE_GITHUB=	yes

NO_ARCH=	yes

post-extract:
	@${REINPLACE_CMD} -e 's/brotlipy/brotli/' -e 's/, <.*",/",/' ${WRKSRC}/setup.py

.include <bsd.port.mk>
