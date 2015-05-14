# Created by: vanilla
# $FreeBSD$

PORTNAME=	cTemplate
PORTVERSION=	1.11
PORTREVISION=	0
CATEGORIES=	textproc pear
MASTER_SITES=	LOCAL/vanilla
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	PECL extension for Google ctemplate library

LIB_DEPENDS=	libctemplate.so:${PORTSDIR}/textproc/google-ctemplate

USES=		tar:xz
USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=	5

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${EXTRA_LIBS}

CONFIGURE_ARGS=	--with-cTemplate=${LOCALBASE}

.include <bsd.port.mk>
