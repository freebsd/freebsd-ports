# New ports collection makefile for:	php_templates
# Date created:				Feb 28 2002
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	php-templates
PORTVERSION=	1.7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	php_templates-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
.if !defined(NOPORTDOCS)
DISTFILES+=	php_templates-doc-eng-1.1${EXTRACT_SUFX}
.endif

MAINTAINER=	sysadmin@alexdupre.com
COMMENT=	A template framework for PHP

BUILD_DEPENDS=	phpize:${PORTSDIR}/www/mod_php4
RUN_DEPENDS=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13 \
		${LOCALBASE}/bin/php:${PORTSDIR}/www/mod_php4

USE_LIBTOOL=	yes
WANT_AUTOMAKE_VER=	15
WANT_AUTOCONF_VER=	253

WRKSRC=		${WRKDIR}/templates

CONFIGURE_ARGS=	--enable-templates=shared \
		--with-php-config=${PREFIX}/bin/php-config

EXT_DIR=	20020429
PLIST_SUB=	EXT_DIR=${EXT_DIR}

PKGMESSAGE=	${WRKDIR}/pkg-message

post-extract:
	@${ECHO_MSG} "===>  PHPizing for ${DISTNAME}"
	@cd ${WRKSRC} && ${LOCALBASE}/bin/phpize

post-build:
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|g;s|%%PREFIX%%|${PREFIX}|g;s|%%EXT_DIR%%|${EXT_DIR}|g" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${EXT_DIR}
	@${INSTALL_DATA} ${WRKSRC}/modules/templates.so \
		${PREFIX}/lib/php/${EXT_DIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}-doc/* ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
