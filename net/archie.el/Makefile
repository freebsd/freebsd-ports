# New ports collection makefile for:	archie.el
# Date created:		99/10/6
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	archie.el	
PORTVERSION=	3.0.2	
CATEGORIES=	net elisp
# I don't know the master site
MASTER_SITES=	ftp://ftp.cis.ohio-state.edu/pub/elisp-lisp/interfaces/ \
		ftp://ftp.kddlabs.co.jp/.2/gnu-attic/ohio-elisp/interfaces/
DISTNAME=	archie.el
EXTRACT_SUFX=	.Z

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS=	archie:${PORTSDIR}/net/archie

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp
XELISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-extract:
	${RM} -rf ${WRKDIR}
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
