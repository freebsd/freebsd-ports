# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	XML-Canonical
PORTVERSION=	0.10
PORTREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl Implementation of Canonical XML

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-GDOME>=0:${PORTSDIR}/textproc/p5-XML-GDOME
LIB_DEPENDS=	libgdome.so:${PORTSDIR}/textproc/gdome2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5 pkgconfig

.include <bsd.port.mk>
