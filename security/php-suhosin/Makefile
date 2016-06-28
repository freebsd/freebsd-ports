# Created by: ale
# $FreeBSD$

PORTNAME=	suhosin
PORTVERSION=	0.9.38
CATEGORIES=	security
MASTER_SITES=	http://download.suhosin.org/
PKGNAMEPREFIX=	php-

MAINTAINER=	ale@FreeBSD.org
COMMENT=	PHP extension that implements high-level protections

LICENSE=	PHP301

BROKEN_powerpc64=	Does not build

OPTIONS_DEFINE=	EXAMPLES

USES=		php:ext
USE_PHP=	session:build
IGNORE_WITH_PHP=	70

CONFIGURE_ARGS=	--enable-suhosin

PORTEXAMPLES=	suhosin.ini

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/suhosin.ini ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
