# New ports collection makefile for:   manued.el
# Date created:                26 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	manued.el
PORTVERSION=	0.9.4
CATEGORIES=	textproc elisp
MASTER_SITES=	http://www.mpi-sb.mpg.de/~hitoshi/projects/manued/arcs/ \
		http://www.archi.is.tohoku.ac.jp/~yamauchi/projects/manued/arcs/
DISTFILES=	${EL}
EXTRACT_ONLY=	# empty
.if !defined(NOPORTDOCS)
DISTFILES+=	${EXTRACT_ONLY}
EXTRACT_ONLY+=	manued-0.9.3${EXTRACT_SUFX}
.endif

MAINTAINER=	fuyuki@mj.0038.net

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/manued-0.9.3

EL=		manued-${PORTVERSION}-cur.el
EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-install:
	${MKDIR} ${EMACSLISPDIR}
	${INSTALL_DATA} ${DISTDIR}/${EL} ${EMACSLISPDIR}/manued.el
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
