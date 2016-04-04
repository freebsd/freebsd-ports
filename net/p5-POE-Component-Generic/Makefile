# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	POE-Component-Generic
PORTVERSION=	0.14.03
PORTREVISION=	2
DISTVERSION=	${PORTVERSION:C/\.(..)$/\1/}
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provides non-blocking access to a blocking object

BUILD_DEPENDS=	p5-POE>=0.31:devel/p5-POE \
		p5-Devel-Symdump>=0:devel/p5-Devel-Symdump \
		p5-Net-SSH2>=0:net/p5-Net-SSH2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
