# New ports collection makefile for: Mew (for xemacs21-mule)
# Date created:		17 January 1998
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Message interface to Emacs Window for xemacs21-mule

# This is a slave port.
MASTERDIR=	${.CURDIR}/../mew

IGNORE=		hangs during build

# Set emacs port
EMACS_PORT_NAME=	xemacs21-mule
EMACS_PACKAGESDIR=	${EMACS_LIBDIR}/site-packages

# Has common part
EMACS_COMMON_PORT=	YES

SCRIPTS_ENV=	EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR}
MAKE_ENV=	EMACS_LIBDIR=${EMACS_LIBDIR} XEMACS_PKGNAME=${XEMACS_PKGNAME} \
		XEMACS_PKGVER=${XEMACS_PKGVER} \
		EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR}
PLIST_SUB=	EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR}

# use pkg-* files in ${.CURDIR}
PKGDIR=		${.CURDIR}

# how to install
ALL_TARGET=	package info jinfo
INSTALL_TARGET=	install-mule-package

# for xemacs package
XEMACS_PKGNAME=	mew
XEMACS_PKGVER=	1.16
MEW_DOCDIR=	${EMACS_PACKAGESDIR}/etc/${XEMACS_PKGNAME}

.include "${MASTERDIR}/Makefile"
