# New ports collection makefile for:	Net-Amazon
# Date created:	   			Oct 23 2003 \
# Whom:		   			clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Net-Amazon
PORTVERSION=	0.38
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Framework for accessing amazon.com via SOAP and XML/HTTP

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/Log/Log4perl.pm:${PORTSDIR}/devel/p5-Log-Log4perl
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Amazon.3 Net::Amazon::Attribute::Review.3 \
		Net::Amazon::Attribute::ReviewSet.3 \
		Net::Amazon::Property.3 \
		Net::Amazon::Property::Book.3 \
		Net::Amazon::Property::CE.3 \
		Net::Amazon::Property::DVD.3 \
		Net::Amazon::Property::Music.3 \
		Net::Amazon::Property::Software.3 \
		Net::Amazon::Property::VideoGames.3 \
		Net::Amazon::Request.3 \
		Net::Amazon::Request::ASIN.3 \
		Net::Amazon::Request::Actor.3 \
		Net::Amazon::Request::Artist.3 \
		Net::Amazon::Request::Author.3 \
		Net::Amazon::Request::Blended.3 \
		Net::Amazon::Request::BrowseNode.3 \
		Net::Amazon::Request::Exchange.3 \
		Net::Amazon::Request::ISBN.3 \
		Net::Amazon::Request::Keyword.3 \
		Net::Amazon::Request::Manufacturer.3 \
		Net::Amazon::Request::MusicLabel.3 \
		Net::Amazon::Request::Power.3 \
		Net::Amazon::Request::Publisher.3 \
		Net::Amazon::Request::Seller.3 \
		Net::Amazon::Request::Similar.3 \
		Net::Amazon::Request::Sort.3 \
		Net::Amazon::Request::TextStream.3 \
		Net::Amazon::Request::UPC.3 \
		Net::Amazon::Request::Wishlist.3 \
		Net::Amazon::Response.3 \
		Net::Amazon::Result::Seller.3 \
		Net::Amazon::Result::Seller::Listing.3 \
		Net::Amazon::Validate::ItemSearch.3 \
		Net::Amazon::Validate::ItemSearch::ca::Actor.3 \
		Net::Amazon::Validate::ItemSearch::ca::Artist.3 \
		Net::Amazon::Validate::ItemSearch::ca::AudienceRating.3 \
		Net::Amazon::Validate::ItemSearch::ca::Author.3 \
		Net::Amazon::Validate::ItemSearch::ca::Brand.3 \
		Net::Amazon::Validate::ItemSearch::ca::BrowseNode.3 \
		Net::Amazon::Validate::ItemSearch::ca::Composer.3 \
		Net::Amazon::Validate::ItemSearch::ca::Condition.3 \
		Net::Amazon::Validate::ItemSearch::ca::Conductor.3 \
		Net::Amazon::Validate::ItemSearch::ca::Count.3 \
		Net::Amazon::Validate::ItemSearch::ca::DeliveryMethod.3 \
		Net::Amazon::Validate::ItemSearch::ca::Director.3 \
		Net::Amazon::Validate::ItemSearch::ca::ItemPage.3 \
		Net::Amazon::Validate::ItemSearch::ca::Keywords.3 \
		Net::Amazon::Validate::ItemSearch::ca::Manufacturer.3 \
		Net::Amazon::Validate::ItemSearch::ca::MaximumPrice.3 \
		Net::Amazon::Validate::ItemSearch::ca::MerchantId.3 \
		Net::Amazon::Validate::ItemSearch::ca::MinimumPrice.3 \
		Net::Amazon::Validate::ItemSearch::ca::MusicLabel.3 \
		Net::Amazon::Validate::ItemSearch::ca::Power.3 \
		Net::Amazon::Validate::ItemSearch::ca::Publisher.3 \
		Net::Amazon::Validate::ItemSearch::ca::Sort.3 \
		Net::Amazon::Validate::ItemSearch::ca::Title.3 \
		Net::Amazon::Validate::ItemSearch::ca::UPC.3 \
		Net::Amazon::Validate::ItemSearch::de::Actor.3 \
		Net::Amazon::Validate::ItemSearch::de::Artist.3 \
		Net::Amazon::Validate::ItemSearch::de::Author.3 \
		Net::Amazon::Validate::ItemSearch::de::BrowseNode.3 \
		Net::Amazon::Validate::ItemSearch::de::Composer.3 \
		Net::Amazon::Validate::ItemSearch::de::Condition.3 \
		Net::Amazon::Validate::ItemSearch::de::Conductor.3 \
		Net::Amazon::Validate::ItemSearch::de::Count.3 \
		Net::Amazon::Validate::ItemSearch::de::DeliveryMethod.3 \
		Net::Amazon::Validate::ItemSearch::de::Director.3 \
		Net::Amazon::Validate::ItemSearch::de::ItemPage.3 \
		Net::Amazon::Validate::ItemSearch::de::Keywords.3 \
		Net::Amazon::Validate::ItemSearch::de::MPAARating.3 \
		Net::Amazon::Validate::ItemSearch::de::Manufacturer.3 \
		Net::Amazon::Validate::ItemSearch::de::MaximumPrice.3 \
		Net::Amazon::Validate::ItemSearch::de::MerchantId.3 \
		Net::Amazon::Validate::ItemSearch::de::MinimumPrice.3 \
		Net::Amazon::Validate::ItemSearch::de::MusicLabel.3 \
		Net::Amazon::Validate::ItemSearch::de::Power.3 \
		Net::Amazon::Validate::ItemSearch::de::Publisher.3 \
		Net::Amazon::Validate::ItemSearch::de::Sort.3 \
		Net::Amazon::Validate::ItemSearch::de::Title.3 \
		Net::Amazon::Validate::ItemSearch::de::UPC.3 \
		Net::Amazon::Validate::ItemSearch::fr::Actor.3 \
		Net::Amazon::Validate::ItemSearch::fr::Artist.3 \
		Net::Amazon::Validate::ItemSearch::fr::AudienceRating.3 \
		Net::Amazon::Validate::ItemSearch::fr::Author.3 \
		Net::Amazon::Validate::ItemSearch::fr::Brand.3 \
		Net::Amazon::Validate::ItemSearch::fr::BrowseNode.3 \
		Net::Amazon::Validate::ItemSearch::fr::Composer.3 \
		Net::Amazon::Validate::ItemSearch::fr::Condition.3 \
		Net::Amazon::Validate::ItemSearch::fr::Conductor.3 \
		Net::Amazon::Validate::ItemSearch::fr::Count.3 \
		Net::Amazon::Validate::ItemSearch::fr::DeliveryMethod.3 \
		Net::Amazon::Validate::ItemSearch::fr::Director.3 \
		Net::Amazon::Validate::ItemSearch::fr::ItemPage.3 \
		Net::Amazon::Validate::ItemSearch::fr::Keywords.3 \
		Net::Amazon::Validate::ItemSearch::fr::Manufacturer.3 \
		Net::Amazon::Validate::ItemSearch::fr::MaximumPrice.3 \
		Net::Amazon::Validate::ItemSearch::fr::MerchantId.3 \
		Net::Amazon::Validate::ItemSearch::fr::MinimumPrice.3 \
		Net::Amazon::Validate::ItemSearch::fr::MusicLabel.3 \
		Net::Amazon::Validate::ItemSearch::fr::Power.3 \
		Net::Amazon::Validate::ItemSearch::fr::Publisher.3 \
		Net::Amazon::Validate::ItemSearch::fr::Sort.3 \
		Net::Amazon::Validate::ItemSearch::fr::Title.3 \
		Net::Amazon::Validate::ItemSearch::fr::UPC.3 \
		Net::Amazon::Validate::ItemSearch::jp::Actor.3 \
		Net::Amazon::Validate::ItemSearch::jp::Artist.3 \
		Net::Amazon::Validate::ItemSearch::jp::Author.3 \
		Net::Amazon::Validate::ItemSearch::jp::Brand.3 \
		Net::Amazon::Validate::ItemSearch::jp::BrowseNode.3 \
		Net::Amazon::Validate::ItemSearch::jp::Composer.3 \
		Net::Amazon::Validate::ItemSearch::jp::Condition.3 \
		Net::Amazon::Validate::ItemSearch::jp::Conductor.3 \
		Net::Amazon::Validate::ItemSearch::jp::Director.3 \
		Net::Amazon::Validate::ItemSearch::jp::ItemPage.3 \
		Net::Amazon::Validate::ItemSearch::jp::Keywords.3 \
		Net::Amazon::Validate::ItemSearch::jp::Manufacturer.3 \
		Net::Amazon::Validate::ItemSearch::jp::MaximumPrice.3 \
		Net::Amazon::Validate::ItemSearch::jp::MerchantId.3 \
		Net::Amazon::Validate::ItemSearch::jp::MinimumPrice.3 \
		Net::Amazon::Validate::ItemSearch::jp::MusicLabel.3 \
		Net::Amazon::Validate::ItemSearch::jp::Orchestra.3 \
		Net::Amazon::Validate::ItemSearch::jp::Power.3 \
		Net::Amazon::Validate::ItemSearch::jp::Publisher.3 \
		Net::Amazon::Validate::ItemSearch::jp::Sort.3 \
		Net::Amazon::Validate::ItemSearch::jp::Title.3 \
		Net::Amazon::Validate::ItemSearch::jp::UPC.3 \
		Net::Amazon::Validate::ItemSearch::uk::Actor.3 \
		Net::Amazon::Validate::ItemSearch::uk::Artist.3 \
		Net::Amazon::Validate::ItemSearch::uk::Author.3 \
		Net::Amazon::Validate::ItemSearch::uk::Brand.3 \
		Net::Amazon::Validate::ItemSearch::uk::BrowseNode.3 \
		Net::Amazon::Validate::ItemSearch::uk::Composer.3 \
		Net::Amazon::Validate::ItemSearch::uk::Condition.3 \
		Net::Amazon::Validate::ItemSearch::uk::Conductor.3 \
		Net::Amazon::Validate::ItemSearch::uk::Director.3 \
		Net::Amazon::Validate::ItemSearch::uk::ItemPage.3 \
		Net::Amazon::Validate::ItemSearch::uk::Keywords.3 \
		Net::Amazon::Validate::ItemSearch::uk::MPAARating.3 \
		Net::Amazon::Validate::ItemSearch::uk::Manufacturer.3 \
		Net::Amazon::Validate::ItemSearch::uk::MaximumPrice.3 \
		Net::Amazon::Validate::ItemSearch::uk::MerchantId.3 \
		Net::Amazon::Validate::ItemSearch::uk::MinimumPrice.3 \
		Net::Amazon::Validate::ItemSearch::uk::MusicLabel.3 \
		Net::Amazon::Validate::ItemSearch::uk::Orchestra.3 \
		Net::Amazon::Validate::ItemSearch::uk::Power.3 \
		Net::Amazon::Validate::ItemSearch::uk::Publisher.3 \
		Net::Amazon::Validate::ItemSearch::uk::Sort.3 \
		Net::Amazon::Validate::ItemSearch::uk::Title.3 \
		Net::Amazon::Validate::ItemSearch::uk::UPC.3 \
		Net::Amazon::Validate::ItemSearch::us::Actor.3 \
		Net::Amazon::Validate::ItemSearch::us::Artist.3 \
		Net::Amazon::Validate::ItemSearch::us::AudienceRating.3 \
		Net::Amazon::Validate::ItemSearch::us::Author.3 \
		Net::Amazon::Validate::ItemSearch::us::Brand.3 \
		Net::Amazon::Validate::ItemSearch::us::BrowseNode.3 \
		Net::Amazon::Validate::ItemSearch::us::City.3 \
		Net::Amazon::Validate::ItemSearch::us::Composer.3 \
		Net::Amazon::Validate::ItemSearch::us::Condition.3 \
		Net::Amazon::Validate::ItemSearch::us::Conductor.3 \
		Net::Amazon::Validate::ItemSearch::us::Count.3 \
		Net::Amazon::Validate::ItemSearch::us::Cuisine.3 \
		Net::Amazon::Validate::ItemSearch::us::DeliveryMethod.3 \
		Net::Amazon::Validate::ItemSearch::us::Director.3 \
		Net::Amazon::Validate::ItemSearch::us::ISPUPostalCode.3 \
		Net::Amazon::Validate::ItemSearch::us::ItemPage.3 \
		Net::Amazon::Validate::ItemSearch::us::Keywords.3 \
		Net::Amazon::Validate::ItemSearch::us::MPAARating.3 \
		Net::Amazon::Validate::ItemSearch::us::Manufacturer.3 \
		Net::Amazon::Validate::ItemSearch::us::MaximumPrice.3 \
		Net::Amazon::Validate::ItemSearch::us::MerchantId.3 \
		Net::Amazon::Validate::ItemSearch::us::MinimumPrice.3 \
		Net::Amazon::Validate::ItemSearch::us::MusicLabel.3 \
		Net::Amazon::Validate::ItemSearch::us::Neighborhood.3 \
		Net::Amazon::Validate::ItemSearch::us::Orchestra.3 \
		Net::Amazon::Validate::ItemSearch::us::Power.3 \
		Net::Amazon::Validate::ItemSearch::us::Publisher.3 \
		Net::Amazon::Validate::ItemSearch::us::Sort.3 \
		Net::Amazon::Validate::ItemSearch::us::State.3 \
		Net::Amazon::Validate::ItemSearch::us::TextStream.3 \
		Net::Amazon::Validate::ItemSearch::us::Title.3 \
		Net::Amazon::Validate::ItemSearch::us::UPC.3 \
		Net::Amazon::Validate::Type.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500805
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
.endif
.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
