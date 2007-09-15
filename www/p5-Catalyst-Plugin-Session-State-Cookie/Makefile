# Ports collection makefile for:	p5-Catalyst-Plugin-Session-State-Cookie
# Date created:				Nov 16, 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Session-State-Cookie
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Stores a Catalyst Session in a Cookie

RUN_DEPENDS=	p5-Catalyst-Plugin-Session>=0.06:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Plugin::Session::State::Cookie.3

post-extract:
	@${PERL} -i.bak -ne 'print unless m,Test::,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
