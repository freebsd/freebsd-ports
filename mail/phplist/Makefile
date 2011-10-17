# New ports collection makefile for:	phplist
# Date created:			August 24 2007
# Whom:				Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$

PORTNAME=	phplist
PORTVERSION=	2.10.17
CATEGORIES=	mail www
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@bsdserwis.com
COMMENT=	A full-featured open-source newsletter manager

USE_PHP=	session mysql imap xml pcre zlib
NO_BUILD=	yes

PORTDOCS=	BUGS INSTALL NEWS PEOPLE README README.batches \
		README.bounces README.commandline README.passwords \
		README.repetition README.rssfeeds README.security \
		README.usertables TODO UPGRADE VERSION phplist.sql

SUB_FILES=	phplist pkg-message

post-extract:
	@${MV} ${WRKSRC}/public_html/lists/config/config.php ${WRKSRC}/public_html/lists/config/config.php-dist

do-install:
	@cd ${WRKSRC}/public_html/&&${COPYTREE_SHARE} . ${WWWDIR}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/
	@${INSTALL_SCRIPT} ${WRKDIR}/phplist ${PREFIX}/bin
	@${ECHO_CMD} @exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR:S|^${PREFIX}/|%D/|} >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
