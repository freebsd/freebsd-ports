# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-Dropbox-API
PORTVERSION=	1.9
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dropbox API interface

BUILD_DEPENDS=	p5-Data-Random>=0:${PORTSDIR}/devel/p5-Data-Random \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Mouse>=0:${PORTSDIR}/devel/p5-Mouse \
		p5-Net-OAuth>=0:${PORTSDIR}/net/p5-Net-OAuth \
		p5-common-sense>=0:${PORTSDIR}/devel/p5-common-sense \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
