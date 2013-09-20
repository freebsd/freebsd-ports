# Created by: vanilla
# $FreeBSD$

PORTNAME=	cTemplate
PORTVERSION=	1.11
PORTREVISION=	0
CATEGORIES=	textproc pear
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	vanilla
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A PECL extension for Google ctemplate library

LIB_DEPENDS=	ctemplate.2:${PORTSDIR}/textproc/google-ctemplate

USE_XZ=		yes
USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=	5

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${EXTRA_LIBS}

CONFIGURE_ARGS=	--with-cTemplate=${LOCALBASE}

NO_STAGE=	yes
.include <bsd.port.mk>
