# Created by: ijliao
# $FreeBSD$

PORTNAME=	WebService-ISBNDB
PORTVERSION=	0.34
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to access isbndb.com

RUN_DEPENDS=	p5-Business-ISBN>=1.80:${PORTSDIR}/misc/p5-Business-ISBN \
		p5-Class-Std>=0.0.8:${PORTSDIR}/devel/p5-Class-Std \
		p5-Error>=0.17:${PORTSDIR}/lang/p5-Error \
		p5-libwww>=5.801:${PORTSDIR}/www/p5-libwww \
		p5-XML-LibXML>=1.58:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-TimeDate>=1.16:${PORTSDIR}/devel/p5-TimeDate
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=	WebService::ISBNDB.3 \
	WebService::ISBNDB::API.3 \
	WebService::ISBNDB::API::Authors.3 \
	WebService::ISBNDB::API::Books.3 \
	WebService::ISBNDB::API::Categories.3 \
	WebService::ISBNDB::API::Publishers.3 \
	WebService::ISBNDB::API::Subjects.3 \
	WebService::ISBNDB::Agent.3 \
	WebService::ISBNDB::Agent::REST.3 \
	WebService::ISBNDB::Iterator.3 \

.include <bsd.port.mk>
