# $FreeBSD$

PORTNAME=	phpmailer
PORTVERSION=	6.1.7
DISTVERSIONPREFIX=	v
CATEGORIES=	mail
PKGNAMESUFFIX=	6

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Full Featured Email Transfer Class for PHP

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe php

CONFLICTS_INSTALL=	phpmailer

PORTSCOUT=	limit:^6\.

CPE_VENDOR=	phpmailer_project

USE_GITHUB=	yes
GH_ACCOUNT=	PHPMailer
GH_PROJECT=	PHPMailer

NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in Exception.php PHPMailer.php POP3.php SMTP.php
	${INSTALL_DATA} ${WRKSRC}/src/$f ${STAGEDIR}${DATADIR}
.endfor

post-install-NLS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/language
	${INSTALL_DATA} ${WRKSRC}/language/* ${STAGEDIR}${DATADIR}/language

.include <bsd.port.mk>
