# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-Riak
PORTVERSION=	0.17.02
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RGE
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to Riak

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-Google-ProtocolBuffers>=0:${PORTSDIR}/devel/p5-Google-ProtocolBuffers \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Role-Parameterized>=0:${PORTSDIR}/devel/p5-MooseX-Role-Parameterized \
		p5-MooseX-Traits>=0:${PORTSDIR}/devel/p5-MooseX-Traits \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-MooseX-Types-Structured>=0:${PORTSDIR}/devel/p5-MooseX-Types-Structured \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
