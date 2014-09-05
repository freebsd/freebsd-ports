# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	phpmailer2
PORTVERSION=	2.0.4
CATEGORIES=	mail
MASTER_SITES=	SF/phpmailer/phpmailer%20for%20php4/PHPMailer%20v${PORTVERSION}%20for%20PHP4
DISTNAME=	PHPMailer_v${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full Featured Email Transfer Class for PHP4

LICENSE=	LGPL21

CONFLICTS=	phpmailer-5*

USES=		dos2unix
NO_BUILD=	yes
USE_PHP=	pcre
SUB_FILES=	pkg-message
OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in class.phpmailer.php class.pop3.php class.smtp.php
	@${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DATADIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/language
	@${INSTALL_DATA} ${WRKSRC}/language/* ${STAGEDIR}${DATADIR}/language
	@${MKDIR} ${STAGEDIR}${DATADIR}/test
	@${INSTALL_DATA} ${WRKSRC}/test/* ${STAGEDIR}${DATADIR}/test
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in README LICENSE
	@${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor
	@${CP} -R ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}
	@${CP} -R ${WRKSRC}/phpdocs/* ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
