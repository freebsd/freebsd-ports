# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	gtk-youtube-viewer
PORTVERSION=	3.0.9
CATEGORIES=	multimedia perl5

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	GTK Search and play YouTube videos streaming in MPlayer

LICENSE=	ART20 GPLv3
LICENSE_COMB=	dual

# According to Build.PL
BUILD_DEPENDS=	p5-Test-More-UTF8>=0:${PORTSDIR}/devel/p5-Test-More-UTF8 \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64 \
		p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https \
		p5-File-Temp>=0:${PORTSDIR}/devel/p5-File-Temp \
		p5-Text-CharWidth>=0:${PORTSDIR}/textproc/p5-Text-CharWidth \
		p5-threads>=0:${PORTSDIR}/devel/p5-threads \
		p5-Thread-Queue>=0:${PORTSDIR}/devel/p5-Thread-Queue \
		p5-ReadLine-Gnu>=0:${PORTSDIR}/devel/p5-ReadLine-Gnu \
		p5-XML-Fast>=0:${PORTSDIR}/net/p5-XML-Fast \
		p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools \
		p5-File-Path>=0:${PORTSDIR}/devel/p5-File-Path \
		p5-Getopt-Long>=0:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Term-ANSIColor>=0:${PORTSDIR}/devel/p5-Term-ANSIColor \
		p5-Term-UI>=0:${PORTSDIR}/devel/p5-Term-UI \
		p5-Text-ParseWords>=0:${PORTSDIR}/textproc/p5-Text-ParseWords \
		p5-Text-Tabs+Wrap>=0:${PORTSDIR}/textproc/p5-Text-Tabs+Wrap  \
		p5-Socket>=0:${PORTSDIR}/net/p5-Socket
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		mplayer:${PORTSDIR}/multimedia/mplayer

CONFLICTS=	youtube-viewer-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	trizen
GH_PROJECT=	youtube-viewer
GH_COMMIT=	116eb3f

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}/WWW-YoutubeViewer

CONFIGURE_ARGS+=${DATADIR}
USES=		perl5
USE_PERL5=	5.16+ patch modbuild

PORTDOCS=	Changes README

OPTIONS_DEFINE=	DOCS GCAP

OPTIONS_MULTI=	USER_INTERFACE
OPTIONS_MULTI_USER_INTERFACE=	CLI GTK2

OPTIONS_DEFAULT=	CLI GCAP GTK2

CLI_DESC=	Enable CLI version
GCAP_DESC=	Enable YouTube captions support

OPTIONS_SUB=	yes

GCAP_RUN_DEPENDS=	${LOCALBASE}/bin/gcap:${PORTSDIR}/multimedia/gcap
GTK2_BUILD_DEPENDS=	p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
			p5-File-ShareDir>=0:${PORTSDIR}/devel/p5-File-ShareDir
GTK2_RUN_DEPENDS=	p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
			p5-File-ShareDir>=0:${PORTSDIR}/devel/p5-File-ShareDir

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGTK2}
CONFIGURE_ARGS+=-gtk-youtube-viewer
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|5.016|0|' ${WRKSRC}/Build.PL
	@cd ${WRKSRC}/bin && ${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		gtk-youtube-viewer youtube-viewer
.if ${PERL_LEVEL} <= 501600
	@${CP} ${FILESDIR}/yv_5.16_to_5.10.pl ${WRKSRC}
	@${CP} ${WRKSRC}/bin/youtube-viewer ${WRKSRC}/bin/youtube-viewer-2patch
	@${PERL} \
	${WRKSRC}/yv_5.16_to_5.10.pl ${WRKSRC}/bin/youtube-viewer-2patch > \
		${WRKSRC}/bin/youtube-viewer
	@${RM} ${WRKSRC}/bin/youtube-viewer-2patch
.endif

.if ! ${PORT_OPTIONS:MCLI}
	@${REINPLACE_CMD} -e "s|'bin/youtube-viewer',||" \
		${WRKSRC}/Build.PL
	@${REINPLACE_CMD} -i '' -e '/copy(catfile($$main_dir, qw(bin youtube-viewer))/,+1d' \
		${WRKSRC}/Build.PL
.endif

post-install:
.if ${PORT_OPTIONS:MGTK2}
	${LN} -sf \
	${SITE_PERL}/auto/share/dist/WWW-YoutubeViewer/gtk-youtube-viewer.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${LN} -sf \
	${SITE_PERL}/auto/share/dist/WWW-YoutubeViewer/gtk-youtube-viewer.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
.endif

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

regression-test: build
	cd ${WRKSRC} && ${PERL} ./Build test

.include <bsd.port.post.mk>
