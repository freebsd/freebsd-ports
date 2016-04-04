# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WWW-Wordnik-API
PORTVERSION=	0.0.5
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PSILVA
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Wordnik API implementation

LICENSE=	GPLv3

RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww
TEST_DEPENDS=	p5-JSON>=0:converters/p5-JSON

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	%%SITE_PERL%%/WWW/Wordnik/API.pm \
		%%PERL5_MAN3%%/WWW::Wordnik::API.3.gz

.include <bsd.port.mk>
