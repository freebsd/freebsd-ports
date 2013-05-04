# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	minidlna
PORTVERSION=	1.0.25
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net multimedia www
MASTER_SITES=	SF
DISTFILES=	${PORTNAME}_${PORTVERSION}_src.tar.gz

MAINTAINER=	william88@gmail.com
COMMENT=	Media-server compatible with "Digital Life Network Alliance"

LIB_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3	\
		jpeg:${PORTSDIR}/graphics/jpeg	\
		exif:${PORTSDIR}/graphics/libexif	\
		id3tag:${PORTSDIR}/audio/libid3tag	\
		ogg:${PORTSDIR}/audio/libogg     	\
		vorbis:${PORTSDIR}/audio/libvorbis	\
		FLAC:${PORTSDIR}/audio/flac      	\
		avformat:${PORTSDIR}/multimedia/ffmpeg

MAKE_JOBS_SAFE=	yes
MAKEFILE=	${FILESDIR}/BSDmakefile
MAKE_ENV+=	FILESDIR="${FILESDIR}" INSTALL_DATA="${INSTALL_DATA}"
EXTRACT_AFTER_ARGS=--exclude getifaddr.c

PKGMESSAGE=	${WRKSRC}/pkg-message
SUB_FILES+=	pkg-message
USE_RC_SUBR=	minidlna
SUB_LIST+=	USER=${USERS}

USERS=	dlna
GROUPS=	dlna

.include <bsd.port.options.mk>

do-configure:
.if ${PORT_OPTIONS:MNLS}
	${CP} ${FILESDIR}/config.h.in ${WRKSRC}/config.h
.else
	${SED} 's,^#define HAVE_ICONV_H,/* & */,' ${FILESDIR}/config.h.in > \
		${WRKSRC}/config.h
.endif

post-install:
	${FMT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800500
EXTRA_PATCHES=	${FILESDIR}/scandir-patch
.endif

.include <bsd.port.post.mk>
