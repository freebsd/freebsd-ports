# Created by: Zhen REN <bg1tpt@gmail.com>
# $FreeBSD$

PORTNAME=	phpmailer
PORTVERSION=	5.2.6
CATEGORIES=	mail
MASTER_SITES=	https://github.com/Synchro/PHPMailer/archive/
DISTNAME=	v${PORTVERSION}

MAINTAINER=	joehorn@gmail.com
COMMENT=	Full Featured Email Transfer Class for PHP

LICENSE=	LGPL3

WRKSRC=		${WRKDIR}/PHPMailer-${PORTVERSION}

FETCH_ARGS=	-Fpr
USE_DOS2UNIX=	yes
NO_BUILD=	yes
USE_PHP=	yes

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${DATADIR}
.for f in class.phpmailer.php class.pop3.php class.smtp.php composer.json
	@${INSTALL_DATA} ${WRKSRC}/$f ${DATADIR}
.endfor
.for d in extras language test
	@${MKDIR} ${DATADIR}/$d
	@${INSTALL_DATA} ${WRKSRC}/$d/* ${DATADIR}/$d
.endfor
	@${CP} -R ${WRKSRC}/test_script ${DATADIR}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in changelog.md README.md LICENSE
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
