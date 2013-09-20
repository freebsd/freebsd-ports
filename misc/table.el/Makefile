# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	table.el
PORTVERSION=	1.5.54
CATEGORIES=	misc elisp
MASTER_SITES=	SF/table/table/${PORTVERSION}
DISTNAME=	table-${PORTVERSION}.el.gz
EXTRACT_SUFX=	# empty

MAINTAINER=	dsh@vlink.ru
COMMENT=	Create and edit WYSIWYG text based embedded tables in Emacs

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

NO_STAGE=	yes
do-extract:
	${MKDIR} ${WRKDIR}
	${GUNZIP_CMD} -c ${DISTDIR}/${DISTNAME} > ${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${EMACSLISPDIR}
	${MKDIR} ${XEMACSLISPDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME} ${EMACSLISPDIR}
	${LN} -sf ${EMACSLISPDIR}/${PORTNAME} ${XEMACSLISPDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
