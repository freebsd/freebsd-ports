# New ports collection makefile for:	php-yaf
# Date created:		13 May 2011
# Whom:			johnpupu <johnpupu@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	yaf
PORTVERSION=	2.0.1
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	php-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	johnpupu@gmail.com
COMMENT=	Yaf is a php framework, the difference is yaf is a PHP Extension

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--with-php-config=${PREFIX}/bin/php-config
PROJECTHOST=	yafphp
USE_PHP=	yes
USE_ZIP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.mk>
