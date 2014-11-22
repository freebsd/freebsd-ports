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

USES+=		perl5 pgsql
USE_PERL5=	configure

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
