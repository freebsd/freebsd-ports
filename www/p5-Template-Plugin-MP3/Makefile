# New ports collection makefile for:	p5-Template-Plugin-MP3
# Date created:		13 June 2004
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Template-Plugin-MP3
PORTVERSION=	1.01
CATEGORIES=	www textproc audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Template
PKGNAMEPREFIX=	p5-

MAINTAINER=	knu@FreeBSD.org
COMMENT=	TT Plugin that wraps around the MP3::Info module

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/MP3/Info.pm:${PORTSDIR}/audio/p5-MP3-Info
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Template::Plugin::MP3.3

.include <bsd.port.mk>
