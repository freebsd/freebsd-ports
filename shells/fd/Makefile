# New ports collection makefile for:    FD
# Version required:     1.03
# Date created:         20 Feb 1996
# Whom:                 Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $Id$
#

DISTNAME=	FD-1.03a
PKGNAME=	fd-1.03a
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.ics.es.osaka-u.ac.jp/pub/FDclone/

MAINTAINER=	nobu@psrc.isac.co.jp

MANLANG=	ja_JP.EUC
MAN1=		fd.1
MAKE_ENV=	LANG=${MANLANG}

post-install:
	${MKDIR} ${PREFIX}/share/doc/fd
	${INSTALL_DATA} ${FILESDIR}/Guarant ${PREFIX}/share/doc/fd

.include <bsd.port.mk>
