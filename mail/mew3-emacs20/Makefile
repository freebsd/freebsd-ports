# New ports collection makefile for: Mew (for xemacs21)
# Date created:		21 November 1997
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	Message interface to Emacs Window (version 3) for emacs20

DEPRECATED=	emacs20 and related ports are obsolete; please use a more recent version
EXPIRATION_DATE=	2007-08-19

# Mew major version
MEW_MAJOR_VER?=	3

LATEST_LINK=	mew3-emacs20

# This is a slave port.
MASTERDIR=	${.CURDIR}/../mew${MEW_MAJOR_VER}

# use pkg-* files in ${.CURDIR} except for pkg-message
PKGDIR=		${.CURDIR}
PKGMESSAGE=	${MASTERDIR}/pkg-message

# set emacs port
USE_EMACS=	yes
EMACS_PORT_NAME=	emacs20

.include "${MASTERDIR}/Makefile"
