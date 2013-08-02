# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	WWW-Comic
PORTVERSION=	1.06
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Retrieve comic strip images

RUN_DEPENDS=	p5-WWW-Dilbert>=1.19:${PORTSDIR}/www/p5-WWW-Dilbert \
		p5-WWW-VenusEnvy>=1.10:${PORTSDIR}/www/p5-WWW-VenusEnvy
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		WWW::Comic.3 WWW::Comic::Plugin::uComics.3 \
		WWW::Comic::Plugin::MrWiggles.3 WWW::Comic::Plugin::UserFriendly.3 \
		WWW::Comic::Plugin::VenusEnvy.3 WWW::Comic::Plugin::UFS.3 \
		WWW::Comic::Plugin.3 WWW::Comic::Plugin::Dilbert.3 \
		WWW::Comic::Plugin::Goats.3

.include <bsd.port.mk>
