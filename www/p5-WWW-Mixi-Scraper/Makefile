# New ports collection makefile for:	p5-WWW-Mixi-Scraper
# Date created:		2007-12-28
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	WWW-Mixi-Scraper
PORTVERSION=	0.29
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Yet another mixi scraper

BUILD_DEPENDS=	p5-Module-Find>=0:${PORTSDIR}/devel/p5-Module-Find \
		p5-String-CamelCase>=0:${PORTSDIR}/textproc/p5-String-CamelCase \
		p5-Test-UseAllModules>=0:${PORTSDIR}/devel/p5-Test-UseAllModules \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Web-Scraper>=0.17:${PORTSDIR}/www/p5-Web-Scraper \
		p5-WWW-Mechanize>=1.50:${PORTSDIR}/www/p5-WWW-Mechanize
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
USE_DOS2UNIX=	yes

MAN3=		WWW::Mixi::Scraper::Utils.3 \
		WWW::Mixi::Scraper::Plugin::NewMusic.3 \
		WWW::Mixi::Scraper::Plugin::NewBBS.3 \
		WWW::Mixi::Scraper::Plugin::ListComment.3 \
		WWW::Mixi::Scraper::Mech.3 \
		WWW::Mixi::Scraper::Plugin::ListMessage.3 \
		WWW::Mixi::Scraper::Plugin::ShowFriend.3 \
		WWW::Mixi::Scraper::Plugin::ViewEvent.3 \
		WWW::Mixi::Scraper::Plugin::ShowLog.3 \
		WWW::Mixi::Scraper::Plugin::ListDiary.3 \
		WWW::Mixi::Scraper::Plugin::ShowCalendar.3 \
		WWW::Mixi::Scraper::Plugin::ViewMessage.3 \
		WWW::Mixi::Scraper::Plugin.3 \
		WWW::Mixi::Scraper.3 \
		WWW::Mixi::Scraper::Plugin::NewFriendDiary.3 \
		WWW::Mixi::Scraper::Plugin::ViewDiary.3 \
		WWW::Mixi::Scraper::Plugin::ViewBBS.3 \
		WWW::Mixi::Scraper::Plugin::NewVideo.3 \
		WWW::Mixi::Scraper::Plugin::ListBookmark.3 \
		WWW::Mixi::Scraper::Plugin::ResEcho.3 \
		WWW::Mixi::Scraper::Plugin::ViewEcho.3 \
		WWW::Mixi::Scraper::Plugin::ListEcho.3 \
		WWW::Mixi::Scraper::Plugin::RecentEcho.3 \
		WWW::Mixi::Scraper::Plugin::ShowSchedule.3

.include <bsd.port.mk>
