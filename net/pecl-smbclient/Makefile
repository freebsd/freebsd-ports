# $FreeBSD$

PORTNAME=	smbclient
PORTVERSION=	0.8.0
CATEGORIES=	net pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Smbclient wrapper extension

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsmbclient.so:net/samba-libsmbclient

USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USES=		tar:tgz

CONFIGURE_ARGS=	--with-libsmbclient=${LOCALBASE}

.include <bsd.port.mk>
