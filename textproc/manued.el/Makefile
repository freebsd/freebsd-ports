# New ports collection makefile for:   manued.el
# Date created:                26 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	manued.el
PORTVERSION=	0.9.5
CATEGORIES=	textproc elisp
MASTER_SITES=	http://www.mpi-sb.mpg.de/~hitoshi/otherprojects/manued/arcs/ \
		http://www.archi.is.tohoku.ac.jp/~yamauchi/otherprojects/manued/arcs/
DISTNAME=	manued-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs minor mode for manued proofreading method

NO_BUILD=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-install:
	${MKDIR} ${EMACSLISPDIR}
	${INSTALL_DATA} ${WRKSRC}/manued.el ${EMACSLISPDIR}
	${MKDIR} ${XEMACSLISPDIR}
	${LN} -sf ${EMACSLISPDIR}/manued.el ${XEMACSLISPDIR}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${EXAMPLESDIR}
	${MKDIR} ${DOCSDIR}
.for i in ChangeLog README README.EUC doc/* tutorial
	${CP} -R ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
