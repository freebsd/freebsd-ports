# ex:ts=8
# Ports collection makefile for:	rpy
# Date created:			Jan 14, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rpy
PORTVERSION=	1.0.3
PORTREVISION=	19
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python interface to the R Programming Language

LICENSE=	GPLv2 LGPL21 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy \
		R:${PORTSDIR}/math/R
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy \
		R:${PORTSDIR}/math/R

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib/R/modules -L${LOCALBASE}/lib/R/lib

post-patch:
	@${REINPLACE_CMD} -e 's,^statichere ,,' ${WRKSRC}/src/rpymodule.c
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/setup.py

pre-configure:
	@(if [ ! -e ${LOCALBASE}/lib/R/lib/libR.so ] ; then \
	${ECHO_MSG} "==> ${PKGNAME} requires math/R to be built WITH_LIBR" ; \
	exit 1; fi)

.include <bsd.port.mk>
