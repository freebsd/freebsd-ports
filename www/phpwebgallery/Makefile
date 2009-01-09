# New ports collection makefile for:   phpwebgallery
# Date created:        8 June 2008
# Whom:                Goran Lowkrantz <glz@hidden-powers.com>
#
# $FreeBSD$
#

PORTNAME=	phpwebgallery
PORTVERSION=	1.7.3
CATEGORIES=	www
MASTER_SITES=	http://download.gna.org/phpwebgallery/release/1.7/${PORTVERSION}/

MAINTAINER=	glz@hidden-powers.com
COMMENT=	A PHP based Web Gallery

USE_PHP=	filter hash json pcre calendar sockets exif recode openssl posix \
		gettext simplexml spl mbstring mysql xmlwriter zlib gd pdo dom \
		iconv tokenizer mhash session ctype xmlreader xml mcrypt pdf
WANT_PHP_WEB=	yes

NO_BUILD=	yes
USE_BZIP2=	yes

SUB_FILES+=	pkg-message pkg-deinstall

PORTDOCS=	COPYING ChangeLog README_en.txt README_fr.txt
PORTEXAMPLES=	config_local.inc.php create_listing_file.php fill_history.pl index.php \
		local-layout.css metadata.php prototype.js ws.htm
CFGFILE_MYSQL=	mysql.inc.php

post-extract:
	@${CHMOD} -R o-w ${WRKSRC}

do-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}
	@cd ${WRKSRC}/tools && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
	@cd ${WRKSRC} && ${RM} -rf doc
	@cd ${WRKSRC} && ${RM} -rf tools
	@cd ${WRKSRC}/include && ${MV} ${CFGFILE_MYSQL} ${CFGFILE_MYSQL}.sample
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${WWWDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644' >> ${TMPPLIST}
	@${FIND} ${WWWDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${FIND} ${WWWDIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755' >> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
