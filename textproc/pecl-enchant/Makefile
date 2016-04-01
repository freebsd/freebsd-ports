# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	enchant
DISTVERSION=	1.1.0
CATEGORIES=	textproc devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Libenchant Binder that Support Near All Spelling Tools

LICENSE=	PHP30

LIB_DEPENDS=	libenchant.so:textproc/enchant

USES=		tar:tgz
USE_PHP=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	${PORTNAME}
IGNORE_WITH_PHP=	56 70
CONFIGURE_ARGS+=	--with-enchant=${LOCALBASE}

.include <bsd.port.mk>
