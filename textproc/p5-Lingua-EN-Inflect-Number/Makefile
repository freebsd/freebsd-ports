# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Lingua-EN-Inflect-Number
PORTVERSION=	1.1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Force number of words to singular or plural

BUILD_DEPENDS=	p5-Lingua-EN-Inflect>=0:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Lingua::EN::Inflect::Number.3

NO_STAGE=	yes
.include <bsd.port.mk>
