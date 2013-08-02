# Created by: Elvis Chiang <elvis@sslab.cs.ccu.edu.tw>
# $FreeBSD$

PORTNAME=	Spork
PORTVERSION=	0.21
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:INGY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Creating standalone HTML slideshows from Kwiki markup

RUN_DEPENDS=	p5-Kwiki>=0.38:${PORTSDIR}/www/p5-Kwiki \
		p5-Spoon>=0.22:${PORTSDIR}/devel/p5-Spoon

USES=		perl5
USE_PERL5=	configure

MAN1=		spork.1
MAN3=		Spork.3 Spork::Config.3 \
		Spork::Formatter.3 Spork::Slides.3 \
		Spork::Command.3 Spork::Plugin.3

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
