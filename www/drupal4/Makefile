# New ports collection makefile for:	Drupal
# Date Created: 			10 Nov 2003
# Whom:					Sebastian Yepes F. <esn@x123.info>
#
# $FreeBSD$
#

PORTNAME=	drupal
PORTVERSION=	4.6.5
PORTREVISION=	2006010502
CATEGORIES=	www
MASTER_SITES=   ${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=     brooks
DIST_SUBDIR=    drupal

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	CMS that supports pgsql and mysql

USE_PHP=	gd pcre session xml
WANT_PHP_WEB=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libpq.so)
RUN_DEPENDS+=	${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if !defined(DRUPDIR)
pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define DRUPDIR to override default of 'www/drupal'."
	@${ECHO_MSG} ""
.endif

DRUPDIR?=	www/drupal
WWWOWN?=	www
WWWGRP?=	www

NO_BUILD=	yes
DOCS=		CHANGELOG.txt INSTALL.txt LICENSE.txt MAINTAINERS.txt
PLIST_SUB+=	DRUPDIR=${DRUPDIR}
SUB_LIST+=	DRUPDIR=${DRUPDIR}
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

do-install:
	${MKDIR} ${PREFIX}/${DRUPDIR}
	${CP} ${WRKSRC}/.htaccess ${PREFIX}/${DRUPDIR}
	${CP} ${WRKSRC}/cron.php ${PREFIX}/${DRUPDIR}
	${CP} -R ${WRKSRC}/database ${PREFIX}/${DRUPDIR}
	${CP} ${WRKSRC}/favicon.ico ${PREFIX}/${DRUPDIR}
	${CP} -R ${WRKSRC}/includes ${PREFIX}/${DRUPDIR}
	${CP} ${WRKSRC}/index.php ${PREFIX}/${DRUPDIR}
	${CP} -R ${WRKSRC}/misc ${PREFIX}/${DRUPDIR}
	${CP} -R ${WRKSRC}/modules ${PREFIX}/${DRUPDIR}
	${CP} -R ${WRKSRC}/scripts ${PREFIX}/${DRUPDIR}
	${MKDIR} ${PREFIX}/${DRUPDIR}/sites/default
	${CP} ${WRKSRC}/sites/default/settings.php ${PREFIX}/${DRUPDIR}/sites/default/settings.php-dist
	@if [ ! -f ${PREFIX}/${DRUPDIR}/sites/default/settings.php ]; then \
		${CP} -p ${PREFIX}/${DRUPDIR}/sites/default/settings.php-dist ${PREFIX}/${DRUPDIR}/sites/default/settings.php ; \
	fi
	${CP} -R ${WRKSRC}/themes ${PREFIX}/${DRUPDIR}
	${CP} ${WRKSRC}/update.php ${PREFIX}/${DRUPDIR}
	${CP} ${WRKSRC}/xmlrpc.php ${PREFIX}/${DRUPDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DRUPDIR}/doc
	${CP} ${DOCS:S|^|${WRKSRC}/|} ${PREFIX}/${DRUPDIR}/doc
.endif
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${DRUPDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
