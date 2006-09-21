# New ports collection makefile for:	www/p5-POE-Component-Server-SimpleHTTP
# Date created:				12 October 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Server-SimpleHTTP
PORTVERSION=	1.13
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Perl extension to serve HTTP requests in POE

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/HTTP/Date.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Server::SimpleHTTP.3 \
		POE::Component::Server::SimpleHTTP::Connection.3 \
		POE::Component::Server::SimpleHTTP::PreFork.3 \
		POE::Component::Server::SimpleHTTP::Response.3

OPTIONS=	SSL "SSL support (POE::Component::SSLify)" on \
		PREFORK "PreFork support (IRC::Shareable)" on

.include <bsd.port.pre.mk>

.ifdef(WITH_SSL)
BUILD_DEPENDS+=	${SITE_PERL}/POE/Component/SSLify.pm:${PORTSDIR}/security/p5-POE-Component-SSLify
.endif

.ifdef(WITH_PREFORK)
BUILD_DEPENDS+=	${SITE_PERL}/IPC/Shareable.pm:${PORTSDIR}/devel/p5-IPC-Shareable
.endif

.if ${PERL_LEVEL} < 500600  # inherited from www/p5-libwww
IGNORE=		requires Perl 5.6. Install lang/perl5 or lang/perl5.8, and try again
.endif

.include <bsd.port.post.mk>
