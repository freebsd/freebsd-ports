# New ports collection makefile for:	p5-App-Nopaste
# Date created:		2009-03-10
# Whom:			bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	App-Nopaste
PORTVERSION=	0.35
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SARTAK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy access to any pastebin

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Moose>=0.74:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Getopt>=0.17:${PORTSDIR}/devel/p5-MooseX-Getopt \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	CLIPBOARD GITHUB PASTEBIN
OPTIONS_DEFAULT=CLIPBOARD GITHUB PASTEBIN
CLIPBOARD_DESC=	Support X11 clipboard
GITHUB_DESC=	Support github.com
PASTEBIN_DESC=	Support pastebin.com

PERL_CONFIGURE=	yes

CONFLICTS=	p5-WebService-NoPaste-[0-9]*

MAN1=		nopaste.1
MAN3=		App::Nopaste.3 \
		App::Nopaste::Command.3 \
		App::Nopaste::Service.3 \
		App::Nopaste::Service::Codepeek.3 \
		App::Nopaste::Service::Debian.3 \
		App::Nopaste::Service::Gist.3 \
		App::Nopaste::Service::PastebinCom.3 \
		App::Nopaste::Service::Pastie.3 \
		App::Nopaste::Service::Shadowcat.3 \
		App::Nopaste::Service::Snitch.3 \
		App::Nopaste::Service::Ubuntu.3 \
		App::Nopaste::Service::ssh.3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIPBOARD}
BUILD_DEPENDS+=	p5-Clipboard>=0:${PORTSDIR}/x11/p5-Clipboard
RUN_DEPENDS+=	p5-Clipboard>=0:${PORTSDIR}/x11/p5-Clipboard
.endif

.if ${PORT_OPTIONS:MGITHUB}
BUILD_DEPENDS+=	p5-Config-GitLike>=0:${PORTSDIR}/devel/p5-Config-GitLike
RUN_DEPENDS+=	p5-Config-GitLike>=0:${PORTSDIR}/devel/p5-Config-GitLike
.endif

.if ${PORT_OPTIONS:MPASTEBIN}
BUILD_DEPENDS+=	p5-WWW-Pastebin-PastebinCom-Create>=0:${PORTSDIR}/www/p5-WWW-Pastebin-PastebinCom-Create
RUN_DEPENDS+=	p5-WWW-Pastebin-PastebinCom-Create>=0:${PORTSDIR}/www/p5-WWW-Pastebin-PastebinCom-Create
.endif

.include <bsd.port.mk>
