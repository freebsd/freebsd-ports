# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WebService-GData
PORTVERSION=	0.0501
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SHIRIRU
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Google data protocol v2 base object to inherit from

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON>=2.0:${PORTSDIR}/converters/p5-JSON \
		p5-Test-Mock-LWP>=0.05:${PORTSDIR}/devel/p5-Test-Mock-LWP \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-JSON>=2.0:${PORTSDIR}/converters/p5-JSON \
		p5-Test-Mock-LWP>=0.05:${PORTSDIR}/devel/p5-Test-Mock-LWP \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
