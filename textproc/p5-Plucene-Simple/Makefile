# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Plucene-Simple
DISTVERSION=	1.04
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:STRYTOAST
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME:S/-//}-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to Plucene

BUILD_DEPENDS=	p5-Time-Piece>=1.08:${PORTSDIR}/devel/p5-Time-Piece \
		p5-Time-Piece-Range>=1.0:${PORTSDIR}/devel/p5-Time-Piece-Range \
		p5-Plucene>=1.09:${PORTSDIR}/textproc/p5-Plucene \
		p5-File-Find-Rule>=0.10:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-File-Slurp>=2002.1031:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Test-Class>=0.03:${PORTSDIR}/devel/p5-Test-Class
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
