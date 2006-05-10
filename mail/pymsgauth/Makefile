# New ports collection makefile for:	pymsgauth
# Date created:		12 Aug 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	pymsgauth
PORTVERSION=	2.1.0
CATEGORIES=	mail python
MASTER_SITES=	http://pyropus.ca/software/pymsgauth/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Automatically process qsecretary confirmation requests

USE_PYTHON=	yes

SUB_FILES=	pkg-message

DOCS=		BUGS CHANGELOG pymsgauth.txt pymsgauth.html
EXAMPLES=	pymsgauthrc-example

do-build:
	${REINPLACE_CMD} -e 's,#!/usr/bin/python,#!/usr/bin/env python,' \
	 	${WRKSRC}/pymsgauth-*
	${RM} ${WRKSRC}/pymsgauth-*.bak

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${WRKSRC}/pymsgauth-* ${DATADIR}
	${LN} -sf ${DATADIR}/pymsgauth-* ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
