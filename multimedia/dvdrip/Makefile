# New ports collection makefile for:   dvdrip
# Date created:	18 April 2002
# Whom:		Michael Nottebrock <michaelnottebrock@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	dvdrip
PORTVERSION=	0.98.11
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.exit1.org/dvdrip/dist/ \
		CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/J/JR/JRED

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Perl Gtk+ based dvd-ripper

RUN_DEPENDS+=	cdrdao:${PORTSDIR}/sysutils/cdrdao \
		convert:${PORTSDIR}/graphics/ImageMagick \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		pstree:${PORTSDIR}/sysutils/pstree \
		transcode:${PORTSDIR}/multimedia/transcode \
		vcdimager:${PORTSDIR}/multimedia/vcdimager \
		xvid4conf:${PORTSDIR}/multimedia/xvid4conf \
		rar:${PORTSDIR}/archivers/rar \
		${LOCALBASE}/sbin/fping:${PORTSDIR}/net/fping \
		${BUILD_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/AnyEvent.pm:${PORTSDIR}/devel/p5-AnyEvent \
		${SITE_PERL}/Event/ExecFlow.pm:${PORTSDIR}/devel/p5-Event-ExecFlow \
		${SITE_PERL}/Gtk2/Ex/FormFactory.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2-Ex-FormFactory \
		${SITE_PERL}/Event/RPC.pm:${PORTSDIR}/devel/p5-Event-RPC \
		${SITE_PERL}/Locale/Messages.pm:${PORTSDIR}/devel/p5-Locale-libintl

OPTIONS=	SUBTITLE	"Enable support for getting subtitles"	on \
		VORBIS		"OGG/Vorbis audio support" on

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	SKIP_UNPACK_REQUIRED_MODULES=1
USE_CDRTOOLS=	yes
USE_GETTEXT=	yes

MAN1=		dvdrip.1 dvdrip-progress.1 dvdrip-splitpipe.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_VORBIS)
RUN_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools \
		ogmmerge:${PORTSDIR}/multimedia/ogmtools
.endif

.if !defined(WITHOUT_SUBTITLE)
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

.include <bsd.port.post.mk>
