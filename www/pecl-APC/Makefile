# Ports collection makefile for:  pear-APC
# Date created:			  31 August 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	APC
PORTVERSION=	2.0.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	marcus@corp.grupos.com.br
COMMENT=	Alternative PHP Cache

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	apc

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

CONFIGURE_ARGS=	--enable-apc

OPTIONS=	MMAP       "Enable mmap memory support (default: IPC shm)" off \
		SEMAPHORES "Enable sysv IPC semaphores (default: fcntl())" off \

.include <bsd.port.pre.mk>

.if ${PHP_VER} == 5
BROKEN=		This port is not compatible with php${PHP_VER}
.endif

.if !defined(WITHOUT_MMAP)
CONFIGURE_ARGS+=	--enable-mmap
.endif

.if !defined(WITHOUT_SEMAPHORES)
CONFIGURE_ARGS+=	--enable-sem
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/NOTICE ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
