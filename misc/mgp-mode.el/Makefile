# New ports collection makefile for:	mgp-mode.el
# Version required:	1.22
# Date created:		99/10/6
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	mgp-mode.el
PKGNAME=	mgp-mode.el-1.22
CATEGORIES=	misc elisp
MASTER_SITES=	ftp://TypeHack.aial.hiroshima-u.ac.jp/pub/Emacs/MagicPoint/
EXTRACT_SUFX=	# empty

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS=	mgp:${PORTSDIR}/misc/magicpoint

EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
XELISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-install:
	${MKDIR} ${ELISPDIR}
	${INSTALL_DATA} ${_DISTDIR}/${DISTFILES} ${ELISPDIR}
# For XEmacs
	${MKDIR} ${XELISPDIR}
	${LN} -sf ${ELISPDIR}/${DISTFILES} ${XELISPDIR}

.include <bsd.port.mk>
