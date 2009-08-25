# New ports collection makefile for:	p5-Catalyst-View-JSON
# Date created:		May 10, 2006
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-JSON
PORTVERSION=	0.26
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Catalyst View handler that returns stash data in JSON format

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Devel>=1.00:${PORTSDIR}/www/p5-Catalyst-Devel \
		p5-JSON-Any>=0:${PORTSDIR}/converters/p5-JSON-Any \
		p5-MRO-Compat>0:${PORTSDIR}/devel/p5-MRO-Compat
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Helper::View::JSON.3 Catalyst::View::JSON.3

.include <bsd.port.mk>
