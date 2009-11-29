# New ports collection makefile for:	p5-ResourcePool-Resourse-SOAP-Lite
# Date created:			February 28th, 2003
# Whom:	      			Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ResourcePool-Resource-SOAP-Lite
PORTVERSION=	1.0102
CATEGORIES=	net perl5
MASTER_SITES=	CPAN \
		http://www.fatalmind.com/projects/ResourcePool/
MASTER_SITE_SUBDIR=	../by-authors/id/M/MW/MWS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A ResourcePool wrapper for SOAP::Lite

RUN_DEPENDS=	p5-ResourcePool>=1.0100:${PORTSDIR}/devel/p5-ResourcePool \
		p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite-060
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
