# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	minidlna
PORTVERSION=	1.1.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net multimedia www
MASTER_SITES=	SF

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Media-server compatible with "Digital Life Network Alliance"

LIB_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3	\
		jpeg:${PORTSDIR}/graphics/jpeg		\
		exif:${PORTSDIR}/graphics/libexif	\
		id3tag:${PORTSDIR}/audio/libid3tag	\
		ogg:${PORTSDIR}/audio/libogg		\
		vorbis:${PORTSDIR}/audio/libvorbis	\
		FLAC:${PORTSDIR}/audio/flac		\
		avformat:${PORTSDIR}/multimedia/ffmpeg

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS+=--with-db-path=/var/db/minidlna \
		--with-os-url="http://www.FreeBSD.org"

PKGMESSAGE=	${WRKSRC}/pkg-message
SUB_FILES+=	pkg-message
USE_RC_SUBR=	minidlna
SUB_LIST+=	USER=${USERS}

USERS=	dlna
GROUPS=	dlna

MAN5=	minidlna.conf.5
MAN8=	minidlnad.8

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	${INSTALL_MAN} ${MAN5:S,^,${WRKSRC}/,} ${MANPREFIX}/man/man5/
	${INSTALL_MAN} ${MAN8:S,^,${WRKSRC}/,} ${MANPREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/minidlna.conf ${PREFIX}/etc/minidlna.conf.sample
	@${FMT} ${PKGMESSAGE}

.include <bsd.port.mk>
