# New ports collection makefile for: offlineimap
# Date created:		08 Aug 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	offlineimap
PORTVERSION=	3.99.15
CATEGORIES=	mail python
MASTER_SITES=	http://gopher.quux.org:70/devel/offlineimap/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sergei@kolobov.com
COMMENT=	Powerful IMAP/Maildir synchronization and reader support

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

MAN1=		offlineimap.1
DOCS=		manual.html manual.pdf manual.ps manual.txt
EXAMPLES=	offlineimap.conf offlineimap.conf.minimal

post-install:
	${INSTALL_MAN} ${WRKSRC}/offlineimap.1 ${MANPREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
	@${SED} -e 's!%%EXAMPLESDIR%%!${EXAMPLESDIR}!' < ${PKGMESSAGE}

.include <bsd.port.mk>
