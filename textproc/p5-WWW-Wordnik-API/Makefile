# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WWW-Wordnik-API
PORTVERSION=	0.0.5
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PSILVA
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Wordnik API implementation

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
TEST_DEPENDS=	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON

USES=		perl5
USE_PERL5=	configure

MAN3=		WWW::Wordnik::API.3
PLIST_FILES=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW/Wordnik/API/.packlist \
		%%SITE_PERL%%/WWW/Wordnik/API.pm
PLIST_DIRS=	%%SITE_PERL%%/WWW/Wordnik %%SITE_PERL%%/WWW \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW/Wordnik/API \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW/Wordnik \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/WWW

NO_STAGE=	yes
.include <bsd.port.mk>
