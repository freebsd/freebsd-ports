# $FreeBSD$

PORTNAME=	Path-Class-URI
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for serialize Path::Class objects as file:// URI

RUN_DEPENDS=	\
	p5-Path-Class>0:devel/p5-Path-Class \
	p5-URI>0:net/p5-URI \
	p5-Exporter-Lite>0:devel/p5-Exporter-Lite
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
