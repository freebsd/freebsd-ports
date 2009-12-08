# New ports collection makefile for:	asql
# Date created:		2008-10-15
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	asql
PORTVERSION=	1.4
CATEGORIES=	www
MASTER_SITES=	http://www.steve.org.uk/Software/asql/

MAINTAINER=	gslin@gslin.org
COMMENT=	Query Apache logfiles via SQL

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/Term/ReadLine/Perl.pm:${PORTSDIR}/devel/p5-ReadLine-Perl

NO_BUILD=	yes
PLIST_FILES=	bin/asql
USE_PERL5=	yes

.include <bsd.port.mk>
