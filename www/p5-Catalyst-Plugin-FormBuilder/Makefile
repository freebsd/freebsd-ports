# Created by: Fernan Aguero
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-FormBuilder
PORTVERSION=	1.07
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	FormBuilder for Catalyst

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7:www/p5-Catalyst-Runtime \
		p5-CGI-FormBuilder>=3.02:www/p5-CGI-FormBuilder
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 tar:tgz
USE_PERL5=	configure

.include <bsd.port.mk>
