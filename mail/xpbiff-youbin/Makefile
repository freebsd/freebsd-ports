# New ports collection makefile for:    xpbiff-youbin
# Date created:         7 April 1997
# Whom:                 Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
#
# $FreeBSD$
#

# can't use PORTSDIR here, since we haven't included bsd.port.mk

PORTNAME=	xpbiff-youbin
PORTVERSION=	1.27

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A replacement for xbiff that handles popup window with mail header

YOUBIN=		yes
MASTERDIR=	${.CURDIR}/../xpbiff
PKGDIR=		${.CURDIR}
PLIST=		${MASTERDIR}/pkg-plist

RUN_DEPENDS=	youbin:${PORTSDIR}/mail/youbin

.include	"${MASTERDIR}/Makefile"
