# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Dancer-Plugin-SiteMap
PORTVERSION=	0.11
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JAMESR
PKGNAMEPREFIX=	p5-

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Automated site map for the Dancer web framework

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Dancer>=1.175:${PORTSDIR}/www/p5-Dancer \
		p5-XML-Simple>0:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS=	p5-Dancer>=1.175:${PORTSDIR}/www/p5-Dancer \
		p5-XML-Simple>0:${PORTSDIR}/textproc/p5-XML-Simple

USES=		perl5
USE_PERL5=	configure

MAN3=		Dancer::Plugin::SiteMap.3

NO_STAGE=	yes
.include <bsd.port.mk>
