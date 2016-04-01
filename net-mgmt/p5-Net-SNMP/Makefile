# Created by: Christopher N. Harrell <cnh@ivmg.net>
# $FreeBSD$

PORTNAME=	Net-SNMP
PORTVERSION=	6.0.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DTOWN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Object oriented interface to SNMP

BUILD_DEPENDS=	p5-Crypt-DES>=0:security/p5-Crypt-DES \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-Digest-HMAC>=0:security/p5-Digest-HMAC
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
CONFLICTS=	p5-Net-SNMP3-[0-9]*

.include <bsd.port.mk>
