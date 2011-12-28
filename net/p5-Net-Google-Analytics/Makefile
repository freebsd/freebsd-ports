# New ports collection makefile for:	Net::Google::Analytics
# Date created:		28 Dec 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Google-Analytics
PORTVERSION=	0.11003
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Google Analytics Data Export API

RUN_DEPENDS=	\
	p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-URI>0:${PORTSDIR}/net/p5-URI \
	p5-XML-LibXML>0:${PORTSDIR}/textproc/p5-XML-LibXML
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Net::Google::Analytics.3 \
	Net::Google::Analytics::AccountFeed.3 \
	Net::Google::Analytics::AccountFeedEntry.3 \
	Net::Google::Analytics::AccountFeedResponse.3 \
	Net::Google::Analytics::DataFeed.3 \
	Net::Google::Analytics::DataFeedEntry.3 \
	Net::Google::Analytics::DataFeedRequest.3 \
	Net::Google::Analytics::DataFeedResponse.3 \
	Net::Google::Analytics::Dimension.3 \
	Net::Google::Analytics::Feed.3 \
	Net::Google::Analytics::FeedRequest.3 \
	Net::Google::Analytics::FeedResponse.3 \
	Net::Google::Analytics::Metric.3 \
	Net::Google::Analytics::XML.3

.include <bsd.port.mk>
