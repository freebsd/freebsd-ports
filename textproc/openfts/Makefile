# New ports collection makefile for:	OpenFTS
# Date Created:				15 Aug, 2003
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openfts
PORTVERSION=	0.36
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openfts
DISTNAME=	Search-OpenFTS-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Open Source Full Text Search engine

PERL_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN3=	Search::OpenFTS.3 Search::OpenFTS::Base.3 \
	Search::OpenFTS::Dict::PorterEng.3 Search::OpenFTS::Dict::Snowball.3 \
	Search::OpenFTS::Dict::Synonym.3 Search::OpenFTS::Dict::UnknownDict.3 \
	Search::OpenFTS::Index.3 Search::OpenFTS::Morph::ISpell.3 \
	Search::OpenFTS::Parser.3

# Sample DB initialization.
DBNAME?=	openfts
create-database:
	createdb ${DBNAME}
	cd ${PREFIX}/share/postgresql/contrib && \
		psql ${DBNAME} < tsearch.sql && \
		psql ${DBNAME} < openfts.sql

.include <bsd.port.mk>
