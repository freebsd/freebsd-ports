# New ports collection makefile for:	safe-rm
# Date created:		2008-09-13
# Whom:			Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	safe-rm
PORTVERSION=	0.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	Wrapper around the rm command to prevent accidental deletions

USE_PERL5_RUN=	yes

NO_BUILD=	yes

PORTDOCS=	COPYING Changes README
PLIST_FILES=	bin/safe-rm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/safe-rm ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
