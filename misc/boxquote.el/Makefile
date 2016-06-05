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

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

PLIST_FILES=	share/emacs/site-lisp/${PORTNAME} lib/xemacs/site-lisp/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${EMACSLISPDIR}
	@${MKDIR} ${STAGEDIR}${XEMACSLISPDIR}
	${INSTALL_DATA} ${_DISTDIR}/${DISTNAME} ${STAGEDIR}${EMACSLISPDIR}/${PORTNAME}
	${LN} -sf ${EMACSLISPDIR}/${PORTNAME} ${STAGEDIR}${XEMACSLISPDIR}

.include <bsd.port.mk>
