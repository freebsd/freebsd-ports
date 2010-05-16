# New ports collection makefile for:	p5-RT-Client-REST
# Date created:				21 Mar 2007
# Whom:					svysh
#
# $FreeBSD$
#

PORTNAME=	RT-Client-REST
PORTVERSION=	0.4
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh@pn.sinp.msu.ru
COMMENT=	Perl modules designed to talk to RT installation using REST protocol

BUILD_DEPENDS=	${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
		${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class \
		${SITE_PERL}/HTTP/Cookies.pm:${PORTSDIR}/www/p5-libwww \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	RT::Client::REST.3 \
	RT::Client::REST::Attachment.3 \
	RT::Client::REST::Exception.3 \
	RT::Client::REST::Object.3 \
	RT::Client::REST::Queue.3 \
	RT::Client::REST::SearchResult.3 \
	RT::Client::REST::Ticket.3 \
	RT::Client::REST::Transaction.3 \
	RT::Client::REST::User.3

.include <bsd.port.mk>
