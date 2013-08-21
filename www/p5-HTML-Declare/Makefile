# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTML-Declare
PORTVERSION=	2.4
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Very simple micro language to generate HTML

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

MAN3=		HTML::Declare.3
PLIST_FILES=	%%SITE_PERL%%/HTML/Declare.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/HTML/Declare/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/HTML/Declare

.include <bsd.port.mk>
