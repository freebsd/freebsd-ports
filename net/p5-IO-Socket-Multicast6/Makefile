# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	IO-Socket-Multicast6
PORTVERSION=	0.03
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Send and receive IPv4 and IPv6 multicast messages

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-Interface>=1.01:net/p5-IO-Interface \
		p5-IO-Socket-INET6>=0:net/p5-IO-Socket-INET6 \
		p5-Socket-Multicast6>=0.01:net/p5-Socket-Multicast6 \
		p5-Socket6>=0.19:net/p5-Socket6
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
