# Ports collection makefile for:	ganglia-webfrontend
# Date created:				Thu Fed 20, 2003
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	webfrontend
PORTVERSION=	3.0.1
CATEGORIES=	sysutils net parallel www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ganglia
PKGNAMEPREFIX=	ganglia-
DISTNAME=	ganglia-${PORTVERSION}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	"Ganglia cluster monitor, web frontend"

RUN_DEPENDS+=	${LOCALBASE}/sbin/gmetad:${PORTSDIR}/sysutils/ganglia-monitor-core

PKGMESSAGE=	${WRKDIR}/pkg-message

PLIST_SUB+=	WEBFRONTDIR="${WEBFRONTDIR}"

NO_BUILD=	yes
USE_REINPLACE=	yes
USE_PHP=	gd pcre xml
USE_BZIP2=	yes
WANT_PHP_MOD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/web

# The Ganglia Web Frontend port supports a number of options that may be
# tweaked at buildtime.  Perform a "make options" to see more
# information on these variables.
WEBFRONTDIR?=	www/ganglia
WWWOWN?=	www
WWWGRP?=	www

# Set custom variables:
#
PKGOPTS=	${FILESDIR}/pkg-opts
EXCEPTFILES=	AUTHORS \
		ChangeLog \
		COPYING \
		Makefile.am \
		addons \
		version.php.in \
		webfrontend.spec

pre-patch:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%WEBFRONTDIR%%|${WEBFRONTDIR}|g' \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}

options:
	@ ${ECHO_MSG} "===>  Build options for ${PKGNAME}:"
	@ ${CAT} ${PKGOPTS}

post-extract:
.if !defined(BATCH)
	@ ${TEST} -r ${PKGOPTS} && \
	    (${ECHO_MSG} '-------------------------------------------------------------------------'; \
	     ${ECHO_MSG} 'Perform a "make options" to see a list of available installation options.'; \
	     ${ECHO_MSG} '-------------------------------------------------------------------------')
.endif

post-patch:
	@ ${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/conf.php

do-install:
	${MKDIR} ${PREFIX}/${WEBFRONTDIR}
	${MKDIR} -m 0775 ${PREFIX}/${WEBFRONTDIR}
	cd ${WRKSRC} && ${FIND} * \( -name conf.php\* \
	    ${EXCEPTFILES:S/^/-o -name /} \) \
	    -a -prune -o -print \
	    | ${TAR} cTf - - | ${TAR} xUCf ${PREFIX}/${WEBFRONTDIR} -
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${WEBFRONTDIR}
	${INSTALL} -c -o ${WWWOWN} -g ${WWWGRP} \
	    ${WRKSRC}/conf.php ${PREFIX}/${WEBFRONTDIR}/conf.php.sample
	@if [ ! -f ${PREFIX}/${WEBFRONTDIR}/conf.php ]; then \
		${INSTALL} -c -o ${WWWOWN} -g ${WWWGRP} \
		    ${WRKSRC}/conf.php ${PREFIX}/${WEBFRONTDIR} ;\
	fi

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
