PORTNAME=	dvdrip
PORTVERSION=	0.98.11
PORTREVISION=	12
CATEGORIES=	multimedia
MASTER_SITES=	CPAN http://www.exit1.org/dvdrip/dist/
MASTER_SITE_SUBDIR=	CPAN:JRED

MAINTAINER=	se@FreeBSD.org
COMMENT=	Perl Gtk+ based dvd-ripper

LICENSE=	ART10 GPLv1 # (ART10 or GPLv1) and CC-BY-SA-2.5
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Gtk2>=0:x11-toolkits/p5-Gtk2 \
		p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-Event-ExecFlow>=0:devel/p5-Event-ExecFlow \
		p5-Gtk2-Ex-FormFactory>=0:x11-toolkits/p5-Gtk2-Ex-FormFactory \
		p5-Event-RPC>=0:devel/p5-Event-RPC \
		p5-Locale-libintl>=0:devel/p5-Locale-libintl
RUN_DEPENDS=	p5-Gtk2>=0:x11-toolkits/p5-Gtk2 \
		p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-Event-ExecFlow>=0:devel/p5-Event-ExecFlow \
		p5-Gtk2-Ex-FormFactory>=0:x11-toolkits/p5-Gtk2-Ex-FormFactory \
		p5-Event-RPC>=0:devel/p5-Event-RPC \
		p5-Locale-libintl>=0:devel/p5-Locale-libintl \
		cdrdao:sysutils/cdrdao \
		mplayer:multimedia/mplayer \
		pstree:sysutils/pstree \
		transcode:multimedia/transcode \
		vcdimager:multimedia/vcdimager \
		${LOCALBASE}/sbin/fping:net/fping \
		cdrecord:sysutils/cdrtools

USES=		gettext magick:6,run perl5 shebangfix
USE_PERL5=	configure patch

SHEBANG_FILES=	bin/dvdrip*
CONFIGURE_ENV=	SKIP_UNPACK_REQUIRED_MODULES=1

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		VORBIS SUBTITLE RAR
OPTIONS_DEFAULT=	VORBIS SUBTITLE
RAR_DESC=		Support RAR-compressed vobsub subtitles
SUBTITLE_DESC=		Enable support for getting subtitles

RAR_RUN_DEPENDS=	rar:archivers/rar
SUBTITLE_RUN_DEPENDS=	subtitle2pgm:multimedia/subtitleripper
VORBIS_RUN_DEPENDS=	oggenc:audio/vorbis-tools \
			ogmmerge:multimedia/ogmtools

post-patch:
	@${PERL} -pi -e 's#/usr/sbin/fping#${LOCALBASE}/sbin/fping#' \
		${WRKSRC}/lib/Video/DVDRip/Cluster/Master.pm \
		${WRKSRC}/lib/Video/DVDRip/Depend.pm
	@${FIND} ${WRKSRC} -name \*.orig -delete

post-install:
.for f in dvdrip-progress dvdrip-splitpipe
	@${CHMOD} u+w ${STAGEDIR}${PREFIX}/bin/${f}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
	@${CHMOD} u-w ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

.include <bsd.port.mk>
