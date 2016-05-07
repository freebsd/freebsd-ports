# $FreeBSD$

PORTNAME=	FCGI-Client
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for fastcgi protocol client library

RUN_DEPENDS=	\
	p5-Any-Moose>=0.1:devel/p5-Any-Moose \
	p5-Try-Tiny>0:lang/p5-Try-Tiny
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
