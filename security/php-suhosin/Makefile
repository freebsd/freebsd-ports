# Created by: ale
# $FreeBSD$

PORTNAME=	suhosin
PORTVERSION=	0.9.37.1
CATEGORIES=	security
MASTER_SITES=	http://download.suhosin.org/
PKGNAMEPREFIX=	php-

MAINTAINER=	ale@FreeBSD.org
COMMENT=	PHP extension that implements high-level protections

LICENSE=	PHP301

OPTIONS_DEFINE=	EXAMPLES

USE_PHP=	session
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--enable-suhosin

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/suhosin.ini ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
