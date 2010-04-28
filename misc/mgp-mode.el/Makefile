# New ports collection makefile for:	mgp-mode.el
# Date created:		99/10/6
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mgp-mode.el
PORTVERSION=	1.30
CATEGORIES=	misc elisp
MASTER_SITES=	ftp://TypeHack.aial.hiroshima-u.ac.jp/pub/Emacs/MagicPoint/ \
		http://freebsd.unixfreunde.de/sources/
DISTFILES=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A mode of Emacs for editing MagicPoint files

#RUN_DEPENDS=	mgp:${PORTSDIR}/misc/magicpoint

EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
XELISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-install:
	${MKDIR} ${ELISPDIR}
	${INSTALL_DATA} ${_DISTDIR}/${DISTFILES} ${ELISPDIR}
# For XEmacs
	${MKDIR} ${XELISPDIR}
	${LN} -sf ${ELISPDIR}/${DISTFILES} ${XELISPDIR}

.include <bsd.port.mk>
