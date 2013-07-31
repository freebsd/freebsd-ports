# Created by: Michael Nottebrock <michaelnottebrock@gmx.net>
# $FreeBSD$

PORTNAME=	dvdrip
PORTVERSION=	0.98.11
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	CPAN \
		http://www.exit1.org/dvdrip/dist/
MASTER_SITE_SUBDIR=	CPAN:JRED

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Gtk+ based dvd-ripper

BUILD_DEPENDS=	p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Event-ExecFlow>=0:${PORTSDIR}/devel/p5-Event-ExecFlow \
		p5-Gtk2-Ex-FormFactory>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2-Ex-FormFactory \
		p5-Event-RPC>=0:${PORTSDIR}/devel/p5-Event-RPC \
		p5-Locale-libintl>=0:${PORTSDIR}/devel/p5-Locale-libintl
RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	cdrdao:${PORTSDIR}/sysutils/cdrdao \
		convert:${PORTSDIR}/graphics/ImageMagick \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		pstree:${PORTSDIR}/sysutils/pstree \
		transcode:${PORTSDIR}/multimedia/transcode \
		vcdimager:${PORTSDIR}/multimedia/vcdimager \
		rar:${PORTSDIR}/archivers/rar \
		${LOCALBASE}/sbin/fping:${PORTSDIR}/net/fping \
		cdrecord:${PORTSDIR}/sysutils/cdrtools

OPTIONS_DEFINE=	VORBIS SUBTITLE
OPTIONS_DEFAULT=	VORBIS SUBTITLE
SUBTITLE_DESC=	Enable support for getting subtitles

CONFIGURE_ENV=	SKIP_UNPACK_REQUIRED_MODULES=1
USES=		gettext perl5
USE_PERL5=	configure patch
MAKE_JOBS_UNSAFE=	yes

MAN1=		dvdrip.1 dvdrip-progress.1 dvdrip-splitpipe.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVORBIS}
RUN_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools \
		ogmmerge:${PORTSDIR}/multimedia/ogmtools
.endif

.if ${PORT_OPTIONS:MSUBTITLE}
RUN_DEPENDS+=	subtitle2pgm:${PORTSDIR}/multimedia/subtitleripper
.endif

post-patch:
	@${PERL} -pi -e 's#/usr/sbin/fping#${LOCALBASE}/sbin/fping#' \
		${WRKSRC}/lib/Video/DVDRip/Cluster/Master.pm \
		${WRKSRC}/lib/Video/DVDRip/Depend.pm
	@${PERL} -pi -e 's#/usr/local/bin/perl#${PERL5}#' \
		${WRKSRC}/bin/dvdrip \
		${WRKSRC}/bin/dvdrip-exec \
		${WRKSRC}/bin/dvdrip-master \
		${WRKSRC}/bin/dvdrip-multitee \
		${WRKSRC}/bin/dvdrip-replex \
		${WRKSRC}/bin/dvdrip-splash \
		${WRKSRC}/bin/dvdrip-subpng \
		${WRKSRC}/bin/dvdrip-thumb
	@${FIND} ${WRKSRC} -name \*.orig -delete

post-install:
	@cd ${WRKSRC}/blib/man3 && ${FIND} * -name "*.3" | ${SED} \
		's,^,${MAN3PREFIX:S,^${PREFIX}/,,}/man/man3/,' >> ${TMPPLIST}

.include <bsd.port.mk>
