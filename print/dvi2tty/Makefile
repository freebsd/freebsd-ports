# New ports collection makefile for:   dvi2tty
# Date created:		17th February 1997
# Whom:			Joel Sutton <jsutton@bbcon.com.au>
#
# $FreeBSD$
#

PORTNAME=	dvi2tty
PORTVERSION=	5.3.4
CATEGORIES=	print
MASTER_SITES=	http://www.mesa.nl/pub/dvi2tty/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dvi-file previewer for text only devices

CONFLICTS=	ja-dvi2tty-[0-9]*

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${STRIP}"

MAN1=		disdvi.1 dvi2tty.1
PLIST_FILES=	bin/disdvi bin/dvi2tty

do-install:
.for name in disdvi dvi2tty
	${INSTALL_PROGRAM} ${WRKSRC}/${name} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${name}.1 ${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
