# Ports collection makefile for:  pear-APC
# Date created:			  31 August 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	APC
DISTVERSION=	3.1.11
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Alternative PHP Cache

OPTIONS_DEFINE=	FILEHITS IPC SEMAPHORES SPINLOCKS
FILEHITS_DESC=	Per request cache info
IPC_DESC=	IPC shm memory support (default: mmap)
SEMAPHORES_DESC=System V IPC semaphores (default: fcntl)
SPINLOCKS_DESC=	Spinlocks (experimental)

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-apc
IGNORE_WITH_PHP=4
PHP_MODNAME=	${PORTNAME:L}
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
USE_PHP=	yes
USE_PHPEXT=	yes

PORTDOCS=	CHANGELOG INSTALL NOTICE apc.php

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFILEHITS}
CONFIGURE_ARGS+=	--enable-apc-filehits
.endif

.if ${PORT_OPTIONS:MIPC}
CONFIGURE_ARGS+=	--disable-apc-mmap
.endif

.if ${PORT_OPTIONS:MSEMAPHORES}
CONFIGURE_ARGS+=	--enable-apc-sem
.endif

.if ${PORT_OPTIONS:MSPINLOCKS}
CONFIGURE_ARGS+=	--enable-apc-spinlocks
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
