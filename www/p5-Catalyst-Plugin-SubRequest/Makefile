# ex:ts=8
# Ports collection makefile for:	p5-Catalyst-Plugin-SubRequest
# Date created:			May 6, 2005
# Whom:				Travis Campbell <hcoyote@ghostar.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-SubRequest
PORTVERSION=	0.15
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Make subrequests to actions in Catalyst

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7012:${PORTSDIR}/www/p5-Catalyst-Runtime
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Plugin::SubRequest.3

.include <bsd.port.mk>
