# New ports collection makefile for:	Net-Amazon
# Date created:	   			Oct 23 2003
# Whom:		   			clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Net-Amazon
PORTVERSION=	0.29
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
		Net::Amazon::Property::DVD.3 \
		Net::Amazon::Property::Music.3 \
		Net::Amazon::Response.3 \
		Net::Amazon::Request.3 \
		Net::Amazon::Request::ASIN.3 \
		Net::Amazon::Request::Artist.3 \
		Net::Amazon::Request::Blended.3 \
		Net::Amazon::Request::BrowseNode.3 \
		Net::Amazon::Request::Keyword.3 \
		Net::Amazon::Request::Manufacturer.3 \
		Net::Amazon::Request::Power.3 \
		Net::Amazon::Request::Similar.3 \
		Net::Amazon::Request::UPC.3 \
		Net::Amazon::Request::Wishlist.3 \
		Net::Amazon::Request::Seller.3 \
		Net::Amazon::Request::Sort.3 \
		Net::Amazon::Request::TextStream.3 \
		Net::Amazon::Result::Seller.3 \
		Net::Amazon::Result::Seller::Listing.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500805
BUILD_DEPENDS+=	${SITE_PERL}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
.endif
.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
