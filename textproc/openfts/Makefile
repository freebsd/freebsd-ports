# Created by: Jun Kuriyama <kuriyama@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openfts
PORTVERSION=	0.40
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/OpenFTS-perl%2C%20v${PORTVERSION}
DISTNAME=	Search-OpenFTS-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Open Source Full Text Search engine

RUN_DEPENDS=	${LOCALBASE}/lib/postgresql/tsearch2.so:${PORTSDIR}/databases/postgresql${DEFAULT_PGSQL_VER}-contrib \
		p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg

USE_PGSQL=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

MAN3=	Search::OpenFTS.3 Search::OpenFTS::Base.3 \
	Search::OpenFTS::Dict::PorterEng.3 Search::OpenFTS::Dict::Snowball.3 \
	Search::OpenFTS::Dict::Synonym.3 Search::OpenFTS::Dict::UnknownDict.3 \
	Search::OpenFTS::Index.3 Search::OpenFTS::Morph::ISpell.3 \
	Search::OpenFTS::Parser.3

PORTDOCS=	Changes INSTALL README primer.html

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.if !defined(NOPORTDOCS)
	@${CP} -p ${WRKSRC}/doc/primer.html ${WRKSRC}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

# Sample DB initialization.
DBNAME?=	openfts
create-database:
	createdb ${DBNAME}
	cd ${LOCALBASE}/share/postgresql/contrib && \
		psql ${DBNAME} < tsearch2.sql && \
		psql ${DBNAME} < openfts.sql

.include <bsd.port.post.mk>
