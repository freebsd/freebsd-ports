# New ports collection makefile for:   getmail
# Date created:        06 May 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	getmail
PORTVERSION=	2.3.9
PORTREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	http://www.qcc.sk.ca/~charlesc/software/getmail-2.0/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old-versions

MAINTAINER=	anders@hack.org

USE_PYTHON=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes

DOCS=		CHANGELOG docs.txt faq.txt getmail.txt

post-patch:
	@${REINPLACE_CMD} -e 's!/usr/lib/getmail!${DATADIR}!' \
		-e 's!`which python`!${PYTHON_CMD}!' ${WRKSRC}/getmail

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/getmail ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/getmailrc-example ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
