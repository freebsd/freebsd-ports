# New ports collection makefile for: offlineimap
# Date created:		08 Aug 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	offlineimap
PORTVERSION=	4.0.0
CATEGORIES=	mail python
MASTER_SITES=	http://gopher.quux.org:70/devel/offlineimap/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Powerful IMAP/Maildir synchronization and reader support

RUN_DEPENDS=	${TKINTER}:${PORTSDIR}/x11-toolkits/py-tkinter

WRKSRC=		${WRKDIR}/${PORTNAME}
PKGMESSAGE=	${WRKDIR}/pkg-message

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
TKINTER=	${PYTHON_SITELIBDIR}/_tkinter.so

MAN1=		offlineimap.1
DOCS=		COPYRIGHT ChangeLog UPGRADING manual.html manual.pdf \
		manual.ps manual.txt
EXAMPLES=	offlineimap.conf offlineimap.conf.minimal

post-install:
	${INSTALL_MAN} ${WRKSRC}/offlineimap.1 ${MANPREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
	@${SED} -e 's!%%EXAMPLESDIR%%!${EXAMPLESDIR}!' \
		${MASTERDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
