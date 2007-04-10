# New ports collection makefile for:	phpmailer
# Date created:		6 April 2007
# Whom:			Zhen REN <bg1tpt@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	phpmailer
PORTVERSION=	1.73
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	bg1tpt@gmail.com
COMMENT=	Full Featured Email Transfer Class for PHP

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_DOS2UNIX=	yes
NO_BUILD=	yes
USE_PHP=	pcre

PKGMESSAGE=	${WRKDIR}/pkg-message
MSG_SRC=	${FILESDIR}/pkg-message

MSG_SUB=	DATADIR=${DATADIR} LOCALBASE=${LOCALBASE}

do-install:
	@${MKDIR} ${DATADIR}
.for f in class.phpmailer.php class.smtp.php
	@${INSTALL_DATA} ${WRKSRC}/$f ${DATADIR}
.endfor
	@${MKDIR} ${DATADIR}/language
	@${INSTALL_DATA} ${WRKSRC}/language/* ${DATADIR}/language
	@${MKDIR} ${DATADIR}/test
	@${INSTALL_DATA} ${WRKSRC}/test/* ${DATADIR}/test
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in README LICENSE
	@${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
.endfor
	@${CP} -R ${WRKSRC}/docs/* ${DOCSDIR}
	@${CP} -R ${WRKSRC}/phpdoc/* ${DOCSDIR}
.endif

post-install:
	@${SED} ${MSG_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} ${MSG_SRC} > \
		${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
