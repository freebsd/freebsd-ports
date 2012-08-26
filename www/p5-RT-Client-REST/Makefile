# New ports collection makefile for:	p5-RT-Client-REST
# Date created:				21 Mar 2007
# Whom:					svysh
#
# $FreeBSD$
#

PORTNAME=	RT-Client-REST
PORTVERSION=	0.43
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh@pn.sinp.msu.ru
COMMENT=	Perl modules designed to talk to RT installation using REST protocol

BUILD_DEPENDS=	p5-Error>=0:${PORTSDIR}/lang/p5-Error \
		p5-Exception-Class>=0:${PORTSDIR}/devel/p5-Exception-Class \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	RT::Client::REST.3 \
	RT::Client::REST::Attachment.3 \
	RT::Client::REST::Exception.3 \
	RT::Client::REST::Group.3 \
	RT::Client::REST::Object.3 \
	RT::Client::REST::Queue.3 \
	RT::Client::REST::SearchResult.3 \
	RT::Client::REST::Ticket.3 \
	RT::Client::REST::Transaction.3 \
	RT::Client::REST::User.3

.include <bsd.port.mk>
