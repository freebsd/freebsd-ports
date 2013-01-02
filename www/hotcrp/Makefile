# $FreeBSD$

PORTNAME=	hotcrp
PORTVERSION=	2.55
CATEGORIES=	www
MASTER_SITES=	http://www.read.seas.harvard.edu/~kohler/hotcrp/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Web based conference management software

RUN_DEPENDS=	${PEARDIR}/Mail.php:${PORTSDIR}/mail/pear-Mail \
		${PEARDIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime \
		pdftohtml:${PORTSDIR}/textproc/pdftohtml \
		zip:${PORTSDIR}/archivers/zip

USE_PHP=	mysql gd session ctype
USE_MYSQL=	server

PEARDIR=	${PREFIX}/share/pear

WWWDOCROOT?=	www

NO_BUILD=	yes
SUB_FILES=	pkg-message

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

do-install:
	${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}
	@cd ${WRKSRC} && \
	    ${FIND} -s -d . -type f -print | \
		${SED} -e "s#^\.#${WWWDIR_REL}#" >> ${TMPPLIST}
	@cd ${WRKSRC} && \
	    ${FIND} -s -d . -type d  -print | \
		${SED} -e "s#^\.#@dirrm ${WWWDIR_REL}#" >> ${TMPPLIST}

.include <bsd.port.mk>
