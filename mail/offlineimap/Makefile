# New ports collection makefile for: offlineimap
# Date created:		08 Aug 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	offlineimap
DISTVERSION=	6.4.0
CATEGORIES=	mail python
MASTER_SITES=	http://download.github.com/ \
		http://dist.codelabs.ru/fbsd/offlineimap/ \
		LOCAL/rea/offlineimap
DISTNAME=	${GITHUB_USER}-${PORTNAME}-v${DISTVERSION}-${GITHUB_VER_SUFX}

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Powerful IMAP/Maildir synchronization and reader support

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LICENSE_FILE_GPLv2=${WRKSRC}/COPYING

OPTIONS=	HTMLDOCS "Generate HTML documentation" Off

WRKSRC=		${WRKDIR}/${GITHUB_USER}-${PORTNAME}-${GITHUB_SRC_SUFX}
SUB_FILES=	pkg-message

GITHUB_USER=	nicolas33
GITHUB_VER_SUFX=	0-gc1120c9
GITHUB_SRC_SUFX=	b1bff15

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCS=		Changelog.rst README.rst SubmittingPatches.rst \
		docs/FAQ.rst docs/INSTALL.rst docs/MANUAL.rst docs/UPGRADE.rst
EXAMPLES=	offlineimap.conf offlineimap.conf.minimal
PORTDOCS=	${DOCS:T}
PORTEXAMPLES=	${EXAMPLES}

.include <bsd.port.options.mk>

.if !defined(NOPORTDOCS) && defined(WITH_HTMLDOCS)
BUILD_DEPENDS+=	rst2html:${PORTSDIR}/textproc/py-docutils
DOCS:=		${DOCS} ${DOCS:M*.rst:S/.rst$/.html/}
.endif

# This is needed for pkg-message.in
.if defined(NOPORTEXAMPLES)
SUB_LIST+=	PORTEXAMPLES="@comment "
.else
SUB_LIST+=	PORTEXAMPLES=""
.endif

pre-fetch:
	# get github download ticket
	if [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
		${FETCH_BINARY} -s >/dev/null \
			http://github.com/${GITHUB_USER}/${PORTNAME}/tarball/v${DISTVERSION}; \
	fi

post-build:
.if !defined(NOPORTDOCS) && defined(WITH_HTMLDOCS)
.for r in ${DOCS:M*.rst}
	rst2html ${WRKSRC}/${r} ${WRKSRC}/${r:R}.html
.endfor
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
