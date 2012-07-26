# New ports collection makefile for:	mod_musicindex
# Date created:				Nov 1 2003
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	mod_musicindex
PORTVERSION=	1.3.7
CATEGORIES=	www audio
MASTER_SITES=	http://www.parisc-linux.org/~varenet/musicindex/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module that allows downloading and streaming of audio

LICENSE=	LGPL21

USE_APACHE=	20+

.include <bsd.port.pre.mk>

OPTIONS_DEFINE=	NLS FLAC MP3 MP4 VORBIS LIBARCHIVE FILECACHE MYSQLCACHE
OPTIONS_DEFAULT=NLS MP3 LIBARCHIVE FILECACHE

LIBARCHIVE_DESC=	Archive downloading support
FILECACHE_DESC=		Flat file caching support
MYSQLCACHE_DESC=	MySQL caching support

.include <bsd.port.options.mk>

MAKE_JOBS_SAFE=	yes

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-apxs=${APXS} \
		--disable-libFLACtest --disable-vorbistest

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

PORTDOCS=	README

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CFLAGS+=	-lintl
PLIST_SUB+=	NLS=""
CONFIGURE_ARGS+=--enable-nls
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=	--enable-flac
.else
CONFIGURE_ARGS+=	--disable-flac
.endif

.if ${PORT_OPTIONS:MMP3}
LIB_DEPENDS+=	id3tag:${PORTSDIR}/audio/libid3tag \
		mad:${PORTSDIR}/audio/libmad
CONFIGURE_ARGS+=	--enable-mp3
.else
CONFIGURE_ARGS+=	--disable-mp3
.endif

.if ${PORT_OPTIONS:MMP4}
LIB_DEPENDS+=	mp4v2:${PORTSDIR}/multimedia/mp4v2
CONFIGURE_ARGS+=	--enable-mp4
.else
CONFIGURE_ARGS+=	--disable-mp4
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--enable-vorbis
.else
CONFIGURE_ARGS+=	--disable-vorbis
.endif

.if ${PORT_OPTIONS:MLIBARCHIVE}
CONFIGURE_ARGS+=	--enable-archive
.else
CONFIGURE_ARGS+=	--disable-archive
.endif

.if ${PORT_OPTIONS:MFILECACHE}
CONFIGURE_ARGS+=	--enable-filecache
.else
CONFIGURE_ARGS+=	--disable-filecache
.endif

.if ${PORT_OPTIONS:MMYSQLCACHE}
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--enable-mysqlcache
.else
CONFIGURE_ARGS+=	--disable-mysqlcache
.endif

post-patch:
	@${REINPLACE_CMD} -e '/@BUILD_FOR_APACHE2/ s| -i -n musicindex| -a &|' \
		${WRKSRC}/src/Makefile.in
.if ${PORT_OPTIONS:MNLS}
	${RM} ${WRKSRC}/po/*.gmo
.endif

post-build:
.if ${PORT_OPTIONS:MNLS}
	cd ${WRKSRC}/po && ${SETENV} ${MAKE_ENV} ${MAKE} update-gmo
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif
	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
