# New ports collection makefile for:	diff-mode for Emacsen
# Date created:		18 Apr 2000
# Whom:			OKAZAKI Tetsurou
#
# $FreeBSD$
#

PORTNAME=	diff-mode.el
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	textproc elisp
MASTER_SITES=	ftp://rum.cs.yale.edu/pub/monnier/misc/
DISTNAME=	diff-mode-${PORTVERSION}.el
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	okazaki@FreeBSD.org
COMMENT=	A mode for viewing/editing context diffs in Emacsen

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-install:
	${MKDIR} ${EMACSLISPDIR}
	${INSTALL_DATA} ${_DISTDIR}/${DISTNAME} ${EMACSLISPDIR}/diff-mode.el
	${MKDIR} ${XEMACSLISPDIR}
	${LN} -sf ${EMACSLISPDIR}/diff-mode.el ${XEMACSLISPDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
