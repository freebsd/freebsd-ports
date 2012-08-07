# New ports collection makefile for:	p5-Dancer-Plugin-SiteMap
# Date created:				2012-01-27
# Whom:					Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	Dancer-Plugin-SiteMap
PORTVERSION=	0.11
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JAMESR
PKGNAMEPREFIX=	p5-

MAINTAINER=	magik@roorback.net
COMMENT=	Automated site map for the Dancer web framework

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Dancer>=1.175:${PORTSDIR}/www/p5-Dancer \
		p5-XML-Simple>0:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS=	p5-Dancer>=1.175:${PORTSDIR}/www/p5-Dancer \
		p5-XML-Simple>0:${PORTSDIR}/textproc/p5-XML-Simple

PERL_CONFIGURE=	yes

MAN3=		Dancer::Plugin::SiteMap.3

.include <bsd.port.mk>
