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

MAN1=		mls.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/mls

MAKE_ARGS+=	DESTDIR="${PREFIX}" CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	mls

NO_STAGE=	yes
.include <bsd.port.mk>
