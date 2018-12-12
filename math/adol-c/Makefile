# $FreeBSD$

PORTNAME=	adol-c
DISTVERSION=	2.6.3
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	https://www.coin-or.org/download/source/${PORTNAME:tu}/
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Automatic differentiation library

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		compiler:c++11-lang gmake libtool tar:tgz
GNU_CONFIGURE=	yes
CONFIGURE_SHELL=	${LOCALBASE}/bin/bash
USE_LDCONFIG=	yes

OPTIONS_DEFINE=			SPARSE # also uses AMPI, a seemingly obscure MPI implementation
OPTIONS_SUB=			yes

SPARSE_DESC=			Build sparse drivers
SPARSE_CONFIGURE_ENABLE=	sparse

.include <bsd.port.mk>
