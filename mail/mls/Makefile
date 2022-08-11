PORTNAME=	mls
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.marki-online.net/MLS/ \
		http://marki.host.sk/MLS/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for generating various statistics on emails

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: r_base64
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: r_base64

PLIST_FILES=	bin/mls man/man1/mls.1.gz

MAKE_ARGS+=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	mls

.include <bsd.port.mk>
