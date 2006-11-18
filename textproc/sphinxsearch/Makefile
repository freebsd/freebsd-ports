# New ports collection makefile for:  Sphinx full-text search engine
# Date created:         12 November 2006
# Whom:                 Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#
# Note: the Sphinx Storage Engine MySQL plugin is not supported by
# this port at the moment.  Maybe later.

PORTNAME=	sphinxsearch
PORTVERSION=	0.9.7.r1
CATEGORIES=	textproc databases
MASTER_SITES=	http://www.sphinxsearch.com/downloads/
DISTNAME=	sphinx-${PORTVERSION:C@\.r([0-9]+)$@-rc\1@}

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	Sphinx Full-Text Search Engine

OPTIONS=	MYSQL            "MySQL support"                   on  \
		PGSQL            "PostgreSQL support"              off \
		OPTIMIZED_CFLAGS "Use compiler optimization (-O3)" off

# Yes, the conflation of CPPFLAGS and CXXFLAGS is deliberate.  No,
# don't ask.

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=		CC=${CC} CPPFLAGS="${CXXFLAGS}"
CFGFILE=	${PREFIX}/etc/sphinx.conf
USE_RC_SUBR=	sphinxsearch.sh
SUB_LIST+=	PORTNAME=${PORTNAME} \
		CFGFILE=${CFGFILE}
.if !defined(NOPORTDOCS)
EXAMPLES=	example.sql api/sphinxapi.php api/test.php api/test2.php
DOCS=		doc/sphinx.css doc/sphinx.html doc/sphinx.txt doc/sphinx.xml
.endif

.include <bsd.port.pre.mk>

# The port will successfully compile with both PGSQL and MYSQL support
# simultaneously.  Not sure how useful that is in practice though.

.if defined(WITH_MYSQL) && !defined(WITHOUT_MYSQL)
CONFIGURE_ARGS+=	--with-mysql
USE_MYSQL=		yes
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if defined(WITH_PGSQL) && !defined(WITHOUT_PGSQL)
CONFIGURE_ARGS+=	--with-pgsql
USE_PGSQL=		yes
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CXXFLAGS+=		-O3 -fomit-frame-pointer
.endif

# Fix up the sample configuration file to correspond to FreeBSD norms

post-patch:
	${REINPLACE_CMD} \
	    -e 's!@CONFDIR@/log/searchd.pid!/var/run/searchd.pid!'    \
	    -e 's!@CONFDIR@/log/query.log!/var/log/sphinx-query.log!' \
	    -e 's!@CONFDIR@/log/searchd.log!/var/log/searchd.log!'    \
	    -e 's!@CONFDIR@!/var/db/sphinxsearch!'                    \
	    ${WRKSRC}/sphinx.conf.in

do-install: install-bin install-docs install-examples

install-bin:
	${INSTALL_PROGRAM} ${WRKSRC}/src/indexer ${PREFIX}/bin/indexer
	${INSTALL_PROGRAM} ${WRKSRC}/src/search  ${PREFIX}/bin/search
	${INSTALL_PROGRAM} ${WRKSRC}/src/searchd ${PREFIX}/sbin/searchd
	${INSTALL_DATA}    ${WRKSRC}/sphinx.conf.dist ${CFGFILE}.sample

install-docs:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

install-examples:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
.for example in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${example} ${EXAMPLESDIR}
.endfor
.endif

post-install:
	@if [ ! -f ${CFGFILE} ]; then \
	  ${CP} -p ${CFGFILE}.sample ${CFGFILE} ; \
	fi

.include <bsd.port.post.mk>
