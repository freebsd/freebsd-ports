PORTNAME=	css-mode-elisp
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	www elisp
MASTER_SITES=	http://www.garshol.priv.no/download/software/css-mode/
DISTNAME=	css-mode.el

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CSS(Cascade Style Sheet) editing mode for Emacsen

EXTRACT_SUFX=	# empty
DISTFILES=	${DISTNAME} doco.html
DIST_SUBDIR=	css-mode

EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

# install-directory for Emacs
ELISP_SUBDIR=	share/emacs/site-lisp
# install-directory for document
DOCSDIR=	${PREFIX}/share/doc/css-mode

PLIST_SUB=	ELISP_SUBDIR=${ELISP_SUBDIR}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ELISP_SUBDIR}
	${INSTALL_DATA} ${_DISTDIR}/${DISTNAME} ${STAGEDIR}${PREFIX}/${ELISP_SUBDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/doco.html ${STAGEDIR}${DOCSDIR}/css-mode-doc.html

.include <bsd.port.mk>
