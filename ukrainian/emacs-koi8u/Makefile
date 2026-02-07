PORTNAME=	koi8u
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	ukrainian elisp
MASTER_SITES=	# none
PKGNAMEPREFIX=	emacs-
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KOI8-U coding system for [X]Emacs

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp

PLIST_FILES=	share/emacs/site-lisp/ukr-koi8u.el

do-install:
	${MKDIR} ${STAGEDIR}${EMACSLISPDIR}
	${INSTALL_DATA} ${FILESDIR}/ukr-koi8u.el ${STAGEDIR}${EMACSLISPDIR}/ukr-koi8u.el

.include <bsd.port.mk>
