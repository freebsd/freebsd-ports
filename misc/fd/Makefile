# New ports collection makefile for:    FD
# Version required:     1.01
# Date created:         20 Feb 1996
# Whom:                 Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $Id: Makefile,v 1.3 1996/11/17 09:05:43 obrien Exp $
#

DISTNAME=       FD-1.01
PKGNAME=        fd-1.01
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.mei.co.jp/free/others/Utilities/

MAINTAINER=	nobu@psrc.isac.co.jp

ALL_TARGET=	goal
PATCH_STRIP=	-p0 -o fdrc
MANLANG=	ja_JP.EUC
MAN1=		fd.1

do-configure:
	cd ${WRKSRC} ; make config

.include <bsd.port.mk>
