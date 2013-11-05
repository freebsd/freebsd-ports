# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	minidlna
PORTVERSION=	1.1.1
PORTEPOCH=	1
CATEGORIES=	net multimedia www
MASTER_SITES=	SF

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Media-server compatible with "Digital Life Network Alliance"

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3	\
		libjpeg.so:${PORTSDIR}/graphics/jpeg		\
		libexif.so:${PORTSDIR}/graphics/libexif	\
		libid3tag.so:${PORTSDIR}/audio/libid3tag	\
		libogg.so:${PORTSDIR}/audio/libogg		\
		libvorbis.so:${PORTSDIR}/audio/libvorbis	\
		libFLAC.so:${PORTSDIR}/audio/flac		\
		libavformat.so:${PORTSDIR}/multimedia/ffmpeg

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-db-path=/var/db/minidlna \
		--with-os-url="http://www.FreeBSD.org"
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		iconv

PKGMESSAGE=	${WRKSRC}/pkg-message
SUB_FILES+=	pkg-message
USE_RC_SUBR=	minidlna
SUB_LIST+=	USER=${USERS}

USERS=	dlna
GROUPS=	dlna

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

post-install:
	${INSTALL_MAN} ${WRKSRC}/*.5 ${STAGEDIR}${MANPREFIX}/man/man5/
	${INSTALL_MAN} ${WRKSRC}/*.8 ${STAGEDIR}${MANPREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/minidlna.conf ${STAGEDIR}${PREFIX}/etc/minidlna.conf.sample

.include <bsd.port.mk>
