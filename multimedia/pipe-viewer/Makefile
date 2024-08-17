PORTNAME=	pipe-viewer
PORTVERSION=	0.5.2
CATEGORIES=	multimedia perl5

MAINTAINER?=	DtxdF@disroot.org
COMMENT?=	Application for searching and playing videos from YouTube
WWW=		https://github.com/trizen/pipe-viewer

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Data-Dump>0:devel/p5-Data-Dump \
		p5-IO-Compress-Brotli>0:archivers/p5-IO-Compress-Brotli \
		p5-JSON>0:converters/p5-JSON \
		p5-libwww>0:www/p5-libwww \
		p5-LWP-Protocol-https>0:www/p5-LWP-Protocol-https

USES=		perl5
USE_GITHUB=	yes
GH_ACCOUNT=	trizen
USE_PERL5=	modbuild

CONFLICTS_INSTALL?=	multimedia/gtk-pipe-viewer

NO_ARCH=	yes

OPTIONS_DEFINE=			FORK_MANAGER GTK3 JSON_XS LOCAL_CACHE READLINE \
				SHARE_DIR
OPTIONS_DEFAULT?=		FORK_MANAGER JSON_XS LINE_BREAK LOCAL_CACHE \
				READLINE YT_DLP
OPTIONS_RADIO=			FIXED_WIDTH YOUTUBE
OPTIONS_RADIO_FIXED_WIDTH=	CHAR_WIDTH LINE_BREAK
OPTIONS_RADIO_YOUTUBE=		YOUTUBE_DL YT_DLP

OPTIONS_SUB=	yes

CHAR_WIDTH_DESC=	Install with p5-Unicode-LineBreak
FIXED_WIDTH_DESC=	Fixed-width formatting
FORK_MANAGER_DESC=	Enable *_parallel config-options support
JSON_XS_DESC=		Faster JSON deserialization
LINE_BREAK_DESC=	Install with p5-Text-CharWidth
LOCAL_CACHE_DESC=	Local cache support
SHARE_DIR_DESC=		Install with p5-File-ShareDir
YOUTUBE_DESC=		Youtube support
YOUTUBE_DL_DESC=	Enable Youtube support with youtube_dl
YT_DLP_DESC=		Enable Youtube support with yt-dlp

CHAR_WIDTH_RUN_DEPENDS=		p5-Text-CharWidth>0:textproc/p5-Text-CharWidth
FORK_MANAGER_RUN_DEPENDS=	p5-Parallel-ForkManager>0:devel/p5-Parallel-ForkManager
GTK3_RUN_DEPENDS=		p5-Gtk3>0:x11-toolkits/p5-Gtk3
GTK3_CONFIGURE_ON=		--gtk
JSON_XS_RUN_DEPENDS=		p5-JSON-XS>0:converters/p5-JSON-XS
LINE_BREAK_RUN_DEPENDS=		p5-Unicode-LineBreak>0:textproc/p5-Unicode-LineBreak
LOCAL_CACHE_RUN_DEPENDS=	p5-LWP-UserAgent-Cached>0:www/p5-LWP-UserAgent-Cached
READLINE_RUN_DEPENDS=		p5-Term-ReadLine-Gnu>0:devel/p5-Term-ReadLine-Gnu
SHARE_DIR_RUN_DEPENDS=		p5-File-ShareDir>0:devel/p5-File-ShareDir
YOUTUBE_DL_RUN_DEPENDS=		youtube_dl>0:www/youtube_dl
YT_DLP_RUN_DEPENDS=		yt-dlp>0:www/yt-dlp

post-install-GTK3-on:
	(cd ${STAGEDIR}${DESKTOPDIR} && ${LN} -sf \
	../../${SITE_PERL_REL}/auto/share/dist/WWW-PipeViewer/gtk-pipe-viewer.desktop)
	(cd ${STAGEDIR}${PREFIX}/share/pixmaps && ${LN} -sf \
	../../${SITE_PERL_REL}/auto/share/dist/WWW-PipeViewer/icons/gtk-pipe-viewer.png)

.include <bsd.port.mk>
