# New ports collection makefile for: Mew (for mule)
# Date created:		17 January 1998
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

MAINTAINER=	kiri@FreeBSD.org

# This is a slave port.
MASTERDIR=	${.CURDIR}/../mew

# set emacs port
EMACS_PORT_NAME=mule

# target name for make build and install
ALL_TARGET=	all # info jinfo
INSTALL_TARGET=	install install-info install-jinfo install-etc

# set *-setupel.el
EMACS_SETUPEL=	${PORTNAME}-setup.el

# use pkg-* files in ${.CURDIR}
PKGDIR=		${.CURDIR}

.include "${MASTERDIR}/Makefile"
