# New ports collection makefile for:	dokuwiki
# Date created:		2005-04-10
# Whom:			chinsan <chinsan@mail2000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	dokuwiki
PORTVERSION=	20050507
PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	http://www.splitbrain.org/Programming/PHP/DokuWiki/
DISTNAME=	${PORTNAME}-2005-05-07
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple and easy to use wiki, no database required

USE_PHP=	pcre session xml zlib
PHP4_PORT?=	www/mod_php4
NO_BUILD=	YES
WANT_PHP_WEB=	YES

WWWDOCROOT?=	www/data-dist
DOKUWIKIURL?=	${PORTNAME}
WWWOWN?=	www
WWWGRP?=	www
DOKUWIKIDIR?=	${WWWDOCROOT}/${DOKUWIKIURL}
PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

pre-install:
	cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|${DOKUWIKIDIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${DOKUWIKIDIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} ${DOKUWIKIDIR}/changes.log >> ${PLIST} \
		&& ${ECHO_CMD} "@unexec rmdir %D/${DOKUWIKIDIR} 2>/dev/null || true">> ${PLIST}

do-install:
	# Data files
	-${MKDIR} ${PREFIX}/${DOKUWIKIDIR}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${DOKUWIKIDIR}
	@${CHMOD} 755 ${PREFIX}/${DOKUWIKIDIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${DOKUWIKIDIR}
	# Setup the correct permissions
	@${TOUCH} ${PREFIX}/${DOKUWIKIDIR}/changes.log
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${DOKUWIKIDIR}/changes.log
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${DOKUWIKIDIR}/data
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${DOKUWIKIDIR}/media
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${DOKUWIKIDIR}/attic

post-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%WWWDOCROOT%%|${WWWDOCROOT}|' \
		-e 's|%%DOKUWIKIURL%%|${DOKUWIKIURL}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
