# New ports collection makefile for:	www/p5-POE-Component-Server-SimpleHTTP
# Date created:				12 October 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Server-SimpleHTTP
PORTVERSION=	2.10
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Perl extension to serve HTTP requests in POE

RUN_DEPENDS=	p5-Moose>=0.81:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-AttributeHelpers>0:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers \
		p5-MooseX-POE>=0.205:${PORTSDIR}/devel/p5-MooseX-POE \
		p5-POE>=1.0000:${PORTSDIR}/devel/p5-POE \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-POE-Filter-HTTP-Parser>=1.06:${PORTSDIR}/www/p5-POE-Filter-HTTP-Parser

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Server::SimpleHTTP.3 \
		POE::Component::Server::SimpleHTTP::Connection.3 \
		POE::Component::Server::SimpleHTTP::Response.3

OPTIONS=	SSL "SSL support (POE::Component::SSLify)" on \

.include <bsd.port.pre.mk>

.ifdef(WITH_SSL)
BUILD_DEPENDS+=	p5-POE-Component-SSLify>=0.04:${PORTSDIR}/security/p5-POE-Component-SSLify
.endif

.include <bsd.port.post.mk>
