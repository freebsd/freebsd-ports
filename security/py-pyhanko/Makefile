PORTNAME=	pyhanko
PORTVERSION=	0.30.0
CATEGORIES=	security python
MASTER_SITES=	PYPI \
		https://github.com/MatthiasValvekens/pyHanko/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tools for stamping and signing PDF files
WWW=		https://docs.pyhanko.eu/en/latest/ \
		https://github.com/MatthiasValvekens/pyHanko

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1crypto>=1.5.1:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.1.3<8.2.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0.7.1<0.8:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyhanko-certvalidator>=0.28.0<0.29:security/py-pyhanko-certvalidator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>=7.3.1:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=4.3:devel/py-tzlocal@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ASYNC_HTTP ETSI IMAGE_SUPPORT OPENTYPE PKCS11 XMP
ASYNC_HTTP_DESC=Asynchronous support
ETSI_DESC=	European Telecommunications Standards Institute (ETSI)
IMAGE_SUPPORT_DESC=	Image handling support
OPENTYPE_DESC=	OpenType/TrueType support
PKCS11_DESC=	PKCS\#11 support
XMP_DESC=	XMP (Extensible Metadata Platform) support

ASYNC_HTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.9<3.13:www/py-aiohttp@${PY_FLAVOR}
ETSI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xsdata>=24.4<26.0:devel/py-xsdata@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}signxml>=4.2.0:security/py-signxml@${PY_FLAVOR}
IMAGE_SUPPORT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=7.2.0:graphics/py-pillow@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}python-barcode>=0.15.1<0.15.1_99:graphics/py-python-barcode@${PY_FLAVOR}
OPENTYPE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>=4.33.3:print/py-fonttools@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}uharfbuzz>=0.25.0<0.51.0:print/py-uharfbuzz@${PY_FLAVOR}
PKCS11_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-pkcs11>=0.9.0<0.10:security/py-python-pkcs11@${PY_FLAVOR}
XMP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0.7.1<0.8:devel/py-defusedxml@${PY_FLAVOR}

.include <bsd.port.mk>
