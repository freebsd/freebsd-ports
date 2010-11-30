# New ports collection makefile for:   phpwebgallery
# Date created:        8 June 2008
# Whom:                Goran Lowkrantz <glz@hidden-powers.com>
#
# $FreeBSD$
#

PORTNAME=	piwigo
PORTVERSION=	2.1.3
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Piwigo/${PORTVERSION}

MAINTAINER=	glz@hidden-powers.com
COMMENT=	A PHP based Web Gallery

USE_PHP=	filter hash json pcre calendar sockets exif recode openssl posix \
		gettext simplexml spl mbstring mysql xmlwriter zlib gd pdo dom \
		iconv tokenizer mhash session ctype xmlreader xml mcrypt pdf
WANT_PHP_WEB=	yes

NO_BUILD=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

SUB_FILES+=	pkg-message pkg-deinstall

PORTDOCS=	COPYING README_en.txt README_fr.txt

post-extract:
	@${CHMOD} -R o-w ${WRKSRC}

do-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}
	@cd ${WRKSRC}/tools && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

# Own version with our owners and we also have to protect if 
# galleries is read-only.

	@cd ${WRKSRC} && ${RM} -rf doc
	@cd ${WRKSRC} && ${RM} -rf tools
	@cd ${WRKSRC} && ${MV} local local.sample
	@cd ${WRKSRC} && ${COPYTREE_WWW} . ${WWWDIR}
	@${CHMOD} 0777 ${WWWDIR}/_data

post-install:
	@${CAT} ${PKGMESSAGE}

COPYTREE_WWW= ${SH} -c '(${FIND} -d $$0 $$2 | ${CPIO} -dumpl $$1 >/dev/null \
                                    2>&1) && \
                                    ${CHOWN} -fR ${WWWOWN}:${WWWGRP} $$1 && \
                                     ${FIND} -d $$0 $$2 -type d -exec ${CHMOD} -f 755 $$1/{} \; && \
                                     ${FIND} -d $$0 $$2 -type f -exec ${CHMOD} -f 644 $$1/{} \;' --

.include <bsd.port.mk>
