# New ports collection makefile for:	b2evo
# Date created:		2005-04-16
# Whom:			chinsan <chinsan@mail20000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	b2evolution
PORTVERSION=	0.9.0.12
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	evocms
DISTNAME=	${PORTNAME}-${PORTVERSION}-${B2EVO_DATE} \
		xmlrpc_fix_111
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}-${B2EVO_DATE}

# Maintainership available: drop me a line if interested :p
MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	A multilingual, multiuser, multi-blog engine

USE_ZIP=	YES

B2EVO_DATE?=	2005-05-06
USE_PHP=	mysql pcre session xml
PHP4_PORT?=	www/mod_php4
NO_BUILD=	YES
WANT_PHP_WEB=	YES

TMPDIR?=	${PORTNAME}
WRKSRC=		${WRKDIR}/${TMPDIR}

.if !defined(B2EVO_DIR)
pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define B2EVO_DIR to override default of '${B2EVO_DIR}'."
	@${ECHO_MSG} ""
.endif

WWWDOCROOT?=	www/data
B2EVO_URL?=	b2evo
WWWOWN?=	www
WWWGRP?=	www
B2EVO_DIR?=	${WWWDOCROOT}/${B2EVO_URL}
PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

post-extract:
	cd ${WRKSRC}/blogs/b2evocore \
		&& ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/xmlrpc_fix_111${EXTRACT_SUFX}

pre-install:
	cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|${B2EVO_DIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${B2EVO_DIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${B2EVO_DIR} >> ${PLIST}

do-install:
	-${MKDIR} ${PREFIX}/${B2EVO_DIR}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${B2EVO_DIR}
	@${CHMOD} 755 ${PREFIX}/${B2EVO_DIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${B2EVO_DIR}

post-install:
	@${SED} -e 's|%%B2EVO_URL%%|${B2EVO_URL}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
