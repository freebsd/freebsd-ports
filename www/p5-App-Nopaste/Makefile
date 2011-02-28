# New ports collection makefile for:	p5-App-Nopaste
# Date created:		2009-03-10
# Whom:			bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	App-Nopaste
PORTVERSION=	0.26
CATEGORIES=	www perl5
MASTER_SITES=	CPAN/../../authors/id/S/SA/SARTAK/
PKGNAMEPREFIX=	p5-

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Easy access to any pastebin

BUILD_DEPENDS+=	p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-MooseX-Getopt>=0.17:${PORTSDIR}/devel/p5-MooseX-Getopt \
		p5-Moose>=0.74:${PORTSDIR}/devel/p5-Moose

RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS=	CLIPBOARD "Support X11 Clipboard" On \
		PASTEBIN "Support pastebin.com" On \
		GITHUB "Support github" On

PERL_CONFIGURE=	yes

LICENSE_COMB=	dual
LICENSE=	ART20 GPLv1

CONFLICTS=	p5-WebService-NoPaste-0*

MAN1=		nopaste.1

MAN3=		App::Nopaste.3 \
		App::Nopaste::Command.3 \
		App::Nopaste::Service.3 \
		App::Nopaste::Service::Debian.3 \
		App::Nopaste::Service::Gist.3 \
		App::Nopaste::Service::Mathbin.3 \
		App::Nopaste::Service::PastebinCom.3 \
		App::Nopaste::Service::Pastie.3 \
		App::Nopaste::Service::Codepeek.3 \
		App::Nopaste::Service::Shadowcat.3 \
		App::Nopaste::Service::Snitch.3 \
		App::Nopaste::Service::ssh.3

.include <bsd.port.pre.mk>
.if defined(WITH_PASTEBIN)
BUILD_DEPENDS+=	p5-WWW-Pastebin-PastebinCom-Create>=0:${PORTSDIR}/www/p5-WWW-Pastebin-PastebinCom-Create
RUN_DEPENDS+=	p5-WWW-Pastebin-PastebinCom-Create>=0:${PORTSDIR}/www/p5-WWW-Pastebin-PastebinCom-Create
.endif
.if defined(WITH_CLIPBOARD)
BUILD_DEPENDS+=	p5-Clipboard>=0:${PORTSDIR}/x11/p5-Clipboard
RUN_DEPENDS+=	p5-Clipboard>=0:${PORTSDIR}/x11/p5-Clipboard
.endif
.if defined(WITH_GITHUB)
BUILD_DEPENDS+=	p5-Config-GitLike>=0:${PORTSDIR}/devel/p5-Config-GitLike
RUN_DEPENDS+=	p5-Config-GitLike>=0:${PORTSDIR}/devel/p5-Config-GitLike
.endif
.include <bsd.port.post.mk>
