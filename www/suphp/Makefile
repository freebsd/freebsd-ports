# New ports collection makefile for:	suphp
# Date created:		15 September 2002
# Whom:			Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	suphp
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.suphp.org/download/

MAINTAINER=	freebsd@jdc.parodius.com
COMMENT=	Securely execute ~user PHP scripts

GNU_CONFIGURE=	yes
USE_PHP=	yes
USE_APACHE=	yes
WANT_PHP_CGI=	yes
CONFLICTS=	mod_php4-4* php-4.* mod_php5-5* php-5.*

WITH_LOGFILE?=	/var/log/suphp.log
PHP_PATH?=	${LOCALBASE}/bin/php
MIN_UID?=	80
MIN_GID?=	80
WITH_SETID_MODE?=	owner
MYPORTDOCS=	apache/CONFIG apache/INSTALL apache/README apache/LICENSE LICENSE INSTALL README
LANG=		en de

CONFIGURE_ARGS+=	--with-php=${PHP_PATH} \
			--with-logfile=${WITH_LOGFILE} \
			--with-apache-user=${WWWOWN} \
			--with-min-gid=${MIN_UID} \
			--with-min-uid=${MIN_GID} \
			--with-apxs=${APXS}

## Available knobs:
##   WITHOUT_CHECKPATH:    disable check if script resides in DOCUMENT_ROOT
.if defined(WITHOUT_CHECKPATH)
CONFIGURE_ARGS+=	--disable-checkpath
.endif
##   WITHOUT_CHECKUID:     accept UIDs that are not listed in /etc/passwd
.if defined(WITHOUT_CHECKUID)
CONFIGURE_ARGS+=	--disable-checkuid
.endif
##   WITHOUT_CHECKGID:     accept GIDs that are not listed in /etc/group
.if defined(WITHOUT_CHECKGID)
CONFIGURE_ARGS+=	--disable-checkgid
.endif
##   WITH_SETID_MODE:      mode to use for setting UID/GID.
CONFIGURE_ARGS+=	--with-setid-mode=${WITH_SETID_MODE}

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
.for l in ${LANG}
	@${MKDIR} ${DOCSDIR}/${l}/apache
.       for f in ${MYPORTDOCS}
	@${CP} -Rfp ${WRKSRC}/doc/${l}/${f} ${DOCSDIR}/${l}/${f}
.       endfor
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
