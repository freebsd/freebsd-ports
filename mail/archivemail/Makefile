# New ports collection makefile for:	archivemail
# Date created:		2002/04/02
# Whom:			Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	archivemail
PORTVERSION=	0.6.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Search mailbox files and archive or delete mail older than N days

USE_PYTHON=	yes
NO_BUILD=	yes

DOCS=		CHANGELOG FAQ Makefile README TODO archivemail.sgml
EXAMPLES=	test_archivemail.py examples/archivemail_all

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/archivemail.py ${PREFIX}/bin/archivemail
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
