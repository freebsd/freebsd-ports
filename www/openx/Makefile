# New ports collection makefile for:	openx
# Date created:		13 March 2008
# Whom:			Piotr Rybicki <meritus@innervision.pl>
#
# $FreeBSD$
#

PORTNAME=	openx
PORTVERSION=	2.4.4
CATEGORIES=	www
MASTER_SITES=	http://download.openx.org/

MAINTAINER=	meritus@innervision.pl
COMMENT=	Free, opensource ad server in PHP

USE_ZIP=	yes
NO_BUILD=	yes
SUB_LIST+=	PKGNAME=${PKGNAME}
SUB_FILES+=	pkg-message
PORTDOCS=	INSTALL.txt LICENSE.txt POLICY.txt README.txt \
		RELEASE_NOTES.txt UPGRADE.txt KNOWN_ISSUES.txt TRANSLATIONS.txt
EXTDOCS=	KNOWN_ISSUES.txt TRANSLATIONS.txt

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	xml pcre zlib mysql ftp
.endif

post-extract:
	@${INSTALL} -d ${WRKDIR}/docs
	@cd ${WRKSRC}/docs && ${MV} ${EXTDOCS} ${WRKSRC}/
	@cd ${WRKSRC} && ${MV} ${PORTDOCS} ${WRKDIR}/docs/
	@cd ${WRKSRC} && ${RM} -rf docs

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' >> ${TMPPLIST}

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKDIR}/docs && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
