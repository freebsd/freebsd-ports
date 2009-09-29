# New ports collection makefile for:	p5-WWW-Shorten
# Date created:				August 29 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	WWW-Shorten
PORTVERSION=	2.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Abstract interface to URL shortening sites

BUILD_DEPENDS=	p5-libwww>=5.75:${PORTSDIR}/www/p5-libwww \
		p5-URI>=1.27:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		shorten.1
MAN3=		WWW::Shorten.3 \
		WWW::Shorten::LinkToolbot.3 \
		WWW::Shorten::Linkz.3 \
		WWW::Shorten::MakeAShorterLink.3 \
		WWW::Shorten::Metamark.3 \
		WWW::Shorten::NotLong.3 \
		WWW::Shorten::OneShortLink.3 \
		WWW::Shorten::Shorl.3 \
		WWW::Shorten::TinyClick.3 \
		WWW::Shorten::TinyURL.3 \
		WWW::Shorten::Tinylink.3 \
		WWW::Shorten::_dead.3 \
		WWW::Shorten::generic.3

.include <bsd.port.mk>
