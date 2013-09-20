# Created by: Andrey Slusar <anrays@gmail.com>
# $FreeBSD$

PORTNAME=	boxquote.el
PORTVERSION=	1.18
CATEGORIES=	misc elisp
MASTER_SITES=	http://www.davep.org/emacs/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quote text with a semi-box in Emacs/XEmacs

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

PLIST_FILES=	share/emacs/site-lisp/${PORTNAME} lib/xemacs/site-lisp/${PORTNAME}
PLIST_DIRS=	lib/xemacs/site-lisp lib/xemacs

NO_STAGE=	yes
do-install:
	${MKDIR} ${EMACSLISPDIR}
	${MKDIR} ${XEMACSLISPDIR}
	${INSTALL_DATA} ${_DISTDIR}/${DISTNAME} ${EMACSLISPDIR}/${PORTNAME}
	${LN} -sf ${EMACSLISPDIR}/${PORTNAME} ${XEMACSLISPDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
