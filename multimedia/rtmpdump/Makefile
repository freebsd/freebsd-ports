# $FreeBSD$

PORTNAME=	rtmpdump
DISTVERSION=	2.4.20190330
CATEGORIES=	multimedia net
MASTER_SITES=	https://git.ffmpeg.org/gitweb/rtmpdump.git/snapshot/c5f04a58fc2aeea6296ca7c44ee4734c18401aa3.tar.gz?/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	RTMP streams download utility

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librtmp.so:multimedia/librtmp

USES=		pkgconfig ssl
MAKE_ENV=	THREADLIB="-lpthread"
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB}
PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}-c5f04a5

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
