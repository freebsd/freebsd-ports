# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net
PORTVERSION=	1.30
PORTEPOCH=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	libnet-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 modules to access and use network protocols

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

OPTIONS_DEFINE=	IPV6 SASL SSL
OPTIONS_DEFAULT=SASL
SASL_DESC=	SASL auth for POP3 and SMTP support

SASL_BUILD_DEPENDS=	p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL
SASL_RUN_DEPENDS=	p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL
SSL_BUILD_DEPENDS=	p5-IO-Socket-SSL>=1.994:${PORTSDIR}/security/p5-IO-Socket-SSL
SSL_RUN_DEPENDS=	p5-IO-Socket-SSL>=1.994:${PORTSDIR}/security/p5-IO-Socket-SSL

PORTSCOUT=	skipv:1.0901

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501800
BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker>=6.64:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker
.endif

.if ${PORT_OPTIONS:MIPV6} && ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-IO-Socket-IP>=0.20:${PORTSDIR}/net/p5-IO-Socket-IP
RUN_DEPENDS+=	p5-IO-Socket-IP>=0.20:${PORTSDIR}/net/p5-IO-Socket-IP
.endif

.include <bsd.port.post.mk>
