# New ports collection makefile for:	libextractor
# Date created:		25 May 2005
# Whom:			kevlo@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libextractor
PORTVERSION=	0.6.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Library for keyword extraction

LIB_DEPENDS=	mpeg2:${PORTSDIR}/multimedia/libmpeg2

USE_GNOME=	glib20
USE_PYTHON=	yes
USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/libextractor
CONFIGURE_ARGS=	--disable-ltdl-install --enable-exiv2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_JOBS_UNSAFE=	yes

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude libltdl

MAN1=	extract.1
MAN3=	libextractor.3

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -f
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/src/plugins/Makefile.*
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

check: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

# this thing depends on install
#regression-test: check

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/wand/magick-wand.h)
LIB_DEPENDS+=	MagickWand.4:${PORTSDIR}/graphics/ImageMagick
.endif

.if exists(${LOCALBASE}/include/vorbis/vorbisfile.h)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	VORBIS=""
.else
PLIST_SUB+=	VORBIS="@comment "
.endif

patch-autotools-libtool::
	@(cd ${PATCH_WRKSRC}; \
	for file in ${LIBTOOLFILES}; do \
		${CP} $$file $$file.tmp; \
		${SED} -e "/^ltmain=/s^\$$ac_aux_dir/ltmain.sh^${LTMAIN}^g" \
			$$file.tmp > $$file; \
		${RM} $$file.tmp; \
	done);

.include <bsd.port.post.mk>
