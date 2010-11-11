# New ports collection makefile for:	mod_musicindex
# Date created:				Nov 1 2003
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	mod_musicindex
PORTVERSION=	1.3.5
CATEGORIES=	www audio
MASTER_SITES=	http://www.parisc-linux.org/~varenet/musicindex/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module that allows downloading and streaming of audio

LICENSE=	LGPL21

OPTIONS=	NLS "Native language support" on \
		FLAC "FLAC support" off \
		MP3 "MP3 support" on \
		MP4 "MP4 support" off \
		VORBIS "Ogg/Vorbis support" off \
		LIBARCHIVE "Archive downloading support" on \
		FILECACHE "Flat file caching support" on \
		MYSQLCACHE "MySQL caching support" off

MAKE_JOBS_SAFE=	yes

USE_APACHE=	2.0+

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-apxs=${APXS} \
		--disable-libFLACtest --disable-vorbistest

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

PORTDOCS=	README

.include <bsd.port.options.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
CFLAGS+=	-lintl
PLIST_SUB+=	NLS=""
.endif

.if defined(WITHOUT_FLAC)
CONFIGURE_ARGS+=	--disable-flac
.else
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
.endif

.if defined(WITHOUT_MP3)
CONFIGURE_ARGS+=	--disable-mp3
.else
LIB_DEPENDS+=	id3tag:${PORTSDIR}/audio/libid3tag \
		mad:${PORTSDIR}/audio/libmad
.endif

.if defined(WITHOUT_MP4)
CONFIGURE_ARGS+=	--disable-mp4
.else
LIB_DEPENDS+=	mp4v2:${PORTSDIR}/multimedia/mp4v2
.endif

.if defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=	--disable-vorbis
.else
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
.endif

.if defined(WITHOUT_LIBARCHIVE)
CONFIGURE_ARGS+=	--disable-archive
.endif

.if defined(WITHOUT_FILECACHE)
CONFIGURE_ARGS+=	--disable-filecache
.endif

.if defined(WITHOUT_MYSQLCACHE)
CONFIGURE_ARGS+=	--disable-mysqlcache
.else
USE_MYSQL=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e '/@BUILD_FOR_APACHE2/ s| -i -n musicindex| -a &|' \
		${WRKSRC}/src/Makefile.in
.if !defined(WITHOUT_NLS)
	${RM} ${WRKSRC}/po/*.gmo
	${MV} ${WRKSRC}/po/pt-br.po ${WRKSRC}/po/pt_BR.po
	cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|pt-br|pt_BR|g' ${WRKSRC}/po/LINGUAS ${WRKSRC}/po/pt_BR.po
.endif

post-build:
.if !defined(WITHOUT_NLS)
	cd ${WRKSRC}/po && ${SETENV} ${MAKE_ENV} ${MAKE} update-gmo
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif
	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.mk>
