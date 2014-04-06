# $FreeBSD$

PORTNAME=	texlive
PORTVERSION=	20120701
PORTREVISION=	10
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2012/
PKGNAMESUFFIX=	-base
DISTNAME=	${PORTNAME}-${DISTVERSION}-source
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	TeX Live Typesetting System, base binaries

RUN_DEPENDS=	psbook:${PORTSDIR}/print/psutils
LIB_DEPENDS=	libicuio.so:${PORTSDIR}/devel/icu \
		libt1.so:${PORTSDIR}/devel/t1lib \
		libTECkit.so:${PORTSDIR}/textproc/teckit \
		libgraphite.so:${PORTSDIR}/graphics/silgraphite \
		libgd.so:${PORTSDIR}/graphics/gd \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libttf.so:${PORTSDIR}/print/freetype \
		libpng15.so:${PORTSDIR}/graphics/png \
		libzzip.so:${PORTSDIR}/devel/zziplib \
		libpoppler.so:${PORTSDIR}/graphics/poppler

USE_TEX=	texlive web2c kpathsea ptexenc texhash-bootstrap
USES=		gmake pkgconfig perl5 tar:xz
USE_AUTOTOOLS=	autoconf
USE_GHOSTSCRIPT=yes
USE_PERL5=	run
USE_LDCONFIG=	yes
# during build phase gnu configure is run a lot
MAKE_ENV+=	CONFIG_SITE=${CONFIG_SITE}
USE_XORG=	x11 xmu xaw
EXCLUDE_FILES=	${DISTNAME}/texk/web2c \
		${DISTNAME}/texk/kpathsea \
		${DISTNAME}/texk/ptexenc \
		${DISTNAME}/texk/xdvik \
		${DISTNAME}/texk/dvipdfmx \
		${DISTNAME}/texk/dvipsk \
		${DISTNAME}/libs/freetype \
		${DISTNAME}/libs/freetype2 \
		${DISTNAME}/libs/gd \
		${DISTNAME}/libs/graphite \
		${DISTNAME}/libs/icu \
		${DISTNAME}/libs/libpng \
		${DISTNAME}/libs/poppler \
		${DISTNAME}/libs/t1lib \
		${DISTNAME}/libs/teckit \
		${DISTNAME}/libs/xpdf \
		${DISTNAME}/libs/zlib \
		${DISTNAME}/libs/zziplib \
		${DISTNAME}/utils/biber \
		${DISTNAME}/utils/psutils \
		${DISTNAME}/utils/t1utils
EXTRACT_AFTER_ARGS=	${EXCLUDE_FILES:S,^,--exclude ,}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --disable-native-texlive-build \
		--disable-web-progs \
		--disable-psutils \
		--enable-shared \
		--disable-t1utils \
		--enable-build-in-source-tree \
		--datarootdir=${LOCALBASE}/share \
		--with-system-freetype \
		--with-freetype-includes=${LOCALBASE}/include/freetype1/freetype \
		--with-freetype-libdir=${LOCALBASE}/lib \
		--with-system-freetype2 \
		--with-freetype2-includes=${LOCALBASE}/include/freetype2 \
		--with-freetype2-libdir=${LOCALBASE}/lib \
		--with-system-gd \
		--with-system-graphite \
		--with-system-icu \
		--with-icu-include=${LOCALBASE}/include \
		--with-icu-libdir=${LOCALBASE}/lib \
		--with-system-kpathsea \
		--with-kpathsea-include=${LOCALBASE}/include/kpathsea \
		--with-kpathsea-libdir=${LOCALBASE}/lib \
		--with-system-libgs \
		--with-libgs-includes=${LOCALBASE}/include \
		--with-libgs-libdir=${LOCALBASE}/lib \
		--with-system-libpng \
		--with-system-poppler \
		--with-system-ptexenc \
		--with-ptexenc-include=${LOCALBASE}/include/ptexenc \
		--with-ptexenc-libdir=${LOCALBASE}/lib \
		--with-system-t1lib \
		--with-system-teckit \
		--with-xpdf-includes=${LOCALBASE}/include/poppler \
		--with-xpdf-libdir=${LOCALBASE}/lib \
		--with-system-xpdf \
		--with-system-zziplib \
		--with-system-zlib
CFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/kpathsea \
		-I${LOCALBASE}/include/ptexenc
PLIST_SUB=	INSTALL_DATA="${INSTALL_DATA}"

INFO=	dvipng

post-patch:
	cd ${WRKSRC} && \
		${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		texk/tetex/fmtutil-sys \
		texk/tetex/texconfig-sys \
		texk/tetex/updmap-sys.sh

post-install-fmtutil:
	${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFCONFIGDIR}/web2c
	${TOUCH} ${STAGEDIR}${PREFIX}/${TEXMFCONFIGDIR}/web2c/.keep_me
	${INSTALL_DATA} ${STAGEDIR}${PREFIX}/${TEXMFDIR}/web2c/fmtutil.cnf \
		${STAGEDIR}${PREFIX}/${FMTUTIL_CNF}

post-install: post-install-fmtutil
.ORDER: post-install-fmtutil do-texhash

.include <bsd.port.mk>
