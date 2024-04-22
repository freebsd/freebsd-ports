PORTNAME=	rtmpdump
DISTVERSION=	2.4.20190330
PORTREVISION=	1
CATEGORIES=	multimedia net
MASTER_SITES=	https://git.ffmpeg.org/gitweb/rtmpdump.git/snapshot/c5f04a58fc2aeea6296ca7c44ee4734c18401aa3.tar.gz?/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	RTMP streams download utility
WWW=		https://rtmpdump.mplayerhq.hu/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Depends on deprecated library librtmp, consider migrating to multimedia/ffmpeg
EXPIRATION_DATE=2024-04-30

LIB_DEPENDS=	librtmp.so:multimedia/librtmp

USES=		cpe pkgconfig ssl
MAKE_ENV=	THREADLIB="-lpthread"
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB}
PORTDOCS=	ChangeLog README
CPE_VENDOR=	rtmpdump_project

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}-c5f04a5

post-patch:
	${REINPLACE_CMD} -e '/^mandir=/s,$$(prefix),$$(prefix)/share,' \
		${WRKSRC}/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
