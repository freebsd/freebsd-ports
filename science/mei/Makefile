# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	mei
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	science parallel
MASTER_SITES=	http://code-saturne.org/releases/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Mathematical Expression Interpreter

LICENSE=	LGPL21

LIB_DEPENDS=	libbft.so:science/bft
BUILD_DEPENDS=	swig3.0:devel/swig30

USES=		libtool python:2.7
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_PYEXE=${PYTHON_CMD}
CONFIGURE_ARGS=	--with-bft=${LOCALBASE}
INSTALL_TARGET=	install-strip
BINARY_ALIAS=	swig=swig3.0

do-test:
	(cd ${WRKSRC}/tests &&	\
	${MAKE_CMD} check &&	\
	./mei_test )

.include <bsd.port.mk>
