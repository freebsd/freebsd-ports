# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httpuv
PORTVERSION=	1.2.0
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	HTTP and WebSocket server library for R

LICENSE=	GPLv3 NODE
LICENSE_COMB=	multi
LICENSE_NAME_NODE=	Node's license
LICENSE_FILE_NODE=	${WRKSRC}/LICENSE
LICENSE_PERMS_NODE=	auto-accept

RUN_DEPENDS=	R-cran-Rcpp>=0.10.2:${PORTSDIR}/devel/R-cran-Rcpp

MAKE_ENV=	MAKE=${MAKE_CMD}
USES=		cran:auto-plist gmake

.include <bsd.port.mk>
