# New ports collection makefile for:	emacs-koi8u.el
# Date created:				Mon Dec 12 23:19:55 UTC 2005
# Whom:					Andrey Slusar <anray@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	koi8u
PORTVERSION=	1.0
CATEGORIES=	ukrainian elisp
MASTER_SITES=	# none
PKGNAMEPREFIX=	emacs-
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KOI8-U coding system for [X]Emacs.

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

PLIST_FILES=	share/emacs/site-lisp/ukr-koi8u.el lib/xemacs/site-lisp/ukr-koi8u.el
PLIST_DIRS=	lib/xemacs/site-lisp lib/xemacs

do-install:
	${MKDIR} ${EMACSLISPDIR}
	${MKDIR} ${XEMACSLISPDIR}
	${INSTALL_DATA} ${FILESDIR}/ukr-koi8u.el ${EMACSLISPDIR}/ukr-koi8u.el
	${LN} -sf ${EMACSLISPDIR}/ukr-koi8u.el ${XEMACSLISPDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
