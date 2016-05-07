# Created by: ijliao
# $FreeBSD$

PORTNAME=	Class-CSV
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Class based CSV parser/writer

BUILD_DEPENDS=	p5-Text-CSV_XS>=0.23:textproc/p5-Text-CSV_XS \
		p5-Class-Accessor>=0.18:devel/p5-Class-Accessor
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
