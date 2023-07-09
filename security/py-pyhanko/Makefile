PORTNAME=	pyhanko
PORTVERSION=	0.19.0
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyHanko-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tools for stamping and signing PDF files
WWW=		https://github.com/MatthiasValvekens/pyHanko

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1crypto>=1.5.1:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.1.2:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=3.3.1,1:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyhanko-certvalidator>=0.23<0.24:security/py-pyhanko-certvalidator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.3.1:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>=6.1:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.24.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=4.3:devel/py-tzlocal@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	IMAGE_SUPPORT OPENTYPE PKGCS11 XMP
IMAGE_SUPPORT_DESC=	Image handling support
OPENTYPE_DESC=	OpenType/TrueType support
PKGCS11_DESC=	PKGCS\#11 support
XMP_DESC=	XMP (Extensible Metadata Platform) support

IMAGE_SUPPORT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=7.2.0:graphics/py-pillow@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}python-barcode>=0.14.0<0.14.0_99:graphics/py-python-barcode@${PY_FLAVOR}
OPENTYPE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>=4.33.3:print/py-fonttools@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}uharfbuzz>=0.25.0:print/py-uharfbuzz@${PY_FLAVOR}
PKGCS11_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-pkcs11>=0.7.0<0.8:security/py-python-pkcs11@${PY_FLAVOR}
XMP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0.7.1<0.8:devel/py-defusedxml@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30900
# tzdata is from backports.zoneinfo[tzdata]
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.zoneinfo>=0:devel/py-backports.zoneinfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzdata>=0:devel/py-tzdata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
