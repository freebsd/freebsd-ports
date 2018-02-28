# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	minidlna
PORTVERSION=	1.2.1
PORTEPOCH=	1
CATEGORIES=	net multimedia www
MASTER_SITES=	SF

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Media-server compatible with "Digital Life Network Alliance"

LICENSE=	GPLv2

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3	\
		libexif.so:graphics/libexif	\
		libid3tag.so:audio/libid3tag	\
		libogg.so:audio/libogg		\
		libvorbis.so:audio/libvorbis	\
		libFLAC.so:audio/flac		\
		libavformat.so:multimedia/ffmpeg

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-db-path=/var/db/minidlna \
		--with-os-url="http://www.FreeBSD.org"
USES=		autoreconf gettext-tools iconv jpeg localbase

PKGMESSAGE=	${WRKSRC}/pkg-message
SUB_FILES+=	pkg-message
USE_RC_SUBR=	minidlna
SUB_LIST+=	USER=${USERS}

USERS=	dlna
GROUPS=	dlna

OPTIONS_DEFINE=	DEBUG KQUEUE NLS
OPTIONS_DEFAULT=KQUEUE
OPTIONS_SUB=	yes

DEBUG_CFLAGS=	-DDEBUG
KQUEUE_DESC=	Experimental patch for automatic rescan using kqueue(2)
NLS_USES=	gettext-runtime

KQUEUE_EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-kqueue

post-install:
	${INSTALL_MAN} ${WRKSRC}/*.5 ${STAGEDIR}${MANPREFIX}/man/man5/
	${INSTALL_MAN} ${WRKSRC}/*.8 ${STAGEDIR}${MANPREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/minidlna.conf ${STAGEDIR}${PREFIX}/etc/minidlna.conf.sample

.include <bsd.port.mk>
