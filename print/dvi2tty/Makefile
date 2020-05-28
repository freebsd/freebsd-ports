# Created by: Joel Sutton <jsutton@bbcon.com.au>
# $FreeBSD$

PORTNAME=	dvi2tty
PORTVERSION=	5.3.4
CATEGORIES=	print
MASTER_SITES=	http://www.mesa.nl/pub/dvi2tty/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DVI file previewer for text only devices

CONFLICTS=	ja-dvi2tty-[0-9]*

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${STRIP}"

PLIST_FILES=	bin/disdvi bin/dvi2tty \
		man/man1/disdvi.1.gz \
		man/man1/dvi2tty.1.gz

do-install:
.for name in disdvi dvi2tty
	${INSTALL_PROGRAM} ${WRKSRC}/${name} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${name}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
