# New ports collection makefile for:	css-mode.el
# Date created:		21 October 1999
# Whom:			Shigeyuki Fukushima <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	css-mode-elisp
PORTVERSION=	0.10
CATEGORIES=	www elisp
MASTER_SITES=	http://www.stud.ifi.uio.no/~lmariusg/download/
DISTNAME=	css-mode.el

MAINTAINER=	shige@FreeBSD.org

EXTRACT_SUFX=	# empty
DISTFILES=	${DISTNAME} css-mode-doc.html
DIST_SUBDIR=	css-mode

EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

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
	@${INSTALL_DATA} ${_DISTDIR}/css-mode-doc.html ${PREFIX}/${CSSMODE_DOCDIR}/
.endif

.include <bsd.port.mk>
