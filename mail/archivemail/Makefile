# New ports collection makefile for:	archivemail
# Date created:		2002/04/02
# Whom:			Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	archivemail
PORTVERSION=	0.7.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Archive or delete mail older than N days

USE_PYTHON=	yes
NO_BUILD=	yes

DOCS=		CHANGELOG FAQ README TODO archivemail.sgml
EXAMPLES=	test_archivemail.py examples/archivemail_all

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/archivemail ${PREFIX}/bin/archivemail
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
