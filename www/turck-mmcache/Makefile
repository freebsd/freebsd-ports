# New ports collection makefile for:	turck-mmcache
# Date created:			Sat Mar 1 13:55:55 CET 2003
# Whom:				Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	turck-mmcache
PORTVERSION=	2.4.6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	An opcode cache for PHP with encoder and loader

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_PHP=	yes
USE_PHPIZE=	yes

CONFIGURE_ARGS=	--enable-mmcache=shared

PKGMESSAGE=	${WRKDIR}/pkg-message

post-patch:
	@${REINPLACE_CMD} 's|ALIGN|MMALIGN|g' ${WRKSRC}/mm.c ${WRKSRC}/mmcache.c

post-build:
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/encoder.php > ${WRKSRC}/encoder
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|g;s|%%PREFIX%%|${PREFIX}|g;s|%%PHP_EXT_DIR%%|${PHP_EXT_DIR}|g" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${INSTALL_DATA} ${WRKSRC}/modules/mmcache.so \
	       ${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/encoder ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/mmcache.php ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/mmcache_password.php ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
