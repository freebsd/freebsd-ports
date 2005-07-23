# New ports collection makefile for: Mew (for mule)
# Date created:		17 January 1998
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Message interface to Emacs Window for mule

# This is a slave port.
MASTERDIR=	${.CURDIR}/../mew

BROKEN=		"Incorrect pkg-plist (removes directories not installed by this port)"
DEPRECATED=	"${BROKEN}"
EXPIRATION_DATE=2005-09-22

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
