# New ports collection makefile for:	suphp
# Date created:		15 September 2002
# Whom:			Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	suphp
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.suphp.org/download/

MAINTAINER=	clement@FreeBSD.org
COMMENT=	A combination which provides a wrapper for PHP

RUN_DEPENDS=	${LOCALBASE}/bin/php:${PORTSDIR}/www/php4-cgi

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_APACHE=	yes
CONFLICTS=	mod_php4-4* php-4.*

LOG_PATH?=	/var/log
PHP_PATH?=	${LOCALBASE}/bin/php
APACHE_USER?=	${WWWOWN}
MIN_UID?=	80
MIN_GID?=	80
WITH_SETID_MODE?=	owner

CONFIGURE_ARGS+=	--with-php=${PHP_PATH} \
			--with-logfile=${LOG_PATH}/suphp.log \
			--with-apache-user=${APACHE_USER} \
			--with-min-gid=${MIN_UID} \
			--with-min-uid=${MIN_GID} \
			--with-apxs=${APXS}

## Available knobs:
##   WITHOUT_CHECKPATH: disable check if script resides in DOCUMENT_ROOT
.if defined(WITHOUT_CHECKPATH)
CONFIGURE_ARGS+=	--disable-checkpath
.endif
##   WITHOUT_CHECKUID: accept UIDs that are not listed in /etc/passwd
.if defined(WITHOUT_CHECKUID)
CONFIGURE_ARGS+=	--disable-checkuid
.endif
##   WITHOUT_CHECKGID: accept GIDs that are not listed in /etc/group
.if defined(WITHOUT_CHECKGID)
CONFIGURE_ARGS+=	--disable-checkgid
.endif
## WITH_SETID_MODE: Mode to use for setting UID/GID.
CONFIGURE_ARGS+=	--enable-setid=${WITH_SETID_MODE}

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/apache2/apr.h) || defined(WITH_APACHE2)
APACHE_PORT=	www/apache2
PLIST_SUB+=	MODULEDIR="libexec/apache2/"
.else
PLIST_SUB+=	MODULEDIR="libexec/apache/"
.endif

show-options:
	@${SED} -ne 's/^##//p' ${.CURDIR}/Makefile

pre-everything::
	@${MAKE} show-options

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -Rfp ${WRKSRC}/doc/* ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
