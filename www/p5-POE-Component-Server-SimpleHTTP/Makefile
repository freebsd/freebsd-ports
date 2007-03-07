# New ports collection makefile for:	www/p5-POE-Component-Server-SimpleHTTP
# Date created:				12 October 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Server-SimpleHTTP
PORTVERSION=	1.20
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Perl extension to serve HTTP requests in POE

RUN_DEPENDS=	p5-Storable>0:${PORTSDIR}/devel/p5-Storable \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		p5-POE>=0.38:${PORTSDIR}/devel/p5-POE
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Server::SimpleHTTP.3 \
		POE::Component::Server::SimpleHTTP::Connection.3 \
		POE::Component::Server::SimpleHTTP::PreFork.3 \
		POE::Component::Server::SimpleHTTP::Response.3

OPTIONS=	SSL "SSL support (POE::Component::SSLify)" on \
		PREFORK "PreFork support (IRC::Shareable)" on

.include <bsd.port.pre.mk>

.ifdef(WITH_SSL)
BUILD_DEPENDS+=	p5-POE-Component-SSLify>=0.04:${PORTSDIR}/security/p5-POE-Component-SSLify
.endif

.ifdef(WITH_PREFORK)
BUILD_DEPENDS+=	p5-IPC-Shareable>0:${PORTSDIR}/devel/p5-IPC-Shareable
.endif

.include <bsd.port.post.mk>
