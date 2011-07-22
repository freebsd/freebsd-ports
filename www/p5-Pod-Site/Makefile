# New ports collection makefile for:	p5-Pod-Site
# Date created:				25 April 2010
# Whom:					milki
#
# $FreeBSD$
#

PORTNAME=	Pod-Site
PORTVERSION=	0.52
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DWHEELER
PKGNAMEPREFIX=	p5-

MAINTAINER=	milki@rescomp.berkeley.edu
COMMENT=	Build browsable HTML documentation for your app

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Object-Tiny>=0:${PORTSDIR}/devel/p5-Object-Tiny

TEST_DEPENDS=	p5-Test-File>=0:${PORTSDIR}/devel/p5-Test-File \
		p5-Test-MockModule>=0.05:${PORTSDIR}/devel/p5-Test-MockModule \
		p5-Test-XPath>=0.12:${PORTSDIR}/lang/p5-Test-XPath

OPTIONS=	PODT "Include Pod package tests" off

PERL_MODBUILD=	yes

MAN1=		podsite.1
MAN3=		Pod::Site.3

.include <bsd.port.options.mk>

.if defined(WITH_PODT)
TEST_DEPENDS+=	p5-Test-Pod>=1.41:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.06:${PORTSDIR}/devel/p5-Test-Pod-Coverage
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
RUN_DEPENDS+=	p5-File-Path>=2.07:${PORTSDIR}/devel/p5-File-Path
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.if ${PERL_LEVEL} < 501200
RUN_DEPENDS+=	p5-Pod-Simple>=3.12:${PORTSDIR}/textproc/p5-Pod-Simple
.endif

.include <bsd.port.post.mk>
