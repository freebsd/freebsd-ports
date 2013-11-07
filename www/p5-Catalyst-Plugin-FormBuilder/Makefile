# Created by: Fernan Aguero
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-FormBuilder
PORTVERSION=	1.07
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FormBuilder for Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-CGI-FormBuilder>=3.02:${PORTSDIR}/www/p5-CGI-FormBuilder
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
