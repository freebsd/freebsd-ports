# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	WWW-Yandex-TIC
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Query Yandex Thematic Index of Citing (TIC) for domain

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		WWW::Yandex::TIC.3

.include <bsd.port.mk>
