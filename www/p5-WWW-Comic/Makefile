# New ports collection makefile for:	p5-WWW-Comic
# Date created:				2006/06/28
# Whom:					chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	WWW-Comic
PORTVERSION=	1.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Retrieve comic strip images

RUN_DEPENDS=	p5-Module-Pluggable>=3.01:${PORTSDIR}/devel/p5-Module-Pluggable \
		p5-WWW-Dilbert>=1.19:${PORTSDIR}/www/p5-WWW-Dilbert \
		p5-WWW-VenusEnvy>=1.10:${PORTSDIR}/www/p5-WWW-VenusEnvy
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		WWW::Comic.3 WWW::Comic::Plugin::uComics.3 \
		WWW::Comic::Plugin::MrWiggles.3 WWW::Comic::Plugin::UserFriendly.3 \
		WWW::Comic::Plugin::VenusEnvy.3 WWW::Comic::Plugin::UFS.3 \
		WWW::Comic::Plugin.3 WWW::Comic::Plugin::Dilbert.3 \
		WWW::Comic::Plugin::Goats.3

.include <bsd.port.mk>
