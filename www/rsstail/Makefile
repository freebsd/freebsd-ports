# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rsstail
PORTVERSION=	2.1
CATEGORIES=	www
MASTER_SITES=	https://www.vanheusden.com/rsstail/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple RSS monitor

LICENSE=	GPLv2

LIB_DEPENDS=	libmrss.so:textproc/libmrss

MAKE_ENV=	bindir="${PREFIX}/bin" mandir="${MANPREFIX}/man/man1"

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
USES=		iconv tar:tgz

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|^DEBUG=|#DEBUG=| ; \
		 s|^LDFLAGS=-liconv_hook |LDFLAGS+=| ; \
		 s|^CFLAGS=-O3 |CFLAGS+=| ; \
		 s|\([[:space:]]\)\($$(..ndir)\)|\1$$(DESTDIR)\2|g ; \
		 /bindir/s|install |$${BSD_INSTALL_PROGRAM} | ; \
		 /mandir/s|install -m 644 |$${BSD_INSTALL_MAN} |' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
