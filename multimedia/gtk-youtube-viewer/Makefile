# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	gtk-youtube-viewer
PORTVERSION=	3.0.7
PORTREVISION=	2
CATEGORIES=	multimedia perl5

MAINTAINER=	nemysis@gmx.ch
COMMENT=	GTK Search and play YouTube videos streaming in MPlayer

LICENSE=	GPLv3

# According to Build.PL
BUILD_DEPENDS=	p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Term-ANSIColor>=0:${PORTSDIR}/devel/p5-Term-ANSIColor \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-LWP-Protocol-https>=0:${PORTSDIR}/www/p5-LWP-Protocol-https \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-ReadLine-Gnu>=0:${PORTSDIR}/devel/p5-ReadLine-Gnu \
		p5-XML-Fast>=0:${PORTSDIR}/net/p5-XML-Fast
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		mplayer:${PORTSDIR}/multimedia/mplayer
TEST_DEPENDS=	p5-Test-More-UTF8>=0:${PORTSDIR}/devel/p5-Test-More-UTF8

CONFLICTS=	youtube-viewer-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	trizen
GH_PROJECT=	youtube-viewer
GH_COMMIT=	c26d9a7

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}/WWW-YoutubeViewer

CONFIGURE_ARGS+=${DATADIR}
USES=		perl5
USE_PERL5=	5.16+ patch modbuild

MAN3=		WWW::YoutubeViewer::RegularExpressions.3 \
		WWW::YoutubeViewer.3 \
		WWW::YoutubeViewer::Itags.3 \
		WWW::YoutubeViewer::Utils.3 \
		WWW::YoutubeViewer::GetCaption.3 \
		WWW::YoutubeViewer::ParseXML.3

PORTDOCS=	Changes README

OPTIONS_DEFINE=	GCAP

OPTIONS_MULTI=	USER_INTERFACE
OPTIONS_MULTI_USER_INTERFACE=	CLI GTK2

OPTIONS_DEFAULT=	GTK2 GCAP

CLI_DESC=	Enable CLI version
GCAP_DESC=	Enable YouTube captions support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLI}
MAN1=		youtube-viewer.1
PLIST_SUB+=	CLI=""
.else
PLIST_SUB+=	CLI="@comment "
.endif

.if ${PORT_OPTIONS:MGTK2}
BUILD_DEPENDS+=	p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2
RUN_DEPENDS+=	p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2
CONFIGURE_ARGS+=--gtk-youtube-viewer
PLIST_SUB+=	GTK2=""
.else
PLIST_SUB+=	GTK2="@comment "
.endif

.if ${PORT_OPTIONS:MGCAP}
RUN_DEPENDS+=	${LOCALBASE}/bin/gcap:${PORTSDIR}/multimedia/gcap
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -n '1,/create_build_script()/p' \
			${WRKSRC}/Build.PL
	@${REINPLACE_CMD} \
		-e 's|5.016|0|' \
			${WRKSRC}/Build.PL
	@cd ${WRKSRC}/bin && ${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		gtk-youtube-viewer youtube-viewer
.if ${PERL_LEVEL} <= 501600
	@${CP} ${FILESDIR}/yv_5.16_to_5.10.pl ${WRKSRC}
	@${CP} ${WRKSRC}/bin/youtube-viewer ${WRKSRC}/bin/youtube-viewer-2patch
	@${PERL} \
	${WRKSRC}/yv_5.16_to_5.10.pl ${WRKSRC}/bin/youtube-viewer-2patch > ${WRKSRC}/bin/youtube-viewer
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
	${INSTALL_DATA} ${WRKSRC}/share/gtk-youtube-viewer.desktop ${PREFIX}/share/applications
	@${MKDIR} ${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/share/gtk-youtube-viewer.glade ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/share/gtk-youtube-viewer-icons/* ${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/share/icons/gtk-youtube-viewer.png ${PREFIX}/share/pixmaps
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

regression-test: build
	cd ${WRKSRC} && ${PERL} ./Build test

.include <bsd.port.post.mk>
