# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Plucene-Simple
DISTVERSION=	1.04
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:STRYTOAST
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME:S/-//}-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to Plucene

BUILD_DEPENDS=	p5-Time-Piece>=1.08:devel/p5-Time-Piece \
		p5-Time-Piece-Range>=1.0:devel/p5-Time-Piece-Range \
		p5-Plucene>=1.09:textproc/p5-Plucene \
		p5-File-Find-Rule>=0.10:devel/p5-File-Find-Rule \
		p5-File-Slurp>=2002.1031:devel/p5-File-Slurp
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Class>=0.03:devel/p5-Test-Class

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
