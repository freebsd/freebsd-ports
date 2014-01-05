# Created by: Alex Deiter <Alex.Deiter@Gmail.COM>
# $FreeBSD$

PORTNAME=	WWW-Mechanize-TreeBuilder
PORTVERSION=	1.10003
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	alex.deiter@gmail.com
COMMENT=	WWW::Mechanize::TreeBuilder

BUILD_DEPENDS=	p5-MooseX-Role-Parameterized>=0:${PORTSDIR}/devel/p5-MooseX-Role-Parameterized \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-Test-WWW-Mechanize>=0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
