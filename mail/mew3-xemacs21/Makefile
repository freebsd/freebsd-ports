# New ports collection makefile for: Mew (for xemacs21)
# Date created:		17 January 1998
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

MAINTAINER=	kiri@FreeBSD.org
COMMENT=	Message interface to Emacs Window (version 3) for xemacs21

# Mew major version
MEW_MAJOR_VER=	3

# This is a slave port.
MASTERDIR=	${.CURDIR}/../mew${MEW_MAJOR_VER}

EMACS_PACKAGESDIR=	${EMACS_LIBDIR}/site-packages

# set emacs port
EMACS_PORT_NAME=	xemacs21

SCRIPTS_ENV=	EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR}
MAKE_ENV=	EMACS_LIBDIR=${EMACS_LIBDIR} XEMACS_PKGNAME=${XEMACS_PKGNAME} \
		XEMACS_PKGVER=${XEMACS_PKGVER} \
		EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR}
PLIST_SUB=	EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR}
INFO=

# use pkg-* files in ${.CURDIR} except for pkg-message
PKGDIR=		${.CURDIR}
PKGMESSAGE=	${MASTERDIR}/pkg-message

# how to install
ALL_TARGET=	package info
INSTALL_TARGET=	install-package

# for xemacs package
XEMACS_PKGNAME=	mew${MEW_MAJOR_VER}
XEMACS_PKGVER=	3.00

.include "${MASTERDIR}/Makefile"
