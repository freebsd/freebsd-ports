# New ports collection makefile for:   uim-el-xemacs21-mule
# Date created:        24 December 2005
# Whom:                MANTANI Nobutaka <nobutaka@freebsd.org>
#
# $FreeBSD$
#

MAINTAINER=	nobutaka@FreeBSD.org

COMMENT=	XEmacs lisp for uim input method library

CONFLICTS=	uim-el-emacs23-[0-9]* \
	uim-el-emacs22-[0-9]* \
	uim-el-emacs21-[0-9]*

CONFIGURE_ARGS=--enable-emacs --with-lispdir=${LOCALBASE}/${EMACS_PACKAGESDIR}/lisp

EMACS_PORT_NAME=xemacs21-mule
EMACS_PACKAGESDIR=	lib/xemacs/site-packages

PLIST=		${.CURDIR}/pkg-plist
DESCR=		${.CURDIR}/pkg-descr
PLIST_SUB=	EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR}

MASTERDIR=	${.CURDIR}/../uim-el

.include "${MASTERDIR}/Makefile"
