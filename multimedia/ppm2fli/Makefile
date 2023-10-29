PORTNAME=	ppm2fli
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	multimedia graphics
MASTER_SITES=	http://vento.pi.tu-berlin.de/ppm2fli/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities to merge PPM files into animated FLI and backwards
WWW=		http://vento.pi.tu-berlin.de/ppm2fli/main.html

DEPRECATED=	BROKEN on all supported versions after the EOL of 12
EXPIRATION_DATE=	2023-12-31
BROKEN_FreeBSD_13=	ld: error: duplicate symbol: Xorigin
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: Xorigin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

pre-patch:
	@${REINPLACE_CMD} -e 's|^C|#C|g ; \
		 s|gcc |\$${CC} |g' ${WRKSRC}/Makefile

do-install:
.for f in ppm2fli unflick
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
