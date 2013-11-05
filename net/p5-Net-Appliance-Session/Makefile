# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Appliance-Session
PORTVERSION=	4.131.260
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Run command-line sessions to network appliances

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-Prompt-Tiny>=0:${PORTSDIR}/devel/p5-IO-Prompt-Tiny \
		p5-Moo>=0:${PORTSDIR}/devel/p5-Moo \
		p5-MooX-Types-MooseLike>=0:${PORTSDIR}/devel/p5-MooX-Types-MooseLike \
		p5-Net-CLI-Interact>=2.122.730:${PORTSDIR}/net/p5-Net-CLI-Interact \
		p5-Term-ReadPassword>=0:${PORTSDIR}/devel/p5-Term-ReadPassword \
		p5-Text-Glob>=0:${PORTSDIR}/textproc/p5-Text-Glob \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
