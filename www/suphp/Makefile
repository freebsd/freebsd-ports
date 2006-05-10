# New ports collection makefile for:	suphp
# Date created:		15 September 2002
# Whom:			Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	suphp
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.suphp.org/download/

MAINTAINER=	freebsd@jdc.parodius.com
COMMENT=	Securely execute PHP scripts

GNU_CONFIGURE=	yes
USE_PHP=	yes
USE_APACHE=	1.3+
WANT_PHP_CGI=	yes

WITH_LOGFILE?=	/var/log/suphp.log
PHP_PATH?=	${LOCALBASE}/bin/php-cgi
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

# This is the default of the PATH environment variable when scripts
# are run under suphp.  This path is normally hard-coded into suphp.c.
# Many people prefer to have /usr/local and other utilities available
# to php scripts.
# Make sure the path is colon-delimited!
#
SUPHP_PATH?=		/bin:/usr/bin

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

show-options:
	@${SED} -ne 's/^##//p' ${.CURDIR}/Makefile

pre-everything:: show-options
	@${DO_NADA}

post-patch:
	@${REINPLACE_CMD} -e 's|%%SUPHP_PATH%%|${SUPHP_PATH}|g' \
		${WRKSRC}/src/suphp.c

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
