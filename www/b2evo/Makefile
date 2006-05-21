# New ports collection makefile for:	b2evo
# Date created:		2005-04-16
# Whom:			chinsan <chinsan@mail20000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	b2evolution
PORTVERSION=	0.9.1b
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	evocms
DISTNAME=	${PORTNAME}-${PORTVERSION}-${B2EVO_DATE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multilingual, multiuser, multi-blog engine

PATCH_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

USE_ZIP=	YES

B2EVO_DATE?=	2005-09-16
USE_PHP=	mysql pcre session xml xmlrpc
NO_BUILD=	YES
WANT_PHP_WEB=	YES

TMPDIR?=	${PORTNAME}
WRKSRC=		${WRKDIR}/${TMPDIR}

.if !defined(B2EVO_URL)
pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define B2EVO_URL to override default of ${PREFIX}/${WWWDOCROOT}/'${B2EVO_URL}'."
	@${ECHO_MSG} ""
.endif

# Get HOSTNAME
.if exists(/sbin/sysctl)
HOSTNAME!=	/sbin/sysctl -n kern.hostname
.else
HOSTNAME!=	/usr/sbin/sysctl -n kern.hostname
.endif

WWWDOCROOT?=	www/data
B2EVO_URL?=	b2evo
WWWOWN?=	www
WWWGRP?=	www
B2EVO_DIR?=	${WWWDOCROOT}/${B2EVO_URL}
HTACCESS=	${WRKSRC}/blogs/sample.htaccess
PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

post-extract:
	@${TR} -d \\r < ${HTACCESS} > ${HTACCESS}.unix

pre-install:
	@cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|${B2EVO_DIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${B2EVO_DIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${B2EVO_DIR} >> ${PLIST} \
		&& ${ECHO_CMD} @dirrmtry ${WWWDOCROOT} >> ${PLIST}

do-install:
	-${MKDIR} ${PREFIX}/${B2EVO_DIR}
	@${CHMOD} 755 ${PREFIX}/${B2EVO_DIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${B2EVO_DIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${B2EVO_DIR}
	@${CHMOD} 665 ${PREFIX}/${B2EVO_DIR}/blogs/conf/_config.php

post-install:
	@${SED} -e 's|%%HOSTNAME%%|${HOSTNAME}|; s|%%B2EVO_URL%%|${B2EVO_URL}|' \
		${PKGMESSAGE}

.include <bsd.port.post.mk>
