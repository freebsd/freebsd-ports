# New ports collection makefile for:	suphp
# Date created:		15 September 2002
# Whom:			Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	suphp
PORTVERSION=	0.3.1
CATEGORIES=	www
MASTER_SITES=	http://www.suphp.org/download/

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	A combination which provides a wrapper for PHP

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/bin/php:${PORTSDIR}/www/php4-cgi

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFLICTS=	mod_php4-4*

APXS?=		${LOCALBASE}/sbin/apxs
LOG_PATH?=	/var/log
PHP_PATH?=	${LOCALBASE}/bin/php
APACHE_USER?=	www

CONFIGURE_ARGS+=	--with-php=${PHP_PATH} \
			--with-logfile=${LOG_PATH}/suphp.log \
			--with-apache-user=${APACHE_USER} \
			--with-min-gid=80 \
			--with-min-uid=80 \
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

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/apache2/apr.h)
BROKEN=			"Doesn't work with Apache 2"
.endif

show-options:
	@${EGREP} '^##' ${.CURDIR}/Makefile | ${SED} 's/##//'

pre-everything::
	@${MAKE} show-options

post-extract:
	@${CHMOD} 755 ${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -Rfp ${WRKSRC}/doc/* ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
