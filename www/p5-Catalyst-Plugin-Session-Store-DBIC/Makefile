# New ports collection makefile for:	www/p5-Catalyst-Plugin-Session-Store-DBIC
# Date created:				28 Dec 2006
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Session-Store-DBIC
PORTVERSION=	0.11
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Store your sessions via DBIx::Class

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Plugin-Session-Store-Delegate>=0.05:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-Store-Delegate \
		p5-DBIx-Class>=0.0700:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-MRO-Compat>0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.2+

MAN3=	Catalyst::Plugin::Session::Store::DBIC.3 \
	Catalyst::Plugin::Session::Store::DBIC::Delegate.3

.include <bsd.port.mk>
