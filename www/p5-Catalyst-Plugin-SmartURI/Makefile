# New ports collection makefile for:	p5-Catalyst-Plugin-SmartURI
# Date created:				2008-07-09
# Whom:					Oleg Mamontov <oleg@mamontov.net>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-SmartURI
PORTVERSION=	0.034
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	oleg@mamontov.net
COMMENT=	Configurable URIs for Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7007:${PORTSDIR}/www/p5-Catalyst-Runtime	\
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor	\
		p5-Class-C3-Componentised>=0:${PORTSDIR}/devel/p5-Class-C3-Componentised	\
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken		\
		p5-URI-SmartURI>=0:${PORTSDIR}/net/p5-URI-SmartURI		\
		p5-parent>=0:${PORTSDIR}/devel/p5-parent
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Plugin::SmartURI.3

.include <bsd.port.mk>
