# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Gungho
PORTVERSION=	0.09.008
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Event Based High Performance Web Crawler Framework

BUILD_DEPENDS=	p5-Best>=0:${PORTSDIR}/devel/p5-Best \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-C3-Componentised>=0:${PORTSDIR}/devel/p5-Class-C3-Componentised \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-Config-Any>=0:${PORTSDIR}/devel/p5-Config-Any \
		p5-Danga-Socket-Callback>=0:${PORTSDIR}/devel/p5-Danga-Socket-Callback \
		p5-Data-Throttler>=0:${PORTSDIR}/devel/p5-Data-Throttler \
		p5-Exception-Class>=0:${PORTSDIR}/devel/p5-Exception-Class \
		p5-HTML-RobotsMETA>=0:${PORTSDIR}/www/p5-HTML-RobotsMETA \
		p5-HTTP-Parser>=0:${PORTSDIR}/www/p5-HTTP-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-IO-Async>=0:${PORTSDIR}/devel/p5-IO-Async \
		p5-Log-Dispatch>=0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-POE-Component-Client-DNS>=0:${PORTSDIR}/dns/p5-POE-Component-Client-DNS \
		p5-POE-Component-Client-Keepalive>=0:${PORTSDIR}/net/p5-POE-Component-Client-Keepalive \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-WWW-RobotRules-Parser>=0:${PORTSDIR}/www/p5-WWW-RobotRules-Parser \
		p5-Web-Scraper-Config>=0:${PORTSDIR}/www/p5-Web-Scraper-Config \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-Class-C3-XS>=0.02:${PORTSDIR}/devel/p5-Class-C3-XS \
		p5-Class-C3>=0.16:${PORTSDIR}/devel/p5-Class-C3 \
		p5-Danga-Socket>=1.57:${PORTSDIR}/devel/p5-Danga-Socket \
		p5-Data-Throttler-Memcached>=0.0003:${PORTSDIR}/devel/p5-Data-Throttler-Memcached \
		p5-Event-Notify>=0.00004:${PORTSDIR}/devel/p5-Event-Notify \
		p5-POE-Component-Client-HTTP>=0.81:${PORTSDIR}/www/p5-POE-Component-Client-HTTP \
		p5-POE>=0.9999:${PORTSDIR}/devel/p5-POE \
		p5-UNIVERSAL-isa>=0.06:${PORTSDIR}/devel/p5-UNIVERSAL-isa
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/script/gungho ${STAGEDIR}${PREFIX}/bin/gungho

.include <bsd.port.mk>
