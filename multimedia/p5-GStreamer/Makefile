# New ports collection makefile for:	p5-GStreamer
# Date created:		2005-10-17
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	GStreamer
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	multimedia perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtk2-perl
PKGNAMEPREFIX=	p5-

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	A set of Perl5 bindings for gstreamer

BUILD_DEPENDS=	p5-Glib2>=1.101:${PORTSDIR}/devel/p5-Glib2 \
		${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GSTREAMER=	yes

MAN3=	GStreamer.3 GStreamer::Bin.3 GStreamer::Buffer.3 GStreamer::Caps.3 \
	GStreamer::Clock.3 GStreamer::ClockID.3 GStreamer::Data.3 GStreamer::Element.3 \
	GStreamer::ElementFactory.3 GStreamer::Error.3 GStreamer::Event.3 GStreamer::Format.3 \
	GStreamer::Index.3 GStreamer::IndexEntry.3 GStreamer::IndexFactory.3 GStreamer::Library.3 \
	GStreamer::Object.3 GStreamer::Pad.3 GStreamer::PadTemplate.3 GStreamer::Parse.3 GStreamer::Pipeline.3 \
	GStreamer::Plugin.3 GStreamer::PluginFeature.3 GStreamer::QueryType.3 GStreamer::Registry.3 \
	GStreamer::RegistryPool.3 GStreamer::Scheduler.3 GStreamer::SchedulerFactory.3 GStreamer::Structure.3 \
	GStreamer::Tag.3 GStreamer::TagSetter.3 GStreamer::Thread.3 GStreamer::index.3

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == "sparc64"
BROKEN=		"Coredump during build on ${ARCH}"
.endif

BROKEN=		uses strndup() which FreeBSD does not have

.include <bsd.port.post.mk>
