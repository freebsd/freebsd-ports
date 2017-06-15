# $FreeBSD$

PORTNAME=	sample
PORTVERSION=	0.02f
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Examine periodic stack traces of all running processes

LICENSE=	BSD3CLAUSE

BROKEN_i386=		does not build: don't know how to make sample_support_i386.c
BROKEN_powerpc64=	does not build
BROKEN_sparc64=		does not build: don't know how to make sample_support_sparc64.c

BUILD_DEPENDS=	${LOCALBASE}/lib/libbfd.a:devel/libbfd \
		${LOCALBASE}/lib/libiberty.a:devel/gnulibiberty \
		${LOCALBASE}/lib/libxo.a:devel/libxo \
		${LOCALBASE}/bin/cython:lang/cython \
		${LOCALBASE}/bin/python:lang/python

USE_GITHUB=	yes
GH_ACCOUNT=	freenas
GH_TAGNAME=	45e2b86

USES=		python:build kmod

MAKE_ENV=	SYSDIR=${SRC_BASE}/sys

SSP_UNSAFE=	yes

do-install:
	${INSTALL_KLD} ${WRKSRC}/driver/sample_driver.ko ${STAGEDIR}${KMODDIR}
	${INSTALL_MAN} ${WRKSRC}/sample/sample.8 ${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/sample/sample ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
