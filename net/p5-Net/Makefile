# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net
PORTVERSION=	3.10
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	libnet-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 modules to access and use network protocols

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Socket>=2.016:net/p5-Socket
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	IPV6 SASL SSL
OPTIONS_DEFAULT=SASL SSL
SASL_DESC=	SASL auth for POP3 and SMTP support

SASL_BUILD_DEPENDS=	p5-Authen-SASL>=0:security/p5-Authen-SASL
SASL_RUN_DEPENDS=	p5-Authen-SASL>=0:security/p5-Authen-SASL
SSL_BUILD_DEPENDS=	p5-IO-Socket-SSL>=2.007:security/p5-IO-Socket-SSL
SSL_RUN_DEPENDS=	p5-IO-Socket-SSL>=2.007:security/p5-IO-Socket-SSL

CONFIGURE_ENV=	PERL5_CPAN_IS_RUNNING=1
NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIPV6} && ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-IO-Socket-IP>=0.20:net/p5-IO-Socket-IP
RUN_DEPENDS+=	p5-IO-Socket-IP>=0.20:net/p5-IO-Socket-IP
.endif

.include <bsd.port.post.mk>
