# New ports collection makefile for:    xpbiff-youbin
# Version required:     1.27
# Date created:         7 April 1997
# Whom:                 Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
#
# $Id$
#

# can't use PORTSDIR here, since we haven't included bsd.port.mk
PKGNAME=	xpbiff-youbin-1.27

MAINTAINER=	sanpei@yy.cs.keio.ac.jp

YOUBIN=		yes
FILESDIR=	${.CURDIR}/../xpbiff/files
PATCHDIR=	${.CURDIR}/../xpbiff/patches
PLIST=		${.CURDIR}/../xpbiff/pkg/PLIST

RUN_DEPENDS=	youbin:${PORTSDIR}/mail/youbin

.include "${.CURDIR}/../xpbiff/Makefile"
