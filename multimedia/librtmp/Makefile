PORTNAME=	librtmp
PORTVERSION=	2.4.20190330
PORTREVISION=	1
CATEGORIES=	multimedia net
MASTER_SITES=	https://git.ffmpeg.org/gitweb/rtmpdump.git/snapshot/c5f04a58fc2aeea6296ca7c44ee4734c18401aa3.tar.gz?/
DISTNAME=	rtmpdump-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	RTMP stream library
WWW=		https://rtmpdump.mplayerhq.hu/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Depends on legacy functionality of OpenSSL and superseded by multimedia/ffmpeg
EXPIRATION_DATE=2024-04-30

USES=		pkgconfig ssl
USE_LDCONFIG=	yes

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
PATCH_WRKSRC=	${WRKDIR}/rtmpdump-c5f04a5
WRKSRC=		${WRKDIR}/rtmpdump-c5f04a5/${PORTNAME}

.include <bsd.port.mk>
