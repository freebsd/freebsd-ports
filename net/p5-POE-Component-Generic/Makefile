# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	POE-Component-Generic
PORTVERSION=	0.14.03
DISTVERSION=	${PORTVERSION:C/\.(..)$/\1/}
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provides non-blocking access to a blocking object

RUN_DEPENDS=	p5-POE>=0.31:${PORTSDIR}/devel/p5-POE \
		p5-Devel-Symdump>=0:${PORTSDIR}/devel/p5-Devel-Symdump \
		p5-Net-SSH2>=0:${PORTSDIR}/net/p5-Net-SSH2

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
