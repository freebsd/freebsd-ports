# New ports collection makefile for: offlineimap
# Date created:		08 Aug 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	offlineimap
DISTVERSION=	6.3.3
CATEGORIES=	mail python
MASTER_SITES=	http://download.github.com/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sergei
DISTNAME=	nicolas33-${PORTNAME}-v${DISTVERSION}-0-g3b09695

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Powerful IMAP/Maildir synchronization and reader support

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/nicolas33-${PORTNAME}-cf325d5
SUB_FILES=	pkg-message

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCS=		*.rst docs/*.rst
EXAMPLES=	offlineimap.conf offlineimap.conf.minimal

pre-fetch:
	# get github download ticket
	if [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
		${FETCH_BINARY} -s >/dev/null \
			http://github.com/nicolas33/${PORTNAME}/tarball/v${DISTVERSION}; \
	fi

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
