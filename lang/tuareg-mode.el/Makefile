# New ports collection makefile for:	tuareg-mode
# Date created:			28 October 2004
# Whom:				dd
#
# $FreeBSD$
#

PORTNAME=	tuareg-mode
PORTVERSION=	1.41.5
CATEGORIES=	lang elisp
MASTER_SITES=	http://www-rocq.inria.fr/~acohen/tuareg/mode/

MAINTAINER=	dd@FreeBSD.org
COMMENT=	Emacs major mode for editing Caml code

BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs20
RUN_DEPENDS=	emacs:${PORTSDIR}/editors/emacs20

DOC_FILES=	README HISTORY append-tuareg.el custom-tuareg.el
DOC_DIR=	share/doc/tuareg-mode
ELISP_FILES=	camldebug.el tuareg.el
ELISP_DIR=	share/emacs/site-lisp

PLIST_FILES=	${ELISP_FILES:S/^/${ELISP_DIR}\//} \
		${ELISP_FILES:S/^/${ELISP_DIR}\//S/$/c/} \
		${DOC_FILES:S/^/${DOC_DIR}\//}
PLIST_DIRS=	${DOC_DIR}

do-build:
.for __f in ${ELISP_FILES}
	cd ${WRKSRC} && echo '(setq load-path (cons "." load-path)) \
			      (batch-byte-compile)' | \
			emacs -batch -q -l /dev/stdin ${__f} 2> /dev/null
.endfor

do-install:
.for __f in ${ELISP_FILES}
	${INSTALL_DATA} ${WRKSRC}/${__f} ${WRKSRC}/${__f}c \
		${PREFIX}/${ELISP_DIR}
.endfor
	${MKDIR} ${PREFIX}/${DOC_DIR}
.for __f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${__f} ${PREFIX}/${DOC_DIR}
.endfor

.include <bsd.port.mk>
