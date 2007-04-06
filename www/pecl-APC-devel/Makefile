# Ports collection makefile for:  pear-APC
# Date created:			  31 August 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	APC
DISTVERSION=	3.0.14
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	Alternative PHP Cache

USE_PHP=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	apc

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

CONFIGURE_ARGS=	--enable-apc

OPTIONS=	MMAP		"Enable mmap memory support (default: IPC shm)"	off \
		SEMAPHORES	"Enable sysv IPC semaphores (default: fcntl())"	off \
		PHP4_OPT	"Little optimization to PHP4"			off

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if defined(WITH_MMAP)
CONFIGURE_ARGS+=	--enable-apc-mmap
.endif

.if defined(WITH_SEMAPHORES)
CONFIGURE_ARGS+=	--enable-apc-sem
.endif

.if defined(WITH_PHP4_OPT)
.if ${PHP_VER} == 4
.if exists(${LOCALBASE}/include/apache/httpd.h)
CFLAGS+=	-I${LOCALBASE}/include/apache -DAPC_PHP4_STAT
.elif exists(${LOCALBASE}/include/apache2/httpd.h)
CFLAGS+=	-I${LOCALBASE}/include/apache2 -DAPC_PHP4_STAT
.elif exists(${LOCALBASE}/include/apache21/httpd.h)
CFLAGS+=	-I${LOCALBASE}/include/apache21 -DAPC_PHP4_STAT
.elif exists(${LOCALBASE}/include/apache22/httpd.h)
CFLAGS+=	-I${LOCALBASE}/include/apache22 -DAPC_PHP4_STAT
.endif
.else
pre-configure:
	@${ECHO_CMD}
	@${ECHO_CMD} "*** WARNING ***"
	@${ECHO_CMD} "This optimization is only for PHP4. PHP5 or newer does not need it"
	@${ECHO_CMD} "I will continue instalation..."
	@${ECHO_CMD}
.endif
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
