# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	tcpwrap
PORTVERSION=	1.1.3
CATEGORIES=	security pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PECL extension which provides tcpwrappers binding

LICENSE=	PHP202

USES=		tar:tgz
USE_PHP=	yes
USE_PHPEXT=	yes
IGNORE_WITH_PHP= 56 70

post-patch:
	@${REINPLACE_CMD} -e 's, -ldl,,' ${WRKSRC}/config.m4

.include <bsd.port.mk>
