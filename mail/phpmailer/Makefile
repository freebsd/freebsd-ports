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

USE_DOS2UNIX=	yes
NO_BUILD=	yes
USE_PHP=	yes

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in class.phpmailer.php class.pop3.php class.smtp.php composer.json
	@${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DATADIR}
.endfor
.for d in extras language test
	@${MKDIR} ${STAGEDIR}${DATADIR}/$d
	@${INSTALL_DATA} ${WRKSRC}/$d/* ${STAGEDIR}${DATADIR}/$d
.endfor
	@${CP} -R ${WRKSRC}/test_script ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in changelog.md README.md LICENSE
	@${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
	@${CP} -R ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
