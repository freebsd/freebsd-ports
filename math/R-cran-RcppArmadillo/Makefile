# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	RcppArmadillo
PORTVERSION=	0.6.300.2.0
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Rcpp integration for Armadillo templated linear algebra library

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	R-cran-Rcpp>=0.11.0:${PORTSDIR}/devel/R-cran-Rcpp

USES=	cran:auto-plist

post-patch:
	@${REINPLACE_CMD} -e '/bin\//s|bash|sh|' ${WRKSRC}/configure

.include <bsd.port.mk>
