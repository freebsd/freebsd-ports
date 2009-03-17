# New ports collection makefile for:	R-sp
# Date created:		2009-01-25
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	sp
PORTVERSION=	0.9.29
CATEGORIES=	math python
MASTER_SITES=	http://mirrors.geoexpat.com/cran/src/contrib/ \
		http://cran.rakanu.com/src/contrib/ \
		http://cran.cnr.berkeley.edu/src/contrib/
PKGNAMEPREFIX=	R-
DISTNAME=	${PORTNAME}_0.9-29

MAINTAINER=	wenheping@gmail.com
COMMENT=	R Classes and Methods for Spatial Data

BUILD_DEPENDS=	${LOCALBASE}/bin/R:${PORTSDIR}/math/R
RUN_DEPENDS=	${LOCALBASE}/bin/R:${PORTSDIR}/math/R

NO_BUILD=	yes
R_INS=		R CMD INSTALL

do-install:
		@cd ${WRKDIR} && ${R_INS} ${PORTNAME}

.include <bsd.port.mk>
