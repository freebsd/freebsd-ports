# New ports collection makefile for:    FD
# Version required:     1.01
# Date created:         20 Feb 1996
# Whom:                 Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $Id$
#

DISTNAME=       FD-1.01
PKGNAME=        fd-1.01
CATEGORIES+=	misc
MASTER_SITES=	ftp://ftp.mei.co.jp/free/others/Utilities/

MAINTAINER=	nobu@psrc.isac.co.jp

ALL_TARGET=	goal
PATCH_STRIP= -p0 -o fdrc
INSTALL_TARGET=	install catman

do-configure:
	cd ${WRKSRC} ; make config

post-install:
	rm -f /usr/local/man/man1/fd.1.gz /usr/local/man/cat1/fd.1.gz
	gzip -9 /usr/local/man/man1/fd.1 /usr/local/man/cat1/fd.1

.include <bsd.port.mk>
