# ex:ts=8
# Ports collection makefile for:	WebService::Technorati
# Date created:			May 25, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	WebService-Technorati
PORTVERSION=	0.04
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Perl interface to the Technorati web services interface

BUILD_DEPENDS=	p5-XML-XPath>=0:${PORTSDIR}/textproc/p5-XML-XPath \
		p5-Exception-Class>=0:${PORTSDIR}/devel/p5-Exception-Class \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	WebService::Technorati.3 \
	WebService::Technorati::ApiQuery.3 \
	WebService::Technorati::Author.3 \
	WebService::Technorati::AuthorinfoApiQuery.3 \
	WebService::Technorati::Blog.3 \
	WebService::Technorati::BlogLink.3 \
	WebService::Technorati::BloginfoApiQuery.3 \
	WebService::Technorati::CosmosApiQuery.3 \
	WebService::Technorati::Exception.3 \
	WebService::Technorati::LinkQuerySubject.3 \
	WebService::Technorati::OutboundApiQuery.3 \
	WebService::Technorati::SearchApiQuery.3 \
	WebService::Technorati::SearchMatch.3 \
	WebService::Technorati::SearchTerm.3

.include <bsd.port.mk>
