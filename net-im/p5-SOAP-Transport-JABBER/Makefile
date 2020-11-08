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

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Net-Jabber>=0:net-im/p5-Net-Jabber \
		p5-SOAP-Lite>=0.711:net/p5-SOAP-Lite

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
