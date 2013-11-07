# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-View-Template-Declare
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to use Template::Declare with Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-View-Templated>=0:${PORTSDIR}/www/p5-Catalyst-View-Templated \
		p5-Class-C3>=0:${PORTSDIR}/devel/p5-Class-C3 \
		p5-PadWalker>=0:${PORTSDIR}/devel/p5-PadWalker \
		p5-Template-Declare>=0.26:${PORTSDIR}/textproc/p5-Template-Declare
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
