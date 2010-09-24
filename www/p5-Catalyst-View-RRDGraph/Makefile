# New ports collection makefile for:	p5-Catalyst-View-RRDGraph
# Date created:		2008-12-22
# Whom:			Andrej Zverev <az@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-RRDGraph
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	RRD graph view class for catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Plugin-Static-Simple>=0.17:${PORTSDIR}/www/p5-Catalyst-Plugin-Static-Simple \
		${SITE_PERL}/RRDp.pm:${PORTSDIR}/databases/rrdtool \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Helper::View::RRDGraph.3 \
	Catalyst::View::RRDGraph.3

.include <bsd.port.mk>
