# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	XML-Canonical
PORTVERSION=	0.10
PORTREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Perl Implementation of Canonical XML

BUILD_DEPENDS=	p5-XML-GDOME>=0:${PORTSDIR}/textproc/p5-XML-GDOME
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libgdome.so:${PORTSDIR}/textproc/gdome2

USES=		perl5 pkgconfig
USE_PERL5=	configure

.include <bsd.port.mk>
