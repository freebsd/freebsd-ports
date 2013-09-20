# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Continuity
PORTVERSION=	1.5
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=CPAN:AWWAIID
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Stateful Web applications in Perl

COMMON_DEPENDS=	p5-Event>0:${PORTSDIR}/devel/p5-Event \
		p5-HTTP-Daemon>=1.36:${PORTSDIR}/www/p5-HTTP-Daemon \
		p5-Coro>=4.37:${PORTSDIR}/devel/p5-Coro \
		p5-PSGI>=0:${PORTSDIR}/www/p5-PSGI \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Continuity.3 \
	Continuity::Adapt::FCGI.3 \
	Continuity::Adapt::HttpDaemon.3 \
	Continuity::Adapt::PSGI.3 \
	Continuity::Inspector.3 \
	Continuity::Mapper.3 \
	Continuity::Request.3 \
	Continuity::RequestCallbacks.3

NO_STAGE=	yes
.include <bsd.port.mk>
