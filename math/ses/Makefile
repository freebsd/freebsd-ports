# New ports collection makefile for:	ses
# Date created:			11 February 2005
# Whom:				dd
#
# $FreeBSD$
#

PORTNAME=	ses
PORTVERSION=	031130
CATEGORIES=	math elisp
MASTER_SITES=	http://home.comcast.net/~jyavner/ses/
DISTNAME=	ses21-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dd@FreeBSD.org
COMMENT=	Simple Emacs Spreadsheet

BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs
RUN_DEPENDS=	emacs:${PORTSDIR}/editors/emacs

DOC_FILES=	ses-example.ses ses-readme.txt \
		ses-coverage.el testcover.el unsafep-coverage.el
DOC_DIR=	share/doc/ses
ELISP_FILES=	ses.el unsafep.el
ELISP_DIR=	share/emacs/site-lisp/ses

PLIST_FILES=	${ELISP_FILES:S/^/${ELISP_DIR}\//} \
		${ELISP_FILES:S/^/${ELISP_DIR}\//S/$/c/} \
		${DOC_FILES:S/^/${DOC_DIR}\//}
PLIST_DIRS=	${ELISP_DIR} ${DOC_DIR}

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		"Does not build on ia64"
.endif

do-build:
.for __f in ${ELISP_FILES}
	cd ${WRKSRC} && echo '(setq load-path (cons "." load-path)) \
			      (batch-byte-compile)' | \
			emacs -batch -q -l /dev/stdin ${__f} 2> /dev/null
.endfor

do-install:
	${MKDIR} ${PREFIX}/${ELISP_DIR}
.for __f in ${ELISP_FILES}
	${INSTALL_DATA} ${WRKSRC}/${__f} ${WRKSRC}/${__f}c \
		${PREFIX}/${ELISP_DIR}
.endfor
	${MKDIR} ${PREFIX}/${DOC_DIR}
.for __f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${__f} ${PREFIX}/${DOC_DIR}
.endfor

.include <bsd.port.post.mk>
