# New ports collection makefile for:	Wanderlust (for xemacs21-mule)
# Date created:		7 Apr 1999
# Whom: 		MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../../mail/wanderlust

COMMENT=	Yet another message interface on Emacsen

EMACS_PORT_NAME=	xemacs21-mule
EMACS_PACKAGESDIR=	lib/xemacs/site-packages
MANIFEST=		MANIFEST.wl

MIMEUI_PORT_NAME=	${MIMEUI_PRODUCT}-${EMACS_PORT_NAME}

EMACS_W3M_PORT_NAME=	emacs-w3m-${EMACS_PORT_NAME}
EMACS_W3M_LISP_FILE=	${LOCALBASE}/${EMACS_PACKAGESDIR}/lisp/w3m/shimbun.el

ALL_TARGET=	package
INSTALL_TARGET=	install-package
UTILSDIR=	${EMACS_PACKAGESDIR}/lisp/wl
STARTUPDIR=	${EMACS_PACKAGESDIR}/lisp/wl

.include "${MASTERDIR}/Makefile"
