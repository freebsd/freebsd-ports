PORTNAME=	dvi2tty
PORTVERSION=	5.3.4
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.mesa.nl/pub/dvi2tty/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DVI file previewer for text only devices
WWW=		https://www.mesa.nl/

CONFLICTS=	texlive-base # bin/disdvi bin/dvi2tty

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${STRIP}"

PLIST_FILES=	bin/disdvi bin/dvi2tty \
		share/man/man1/disdvi.1.gz \
		share/man/man1/dvi2tty.1.gz

do-install:
.for name in disdvi dvi2tty
	${INSTALL_PROGRAM} ${WRKSRC}/${name} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${name}.1 ${STAGEDIR}${PREFIX}/share/man/man1
.endfor

.include <bsd.port.mk>
