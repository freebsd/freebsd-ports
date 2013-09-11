# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Geo-Parse-OSM
PORTVERSION=	0.42
CATEGORIES=	textproc geography perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LIOSHA
PKGNAMEPREFIX=	p5-

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	OpenStreetMap XML file regexp parser

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils
RUN_DEPENDS:=	${BUILD_DEPENDS}

PORTSCOUT=	skipv:0.221

USES=		perl5
USE_PERL5=	configure

MAN3=	Geo::Parse::OSM.3 \
	Geo::Parse::OSM::Multipass.3 \
	Geo::Parse::OSM::Singlepass.3

.include <bsd.port.mk>
