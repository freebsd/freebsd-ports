# New ports collection makefile for:	p5-Mojolicious-Plugin-Database
# Date created:		2011-03-29
# Whom:			Henk van Oers <hvo.pm@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	Mojolicious-Plugin-Database
PORTVERSION=	1.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Handling of DBI based connections in Mojolicious

RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Mojolicious>=1:${PORTSDIR}/www/p5-Mojolicious

PERL_CONFIGURE=	yes

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

MAN3=		Mojolicious::Plugin::Database.3

.include <bsd.port.mk>
