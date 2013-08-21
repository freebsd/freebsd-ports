# Created by: ache@FreeBSD.org
# $FreeBSD$

PORTNAME=	ParallelUA
PORTVERSION=	2.57
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN/LWP
PKGNAMEPREFIX=	p5-
DISTNAME=	ParallelUserAgent-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl5 Parallel LWP User Agent for WWW access

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5
REINPLACE_ARGS=	-i ''

MAN3=		Bundle::ParallelUA.3 \
		LWP::Parallel.3 \
		LWP::Parallel::Protocol.3 \
		LWP::Parallel::Protocol::ftp.3 \
		LWP::Parallel::Protocol::http.3 \
		LWP::Parallel::RobotUA.3 \
		LWP::Parallel::UserAgent.3 \
		LWP::ParallelUA.3 \
		LWP::RobotPUA.3

post-patch:
	@${REINPLACE_CMD} -e '/protocol->parse_head/d' ${WRKSRC}/lib/LWP/Parallel/UserAgent.pm

.include <bsd.port.mk>
