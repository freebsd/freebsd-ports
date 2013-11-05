# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Email-Filter
PORTVERSION=	1.03.3
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Library for creating easy email filters

BUILD_DEPENDS=	p5-Email-Simple>=0:${PORTSDIR}/mail/p5-Email-Simple \
		p5-Email-LocalDelivery>=0:${PORTSDIR}/mail/p5-Email-LocalDelivery \
		p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run \
		p5-Class-Trigger>=0:${PORTSDIR}/devel/p5-Class-Trigger
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
