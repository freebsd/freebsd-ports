# New ports collection makefile for:    FD
# Version required:     1.03g
# Date created:         20 Feb 1996
# Whom:                 Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $Id: Makefile,v 1.9 1998/02/07 16:26:15 max Exp $
#

DISTNAME=	FD-1.03g
PKGNAME=	fd-1.03g
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.ics.es.osaka-u.ac.jp/pub/FDclone/

MAINTAINER=	nobu@psrc.isac.co.jp

MANLANG=	ja
MAN1=		fd.1
MAKE_ENV=	LANG=${MANLANG}

post-install:
	${MKDIR} ${PREFIX}/share/doc/fd
	${INSTALL_DATA} ${FILESDIR}/Guarant ${PREFIX}/share/doc/fd

.include <bsd.port.mk>
