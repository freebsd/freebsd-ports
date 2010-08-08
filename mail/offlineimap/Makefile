# New ports collection makefile for: offlineimap
# Date created:		08 Aug 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	offlineimap
DISTVERSION=	6.2.0.2
DISTVERSIONSUFFIX=-0-g6b1cb5e
CATEGORIES=	mail python
MASTER_SITES=	http://download.github.com/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sergei
DISTNAME=	jgoerzen-${PORTNAME}-debian-${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Powerful IMAP/Maildir synchronization and reader support

WRKSRC=		${WRKDIR}/jgoerzen-${PORTNAME}-0f1a667
SUB_FILES=	pkg-message

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=${PORTVERSION:R}

DOCS=		COPYING COPYRIGHT FAQ.html UPGRADING
EXAMPLES=	offlineimap.conf offlineimap.conf.minimal

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
