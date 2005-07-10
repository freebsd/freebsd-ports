# New ports collection makefile for:    mplex
# Date created:         Wed Jul 31 20:54:54 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mplex
PORTVERSION=	1.1
CATEGORIES=	multimedia
MASTER_SITES=	http://ftp.yars.free.net/pub/software/unix/X11/mpeg/ \
		http://www.netsw.org/graphic/movie/mpeg/mplex/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiplexes MPEG component streams into system layers

CONFLICTS=	mjpegtools-*

MAN1=		mplex.1
PLIST_FILES=	bin/mplex

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplex ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/mplex.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
