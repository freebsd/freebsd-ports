# Created by: ijliao
# $FreeBSD$

PORTNAME=	WebService-ISBNDB
PORTVERSION=	0.34
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to access isbndb.com

BUILD_DEPENDS=	p5-Business-ISBN>=1.80:misc/p5-Business-ISBN \
		p5-Class-Std>=0.0.8:devel/p5-Class-Std \
		p5-Error>=0.17:lang/p5-Error \
		p5-libwww>=5.801:www/p5-libwww \
		p5-XML-LibXML>=1.58:textproc/p5-XML-LibXML \
		p5-TimeDate>=1.16:devel/p5-TimeDate
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
