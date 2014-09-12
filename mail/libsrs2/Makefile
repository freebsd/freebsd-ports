# Created by: snowchyld
# $FreeBSD$

PORTNAME=		libsrs2
PORTVERSION=		1.0.18
PORTREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		http://www.libsrs2.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	srs

MAINTAINER=		pi@FreeBSD.org
COMMENT=		Sender Rewriting Scheme 2 C Implementation

CONFLICTS=		p5-Mail-SRS*

USES=		libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=		yes

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsrs2.so.0.0.0

.include <bsd.port.mk>
