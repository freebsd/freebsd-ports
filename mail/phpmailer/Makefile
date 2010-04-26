# New ports collection makefile for:	phpmailer
# Date created:		6 April 2007
# Whom:			Zhen REN <bg1tpt@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	phpmailer
PORTVERSION=	5.1
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20for%20php5_6/PHPMailer%20v${PORTVERSION}
DISTNAME=	PHPMailer_v${DISTVERSION}

MAINTAINER=	joehorn@gmail.com
COMMENT=	Full Featured Email Transfer Class for PHP

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_DOS2UNIX=	yes
NO_BUILD=	yes
IGNORE_WITH_PHP=	4
USE_PHP=	pcre

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${DATADIR}
.for f in class.phpmailer.php class.pop3.php class.smtp.php
	@${INSTALL_DATA} ${WRKSRC}/$f ${DATADIR}
.endfor
	@${MKDIR} ${DATADIR}/language
	@${INSTALL_DATA} ${WRKSRC}/language/* ${DATADIR}/language
	@${MKDIR} ${DATADIR}/test
	@${INSTALL_DATA} ${WRKSRC}/test/* ${DATADIR}/test
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in aboutus.html changelog.txt README LICENSE
	@${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
.endfor
	@${CP} -R ${WRKSRC}/docs/* ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
