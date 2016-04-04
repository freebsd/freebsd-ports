# Created by: Michael Nottebrock <michaelnottebrock@gmx.net>
# $FreeBSD$

PORTNAME=	dvdrip
PORTVERSION=	0.98.11
PORTREVISION=	9
CATEGORIES=	multimedia
MASTER_SITES=	CPAN http://www.exit1.org/dvdrip/dist/
MASTER_SITE_SUBDIR=	CPAN:JRED

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl Gtk+ based dvd-ripper

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
		convert:graphics/ImageMagick \
		mplayer:multimedia/mplayer \
		pstree:sysutils/pstree \
		transcode:multimedia/transcode \
		vcdimager:multimedia/vcdimager \
		${LOCALBASE}/sbin/fping:net/fping \
		cdrecord:sysutils/cdrtools

OPTIONS_DEFINE=	VORBIS SUBTITLE RAR
OPTIONS_DEFAULT=	VORBIS SUBTITLE
RAR_DESC=	Support RAR-compressed vobsub subtitles
SUBTITLE_DESC=	Enable support for getting subtitles

RAR_RUN_DEPENDS=	rar:archivers/rar
SUBTITLE_RUN_DEPENDS=	subtitle2pgm:multimedia/subtitleripper
VORBIS_RUN_DEPENDS=	oggenc:audio/vorbis-tools \
			ogmmerge:multimedia/ogmtools

CONFIGURE_ENV=	SKIP_UNPACK_REQUIRED_MODULES=1
USES=		gettext perl5 shebangfix
USE_PERL5=	configure patch
SHEBANG_FILES=	bin/dvdrip*

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${PERL} -pi -e 's#/usr/sbin/fping#${LOCALBASE}/sbin/fping#' \
		${WRKSRC}/lib/Video/DVDRip/Cluster/Master.pm \
		${WRKSRC}/lib/Video/DVDRip/Depend.pm
	@${FIND} ${WRKSRC} -name \*.orig -delete

post-install:
.for f in dvdrip-progress dvdrip-splitpipe
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/bin/${f}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
	${CHMOD} u-w ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

.include <bsd.port.mk>
