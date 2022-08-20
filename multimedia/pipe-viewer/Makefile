PORTNAME=	pipe-viewer
PORTVERSION=	0.2.3
CATEGORIES=	multimedia perl5

MAINTAINER?=	DtxdF@riseup.net
COMMENT?=	Application for searching and playing videos from YouTube

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Data-Dump>0:devel/p5-Data-Dump \
		p5-IO-Compress-Brotli>0:archivers/p5-IO-Compress-Brotli \
		p5-JSON>0:converters/p5-JSON \
		p5-libwww>0:www/p5-libwww \
		p5-LWP-Protocol-https>0:www/p5-LWP-Protocol-https

USES=	perl5
USE_PERL5=	modbuild

USE_GITHUB=	yes
GH_ACCOUNT=	trizen

CONFLICTS_INSTALL?=	multimedia/gtk-pipe-viewer

OPTIONS_DEFINE=	GTK3 JSON_XS LOCAL_CACHE READLINE SHARE_DIR
OPTIONS_DEFAULT?=	JSON_XS LINE_BREAK LOCAL_CACHE READLINE YT_DLP
OPTIONS_RADIO=	FIXED_WIDTH YOUTUBE
OPTIONS_RADIO_FIXED_WIDTH=	CHAR_WIDTH LINE_BREAK
OPTIONS_RADIO_YOUTUBE=	YOUTUBE_DL YT_DLP

OPTIONS_SUB=	yes

LOCAL_CACHE_DESC=	Local cache support
JSON_XS_DESC=	Faster JSON deserialization
SHARE_DIR_DESC=	Install with p5-File-ShareDir
FIXED_WIDTH_DESC=	Fixed-width formatting
LINE_BREAK_DESC=	Install with p5-Text-CharWidth
CHAR_WIDTH_DESC=	Install with p5-Unicode-LineBreak
YOUTUBE_DESC=	Youtube support
YT_DLP_DESC=	Enable Youtube support with yt-dlp
YOUTUBE_DL_DESC=	Enable Youtube support with youtube_dl

GTK3_RUN_DEPENDS=	p5-Gtk3>0:x11-toolkits/p5-Gtk3
GTK3_CONFIGURE_ON=	--gtk
SHARE_DIR_RUN_DEPENDS=	p5-File-ShareDir>0:devel/p5-File-ShareDir
LOCAL_CACHE_RUN_DEPENDS=	p5-LWP-UserAgent-WithCache>0:www/p5-LWP-UserAgent-WithCache
READLINE_RUN_DEPENDS=	p5-Term-ReadLine-Gnu>0:devel/p5-Term-ReadLine-Gnu
JSON_XS_RUN_DEPENDS=	p5-JSON-XS>0:converters/p5-JSON-XS
LINE_BREAK_RUN_DEPENDS=	p5-Unicode-LineBreak>0:textproc/p5-Unicode-LineBreak
CHAR_WIDTH_RUN_DEPENDS=	p5-Text-CharWidth>0:textproc/p5-Text-CharWidth
YT_DLP_RUN_DEPENDS=	yt-dlp>0:www/yt-dlp
YOUTUBE_DL_RUN_DEPENDS=	youtube_dl>0:www/youtube_dl

.include <bsd.port.mk>
