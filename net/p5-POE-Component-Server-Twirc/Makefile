# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	POE-Component-Server-Twirc
PORTVERSION=	0.16
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MMIMS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Twitter/IRC gateway

BUILD_DEPENDS=	p5-AnyEvent-Twitter-Stream>=0:${PORTSDIR}/net/p5-AnyEvent-Twitter-Stream \
		p5-Config-Any>=0:${PORTSDIR}/devel/p5-Config-Any \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-LWP-UserAgent-POE>=0.02:${PORTSDIR}/www/p5-LWP-UserAgent-POE \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Getopt>=0.15:${PORTSDIR}/devel/p5-MooseX-Getopt \
		p5-MooseX-Log-Log4perl>=0:${PORTSDIR}/devel/p5-MooseX-Log-Log4perl \
		p5-MooseX-POE>=0.215:${PORTSDIR}/devel/p5-MooseX-POE \
		p5-MooseX-SimpleConfig>=0:${PORTSDIR}/devel/p5-MooseX-SimpleConfig \
		p5-MooseX-Storage>=0:${PORTSDIR}/devel/p5-MooseX-Storage \
		p5-Net-Twitter>=3.11007:${PORTSDIR}/net/p5-Net-Twitter \
		p5-POE-Component-Server-IRC>=0.02005:${PORTSDIR}/irc/p5-POE-Component-Server-IRC \
		p5-POE-Component-TSTP>=0:${PORTSDIR}/devel/p5-POE-Component-TSTP \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Proc-Daemon>=0:${PORTSDIR}/devel/p5-Proc-Daemon \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-String-Truncate>=0:${PORTSDIR}/textproc/p5-String-Truncate \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -i '' -e '/auto_install/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
