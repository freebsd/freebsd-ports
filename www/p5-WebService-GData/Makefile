# New ports collection makefile for:	www/p5-WebService-GData
# Date created:				Oct 11, 2010
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WebService-GData
PORTVERSION=	0.0402
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SHIRIRU
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Google data protocol v2 base object to inherit from

BUILD_DEPENDS=	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		p5-JSON>=2.0:${PORTSDIR}/converters/p5-JSON \
		p5-Test-Mock-LWP>=0.05:${PORTSDIR}/devel/p5-Test-Mock-LWP
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

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
	WebService::GData::YouTube::Feed::Video.3 \
	WebService::GData::Constants.3 \
	WebService::GData::Query.3 \
	WebService::GData::YouTube::Query.3 \
	WebService::GData.3 \
	WebService::GData::Error::Entry.3 \
	WebService::GData::Feed.3 \
	WebService::GData::YouTube.3 \
	WebService::GData::YouTube::Feed::Comment.3 \
	WebService::GData::YouTube::Feed::PlaylistLink.3

.include <bsd.port.mk>
