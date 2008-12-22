# New ports collection makefile for:	p5-Catalyst-View-RRDGraph
# Date created:		2008-12-22
# Whom:			Andrej Zverev <az@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-RRDGraph
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/J/JL/JLMARTIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	az@FreeBSD.org
COMMENT=	RRD graph view class for catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		${SITE_PERL}/Catalyst/Plugin/Static/Simple.pm:${PORTSDIR}/www/p5-Catalyst-Plugin-Static-Simple \
		${SITE_PERL}/RRDp.pm:${PORTSDIR}/databases/rrdtool
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Helper::View::RRDGraph.3 \
	Catalyst::View::RRDGraph.3

.include <bsd.port.mk>
