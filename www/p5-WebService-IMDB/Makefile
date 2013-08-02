# New ports collection makefile for:	p5-WebService-IMDB
# Date created:		2011-06-13
# Whom:			Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	WebService-IMDB
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl interface to IMDb

RUN_DEPENDS=	p5-Cache-Cache>=0:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-Strptime>=0:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		p5-DateTime-Incomplete>=0:${PORTSDIR}/devel/p5-DateTime-Incomplete \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	configure

MAN3=		WebService::IMDB.3 \
		WebService::IMDB::Birth.3 \
		WebService::IMDB::Certificate.3 \
		WebService::IMDB::Char.3 \
		WebService::IMDB::Credit.3 \
		WebService::IMDB::CreditList.3 \
		WebService::IMDB::Date.3 \
		WebService::IMDB::DatePlace.3 \
		WebService::IMDB::DateText.3 \
		WebService::IMDB::Death.3 \
		WebService::IMDB::Encoding.3 \
		WebService::IMDB::Goof.3 \
		WebService::IMDB::Image.3 \
		WebService::IMDB::KnownFor.3 \
		WebService::IMDB::Name.3 \
		WebService::IMDB::Name::Stub.3 \
		WebService::IMDB::News.3 \
		WebService::IMDB::NewsItem.3 \
		WebService::IMDB::NewsSource.3 \
		WebService::IMDB::ParentalGuideItem.3 \
		WebService::IMDB::Photo.3 \
		WebService::IMDB::Plot.3 \
		WebService::IMDB::Quote.3 \
		WebService::IMDB::QuoteLine.3 \
		WebService::IMDB::Review.3 \
		WebService::IMDB::Runtime.3 \
		WebService::IMDB::Season.3 \
		WebService::IMDB::Title.3 \
		WebService::IMDB::Title::Stub.3 \
		WebService::IMDB::Trailer.3 \
		WebService::IMDB::Trivium.3 \
		WebService::IMDB::UserComment.3 \
		WebService::IMDB::WhereNow.3 \

.include <bsd.port.mk>
