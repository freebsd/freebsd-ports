# New ports collection makefile for:	p5-Spork
# Date created:		2004-07-18
# Whom:			Elvis Chiang <elvis@sslab.cs.ccu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Spork
PORTVERSION=	0.20
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/I/IN/INGY/
PKGNAMEPREFIX=	p5-

MAINTAINER=	include@npf.pt.freebsd.org
COMMENT=	Creating standalone HTML slideshows from Kwiki markup

BUILD_DEPENDS=	${SITE_PERL}/Kwiki.pm:${PORTSDIR}/www/p5-Kwiki
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${SITE_PERL}/Kwiki/Cache.pm:${PORTSDIR}/www/p5-Kwiki-Cache

PERL_CONFIGURE=	yes

MAN1=		spork.1
MAN3=		Spork.3 Spork::Config.3 \
		Spork::Formatter.3 Spork::Slides.3 \
		Spork::Command.3 Spork::Plugin.3

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.1 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
