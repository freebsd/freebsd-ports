# New ports collection makefile for:	hotcrp
# Date created:		26 April 2011
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hotcrp
PORTVERSION=	2.45
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.cs.ucla.edu/~kohler/hotcrp/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A web based conference management software

RUN_DEPENDS=	${PEARDIR}/Mail.php:${PORTSDIR}/mail/pear-Mail \
		${PEARDIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime \
		pdftohtml:${PORTSDIR}/textproc/pdftohtml

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
	@${FIND} -s -d ${WWWDIR} -type f -print | \
		${SED} -e "s#${PREFIX}/##g" >> ${TMPPLIST}
	@${FIND} -s -d ${WWWDIR} -type d  -print | \
		${SED} -E -e "s#${PREFIX}/#@dirrm #g" >> ${TMPPLIST}

.include <bsd.port.mk>
