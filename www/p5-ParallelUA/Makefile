# Created by: ache@FreeBSD.org
# $FreeBSD$

PORTNAME=	ParallelUA
PORTVERSION=	2.57
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN/LWP
PKGNAMEPREFIX=	p5-
DISTNAME=	ParallelUserAgent-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl5 Parallel LWP User Agent for WWW access

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
REINPLACE_ARGS=	-i ''
USE_PERL5=	configure
USES=		perl5

post-patch:
	@${REINPLACE_CMD} -e '/protocol->parse_head/d' ${WRKSRC}/lib/LWP/Parallel/UserAgent.pm

.include <bsd.port.mk>
