# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Blog-Spam
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SKX
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Blog & Forum SPAM Detection

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Net-CIDR-Lite>=0:net/p5-Net-CIDR-Lite \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-RPC-XML>=0:net/p5-RPC-XML \
		p5-URI-Find>=0:textproc/p5-URI-Find \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
