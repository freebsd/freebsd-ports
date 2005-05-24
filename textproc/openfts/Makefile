# New ports collection makefile for:	OpenFTS
# Date Created:				15 Aug, 2003
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openfts
PORTVERSION=	0.37
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openfts
DISTNAME=	Search-OpenFTS-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Open Source Full Text Search engine

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes	\
		${LOCALBASE}/lib/postgresql/tsearch2.so:${PORTSDIR}/databases/postgresql-contrib

PERL_CONFIGURE=	yes

MAN3=	Search::OpenFTS.3 Search::OpenFTS::Base.3 \
	Search::OpenFTS::Dict::PorterEng.3 Search::OpenFTS::Dict::Snowball.3 \
	Search::OpenFTS::Dict::Synonym.3 Search::OpenFTS::Dict::UnknownDict.3 \
	Search::OpenFTS::Index.3 Search::OpenFTS::Morph::ISpell.3 \
	Search::OpenFTS::Parser.3

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes INSTALL README primer.html

.if ${PERL_LEVEL} < 500600
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg-13
.else
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif	# ${PERL_LEVEL} < 500600

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
	@${CP} -p ${WRKSRC}/doc/primer.html ${WRKSRC}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif	# defined(NOPORTDOCS)

# Sample DB initialization.
DBNAME?=	openfts
create-database:
	createdb ${DBNAME}
	cd ${LOCALBASE}/share/postgresql/contrib && \
		psql ${DBNAME} < tsearch.sql && \
		psql ${DBNAME} < openfts.sql

.include <bsd.port.post.mk>
