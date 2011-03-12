# New ports collection makefile for:	p5-Geo-Parse-OSM
# Date created:		03 Mar 2011
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-Parse-OSM
PORTVERSION=	0.42
CATEGORIES=	textproc geography perl5
MASTER_SITES=	CPAN/../../authors/id/L/LI/LIOSHA
PKGNAMEPREFIX=	p5-

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	OpenStreetMap XML file regexp parser

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/${PERL_ARCH}/List/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/${PERL_ARCH}/List/MoreUtils.pm:${PORTSDIR}/lang/p5-List-MoreUtils
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Geo::Parse::OSM.3 \
	Geo::Parse::OSM::Multipass.3 \
	Geo::Parse::OSM::Singlepass.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
BUILD_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
