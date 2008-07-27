# New ports collection makefile for: offlineimap
# Date created:		08 Aug 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	offlineimap
PORTVERSION=	6.0.0
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful IMAP/Maildir synchronization and reader support

.if !defined(WITHOUT_X11)
RUN_DEPENDS=	${TKINTER}:${PORTSDIR}/x11-toolkits/py-tkinter
TKINTER=	${PYTHON_SITELIBDIR}/_tkinter.so
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}
PKGMESSAGE=	${WRKDIR}/pkg-message

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCS=		COPYING COPYRIGHT FAQ.html README UPGRADING
EXAMPLES=	offlineimap.conf offlineimap.conf.minimal

post-install:
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
