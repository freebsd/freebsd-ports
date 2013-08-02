# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WebService-GData
PORTVERSION=	0.0501
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SHIRIRU
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Google data protocol v2 base object to inherit from

BUILD_DEPENDS=	p5-JSON>=2.0:${PORTSDIR}/converters/p5-JSON \
		p5-Test-Mock-LWP>=0.05:${PORTSDIR}/devel/p5-Test-Mock-LWP \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-JSON>=2.0:${PORTSDIR}/converters/p5-JSON \
		p5-Test-Mock-LWP>=0.05:${PORTSDIR}/devel/p5-Test-Mock-LWP \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	configure

MAN3=	WebService::GData::Error.3 \
	WebService::GData::ClientLogin.3 \
	WebService::GData::Collection.3 \
	WebService::GData::Feed::Entry.3 \
	WebService::GData::Base.3 \
	WebService::GData::Node.3 \
	WebService::GData::Node::AbstractEntity.3 \
	WebService::GData::Serialize.3 \
	WebService::GData::YouTube::Constants.3 \
	WebService::GData::YouTube::Doc::BrowserBasedUpload.3 \
	WebService::GData::YouTube::Doc::GeneralOverview.3 \
	WebService::GData::YouTube::Feed::Complaint.3 \
	WebService::GData::YouTube::Feed::Friend.3 \
	WebService::GData::YouTube::Feed::UserProfile.3 \
	WebService::GData::YouTube::Feed::Video.3 \
	WebService::GData::YouTube::StagingServer.3 \
	WebService::GData::Constants.3 \
	WebService::GData::Query.3 \
	WebService::GData::YouTube::Query.3 \
	WebService::GData.3 \
	WebService::GData::Error::Entry.3 \
	WebService::GData::Feed.3 \
	WebService::GData::YouTube.3 \
	WebService::GData::YouTube::Feed::Comment.3 \
	WebService::GData::YouTube::Feed::PlaylistLink.3 \
	WebService::GData::YouTube::Feed::VideoMessage.3

.include <bsd.port.mk>
