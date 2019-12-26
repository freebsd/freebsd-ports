# Created by: ijliao
# $FreeBSD$

PORTNAME=	rpy
PORTVERSION=	1.0.3
PORTREVISION=	40
CATEGORIES=	math
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to the R Programming Language

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2 LGPL21 MPL11
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libR.so:math/R
RUN_DEPENDS=	${PYNUMPY}

USES=		python:2.7
USE_PYTHON=	distutils autoplist
LDFLAGS+=	-L${LOCALBASE}/lib/R/modules -L${LOCALBASE}/lib/R/lib

post-patch:
	@${REINPLACE_CMD} -e 's,^statichere ,,' ${WRKSRC}/src/rpymodule.c
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/lib|' ${WRKSRC}/setup.py

pre-configure:
	@(if [ ! -e ${LOCALBASE}/lib/R/lib/libR.so ] ; then \
	${ECHO_MSG} "==> ${PKGNAME} requires math/R to be built WITH_LIBR" ; \
	exit 1; fi)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/*.so

.include <bsd.port.mk>
