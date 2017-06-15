# $FreeBSD$

PORTNAME=	h323plus
PORTVERSION=	1.26.5
PORTREVISION=	2
CATEGORIES=	net multimedia
MASTER_SITES=	http://www.h323plus.org/source/download/
DISTNAME=	${PORTNAME}-v${PORTVERSION:S/./_/g}

MAINTAINER=	koue@chaosophia.net
COMMENT=	H323 Video Conferencing library

LICENSE=	MPL

LIB_DEPENDS=	libpt.so:devel/ptlib

WRKSRC=		${WRKDIR}/${PORTNAME}

CONFLICTS=	openh323-[0-9]*

USES=		gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include -I${WRKSRC}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_JOBS_UNSAFE=yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libh323.so.1.26.5

.include <bsd.port.mk>
