# New ports collection makefile for:	whitespace.el
# Date created:		6 November 2002
# Whom:			Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$
#

PORTNAME=	whitespace.el
PORTVERSION=	3.0
CATEGORIES=	textproc elisp
MASTER_SITES=	http://www.dsmit.com/lisp/
DISTNAME=	whitespace.el
EXTRACT_SUFX=
DIST_SUBDIR=    ${PORTNAME}-${PORTVERSION}

MAINTAINER=	stolz@i2.informatik.rwth-aachen.de

EXTRACT_AFTER_ARGS=	| ${CAT} >${WRKDIR}/${DISTNAME}

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

EMACSLISPDIR=   ${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=  ${PREFIX}/lib/xemacs/site-lisp

do-install:
	${MKDIR} ${EMACSLISPDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} ${EMACSLISPDIR}/${DISTNAME}
	${MKDIR} ${XEMACSLISPDIR}
	${LN} -sf ${EMACSLISPDIR}/${DISTNAME} ${XEMACSLISPDIR}

.include <bsd.port.mk>
