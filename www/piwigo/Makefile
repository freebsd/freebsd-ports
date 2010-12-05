# New ports collection makefile for:   phpwebgallery
# Date created:        8 June 2008
# Whom:                Goran Lowkrantz <glz@hidden-powers.com>
#
# $FreeBSD$
#

PORTNAME=	piwigo
PORTVERSION=	2.1.5
CATEGORIES=	www
MASTER_SITES=	http://piwigo.org/download/dlcounter.php?code=${PORTVERSION}&/ \
		SF/${PORTNAME}/Piwigo/${PORTVERSION}

MAINTAINER=	glz@hidden-powers.com
COMMENT=	A PHP based Web Gallery

FETCH_BEFORE_ARGS=	-o ${DISTDIR}/${DISTFILES}
NO_BUILD=	yes
USE_PHP=	calendar ctype dom exif filter gd gettext hash iconv json \
		mbstring mcrypt mhash mysql openssl pcre pdf pdo posix recode \
		session simplexml sockets spl tokenizer xml xmlreader xmlwriter zlib
USE_ZIP=	yes
WANT_PHP_WEB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	COPYING README_en.txt README_fr.txt
SUB_FILES=	pkg-deinstall pkg-message

post-extract:
	@${CHMOD} -R o-w ${WRKSRC}

do-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/doc/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}/
	@cd ${WRKSRC}/tools/ && ${COPYTREE_SHARE} . ${EXAMPLESDIR}/
.endif

# Own version with our owners and we also have to protect if
# galleries is read-only.

	@${RM} -fr ${WRKSRC}/doc/ ${WRKSRC}/tools/
	@${MV} ${WRKSRC}/local/ ${WRKSRC}/local.sample/
	@${TOUCH} ${WRKSRC}/upload/.keepme
	@cd ${WRKSRC}/ && ${COPYTREE_WWW} . ${WWWDIR}
	@${CHMOD} ugo+rwx ${WWWDIR}/_data/

post-install:
	@${CAT} ${PKGMESSAGE}

COPYTREE_WWW=	\
	${SH} -c '(${FIND} -d $$0 $$2 | ${CPIO} -dumpl $$1 >/dev/null 2>&1) && \
		${CHOWN} -fR ${WWWOWN}:${WWWGRP} $$1 && \
		${FIND} -d $$0 $$2 -type d -exec ${CHMOD} -f 755 $$1/{} \; && \
		${FIND} -d $$0 $$2 -type f -exec ${CHMOD} -f 644 $$1/{} \;' --

.include <bsd.port.mk>
