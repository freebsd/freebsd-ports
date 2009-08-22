# New ports collection makefile for:	p5-GStreamer
# Date created:		2005-10-17
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	GStreamer
PORTVERSION=	0.09
PORTREVISION=	2
CATEGORIES=	multimedia perl5
MASTER_SITES=	SF/gtk2-perl/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A set of Perl5 bindings for gstreamer

BUILD_DEPENDS=	p5-Glib2>=1.101:${PORTSDIR}/devel/p5-Glib2 \
		${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig
RUN_DEPENDS=	p5-Glib2>=1.101:${PORTSDIR}/devel/p5-Glib2 \
		${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig

USE_GMAKE=	yes
USE_GSTREAMER=	yes
PERL_CONFIGURE=	yes

MAN3=	GStreamer.3 GStreamer::Bin.3 GStreamer::Buffer.3 GStreamer::Bus.3 \
	GStreamer::Caps.3 GStreamer::Caps::Any.3 GStreamer::Caps::Empty.3 \
	GStreamer::Caps::Full.3 GStreamer::Caps::Simple.3 \
	GStreamer::ChildProxy.3 GStreamer::Clock.3 GStreamer::ClockID.3 \
	GStreamer::Element.3 GStreamer::ElementFactory.3 GStreamer::Event.3 \
	GStreamer::Event::BufferSize.3 GStreamer::Event::Custom.3 \
	GStreamer::Event::EOS.3 GStreamer::Event::FlushStart.3 \
	GStreamer::Event::FlushStop.3 GStreamer::Event::Navigation.3 \
	GStreamer::Event::NewSegment.3 GStreamer::Event::QOS.3 \
	GStreamer::Event::Seek.3 GStreamer::Event::Tag.3 GStreamer::Format.3 \
	GStreamer::GhostPad.3 GStreamer::Index.3 GStreamer::IndexEntry.3 \
	GStreamer::IndexFactory.3 GStreamer::Iterator.3 \
	GStreamer::Iterator::Tie.3 GStreamer::Message.3 \
	GStreamer::Message::Application.3 GStreamer::Message::ClockLost.3 \
	GStreamer::Message::ClockProvide.3 GStreamer::Message::Custom.3 \
	GStreamer::Message::Duration.3 GStreamer::Message::EOS.3 \
	GStreamer::Message::Element.3 GStreamer::Message::Error.3 \
	GStreamer::Message::NewClock.3 GStreamer::Message::SegmentDone.3 \
	GStreamer::Message::SegmentStart.3 GStreamer::Message::StateChanged.3 \
	GStreamer::Message::StateDirty.3 GStreamer::Message::Tag.3 \
	GStreamer::Message::Warning.3 GStreamer::MiniObject.3 \
	GStreamer::Object.3 GStreamer::Pad.3 GStreamer::PadTemplate.3 \
	GStreamer::Pipeline.3 GStreamer::Plugin.3 GStreamer::PluginFeature.3 \
	GStreamer::Query.3 GStreamer::Query::Application.3 \
	GStreamer::Query::Convert.3 GStreamer::Query::Duration.3 \
	GStreamer::Query::Position.3 GStreamer::Query::Segment.3 \
	GStreamer::QueryType.3 GStreamer::Registry.3 GStreamer::Structure.3 \
	GStreamer::SystemClock.3 GStreamer::Tag.3 GStreamer::TagSetter.3 \
	GStreamer::TypeFindFactory.3 GStreamer::index.3

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == "sparc64"
BROKEN=		Coredump during build on ${ARCH}
.endif

PERL_THREADED!=	${PERL} -mthreads -e '' >/dev/null 2>&1 && ${ECHO_CMD} 'yes' || true
.if ${PERL_THREADED} == ""
IGNORE=		must be built with a threaded Perl, reinstall Perl with WITH_THREADS=yes
.endif

.include <bsd.port.post.mk>
