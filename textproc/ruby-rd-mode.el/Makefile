# New ports collection makefile for:	ruby-rd-mode.el
# Date created:		12 May 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rd-mode.el
PORTVERSION=	0.6.16
CATEGORIES=	textproc ruby elisp
MASTER_SITES=	# none
PKGNAMEPREFIX=	ruby-	# not ${RUBY_PKGNAMEPREFIX} since this is not version specific
DISTFILES=	# none

MAINTAINER=	knu@FreeBSD.org
COMMENT=	An Emacs lisp module for editing RD files

BUILD_DEPENDS=	${NONEXISTENT}:${.CURDIR}/../ruby-rdtool:patch

USE_RUBY=	yes

WRKSRC=		${WRKDIR}/utils
NO_BUILD=	yes

ELISP_FILES=	rd-mode.el

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf `cd ${.CURDIR}/../ruby-rdtool; ${MAKE} -V WRKSRC`/utils ${WRKSRC}

do-install:
	${MKDIR} ${XEMACSLISPDIR}/
.for f in ${ELISP_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_ELISPDIR}/
	${LN} -sf ${RUBY_ELISPDIR}/${f} ${EMACSLISPDIR}/
	${LN} -sf ${RUBY_ELISPDIR}/${f} ${XEMACSLISPDIR}/
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
