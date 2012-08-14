# New ports collection makefile for:	p5-Mojolicious-Plugin-Database
# Date created:		2011-03-29
# Whom:			Henk van Oers <hvo.pm@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	Mojolicious-Plugin-Database
PORTVERSION=	1.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Handling of DBI based connections in Mojolicious

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Mojolicious>=1:${PORTSDIR}/www/p5-Mojolicious
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny

PERL_CONFIGURE=	yes

MAN3=		Mojolicious::Plugin::Database.3 \
		Mojolicious::Plugin::README.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-version>=0:${PORTSDIR}/devel/p5-version
RUN_DEPENDS+=	p5-version>=0:${PORTSDIR}/devel/p5-version
.endif

.include <bsd.port.post.mk>
