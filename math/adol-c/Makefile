PORTNAME=	adol-c
DISTVERSION=	2.7.2
PORTREVISION=	13
CATEGORIES=	math
MASTER_SITES=	https://www.coin-or.org/download/source/${PORTNAME:tu}/
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Automatic differentiation library
WWW=		https://github.com/coin-or/ADOL-C

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		compiler:c++11-lang gmake libtool tar:tgz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-boost-system=boost_thread
CONFIGURE_SHELL=	${LOCALBASE}/bin/bash

INSTALL_TARGET=	install-strip

BINARY_ALIAS=	swig=false

OPTIONS_DEFINE=			PYTHON SPARSE # also uses AMPI, a seemingly obscure MPI implementation
OPTIONS_DEFAULT=		SPARSE
OPTIONS_SUB=			yes

PYTHON_USES=			python:build
PYTHON_CONFIGURE_ENV=		PYTHON=${PYTHON_CMD}
PYTHON_BROKEN=			https://github.com/coin-or/ADOL-C/issues/42

SPARSE_DESC=			Build sparse drivers
SPARSE_CONFIGURE_ENABLE=	sparse

post-patch: # broken with ColPack: https://github.com/coin-or/ADOL-C/issues/40
	@${REINPLACE_CMD} -e 's|with_colpack|with_colpackx| ; s|-lColPack||' ${WRKSRC}/configure

post-patch-PYTHON-off:
	@${REINPLACE_CMD} -e 's|test x$$python_found = xyes|false \&\& &|' ${WRKSRC}/configure

.include <bsd.port.mk>
