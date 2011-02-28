# New ports collection makefile for:	mkvtoolnix
# Date created:		Tue Feb 24 02:09:12 UTC 2004
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mkvtoolnix
PORTVERSION=	4.5.0
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www.bunkus.org/videotools/mkvtoolnix/sources/ \
		CRITICAL

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Tools to extract from/get info about/create Matroska media streams

LIB_DEPENDS=	FLAC.10:${PORTSDIR}/audio/flac \
		ebml.3:${PORTSDIR}/textproc/libebml \
		expat.6:${PORTSDIR}/textproc/expat2 \
		lzo2.2:${PORTSDIR}/archivers/lzo2 \
		matroska.3:${PORTSDIR}/multimedia/libmatroska \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		ogg.7:${PORTSDIR}/audio/libogg \
		boost_regex.4:${PORTSDIR}/devel/boost-libs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_RAKE=	yes
USE_RUBY=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		ac_cv_path_PO4A=no
CONFIGURE_ARGS=	--enable-lzo --enable-bz2 --disable-qt \
		--with-boost=${LOCALBASE} \
		--with-boost-filesystem=boost_filesystem \
		--with-boost-system=boost_system \
		--with-boost-regex=boost_regex
MAKE_JOBS_SAFE=	yes

MANLANG=	"" ja zh_CN
MAN1=		mkvextract.1 mkvinfo.1 mkvmerge.1 mkvpropedit.1

OPTIONS=	WXGTK "build wxGTK2 based GUI" on

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64
.endif

.if defined(BATCH)
MAKE_ENV+=	V=1
.endif

.ifndef(WITHOUT_WXGTK)
USE_WX=		2.8+
WX_UNICODE=	yes
WX_CONF_ARGS=	absolute
MAN1+=		mmg.1
PLIST_SUB+=	GUI=""
.else
CONFIGURE_ARGS+=--disable-gui
PLIST_SUB+=	GUI="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|"-O3"|""|g' ${WRKSRC}/configure

do-build:
	@(cd ${WRKSRC}/; ${SETENV} ${MAKE_ENV} ${RAKE_BIN})

do-install:
	@(cd ${WRKSRC}/; ${SETENV} ${MAKE_ENV} ${RAKE_BIN} install)

.include <bsd.port.post.mk>
