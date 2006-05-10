# New ports collection makefile for:	p5-Catalyst-View-JSON
# Date created:		May 10, 2006
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-JSON
PORTVERSION=	0.09
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Catalyst View handler that returns stash data in JSON format

BUILD_DEPENDS=	p5-Test-Simple>=0.32:${PORTSDIR}/devel/p5-Test-Simple \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-JSON>=1.00:${PORTSDIR}/converters/p5-JSON \
		p5-Catalyst>=5.60:${PORTSDIR}/www/p5-Catalyst

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Helper::View::JSON.3 Catalyst::View::JSON.3

.include <bsd.port.mk>
