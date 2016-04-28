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

RUN_DEPENDS=	smbclient:${PORTSDIR}/${SAMBA_PORT}

SAMBA_PORT?=	net/samba36

USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USES=		tar:tgz

CONFIGURE_ARGS=	--with-libsmbclient=${LOCALBASE}

.include <bsd.port.mk>
