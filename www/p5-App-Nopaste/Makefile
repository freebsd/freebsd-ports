# New ports collection makefile for:	p5-App-Nopaste
# Date created:		2009-03-10
# Whom:			bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	App-Nopaste
PORTVERSION=	0.21
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	Easy access to any pastebin

BUILD_DEPENDS+=	${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize \
		${SITE_PERL}/MooseX/Getopt.pm:${PORTSDIR}/devel/p5-MooseX-Getopt

RUN_DEPENDS+=	${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize \
		${SITE_PERL}/MooseX/Getopt.pm:${PORTSDIR}/devel/p5-MooseX-Getopt

OPTIONS=	CLIPBOARD "Support Clipboard" On \
		PASTEBIN "Support pastebin.com" On \
		GITHUB "Support github" Off

PERL_CONFIGURE=	yes

CONFLICTS=	p5-WebService-NoPaste-0*

MAN1=		nopaste.1

MAN3=		App::Nopaste.3 \
		App::Nopaste::Command.3 \
		App::Nopaste::Service.3 \
		App::Nopaste::Service::Debian.3 \
		App::Nopaste::Service::Gist.3 \
		App::Nopaste::Service::Husk.3 \
		App::Nopaste::Service::Mathbin.3 \
		App::Nopaste::Service::PastebinCom.3 \
		App::Nopaste::Service::Pastie.3 \
		App::Nopaste::Service::Codepeek.3 \
		App::Nopaste::Service::Shadowcat.3 \
		App::Nopaste::Service::Snitch.3 \
		App::Nopaste::Service::SSH.3

.include <bsd.port.pre.mk>
.if defined(WITH_PASTEBIN)
BUILD_DEPENDS+=	${SITE_PERL}/WWW/Pastebin/PastebinCom/Create.pm:${PORTSDIR}/www/p5-WWW-Pastebin-PastebinCom-Create
RUN_DEPENDS+=	${SITE_PERL}/WWW/Pastebin/PastebinCom/Create.pm:${PORTSDIR}/www/p5-WWW-Pastebin-PastebinCom-Create
.endif
.if defined(WITH_CLIPBOARD)
BUILD_DEPENDS+=	${SITE_PERL}/Clipboard.pm:${PORTSDIR}/x11/p5-Clipboard
RUN_DEPENDS+=	${SITE_PERL}/Clipboard.pm:${PORTSDIR}/x11/p5-Clipboard
.endif
.if defined(WITH_GITHUB)
BUILD_DEPENDS+=	${SITE_PERL}/Git.pm:${PORTSDIR}/devel/git \
		${SITE_PERL}/Config/INI/Reader.pm:${PORTSDIR}/devel/p5-Config-INI

RUN_DEPENDS+=	${SITE_PERL}/Git.pm:${PORTSDIR}/devel/git \
		${SITE_PERL}/Config/INI/Reader.pm:${PORTSDIR}/devel/p5-Config-INI
.endif
.include <bsd.port.post.mk>
