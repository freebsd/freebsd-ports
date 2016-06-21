# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-Address-Ethernet
PORTVERSION=	1.124
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Find hardware ethernet address

BUILD_DEPENDS=	p5-Env-Path>=0:devel/p5-Env-Path \
		p5-Net-Ifconfig-Wrapper>=0:net/p5-Net-Ifconfig-Wrapper \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
