# New ports collection makefile for:	www/p5-Catalyst-View-TT-ControllerLocal
# Date created:				11 Feb 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-TT-ControllerLocal
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catalyst TT View with template names relative to the Controller

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Devel>=1.00:${PORTSDIR}/www/p5-Catalyst-Devel \
		p5-Catalyst-View-TT>=0:${PORTSDIR}/www/p5-Catalyst-View-TT \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.2+

MAN3=	Catalyst::Helper::View::TTControllerLocal.3 \
	Catalyst::View::TT::ControllerLocal.3

.include <bsd.port.mk>
