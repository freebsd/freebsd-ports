# Created by: snowchyld
# $FreeBSD$

PORTNAME=	libsrs2
PORTVERSION=	1.0.18
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	http://www.libsrs2.org/srs/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Sender Rewriting Scheme 2 C Implementation

CONFLICTS=	p5-Mail-SRS*

USES=		libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

post-patch:
	${REINPLACE_CMD} '/^lib_LIBRARIES/s/libsrs2.a//' \
		${WRKSRC}/libsrs2/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsrs2.so.0.0.0

.include <bsd.port.mk>
