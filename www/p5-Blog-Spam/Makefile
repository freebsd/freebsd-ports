# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Blog-Spam
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SKX
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Blog & Forum SPAM Detection

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Module-Pluggable>=0:devel/p5-Module-Pluggable \
		p5-Net-CIDR-Lite>=0:net/p5-Net-CIDR-Lite \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-RPC-XML>=0:net/p5-RPC-XML \
		p5-URI-Find>=0:textproc/p5-URI-Find \
		p5-libwww>=0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
