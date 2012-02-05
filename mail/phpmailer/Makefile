# New ports collection makefile for:	phpmailer
# Date created:		6 April 2007
# Whom:			Zhen REN <bg1tpt@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	phpmailer
PORTVERSION=	5.2.1
CATEGORIES=	mail
MASTER_SITES=	http://${PORTNAME}.apache-extras.org.codespot.com/files/
DISTNAME=	PHPMailer_${PORTVERSION}

MAINTAINER=	joehorn@gmail.com
COMMENT=	Full Featured Email Transfer Class for PHP

LICENSE=	LGPL3

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_ZIP=	yes
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
.for d in extras language test
	@${MKDIR} ${DATADIR}/$d
	@${INSTALL_DATA} ${WRKSRC}/$d/* ${DATADIR}/$d
.endfor
	@${CP} -R ${WRKSRC}/test_script ${DATADIR}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in changelog.txt README LICENSE
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
