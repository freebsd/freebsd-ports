# New ports collection makefile for: offlineimap
# Date created:		08 Aug 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	offlineimap
PORTVERSION=	3.99.3
CATEGORIES=	mail python
MASTER_SITES=	http://gopher.quux.org:70/devel/offlineimap/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	nbm@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

MAN1=		offlineimap.1
DOCS=		manual.html manual.pdf manual.ps manual.txt

post-install:
	${INSTALL_MAN} ${WRKSRC}/offlineimap.1 ${MANPREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/offlineimap.conf ${EXAMPLESDIR}
	@${SED} -e 's!__EXAMPLESDIR__!${EXAMPLESDIR}!' ${PKGMESSAGE}

.include <bsd.port.mk>
