# New ports collection makefile for:	archivemail
# Date created:		2002/04/02
# Whom:			Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	archivemail
PORTVERSION=	0.9.0
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Archive or delete mail older than N days

USE_PYTHON=	2.5+
NO_BUILD=	yes

DOCS=		CHANGELOG FAQ NEWS README TODO
EXAMPLES=	test_archivemail examples/archivemail_all

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/archivemail ${PREFIX}/bin/archivemail
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${EXAMPLES} ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
