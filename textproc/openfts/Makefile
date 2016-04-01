# $FreeBSD$

PORTNAME=	openfts
PORTVERSION=	0.40
PORTREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/OpenFTS-perl%2C%20v${PORTVERSION}
DISTNAME=	Search-OpenFTS-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Open Source Full Text Search engine

RUN_DEPENDS=	p5-DBD-Pg>=0:databases/p5-DBD-Pg

USES+=		perl5 pgsql shebangfix
SHEBANG_FILES=	examples/*.pl examples/parser/*.pl
USE_PERL5=	configure
WANT_PGSQL=	contrib

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	Changes INSTALL README primer.html

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${STAGEDIR}${EXAMPLESDIR}."

	@${CP} -p ${WRKSRC}/doc/primer.html ${WRKSRC}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${STAGEDIR}${DOCSDIR}."

# Sample DB initialization.
DBNAME?=	openfts
create-database:
	createdb ${DBNAME}
	cd ${LOCALBASE}/share/postgresql/contrib && \
		psql ${DBNAME} < tsearch2.sql && \
		psql ${DBNAME} < openfts.sql

.include <bsd.port.mk>
