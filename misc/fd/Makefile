# New ports collection makefile for:    FD
# Version required:     1.01h
# Date created:         20 Feb 1996
# Whom:                 Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $Id: $
#

DISTNAME=	FD-1.01
PKGNAME=	fd-1.01h
CATEGORIES=	misc
# The original distribution (NetNews articles) can be found at following site.
#  site= ftp://skylark.ics.es.osaka-u.ac.jp/pub/FDclone/
#  files= FD-1.01 FD-1.01g FD-1.01h
# Here ,we use already decoded archive for convenience.
MASTER_SITES=	ftp://ftp.hipecs.hokudai.ac.jp/pub/unix/FD/ \
		ftp://ftp.cc.saga-u.ac.jp/pub/fj.sources/FD/

PATCHFILES=	FD-1.01g.patch.gz FD-1.01h.patch.gz
PATCH_SITES=	${MASTER_SITES}

MAINTAINER=	nobu@psrc.isac.co.jp

ALL_TARGET=	goal
INSTALL_TARGET=	install
MANLANG=	ja_JP.EUC
MAN1=		fd.1

do-configure:
	cd ${WRKSRC} ; make config

post-install:
	@strip ${PREFIX}/bin/fd

.include <bsd.port.mk>
