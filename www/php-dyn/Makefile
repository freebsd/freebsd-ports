# New ports collection makefile for:	php-dyn
# Date created:         Wed May 22 14:27:22 CET 2002
# Whom:                 Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	php-dyn
PORTVERSION=	1.2.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	php_dyn-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sysadmin@alexdupre.com
COMMENT=	A PHP Extension to help debugging a PHP script

BUILD_DEPENDS=	phpize:${PORTSDIR}/www/mod_php4
RUN_DEPENDS=	${LOCALBASE}/sbin/httpd:${APACHE_PORT} \
		${LOCALBASE}/bin/php:${PORTSDIR}/www/mod_php4

USE_LIBTOOL=	yes
WANT_AUTOMAKE_VER=	15
WANT_AUTOCONF_VER=	253

CONFIGURE_ARGS=	--enable-php_dyn=shared \
		--with-php-config=${LOCALBASE}/bin/php-config

EXT_DIR=	20020429
PLIST_SUB=	EXT_DIR=${EXT_DIR}

PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if defined(WITH_APACHE2) || exists(${LOCALBASE}/include/apache2/apr.h)
APACHE_PORT?=	${PORTSDIR}/www/apache2
.else
APACHE_PORT?=	${PORTSDIR}/www/apache13
.endif

post-extract:
	@${ECHO_MSG} "===>    PHPizing for ${PORTNAME}-${PORTVERSION}"
	@(cd ${WRKSRC}; ${LOCALBASE}/bin/phpize)

post-build:
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|g;s|%%PREFIX%%|${PREFIX}|g;s|%%EXT_DIR%%|${EXT_DIR}|g" \
		${FILESDIR}/pkg-message.in > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${EXT_DIR}
	@${INSTALL_DATA} ${WRKSRC}/modules/php_dyn.so \
		${PREFIX}/lib/php/${EXT_DIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.en ${DOCSDIR}/README
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
