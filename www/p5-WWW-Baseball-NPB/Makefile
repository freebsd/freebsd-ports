# New ports collection makefile for:	p5-WWW-Baseball-NPB
# Date created:				2006/07/21
# Whom:					chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	WWW-Baseball-NPB
PORTVERSION=	0.03
CATEGORIES=	www japanese perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fetches Japanese baseball games information

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Baseball::NPB.3 WWW::Baseball::NPB::Game.3

.include <bsd.port.mk>
