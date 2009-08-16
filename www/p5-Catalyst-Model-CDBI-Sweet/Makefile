# New ports collection makefile for:	www/p5-Catalyst-Model-CDBI-Sweet
# Date created:				18 May 2005
# Whom:					Travis Campbell <hcoyote@ghostar.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Model-CDBI-Sweet
PORTVERSION=	0.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/M/MR/MRAMBERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	CDBI model class for Catalyst that makes things sweeter

BUILD_DEPENDS=	${SITE_PERL}/Catalyst.pm:${PORTSDIR}/www/p5-Catalyst-Runtime \
		${SITE_PERL}/Class/DBI/Sweet.pm:${PORTSDIR}/databases/p5-Class-DBI-Sweet
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	5.8.2+

MAN3=		Catalyst::Model::CDBI::Sweet.3

.include <bsd.port.mk>
