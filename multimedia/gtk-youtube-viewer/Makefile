PORTNAME=	gtk-youtube-viewer
PORTVERSION=	3.11.6
PORTREVISION=	2
CATEGORIES=	multimedia perl5

MAINTAINER=	nc@FreeBSD.org
COMMENT=	GTK Search and play YouTube videos streaming in MPlayer
WWW=		https://github.com/trizen/youtube-viewer

LICENSE=	ART10 GPLv3
LICENSE_COMB=	dual

# According to Build.PL
BUILD_DEPENDS=	p5-JSON>0:converters/p5-JSON \
		p5-JSON-XS>0:converters/p5-JSON-XS \
		p5-Data-Dump>0:devel/p5-Data-Dump \
		p5-PathTools>0:devel/p5-PathTools \
		p5-Term-ReadLine-Gnu>0:devel/p5-Term-ReadLine-Gnu \
		p5-Text-CharWidth>0:textproc/p5-Text-CharWidth \
		p5-Text-Tabs+Wrap>0:textproc/p5-Text-Tabs+Wrap  \
		p5-LWP-Protocol-https>0:www/p5-LWP-Protocol-https \
		p5-Mozilla-CA>0:www/p5-Mozilla-CA \
		p5-libwww>0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		p5-common-sense>=2.02:devel/p5-common-sense

USES=		perl5 shebangfix
SHEBANG_FILES=	bin/gtk-youtube-viewer bin/youtube-viewer
USE_PERL5=	patch modbuild

USE_GITHUB=	yes
GH_ACCOUNT=	trizen
GH_PROJECT=	youtube-viewer

NO_ARCH=	yes

OPTIONS_DEFINE=		GTK2
OPTIONS_MULTI=		PLAYER
OPTIONS_MULTI_PLAYER=	MPLAYER MPV VLC
OPTIONS_DEFAULT=	GTK2 MPLAYER
OPTIONS_SUB=		yes

MPLAYER_DESC=		Media player
MPV_DESC=		MPV media player support
VLC_DESC=		VLC media player support

GTK2_BUILD_DEPENDS=	p5-File-ShareDir>0:devel/p5-File-ShareDir \
			p5-Gtk2>0:x11-toolkits/p5-Gtk2
GTK2_RUN_DEPENDS=	p5-File-ShareDir>0:devel/p5-File-ShareDir \
			p5-Gtk2>0:x11-toolkits/p5-Gtk2
GTK2_CONFIGURE_ON=	--gtk-youtube-viewer
MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer
MPV_RUN_DEPENDS=	mpv:multimedia/mpv
VLC_RUN_DEPENDS=	vlc:multimedia/vlc

post-install-GTK2-on:
	(cd ${STAGEDIR}${DESKTOPDIR} && ${LN} -sf \
	../../${SITE_PERL_REL}/auto/share/dist/WWW-YoutubeViewer/gtk-youtube-viewer.desktop)
	(cd ${STAGEDIR}${PREFIX}/share/pixmaps && ${LN} -sf \
	../../${SITE_PERL_REL}/auto/share/dist/WWW-YoutubeViewer/icons/gtk-youtube-viewer.png)

do-test:
	cd ${WRKSRC} && ${PERL} ./Build test

.include <bsd.port.mk>
