# Created by: vanilla
# $FreeBSD$

PORTNAME=	cTemplate
PORTVERSION=	1.12
CATEGORIES=	textproc pear
DISTVERSIONPREFIX=	v
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	PECL extension for ctemplate library

LIB_DEPENDS=	libctemplate.so:textproc/google-ctemplate

USES=		tar:xz
USE_PHP=	yes
USE_PHPEXT=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	vanillahsu
GH_PROJECT=	pecl-ctemplate
IGNORE_WITH_PHP=	70

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${EXTRA_LIBS}

CONFIGURE_ARGS=	--with-cTemplate=${LOCALBASE}

.include <bsd.port.mk>
