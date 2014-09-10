# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtk-youtube-viewer
PORTVERSION=	3.1.1
PORTREVISION=	1
CATEGORIES=	multimedia perl5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK Search and play YouTube videos streaming in MPlayer

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

# According to Build.PL
BUILD_DEPENDS=	p5-MIME-Base64>0:${PORTSDIR}/converters/p5-MIME-Base64 \
		p5-Data-Dump>0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-File-Path>0:${PORTSDIR}/devel/p5-File-Path \
		p5-File-Temp>0:${PORTSDIR}/devel/p5-File-Temp \
		p5-Getopt-Long>0:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-PathTools>0:${PORTSDIR}/devel/p5-PathTools \
		p5-ReadLine-Gnu>0:${PORTSDIR}/devel/p5-ReadLine-Gnu \
		p5-Term-ANSIColor>0:${PORTSDIR}/devel/p5-Term-ANSIColor \
		p5-Test-More-UTF8>0:${PORTSDIR}/devel/p5-Test-More-UTF8 \
		p5-Thread-Queue>0:${PORTSDIR}/devel/p5-Thread-Queue \
		p5-threads>0:${PORTSDIR}/devel/p5-threads \
		p5-Scalar-List-Utils>0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Socket>0:${PORTSDIR}/net/p5-Socket \
		p5-XML-Fast>0:${PORTSDIR}/net/p5-XML-Fast \
		p5-Text-CharWidth>0:${PORTSDIR}/textproc/p5-Text-CharWidth \
		p5-Text-ParseWords>0:${PORTSDIR}/textproc/p5-Text-ParseWords \
		p5-Text-Tabs+Wrap>0:${PORTSDIR}/textproc/p5-Text-Tabs+Wrap  \
		p5-LWP-Protocol-https>0:${PORTSDIR}/www/p5-LWP-Protocol-https \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		mplayer:${PORTSDIR}/multimedia/mplayer

USE_GITHUB=	yes
GH_ACCOUNT=	trizen
GH_PROJECT=	youtube-viewer
GH_COMMIT=	e3d45f7

WRKSRC_SUBDIR=	WWW-YoutubeViewer

USES=		perl5 shebangfix
SHEBANG_FILES=	bin/gtk-youtube-viewer bin/youtube-viewer
USE_PERL5=	5.16+ patch modbuild
CONFIGURE_ARGS+=${DATADIR}

OPTIONS_DEFINE=		GCAP GTK2
OPTIONS_DEFAULT=	GCAP GTK2
OPTIONS_SUB=		yes

GCAP_DESC=		YouTube closed captions support
GCAP_RUN_DEPENDS=	${LOCALBASE}/bin/gcap:${PORTSDIR}/multimedia/gcap
GTK2_BUILD_DEPENDS=	p5-File-ShareDir>0:${PORTSDIR}/devel/p5-File-ShareDir \
			p5-Gtk2>0:${PORTSDIR}/x11-toolkits/p5-Gtk2
GTK2_RUN_DEPENDS=	p5-File-ShareDir>0:${PORTSDIR}/devel/p5-File-ShareDir \
			p5-Gtk2>0:${PORTSDIR}/x11-toolkits/p5-Gtk2
GTK2_CONFIGURE_ON=	--gtk-youtube-viewer

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MGTK2}
	${LN} -sf \
	${SITE_PERL}/auto/share/dist/WWW-YoutubeViewer/gtk-youtube-viewer.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${LN} -sf \
	${SITE_PERL}/auto/share/dist/WWW-YoutubeViewer/icons/gtk-youtube-viewer.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
.endif

regression-test: build
	cd ${WRKSRC} && ${PERL} ./Build test

.include <bsd.port.mk>
