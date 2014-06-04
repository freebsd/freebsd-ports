# Created by: The Anarcat <anarcat@anarcat.ath.cx>
# $FreeBSD$

PORTNAME=	mls
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.marki-online.net/MLS/ \
		http://marki.host.sk/MLS/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for generating various statistics on emails

PLIST_FILES=	bin/mls man/man1/mls.1.gz

MAKE_ARGS+=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	mls

.include <bsd.port.mk>
