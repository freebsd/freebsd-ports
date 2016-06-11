# Created by: Henk van Oers <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Dancer2-Plugin-Path-Class
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hvo.pm@xs4all.nl
COMMENT=	List a directory using Path::Class

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Path-Tiny>=0:devel/p5-Path-Tiny
BUILD_DEPENDS=	p5-Dancer2>=0.166000:www/p5-Dancer2 \
		p5-MIME-Types>=0:mail/p5-MIME-Types \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Format-Human-Bytes>=0:converters/p5-Format-Human-Bytes
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
