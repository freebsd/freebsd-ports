# New ports collection makefile for:   dvdrip
# Date created:	18 April 2002
# Whom:		Michael Nottebrock <michaelnottebrock@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	dvdrip
PORTVERSION=	0.50.13
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.exit1.org/dvdrip/dist/
DISTNAME=	Video-DVDRip-${PORTVERSION}

MAINTAINER=	lofi@freebsd.org
COMMENT=	This is dvd::rip, a Perl Gtk+ based dvd-ripper

.if !defined(WITHOUT_CLUSTER)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/${PERL_ARCH}/Event.pm:${PORTSDIR}/devel/p5-Event \
		${LOCALBASE}/sbin/fping:${PORTSDIR}/net/fping \
		pstree:${PORTSDIR}/sysutils/pstree
.endif
RUN_DEPENDS+=	cdrdao:${PORTSDIR}/sysutils/cdrdao \
		cdrecord:${PORTSDIR}/sysutils/cdrtools \
		convert:${PORTSDIR}/graphics/ImageMagick \
		mkisofs:${PORTSDIR}/sysutils/mkisofs \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		ogmmerge:${PORTSDIR}/multimedia/ogmtools \
		rar:${PORTSDIR}/archivers/rar \
		transcode:${PORTSDIR}/multimedia/transcode \
		vcdimager:${PORTSDIR}/multimedia/vcdimager \
		${BUILD_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk \
		${SITE_PERL}/${PERL_ARCH}/Gtk/Gdk/Pixbuf.pm:${PORTSDIR}/x11-toolkits/p5-GdkPixbuf

PERL_CONFIGURE=	yes
USE_PERL5=	yes

MAN1=		dvdrip.1 dr_splitpipe.1 dr_progress.1

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Video::DVDRip.3

.include <bsd.port.pre.mk>

pre-everything::
.if !defined(WITHOUT_CLUSTER)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can disable the cluster daemon and its"
	@${ECHO_MSG} "dependencies by defining WITHOUT_CLUSTER."
	@${ECHO_MSG}
	@${ECHO_MSG} "Warning: dvdrip does not like this and will"
	@${ECHO_MSG} "throw cryptic error-messages. Use with caution."
.endif

post-patch:
	@${PERL} -pi -e 's#/usr/sbin/fping#${LOCALBASE}/sbin/fping#' \
		${WRKSRC}/lib/Video/DVDRip/Cluster/Master.pm
	@${PERL} -pi -e 's#/usr/local/bin/perl#${PERL5}#' \
		${WRKSRC}/dvdrip
	@${PERL} -pi -e 's#/usr/local/bin/perl#${PERL5}#' \
		${WRKSRC}/dvdrip-master
	@${PERL} -pi -e 's#cc#${CC}#' \
		${WRKSRC}/src/Makefile
	@${FIND} ${WRKSRC} -name *.orig -delete

post-install:
	@${CAT} ${PKGMESSAGE}

.if ${PERL_LEVEL} < 500600
BROKEN=	"You need at least perl 5.6.0. Do not use FreeBSD 4.x' system perl,\
	it's outdated. Install lang/perl5 and issue 'use.perl port'"
.endif

.include <bsd.port.post.mk>
