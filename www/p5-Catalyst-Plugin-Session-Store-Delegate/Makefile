# New ports collection makefile for:	www/p5-Catalyst-Plugin-Session-Store-Delegate
# Date created:				28 Dec 2006
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Session-Store-Delegate
PORTVERSION=	0.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Delegate session storage to an application model object

BUILD_DEPENDS=	p5-Catalyst-Plugin-Session>=0.27:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-MRO-Compat>0:${PORTSDIR}/devel/p5-MRO-Compat
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.2+

MAN3=	Catalyst::Plugin::Session::Store::Delegate.3

.include <bsd.port.mk>
