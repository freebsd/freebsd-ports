# New ports collection makefile for:	turck-mmcache
# Date created:			Sat Mar 1 13:55:55 CET 2003
# Whom:				Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	turck-mmcache
PORTVERSION=	2.3.10
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sysadmin@alexdupre.com
COMMENT=	An opcode cache for PHP with encoder and loader

EXTRACT_DEPENDS=phpize:${PORTSDIR}/www/mod_php4
BUILD_DEPENDS=	${LOCALBASE}/include/php/Zend/zend.h:${PORTSDIR}/www/mod_php4
LIB_DEPENDS=	mm.12:${PORTSDIR}/devel/mm
RUN_DEPENDS=	${LOCALBASE}/sbin/httpd:${APACHE_PORT} \
		${LOCALBASE}/bin/php:${PORTSDIR}/www/mod_php4

USE_LIBTOOL=	yes
WANT_AUTOMAKE_VER=	15
WANT_AUTOCONF_VER=	253

CONFIGURE_ARGS=	--enable-mmcache=shared \
		--with-php-config=${LOCALBASE}/bin/php-config \
		--prefix=${PREFIX}

EXT_DIR=	20020429
PLIST_SUB=	EXT_DIR=${EXT_DIR}

PKGMESSAGE=	${WRKDIR}/pkg-message

USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_APACHE2) || exists(${LOCALBASE}/include/apache2/apr.h)
APACHE_PORT?=	${PORTSDIR}/www/apache2
.else
APACHE_PORT?=	${PORTSDIR}/www/apache13
.endif

post-extract:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/config.m4
	@${ECHO_MSG} "===>  PHPizing for ${DISTNAME}"
	@cd ${WRKSRC} && ${LOCALBASE}/bin/phpize

post-build:
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/encoder.php > ${WRKSRC}/encoder
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|g;s|%%PREFIX%%|${PREFIX}|g;s|%%EXT_DIR%%|${EXT_DIR}|g" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${EXT_DIR}
	@${INSTALL_DATA} ${WRKSRC}/modules/mmcache.so \
	       ${PREFIX}/lib/php/${EXT_DIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/encoder ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/mmcache.php ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
