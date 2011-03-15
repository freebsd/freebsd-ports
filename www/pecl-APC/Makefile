# Ports collection makefile for:  pear-APC
# Date created:			  31 August 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	APC
DISTVERSION=	3.1.7
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	Alternative PHP Cache

USE_PHP=	yes
IGNORE_WITH_PHP=4
USE_PHPEXT=	yes
PHP_MODNAME=	apc

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

CONFIGURE_ARGS=	--enable-apc
CFLAGS=		-I${LOCALBASE}/include

OPTIONS=	IPC		"Enable IPC shm memory support (default: mmap)"	off \
		SEMAPHORES	"Enable sysv IPC semaphores (default: fcntl())"	off \
		SPINLOCKS	"Enable spinlocks (experimental)"		off \
		FILEHITS	"Enable per request cache info"			off

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if defined(WITH_IPC)
CONFIGURE_ARGS+=	--disable-apc-mmap
.endif

.if defined(WITH_SEMAPHORES)
CONFIGURE_ARGS+=	--enable-apc-sem
.endif

.if defined(WITH_SPINLOCKS)
CONFIGURE_ARGS+=	--enable-apc-spinlocks
.endif

.if defined(WITH_FILEHITS)
CONFIGURE_ARGS+=	--enable-apc-filehits
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NOTICE ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/apc.php ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
