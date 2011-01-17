# New ports collection makefile for:	p5-Spork
# Date created:		2004-07-18
# Whom:			Elvis Chiang <elvis@sslab.cs.ccu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Spork
PORTVERSION=	0.20
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/I/IN/INGY/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Creating standalone HTML slideshows from Kwiki markup

BUILD_DEPENDS=	${LOCALBASE}/kwiki/lib/Kwiki.pm:${PORTSDIR}/www/p5-Kwiki
RUN_DEPENDS=	${LOCALBASE}/kwiki/lib/Kwiki.pm:${PORTSDIR}/www/p5-Kwiki

PERL_CONFIGURE=	yes

MAN1=		spork.1
MAN3=		Spork.3 Spork::Config.3 \
		Spork::Formatter.3 Spork::Slides.3 \
		Spork::Command.3 Spork::Plugin.3

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
