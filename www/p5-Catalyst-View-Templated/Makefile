# New ports collection makefile for:	Catalyst-View-Templated
# Date created:	   18 Jan 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-Templated
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JROCKWAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generic base class for template-based views

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Component-ACCEPT_CONTEXT>=0:${PORTSDIR}/www/p5-Catalyst-Component-ACCEPT_CONTEXT \
		p5-Class-C3>=0:${PORTSDIR}/devel/p5-Class-C3
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject \
		p5-Test-WWW-Mechanize-Catalyst>=0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize-Catalyst \
		p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok \

PERL_CONFIGURE=	yes

MAN3=		Catalyst::View::Templated.3

.include <bsd.port.mk>
