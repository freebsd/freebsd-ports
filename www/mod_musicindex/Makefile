# Created by: clsung
# $FreeBSD$

PORTNAME=	mod_musicindex
PORTVERSION=	1.4.1
PORTREVISION=	4
CATEGORIES=	www audio
MASTER_SITES=	http://hacks.slashdirt.org/musicindex/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module that allows downloading and streaming of audio

LICENSE=	LGPL21

USES=		libarchive
USE_APACHE=	22

OPTIONS_DEFINE=	NLS FLAC MP3 MP4 VORBIS LIBARCHIVE FILECACHE MYSQLCACHE
OPTIONS_DEFAULT=NLS MP3 LIBARCHIVE FILECACHE

LIBARCHIVE_DESC=	Archive downloading support
FILECACHE_DESC=		Flat file caching support
MYSQLCACHE_DESC=	MySQL caching support

OPTIONS_SUB=			yes
FILECACHE_CONFIGURE_ENABLE=	filecache
FLAC_CONFIGURE_ENABLE=		flac
FLAC_LIB_DEPENDS=		libFLAC.so:audio/flac
LIBARCHIVE_CONFIGURE_ENABLE=	archive
MP3_CONFIGURE_ENABLE=		mp3
MP3_LIB_DEPENDS=		libid3tag.so:audio/libid3tag \
				libmad.so:audio/libmad
MP4_CONFIGURE_ENABLE=		mp4
MP4_LIB_DEPENDS=		libmp4v2.so:multimedia/mp4v2
MYSQLCACHE_CONFIGURE_ENABLE=	mysqlcache
MYSQLCACHE_USE=			MYSQL=yes
NLS_CFLAGS=			-lintl
NLS_CONFIGURE_ENABLE=		nls
NLS_USES=			gettext
VORBIS_CONFIGURE_ENABLE=	vorbis
VORBIS_LIB_DEPENDS=		libvorbis.so:audio/libvorbis

.include <bsd.port.options.mk>

GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-apxs=${APXS} \
			--disable-libFLACtest --disable-vorbistest

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

PORTDOCS=	README

post-patch:
.if ${PORT_OPTIONS:MNLS}
	${RM} ${WRKSRC}/po/*.gmo
.endif

post-build:
.if ${PORT_OPTIONS:MNLS}
	@(${SETENV} ${MAKE_ENV} ${MAKE} -C ${WRKSRC}/po update-gmo)
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MODULENAME}.so

.include <bsd.port.mk>
