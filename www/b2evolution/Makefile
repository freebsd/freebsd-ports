# New ports collection makefile for:	b2evo
# Date created:		2005-04-16
# Whom:			chinsan <chinsan@mail20000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	b2evolution
PORTVERSION=	0.9.0.12
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	evocms
DISTNAME=	${PORTNAME}-${PORTVERSION}-${B2EVO_DATE}${EXTRACT_SUFX} \
		${PATCH_VER}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}-${B2EVO_DATE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multilingual, multiuser, multi-blog engine

PATCH_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

USE_ZIP=	YES

PATCH_VER=	xmlrpc_fix_112
B2EVO_DATE?=	2005-05-06
USE_PHP=	mysql pcre session xml xmlrpc
PHP4_PORT?=	www/mod_php4
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

post-patch:
	@cd ${WRKSRC} \
		&& ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${PATCH_VER}${EXTRACT_SUFX}
	@${MV} -f ${WRKSRC}/${PATCH_VER}/b2evocore/* ${WRKSRC}/blogs/b2evocore
	@${RM} -rf ${WRKSRC}/${PATCH_VER}

pre-install:
	@cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|${B2EVO_DIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${B2EVO_DIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${B2EVO_DIR} >> ${PLIST}

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
