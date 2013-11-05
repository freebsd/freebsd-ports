# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net
PORTVERSION=	1.23
PORTEPOCH=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	libnet-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 modules to access and use network protocols

OPTIONS_DEFINE=		SASL
OPTIONS_DEFAULT=	SASL
SASL_DESC=		SASL auth for POP3 and SMTP support.

SASL_RUN_DEPENDS=	p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL

PORTSCOUT=	skipv:1.0901

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
