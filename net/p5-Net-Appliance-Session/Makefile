# New ports collection makefile for:	net/p5-Net-Appliance-Session
# Date created:				05 May 2010
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Appliance-Session
PORTVERSION=	1.36
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Run command-line sessions to network appliances

BUILD_DEPENDS=	${SITE_PERL}/Net/Appliance/Phrasebook.pm:${PORTSDIR}/net/p5-Net-Appliance-Phrasebook \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod \
		${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class \
		${SITE_PERL}/Class/Accessor/Fast/Contained.pm:${PORTSDIR}/devel/p5-Class-Accessor-Fast-Contained \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/${PERL_ARCH}/IO/Pty.pm:${PORTSDIR}/devel/p5-IO-Tty \
		${SITE_PERL}/Net/Telnet.pm:${PORTSDIR}/net/p5-Net-Telnet \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-require
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Net::Appliance::Session.3 \
	Net::Appliance::Session::Cookbook.3 \
	Net::Appliance::Session::Cookbook::Intro.3 \
	Net::Appliance::Session::Cookbook::Recipe01.3 \
	Net::Appliance::Session::Cookbook::Recipe02.3 \
	Net::Appliance::Session::Cookbook::Recipe03.3 \
	Net::Appliance::Session::Cookbook::Recipe04.3 \
	Net::Appliance::Session::Cookbook::Recipe05.3 \
	Net::Appliance::Session::Cookbook::Recipe06.3 \
	Net::Appliance::Session::Cookbook::Recipe07.3 \
	Net::Appliance::Session::Transport.3 \
	Net::Appliance::Session::Transport::SSH.3 \
	Net::Appliance::Session::Transport::Serial.3 \
	Net::Appliance::Session::Transport::Telnet.3

.include <bsd.port.mk>
