# New ports collection makefile for:	eventum
# Date created:		2006-01-06
# Whom:			Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	phproxy
PORTVERSION=	0.5b2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	poxy
DISTNAME=	poxy-${DISTVERSION}

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	PHP based web proxy

NO_BUILD=	YES
WANT_PHP_WEB=	YES
USE_ZIP=	YES
USE_PHP=	YES
PLIST_SUB+=	PHPROXY=${PHPROXY}
PHPROXY=	www/${PORTNAME}
EXTRACT_AFTER_ARGS+=	-d ${WRKSRC}

DOCFILES=	ChangeLog.txt LICENSE.txt README.txt TODO.txt
ROOTFILES=	index.inc.php index.php style.css

do-install:
	-${MKDIR} ${PREFIX}/${PHPROXY}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${PHPROXY}
	@(cd ${WRKSRC} && ${CP} ${ROOTFILES} ${PREFIX}/${PHPROXY}/)
	@${CHMOD} 755 ${PREFIX}/${PHPROXY}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
