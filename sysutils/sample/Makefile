PORTNAME=	sample
PORTVERSION=	0.02f
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Examine periodic stack traces of all running processes

BROKEN_FreeBSD_13=	does not build: vm_page_unhold(page) API has changed
BROKEN_FreeBSD_14=	does not build: vm_page_unhold(page) API has changed
DEPRECATED=		abandoned upstream, incompatible with newer kernels
EXPIRATION_DATE=	2021-12-31

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	device driver part of the program only supports amd64

BUILD_DEPENDS=	${LOCALBASE}/lib/libbfd.a:devel/libbfd \
		${LOCALBASE}/lib/libiberty.a:devel/gnulibiberty \
		${LOCALBASE}/lib/libxo.a:devel/libxo

USE_GITHUB=	yes
GH_ACCOUNT=	freenas
GH_TAGNAME=	45e2b86

BINARY_ALIAS=	python=${PYTHON_CMD}
USES=		python:build kmod
USE_PYTHON=	cython

MAKE_ENV=	SYSDIR=${SRC_BASE}/sys

SSP_UNSAFE=	yes

do-install:
	${INSTALL_KLD} ${WRKSRC}/driver/sample_driver.ko ${STAGEDIR}${KMODDIR}
	${INSTALL_MAN} ${WRKSRC}/sample/sample.8 ${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/sample/sample ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
