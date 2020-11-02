# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rd-mode.el
PORTVERSION=	0.6.38
PORTREVISION=	1
CATEGORIES=	textproc ruby elisp
MASTER_SITES=	# none
PKGNAMEPREFIX=	ruby-	# not ${RUBY_PKGNAMEPREFIX} since this is not version specific
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs lisp module for editing RD files

BUILD_DEPENDS=	${NONEXISTENT}:textproc/ruby-rdtool:patch

USE_RUBY=	yes

WRKSRC=		${WRKDIR}/utils
NO_BUILD=	yes

ELISP_FILES=	rd-mode.el

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp

RUBY_ELISPDIR=	${PREFIX}/lib/ruby/elisp

PLIST_SUB+=	RUBY_ELISPDIR=${RUBY_ELISPDIR}

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf `cd ${.CURDIR}/../ruby-rdtool; ${MAKE} -V WRKSRC`/utils ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${RUBY_ELISPDIR}/
	@${MKDIR} ${STAGEDIR}${EMACSLISPDIR}/
.for f in ${ELISP_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_ELISPDIR}/
	${LN} -sf ${RUBY_ELISPDIR}/${f} ${STAGEDIR}${EMACSLISPDIR}/
.endfor

.include <bsd.port.mk>
