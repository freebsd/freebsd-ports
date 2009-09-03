# ex:ts=8
# Ports collection makefile for:	rpy
# Date created:			Jan 14, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rpy
PORTVERSION=	1.0.3
PORTREVISION=	9
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	wenheping@gmail.com
COMMENT=	Python interface to the R Programming Language

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy \
		R:${PORTSDIR}/math/R
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
MAKE_ENV=	LDFLAGS="-L${LOCALBASE}/lib/R/modules -L${LOCALBASE}/lib/R/lib"

post-patch:
	@${REINPLACE_CMD} -e 's,^statichere ,,' ${WRKSRC}/src/rpymodule.c
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
