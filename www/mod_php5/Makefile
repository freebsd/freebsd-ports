# New ports collection makefile for:	mod_php4
# Date created:		Sun May 28 11:31:54 CEST 2000
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	mod_php4
PORTVERSION=	4.2.3
PORTREVISION?=	0
CATEGORIES?=	www
MASTER_SITES=	http://us.php.net/${PHP_DISTDIR}/ \
		http://php.he.net/${PHP_DISTDIR}/ \
		http://www.php3.de/${PHP_DISTDIR}/ \
		http://au.php.net/${PHP_DISTDIR}/ \
		http://at.php.net/${PHP_DISTDIR}/ \
		http://br.php.net/${PHP_DISTDIR}/ \
		http://php.easydns.com/${PHP_DISTDIR}/ \
		http://www.php.cz/${PHP_DISTDIR}/ \
		http://php3.globe.de/${PHP_DISTDIR}/
DISTNAME=	php-${PORTVERSION}

MAINTAINER=	dirk@FreeBSD.org

.if !defined(STANDALONE)
BUILD_DEPENDS=	${APXS}:${APACHE_PORT}
RUN_DEPENDS=	${APXS}:${APACHE_PORT}
.if defined(WITH_APACHE2)
LIB_DEPENDS=	pth.14:${PORTSDIR}/devel/pth
.endif
.endif

PHP_DISTDIR=	distributions

SLAVEDIRS=	lang/php4

USE_BZIP2=	yes
USE_SUBMAKE=	yes
USE_AUTOCONF_VER=213
.if defined(WITH_APACHE2)
APACHE_PORT?=	${PORTSDIR}/www/apache2
.else
APACHE_PORT?=	${PORTSDIR}/www/apache13
.endif
APXS?=		${LOCALBASE}/sbin/apxs

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

.if defined(STANDALONE)
CONFIGURE_ARGS=	--with-config-file-path=${PREFIX}/etc/php.standalone \
		--disable-pear \
		--enable-discard-path \
		--with-readline=/usr

MAKE_ENV=	STANDALONE="${STANDALONE}"
.else
.if defined(WITH_APACHE2)
CONFIGURE_ARGS=	--with-apxs2=${PREFIX}/sbin/apxs \
		--with-tsrm-pth
PLIST_SUB=	MOD_DIR=libexec/apache2 \
		NON=
.else
CONFIGURE_ARGS=	--with-apxs=${PREFIX}/sbin/apxs
PLIST_SUB=	MOD_DIR=libexec/apache \
		NON=non-
.endif
CONFIGURE_ARGS+=--with-config-file-path=${PREFIX}/etc
.endif

CONFIGURE_ARGS+=--enable-versioning \
		--with-regex=system \
		--without-gd \
		--without-mysql

CFLAGS+=	-I${PREFIX}/include

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		CAT="${CAT}" \
		PHP4_OPTIONS="${PHP4_OPTIONS}" \
		REALCURDIR="${.CURDIR}"

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.php
.if !defined(STANDALONE) && !defined(WITH_APACHE2)
	@${ECHO_CMD} "Define WITH_APACHE2 to build mod_php4 as an apache2 module."
	@${ECHO_CMD} ""
.endif

post-install:
.if !defined(STANDALONE)
	@${INSTALL_DATA} ${WRKSRC}/php.ini-dist ${PREFIX}/etc
.else
	@${MKDIR} ${PREFIX}/etc/php.standalone
	@${INSTALL_DATA} ${WRKSRC}/php.ini-dist ${PREFIX}/etc/php.standalone
.endif

.if !defined(STANDALONE)
	@${ECHO_CMD} "*****************************************************************************"
	@${ECHO_CMD} "Make sure the mime.types are connected to the php module properly and"
	@${ECHO_CMD} "index.php is part of your DirectoryIndex."
	@${ECHO_CMD} ""
	@${ECHO_CMD} "The following should be in your Apache configuration file:"
	@${ECHO_CMD} "[...]"
	@${ECHO_CMD} "DirectoryIndex index.php index.html"
	@${ECHO_CMD} "[...]"
	@${ECHO_CMD} "AddType application/x-httpd-php .php"
	@${ECHO_CMD} "AddType application/x-httpd-php-source .phps"
	@${ECHO_CMD} "[...]"
	@${ECHO_CMD} "*****************************************************************************"
.endif

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.include <bsd.port.mk>
