# Created by: ale
# $FreeBSD$

PORTNAME=	suhosin
PORTVERSION=	0.9.35
CATEGORIES=	security
MASTER_SITES=	http://download.suhosin.org/
PKGNAMEPREFIX=	php-
EXTRACT_SUFX=	.tgz

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A PHP extension that implements high-level protections

LICENSE=	PHP301

OPTIONS_DEFINE=	EXAMPLES

USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP=53

CONFIGURE_ARGS=	--enable-suhosin

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/suhosin.ini ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
