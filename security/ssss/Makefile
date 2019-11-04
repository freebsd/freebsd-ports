# Created by: Lukasz Komsta
# $FreeBSD$

PORTNAME=	ssss
PORTVERSION=	0.5
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://point-at-infinity.org/ssss/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shamir's Secret Sharing Scheme

LIB_DEPENDS=	libgmp.so:math/gmp

PLIST_FILES=	bin/ssss-combine bin/ssss-split man/man1/ssss.1.gz

post-patch:
	${REINPLACE_CMD} 's,(DESTDIR),&$$(PREFIX),' ${WRKSRC}/Makefile

.include <bsd.port.mk>
