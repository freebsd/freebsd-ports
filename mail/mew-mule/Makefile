# New ports collection makefile for: Mew (for mule)
# Date created:		17 January 1998
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../mew

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Message interface to Emacs Window for mule

BROKEN=		"Not work on this emacs port"
EXPIRATION_DATE=	2006-04-10

# set emacs port
USE_EMACS=	yes
EMACS_PORT_NAME=mule

# target name for make build and install
ALL_TARGET=	all # info jinfo
INSTALL_TARGET=	install install-info install-jinfo install-etc

# set *-setupel.el
EMACS_SETUPEL=	${PORTNAME}-setup.el

# use pkg-* files in ${.CURDIR}
PKGDIR=		${.CURDIR}
INFO=		mew.jis

.include "${MASTERDIR}/Makefile"
