# ex:ts=8
# Ports collection makefile for:	p5-Catalyst-Plugin-Textile
# Date created:			May 4, 2005
# Whom:				Travis Campbell <hcoyote@ghostar.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Textile
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/S/SR/SRI
PKGNAMEPREFIX=	p5-

MAINTAINER=	hcoyote@ghostar.org
COMMENT=	Textile for Catalyst

BUILD_DEPENDS=	${SITE_PERL}/Catalyst.pm:${PORTSDIR}/www/p5-Catalyst-Runtime \
	${SITE_PERL}/Text/Textile.pm:${PORTSDIR}/textproc/p5-Text-Textile
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Plugin::Textile.3

.include <bsd.port.mk>
