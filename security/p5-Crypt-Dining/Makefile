# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Crypt-Dining
PORTVERSION=	1.01
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The Dining Cryptographers' Protocol

BUILD_DEPENDS=	p5-Crypt-Random>=0:${PORTSDIR}/security/p5-Crypt-Random \
		p5-Net-Address-IPv4-Local>=0:${PORTSDIR}/net/p5-Net-Address-IPv4-Local
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
