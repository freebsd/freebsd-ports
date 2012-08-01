# New ports collection makefile for:	tuareg-mode
# Date created:			28 October 2004
# Whom:				dd
#
# $FreeBSD$
#

PORTNAME=	tuareg-mode
PORTVERSION=	1.45.6
PORTREVISION=	10
PORTEPOCH=	1
CATEGORIES=	lang elisp
MASTER_SITES=	http://www-rocq.inria.fr/~acohen/tuareg/mode/

MAINTAINER=	michael.grunewald@laposte.net
COMMENT=	Emacs major mode for editing Caml code

USE_EMACS=	yes
USE_BZIP2=	yes

DOC_FILES=	README HISTORY append-tuareg.el custom-tuareg.el
DOC_DIR=	share/doc/tuareg-mode
ELISP_FILES=	camldebug.el tuareg.el

PLIST_FILES=	${ELISP_FILES:S/^/${EMACS_SITE_LISPDIR}\//} \
		${ELISP_FILES:S/^/${EMACS_SITE_LISPDIR}\//S/$/c/} \
		${DOC_FILES:S/^/${DOC_DIR}\//}
PLIST_DIRS=	${DOC_DIR}

# Note: append-tuareg.el and custom-tuareg.el are example files,
# they are thus considered part of the documentation.

#
# Operations
#

# We do provide our own build and install procedures, instead of using
# mainstream author's one.

do-build:
.for tuareg_mode_f in ${ELISP_FILES}
	cd ${WRKSRC} &&\
	  ${EMACS_CMD} -batch -q -l ${SCRIPTDIR}/batch-compile.el ${tuareg_mode_f}
.endfor

do-install:
.for tuareg_mode_f in ${ELISP_FILES}
	${INSTALL_DATA} ${WRKSRC}/${tuareg_mode_f} ${WRKSRC}/${tuareg_mode_f}c \
		${PREFIX}/${EMACS_SITE_LISPDIR}
.endfor
	${MKDIR} ${PREFIX}/${DOC_DIR}
.for tuareg_mode_f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${tuareg_mode_f} ${PREFIX}/${DOC_DIR}
.endfor

.include <bsd.port.mk>
