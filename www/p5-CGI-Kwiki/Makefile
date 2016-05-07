# Created by: clsung@dragon2.net
# $FreeBSD$

PORTNAME=	CGI-Kwiki
PORTVERSION=	0.18
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Quickie Wiki Package that's not too Tricky

BUILD_DEPENDS=	p5-CGI>=0:www/p5-CGI
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		p5-Locale-Maketext>=0:devel/p5-Locale-Maketext

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
