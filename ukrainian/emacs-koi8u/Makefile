# Created by: Andrey Slusar <anray@FreeBSD.org>
# $FreeBSD$

PORTNAME=	koi8u
PORTVERSION=	1.0
CATEGORIES=	ukrainian elisp
MASTER_SITES=	# none
PKGNAMEPREFIX=	emacs-
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KOI8-U coding system for [X]Emacs

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

PLIST_FILES=	share/emacs/site-lisp/ukr-koi8u.el lib/xemacs/site-lisp/ukr-koi8u.el

do-install:
	${MKDIR} ${STAGEDIR}${EMACSLISPDIR}
	${MKDIR} ${STAGEDIR}${XEMACSLISPDIR}
	${INSTALL_DATA} ${FILESDIR}/ukr-koi8u.el ${STAGEDIR}${EMACSLISPDIR}/ukr-koi8u.el
	${LN} -sf ${EMACSLISPDIR}/ukr-koi8u.el ${STAGEDIR}${XEMACSLISPDIR}

.include <bsd.port.mk>
