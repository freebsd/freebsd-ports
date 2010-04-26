# New ports collection makefile for:	p5-Pod-Site
# Date created:				25 April 2010
# Whom:					milki
#
# $FreeBSD$
#

PORTNAME=	Pod-Site
PORTVERSION=	0.52
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	 ../../authors/id/D/DW/DWHEELER
PKGNAMEPREFIX=	p5-

MAINTAINER=	milki@rescomp.berkeley.edu
COMMENT=	Build browsable HTML documentation for your app

BUILD_DEPENDS=	  p5-Module-Build>=0.35:${PORTSDIR}/devel/p5-Module-Build \
		p5-Test-MockModule>=0.05:${PORTSDIR}/devel/p5-Test-MockModule \
		p5-Test-XPath>=0.12:${PORTSDIR}/lang/p5-Test-XPath \
		p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	p5-File-Path>=2.07:${PORTSDIR}/devel/p5-File-Path \
		p5-Getopt-Long>=0:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Object-Tiny>=0:${PORTSDIR}/devel/p5-Object-Tiny \
		p5-Pod-Parser>=0:${PORTSDIR}/textproc/p5-Pod-Parser \
		p5-Pod-Simple>=3.12:${PORTSDIR}/textproc/p5-Pod-Simple \
		p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools

PERL_MODBUILD=	YES

MAN1=	podsite.1

MAN3=	Pod::Site.3

.include <bsd.port.mk>
