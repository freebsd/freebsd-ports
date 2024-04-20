PORTNAME=	pycups
PORTVERSION=	2.0.4
CATEGORIES=	print python
MASTER_SITES=	PYPI \
		https://github.com/OpenPrinting/pycups/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CUPS bindings for Python
WWW=		https://github.com/OpenPrinting/pycups

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libcups.so:print/cups

USES=		iconv localbase python
USE_PYTHON=	autoplist concurrent pep517

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^\(VERSION=\).*$$|\1${PORTVERSION}|' ${WRKSRC}/Makefile
.if empty(ICONV_LIB)
	@${REINPLACE_CMD} -e 's| or sys.platform.startswith("freebsd"):|:|' ${WRKSRC}/setup.py
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/cupsconnection.c
	@${REINPLACE_CMD} -e 's|#ifdef __SVR4|#ifdef __FreeBSD__|' ${WRKSRC}/cupsppd.c

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.post.mk>
