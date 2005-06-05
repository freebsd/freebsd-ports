# New ports collection makefile for:	eaccelerator
# Date created:			Sat Mar 1 13:55:55 CET 2003
# Whom:				Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	eaccelerator
PORTVERSION=	0.9.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	An opcode cache for PHP with encoder and loader

USE_PHP=	yes
USE_PHPIZE=	yes

CONFIGURE_ARGS=	--enable-eaccelerator=shared

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if !exists(${LOCALBASE}/lib/php/${PHP_EXT_DIR}/session.so)
WITHOUT_PHP_SESSION=	yes
CONFIGURE_ARGS+=	--without-eaccelerator-sessions
.endif

pre-everything::
.if defined(WITHOUT_PHP_SESSION)
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> If you use ${PORTNAME} with php session, please"
	@${ECHO_MSG} "===> press CTRL+C and install www/php${PHP_VER}-session"
	@${ECHO_MSG} "===>"
	@sleep 2
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-build:
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/encoder.php > ${WRKSRC}/encoder

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

.include <bsd.port.post.mk>
