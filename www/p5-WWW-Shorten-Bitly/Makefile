# Created by: Masafumi NAKANE <max@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WWW-Shorten-Bitly
PORTVERSION=	1.17
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	max@FreeBSD.org
COMMENT=	Abstract interface to bit.ly, one of URL shortening sites

BUILD_DEPENDS=	p5-JSON-Any>=1.18:${PORTSDIR}/converters/p5-JSON-Any \
		p5-WWW-Shorten>=1.9:${PORTSDIR}/www/p5-WWW-Shorten \
		p5-XML-Simple>=2.18:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		bitly_url.1
MAN3=		WWW::Shorten::Bitly.3

NO_STAGE=	yes
.include <bsd.port.mk>
