# New ports collection makefile for: trac-email2trac
# Date created:                      May 18 2007
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	email2trac
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	ftp://ftp.sara.nl/pub/outgoing/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	Convert email to trac tickets

BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_PYTHON=	2.3+

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/delete_spam.py ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/email2trac.py ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/run_email2trac ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/email2trac.conf ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
