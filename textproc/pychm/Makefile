# New ports collection makefile for:	pychm
# Date created:                		25 November 2004
# Whom:                    		Radek Kozlowski <radek@raadradd.com>
#
# $FreeBSD$
#

PORTNAME=	pychm
PORTVERSION=	0.8.2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnochm

MAINTAINER=	radek@raadradd.com
COMMENT=	A package that provides bindings for CHMLIB library

LIB_DEPENDS=	chm.0:${PORTSDIR}/misc/chmlib

NO_BUILD=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_INSTALLARGS=	build_ext -I${LOCALBASE}/include -L${LOCALBASE}/lib \
			 	install -c -O1 --prefix=${PREFIX}

.include <bsd.port.mk>
