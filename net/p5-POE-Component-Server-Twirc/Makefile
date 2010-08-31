# New ports collection makefile for:	net/p5-POE-Component-Server-Twirc
# Date created:				25 February 2009
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Server-Twirc
PORTVERSION=	0.12
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Twitter/IRC gateway

RUN_DEPENDS=	p5-Email-Valid>=0:${PORTSDIR}/mail/p5-Email-Valid \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-LWP-UserAgent-POE>=0.02:${PORTSDIR}/www/p5-LWP-UserAgent-POE \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-MooseX-AttributeHelpers>=0:${PORTSDIR}/devel/p5-MooseX-AttributeHelpers \
		p5-MooseX-Getopt>=0.15:${PORTSDIR}/devel/p5-MooseX-Getopt \
		p5-MooseX-Log-Log4perl>=0:${PORTSDIR}/devel/p5-MooseX-Log-Log4perl \
		p5-MooseX-POE>=0.205:${PORTSDIR}/devel/p5-MooseX-POE \
		p5-MooseX-SimpleConfig>=0:${PORTSDIR}/devel/p5-MooseX-SimpleConfig \
		p5-MooseX-Storage>=0:${PORTSDIR}/devel/p5-MooseX-Storage \
		p5-Net-Twitter>=3.11007:${PORTSDIR}/net/p5-Net-Twitter \
		p5-POE-Component-SSLify>=0:${PORTSDIR}/security/p5-POE-Component-SSLify \
		p5-POE-Component-Server-IRC>=0.02005:${PORTSDIR}/irc/p5-POE-Component-Server-IRC \
		p5-POE-Component-TSTP>=0:${PORTSDIR}/devel/p5-POE-Component-TSTP \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Proc-Daemon>=0:${PORTSDIR}/devel/p5-Proc-Daemon \
		p5-String-Truncate>=0:${PORTSDIR}/textproc/p5-String-Truncate
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		App::Twirc.3 \
		App::Twirc::Manual.3 \
		App::Twirc::Plugin::SquashWhiteSpace.3 \
		App::Twirc::Plugin::BangCommands.3 \
		App::Twirc::Plugin::SecondaryAccount.3 \
		POE::Component::Server::Twirc.3

post-patch:
	@${PERL} -pi -e '$$_="" if m/auto_install/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
