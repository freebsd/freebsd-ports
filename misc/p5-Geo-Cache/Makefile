# New ports collection makefile for:	Geo-Cache
# Date created:				18 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Geo-Cache
PORTVERSION=	0.06
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Geo
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Object interface for GPS waypoints

BUILD_DEPENDS=	${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/Time/CTime.pm:${PORTSDIR}/devel/p5-Time-modules

MAN3=	Geo::Cache.3 \
	Geo::Gpx.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
