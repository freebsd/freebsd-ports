# New ports collection makefile for:	p5-Geo-Coordinates-Converter
# Date created:				Dec 29, 2010
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Geo-Coordinates-Converter
PORTVERSION=	0.08
CATEGORIES=	science geography perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/Y/YA/YAPPO
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Simple converter of geo coordinates

BUILD_DEPENDS=	p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Readonly>0:${PORTSDIR}/devel/p5-Readonly \
		p5-String-CamelCase>0:${PORTSDIR}/textproc/p5-String-CamelCase \
		p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Geo::Coordinates::Converter::Datum.3 \
		Geo::Coordinates::Converter.3 \
		Geo::Coordinates::Converter::Point.3 \
		Geo::Coordinates::Converter::Format.3

.include <bsd.port.mk>
