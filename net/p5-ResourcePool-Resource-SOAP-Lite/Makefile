# New ports collection makefile for:	p5-ResourcePool-Resourse-SOAP-Lite
# Date created:			February 28th, 2003
# Whom:	      			Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ResourcePool-Resource-SOAP-Lite
PORTVERSION=	1.0101
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://www.fatalmind.com/projects/ResourcePool/
MASTER_SITE_SUBDIR=	../by-authors/id/M/MW/MWS
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	A ResourcePool wrapper for SOAP::Lite

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/ResourcePool.pm:${PORTSDIR}/devel/p5-ResourcePool \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		ResourcePool::Factory::SOAP::Lite.3 \
		ResourcePool::Command::SOAP::Lite::Call.3

.include <bsd.port.mk>
