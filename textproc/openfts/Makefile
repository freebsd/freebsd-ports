# New ports collection makefile for:	OpenFTS
# Date Created:				15 Aug, 2003
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openfts
PORTVERSION=	0.34
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openfts
DISTNAME=	Search-OpenFTS-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Open Source Full Text Search engine

EXTRACT_DEPENDS=/nonexistent:${PORTSDIR}/databases/postgresql7:configure
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg

PERL_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN3=	Search::OpenFTS.3 Search::OpenFTS::Base.3 \
	Search::OpenFTS::Dict::PorterEng.3 Search::OpenFTS::Dict::Snowball.3 \
	Search::OpenFTS::Dict::UnknownDict.3 Search::OpenFTS::Index.3 \
	Search::OpenFTS::Morph::ISpell.3 Search::OpenFTS::Parser.3

PGSRC=	`cd ${PORTSDIR}/databases/postgresql7; ${MAKE} -VWRKSRC`/contrib
PGMAKE=	${GMAKE} docdir=${PREFIX}/share/doc

post-extract:
	cd ${WRKSRC} && ${CP} -r pgsql_contrib_openfts ${PGSRC}/

post-build:
	cd ${PGSRC}/tsearch && ${GMAKE} && \
	${REINPLACE_CMD} 's,$$libdir,${PREFIX}/lib/postgresql,' tsearch.sql
	cd ${PGSRC}/pgsql_contrib_openfts && ${GMAKE}

post-install:
	cd ${PGSRC}/tsearch && ${PGMAKE} install
	cd ${PGSRC}/pgsql_contrib_openfts && ${PGMAKE} install

# Sample DB initialization.
DBNAME?=	openfts
create-database:
	createdb ${DBNAME}
	cd ${PREFIX}/share/postgresql/contrib && \
		psql ${DBNAME} < tsearch.sql && \
		psql ${DBNAME} < openfts.sql

.include <bsd.port.mk>
