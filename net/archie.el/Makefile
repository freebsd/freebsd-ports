# New ports collection makefile for:	archie.el
# Date created:		99/10/6
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	archie.el
PORTVERSION=	3.0.2
CATEGORIES=	net elisp
MASTER_SITES=	#
DISTNAME=	archie.el
EXTRACT_SUFX=	.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A mock-interface to Archie for Emacs

DEPRECATED=	"master site disappeared"
EXPIRATION_DATE=2005-06-01

RUN_DEPENDS=	archie:${PORTSDIR}/net/archie

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
XELISPDIR=	${PREFIX}/lib/xemacs/site-lisp

PLIST_FILES=	share/emacs/site-lisp/archie.el \
		lib/xemacs/site-lisp/archie.el
PLIST_DIRS=	lib/xemacs/site-lisp

do-extract:
	${MKDIR} ${WRKDIR}
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${DISTFILES} \
		> ${WRKDIR}/${PKGNAME}

do-install:
	${MKDIR} ${ELISPDIR}
	${INSTALL_DATA} ${WRKDIR}/${PKGNAME} ${ELISPDIR}/archie.el
# For XEmacs
	${MKDIR} ${XELISPDIR}
	${LN} -sf ${ELISPDIR}/archie.el ${XELISPDIR}

.include <bsd.port.mk>
