# New ports collection makefile for:	p5-ResourcePool-Resourse-Net-LDAP
# Date created:			February 06th, 2003
# Whom:	      			erwin@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ResourcePool-Resource-Net-LDAP
PORTVERSION=	1.0002
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://www.fatalmind.com/projects/ResourcePool/
MASTER_SITE_SUBDIR=	../by-authors/id/M/MW/MWS
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	A ResourcePool wrapper for Net::LDAP

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/ResourcePool.pm:${PORTSDIR}/devel/p5-ResourcePool \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		ResourcePool::Resource::Net::LDAP.3 ResourcePool::Factory::Net::LDAP.3

.include <bsd.port.mk>
