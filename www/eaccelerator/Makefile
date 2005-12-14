# New ports collection makefile for:	eaccelerator
# Date created:			Sat Mar 1 13:55:55 CET 2003
# Whom:				Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	eaccelerator
DISTVERSION=	0.9.4-rc1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	An opcode cache for PHP with encoder and loader

USE_PHP=	session
USE_PHPIZE=	yes
USE_PHP_BUILD=	yes
BROKEN_WITH_PHP=	5

CONFIGURE_ARGS=	--enable-eaccelerator=shared

USE_BZIP2=	yes
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PORTDOCS=	*

post-build:
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|g; s|0777|0755|g" \
		${WRKSRC}/encoder.php > ${WRKSRC}/encoder

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${INSTALL_DATA} ${WRKSRC}/modules/${PORTNAME}.so \
	       ${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/encoder ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.ini ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.php ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}_password.php ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
