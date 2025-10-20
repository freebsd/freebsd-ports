PORTNAME=	vowpal_wabbit
PORTVERSION=	7.10
PORTREVISION=	29
CATEGORIES=	math

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Fast out-of-core learning system
WWW=		https://github.com/JohnLangford/vowpal_wabbit/wiki

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		compiler:c++11-lang libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	JohnLangford

CONFIGURE_ARGS=	--enable-shared=no --with-boost=${LOCALBASE}
LIBS+=		-lutil

.include <bsd.port.mk>
