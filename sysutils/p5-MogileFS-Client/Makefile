# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	MogileFS-Client
PORTVERSION=	1.17
PORTREVISION=	1
CATEGORIES=	sysutils net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DORMANDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	Client library for the MogileFS distributed file system

BUILD_DEPENDS=	p5-IO-stringy>=2.102:devel/p5-IO-stringy \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
