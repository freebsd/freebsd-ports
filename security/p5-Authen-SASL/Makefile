# Created by: Blaz Zupan <blaz@si.FreeBSD.org>
# $FreeBSD$

PORTNAME=	Authen-SASL
PORTVERSION=	2.16
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module for SASL authentication

RUN_DEPENDS=	p5-Digest-HMAC>0:${PORTSDIR}/security/p5-Digest-HMAC
BUILD_DEPENDS:=	${RUN_DEPENDS}

OPTIONS_DEFINE=	KERBEROS
OPTIONS_DEFAULT=	KERBEROS

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ENV+=	AUTOMATED_TESTING=yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKERBEROS}
RUN_DEPENDS+=	p5-GSSAPI>0:${PORTSDIR}/security/p5-GSSAPI
.endif

.include <bsd.port.mk>
