# New ports collection makefile for:	p5-AnyEvent-HTTP
# Date created:		06 Jul 2008
# Whom:			Vladimir Timofeev <vovkasm@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	AnyEvent-HTTP
PORTVERSION=	2.1
PORTEPOCH=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/ML/MLEHMANN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vovkasm@gmail.com
COMMENT=	Simple but non-blocking HTTP/HTTPS client

BUILD_DEPENDS=	p5-AnyEvent>=5:${PORTSDIR}/devel/p5-AnyEvent \
		p5-common-sense>=3.3:${PORTSDIR}/devel/p5-common-sense
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	AnyEvent::HTTP.3

.include <bsd.port.mk>
