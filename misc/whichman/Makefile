PORTNAME=	whichman
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://main.linuxfocus.org/~guido.socher/ \
		http://main.linuxfocus.org/~guido/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Approximate matching utilities to search for manpages and files
WWW=		http://main.linuxfocus.org/~guido/ #whichman

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/ftff bin/ftwhich bin/whichman \
		share/man/man1/ftff.1.gz share/man/man1/ftwhich.1.gz \
		share/man/man1/whichman.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/man:||g' ${WRKSRC}/whichman.c

do-install:
.for name in ftff ftwhich whichman
	${INSTALL_PROGRAM} ${WRKSRC}/${name} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man1/${name}.1 ${STAGEDIR}${PREFIX}/share/man/man1
.endfor

.include <bsd.port.mk>
