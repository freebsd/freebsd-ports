PORTNAME=	cdrdao
DISTVERSION=	1_2_5
PORTREVISION=	2
CATEGORIES=	sysutils audio
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/rel_${DISTVERSION}/ \
		SF/${PORTNAME}/rel_${DISTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Record CD-R[W]s in disk-at-once mode
WWW=		https://cdrdao.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		alias autoreconf compiler:c++11-lang gettext-tools gmake iconv \
		localbase tar:bzip2
USE_CXXSTD=	c++11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gcdmaster=no \
		--without-pcctsbin \
		--without-pcctsinc \
		--with-posix-threads=no \
		--with-scglib

OPTIONS_DEFINE=		DOCS TOC2MP3 MP3OGG
OPTIONS_DEFAULT=	MP3OGG
OPTIONS_SUB=		yes

MP3OGG_DESC=		Build with MP3/Ogg support (for sysutils/gcdmaster)
MP3OGG_LIB_DEPENDS=	libao.so:audio/libao \
			libmad.so:audio/libmad \
			libvorbis.so:audio/libvorbis
MP3OGG_USES=		pkgconfig
MP3OGG_CONFIGURE_OFF=	--with-mp3-support=no --with-ogg-support=no

TOC2MP3_DESC=		Build with toc2mp3 (requires audio/lame)
TOC2MP3_LIB_DEPENDS=	libmp3lame.so:audio/lame
TOC2MP3_CONFIGURE_OFF=	--with-lame=no

post-patch:
.for i in cdrdao.man main.cc
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/dao/${i}
.endfor
.for i in toc2cddb.1 toc2cue.1
	@${REINPLACE_CMD} -e 's|1\.2\.2|${PORTVERSION}|g' ${WRKSRC}/utils/${i}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in CREDITS ChangeLog README README.PlexDAE
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
