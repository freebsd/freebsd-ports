# New ports collection makefile for: Mew (for emacs20)
# Date created:		17 January 1998
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Message interface to Emacs Window for emacs20

# This is a slave port.
MASTERDIR=	${.CURDIR}/../mew

# set emacs port
EMACS_PORT_NAME=emacs20

# target name for make build and install
ALL_TARGET=	all jinfo #info
INSTALL_TARGET=	install install-info install-jinfo install-etc

# use pkg-* files in ${.CURDIR}
PKGDIR=		${.CURDIR}

.include "${MASTERDIR}/Makefile"
