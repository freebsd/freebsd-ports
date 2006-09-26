# ex:ts=8
# Ports collection makefile for:	Net-Blogger
# Date created:			Jan 10, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Net-Blogger
PORTVERSION=	1.02
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	An OOP-ish interface for accessing a weblog via the XML-RPC API

BUILD_DEPENDS=	${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/HTTP/Cookies.pm:${PORTSDIR}/www/p5-libwww \
		p5-SOAP-Lite>0.55:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Net::Blogger.3 \
	Net::Blogger::API::Core.3 \
	Net::Blogger::API::Extended.3 \
	Net::Blogger::Engine::Base.3 \
	Net::Blogger::Engine::Blogger.3 \
	Net::Blogger::Engine::Manila.3 \
	Net::Blogger::Engine::Movabletype.3 \
	Net::Blogger::Engine::Movabletype::mt.3 \
	Net::Blogger::Engine::Radio.3 \
	Net::Blogger::Engine::Slash.3 \
	Net::Blogger::Engine::Slash::slashcode.3 \
	Net::Blogger::Engine::Userland.3 \
	Net::Blogger::Engine::Userland::metaWeblog.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires Perl 5.6 or newer. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
