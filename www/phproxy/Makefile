# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	phproxy
PORTVERSION=	0.5b2
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	SF/poxy/PHProxy/0.5%20beta%202
DISTNAME=	poxy-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP based web proxy

NO_BUILD=	YES
WANT_PHP_WEB=	YES
USES=		zip
USE_PHP=	ctype pcre
EXTRACT_AFTER_ARGS+=	-d ${WRKSRC}

DOCFILES=	ChangeLog.txt LICENSE.txt README.txt TODO.txt

NO_STAGE=	yes
do-install:

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
.endif

	@${RM} ${WRKSRC}/*.txt
	${MKDIR} ${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}/)
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
