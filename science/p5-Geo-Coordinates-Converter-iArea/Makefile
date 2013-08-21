# New ports collection makefile for:	p5-Geo-Coordinates-Converter-iArea
# Date created:		2011-06-12
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-Coordinates-Converter-iArea
PORTVERSION=	0.14
CATEGORIES=	science geography perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Some utility functions around iArea

RUN_DEPENDS=	p5-CDB_File>=0.96:${PORTSDIR}/databases/p5-CDB_File \
		p5-File-ShareDir>=1.02:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-Geo-Coordinates-Converter>=0.09:${PORTSDIR}/science/p5-Geo-Coordinates-Converter

USE_PERL5=	configure
USES=		perl5

MAN3=		Geo::Coordinates::Converter::iArea.3 \
		Geo::Coordinates::Converter::Format::IArea.3

.include <bsd.port.mk>
