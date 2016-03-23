# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	APC
PORTVERSION=	3.1.14
PORTREVISION=	1
CATEGORIES=	www
#MASTER_SITES=	http://pecl.php.net/get/
MASTER_SITES=	LOCAL/sunpoet
PKGNAMEPREFIX=	pecl-
DISTNAME=	${PORTNAME}-3.1.13
DIST_SUBDIR=	PECL

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Alternative PHP Cache

LICENSE=	PHP301

DEPRECATED=	Unmaintained by upstream and not work for PHP 5.5+
EXPIRATION_DATE=2016-03-15

OPTIONS_DEFINE=	DOCS FILEHITS IPC SEMAPHORES SPINLOCKS
FILEHITS_DESC=	Per request cache info
IPC_DESC=	IPC shm memory support (default: mmap)
SEMAPHORES_DESC=System V IPC semaphores (default: fcntl)
SPINLOCKS_DESC=	Spinlocks (experimental)

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-apc
IGNORE_WITH_PHP=55 56 70
PHP_MODNAME=	${PORTNAME:tl}
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
USE_PHP=	yes
USE_PHPEXT=	yes
USES=		tar:tgz

PORTDOCS=	CHANGELOG INSTALL NOTICE apc.php

FILEHITS_CONFIGURE_ARGS=--enable-apc-filehits
IPC_CONFIGURE_ARGS=	--disable-apc-mmap
SEMAPHORES_CONFIGURE_ARGS=	--enable-apc-sem
SPINLOCKS_CONFIGURE_ARGS=	--enable-apc-spinlocks

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
