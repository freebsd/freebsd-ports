# Created by: chinsan <chinsan.tw@gmail.com>, Gea-Suan Lin <gslin@gslin.org>
# Thanks to Gea-Suan Lin for his great patch for this port.
# $FreeBSD$

PORTNAME=	WWW-VenusEnvy
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	VenusEnvy comic strip archive and retrieval module

RUN_DEPENDS=	p5-libwww>=5.805:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		WWW::VenusEnvy.3

.include <bsd.port.mk>
