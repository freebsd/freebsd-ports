# ex:ts=8
# Ports collection makefile for:	rpy
# Date created:			Jan 14, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rpy
PORTVERSION=	0.3.5
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to the R Programming Language

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Numeric.pth:${PORTSDIR}/math/py-numeric \
		R:${PORTSDIR}/math/R
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
MAKE_ENV=	LDFLAGS="-L${LOCALBASE}/lib/R/modules -L${LOCALBASE}/lib/R/lib"

.include <bsd.port.mk>
