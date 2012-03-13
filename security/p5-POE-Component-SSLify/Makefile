# New ports collection makefile for:	POE-Component-SSLify
# Date created:	   05 November 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-SSLify
PORTVERSION=	1.008
CATEGORIES=	security perl5
MASTER_SITES=	CPAN/${PORTNAME:C/-.*//}/APOCAL
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Integrate SSL into POE

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Net-SSLeay>=1.36:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-POE>=1.267:${PORTSDIR}/devel/p5-POE \
		p5-Task-Weaken>=1.03:${PORTSDIR}/devel/p5-Task-Weaken
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::SSLify.3 \
		POE::Component::SSLify::ClientHandle.3 \
		POE::Component::SSLify::ServerHandle.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500809
BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker>=6.31:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
RUN_DEPENDS+=	p5-ExtUtils-MakeMaker>=6.31:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
.endif

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-IO>=1.28:${PORTSDIR}/devel/p5-IO
RUN_DEPENDS+=	p5-IO>=1.28:${PORTSDIR}/devel/p5-IO
.endif

.include <bsd.port.post.mk>
