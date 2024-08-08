PORTNAME=	pyhanko
PORTVERSION=	0.23.2
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI \
		https://github.com/MatthiasValvekens/pyHanko/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyHanko-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tools for stamping and signing PDF files
WWW=		https://pyhanko.readthedocs.io/en/latest/ \
		https://github.com/MatthiasValvekens/pyHanko

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1crypto>=1.5.1:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.1.3:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyhanko-certvalidator>=0.26.2<0.27:security/py-pyhanko-certvalidator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>=7.3.1:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=4.3:devel/py-tzlocal@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ASYNC_HTTP ETSI IMAGE_SUPPORT OPENTYPE PKGCS11 XMP
ASYNC_HTTP_DESC=Asynchronous support
ETSI_DESC=	European Telecommunications Standards Institute (ETSI)
IMAGE_SUPPORT_DESC=	Image handling support
OPENTYPE_DESC=	OpenType/TrueType support
PKGCS11_DESC=	PKGCS\#11 support
XMP_DESC=	XMP (Extensible Metadata Platform) support

ASYNC_HTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.9.0<3.10:www/py-aiohttp@${PY_FLAVOR}
ETSI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xsdata>=23.8<25.0:devel/py-xsdata@${PY_FLAVOR}
IMAGE_SUPPORT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=7.2.0:graphics/py-pillow@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}python-barcode>=0.15.1<0.15.1_99:graphics/py-python-barcode@${PY_FLAVOR}
OPENTYPE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>=4.33.3:print/py-fonttools@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}uharfbuzz>=0.25.0<0.40.0:print/py-uharfbuzz@${PY_FLAVOR}
PKGCS11_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-pkcs11>=0.7.0<0.8:security/py-python-pkcs11@${PY_FLAVOR}
XMP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0.7.1<0.8:devel/py-defusedxml@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30900
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.zoneinfo>=0:devel/py-backports.zoneinfo@${PY_FLAVOR}
# backports.zoneinfo[tzdata]
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tzdata>=0:devel/py-tzdata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
