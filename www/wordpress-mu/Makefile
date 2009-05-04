# New ports collection makefile for:   wordpress-mu
# Date created:                2004-12-19
# Whom:                        Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	wordpress-mu
PORTVERSION=	2.7.1
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	www
MASTER_SITES=	http://mu.wordpress.org/
DISTNAME=	latest

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Multi-user version of the famous WordPress blogging application

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PHP=	mysql pcre xml
NO_BUILD=	YES
WANT_PHP_WEB=	YES
SUB_FILES=	pkg-message

pre-everything::
.ifdef WORDPRESSMU
	@${ECHO_CMD} "WORDPRESSMU is depreciated, use WWWDIR instead!"
	@${ECHO_CMD} "${PKGNAME} installs in WWWDIR=${WWWDIR}"
.endif

do-install:
	@${MKDIR} ${WWWDIR}
	@${CHMOD} 755 ${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR}/)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
