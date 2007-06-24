# New ports collection makefile for:	pecl-cTemplate
# Date created:				07 May 2006
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	cTemplate
PORTVERSION=	1.0
CATEGORIES=	textproc pear
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	vanilla
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A PECL extension for google ctemplate library

LIB_DEPENDS=	ctemplate.0:${PORTSDIR}/textproc/google-ctemplate

USE_BZIP2=	yes
USE_GCC=	3.2+
USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=	5

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${EXTRA_LIBS}"

CONFIGURE_ARGS=	--with-cTemplate=${LOCALBASE}

.include <bsd.port.mk>
