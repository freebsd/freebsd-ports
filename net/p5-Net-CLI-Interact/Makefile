# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-CLI-Interact
PORTVERSION=	2.123.620
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Toolkit for CLI Automation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Load>=0:${PORTSDIR}/devel/p5-Class-Load \
		p5-Class-Mix>=0:${PORTSDIR}/devel/p5-Class-Mix \
		p5-IO-Tty>=0:${PORTSDIR}/devel/p5-IO-Tty \
		p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run \
		p5-Log-Dispatch-Config>=0:${PORTSDIR}/devel/p5-Log-Dispatch-Config \
		p5-Log-Dispatch-Configurator-Any>=0:${PORTSDIR}/devel/p5-Log-Dispatch-Configurator-Any \
		p5-Moo>=0:${PORTSDIR}/devel/p5-Moo \
		p5-MooX-Types-MooseLike>=0:${PORTSDIR}/devel/p5-MooX-Types-MooseLike \
		p5-Net-Telnet>=0:${PORTSDIR}/net/p5-Net-Telnet \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::CLI::Interact.3 \
		Net::CLI::Interact::Action.3 \
		Net::CLI::Interact::ActionSet.3 \
		Net::CLI::Interact::Logger.3 \
		Net::CLI::Interact::Manual::Cookbook.3 \
		Net::CLI::Interact::Manual::Phrasebook.3 \
		Net::CLI::Interact::Manual::Tutorial.3 \
		Net::CLI::Interact::Phrasebook.3 \
		Net::CLI::Interact::Role::Engine.3 \
		Net::CLI::Interact::Role::Iterator.3 \
		Net::CLI::Interact::Role::Prompt.3 \
		Net::CLI::Interact::Transport::Base.3 \
		Net::CLI::Interact::Transport::Loopback.3 \
		Net::CLI::Interact::Transport::SSH.3 \
		Net::CLI::Interact::Transport::Serial.3 \
		Net::CLI::Interact::Transport::Telnet.3

.include <bsd.port.mk>
