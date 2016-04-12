# Created by: will
# $FreeBSD$

PORTNAME=	WWW-Babelfish
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to obtain translations from the babelfish server

BUILD_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-IO-String>=0:devel/p5-IO-String
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
