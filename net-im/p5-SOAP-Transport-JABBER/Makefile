# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SOAP-Transport-JABBER
PORTVERSION=	0.713
PORTREVISION=	1
CATEGORIES=	net-im net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Jabber-based transport backend for SOAP::Lite

LICENSE=	ART10

BUILD_DEPENDS=	p5-Net-Jabber>=0:net-im/p5-Net-Jabber \
		p5-SOAP-Lite>=0.711:net/p5-SOAP-Lite
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.mk>
