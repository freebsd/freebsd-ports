# New ports collection makefile for:	css-mode.el
# Date created:		21 October 1999
# Whom:			Shigeyuki Fukushima <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	css-mode-elisp
PORTVERSION=	0.11
CATEGORIES=	www elisp
MASTER_SITES=	http://www.garshol.priv.no/download/software/css-mode/
DISTNAME=	css-mode.el

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A CSS(Cascade Style Sheet) editing mode for Emacsen

EXTRACT_SUFX=	# empty
DISTFILES=	${DISTNAME} doco.html
DIST_SUBDIR=	css-mode

EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

# install-directory for Emacs
ELISP_SUBDIR=	share/emacs/site-lisp
# install-directory for XEmacs
XELISP_SUBDIR=	lib/xemacs/site-lisp
# install-directory for document
CSSMODE_DOCDIR=	share/doc/css-mode

PLIST_SUB=	ELISP_SUBDIR=${ELISP_SUBDIR} XELISP_SUBDIR=${XELISP_SUBDIR} \
		CSSMODE_DOCDIR=${CSSMODE_DOCDIR}

do-install:
	${MKDIR} ${PREFIX}/${ELISP_SUBDIR}
	${INSTALL_DATA} ${_DISTDIR}/${DISTNAME} ${PREFIX}/${ELISP_SUBDIR}/
# For XEmacs
	${MKDIR} ${PREFIX}/${XELISP_SUBDIR}
	${INSTALL_DATA} ${_DISTDIR}/${DISTNAME} ${PREFIX}/${XELISP_SUBDIR}/

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${CSSMODE_DOCDIR}
	@${INSTALL_DATA} ${_DISTDIR}/doco.html ${PREFIX}/${CSSMODE_DOCDIR}/css-mode-doc.html
.endif

.include <bsd.port.mk>
