# New ports collection makefile for:  Sphinx full-text search engine
# Date created:         18 January 2008
# Whom:                 Daniel Gerzo <danger@FreeBSD.org>
#
# $FreeBSD$
#
# Note: the Sphinx Storage Engine MySQL plugin is not supported by
# this port.  You need a patched version of mysql server for that.

PORTNAME=	sphinxsearch
PORTVERSION=	0.9.9.r2
PORTEPOCH=	1
CATEGORIES=	textproc databases
MASTER_SITES=	http://www.sphinxsearch.com/downloads/
PKGNAMESUFFIX?=	-devel
DISTNAME=	sphinx-0.9.9-rc2

PATCH_DIST_STRIP=-p1

MAINTAINER=	danger@FreeBSD.org
COMMENT=	Sphinx Full-Text Search Engine

LATEST_LINK=	sphinxsearch-devel

CONFLICTS=	sphinxsearch-[0-9]*

OPTIONS=	MYSQL            "MySQL support"                   on  \
		PGSQL            "PostgreSQL support"              off \
		OPTIMIZED_CFLAGS "Use compiler optimization (-O3)" off

SPHINX_USR?=	_sphinx
SPHINX_UID?=	312
SPHINX_GRP?=	_sphinx
SPHINX_GID?=	312
SPHINX_DIR?=	/var/db/${PORTNAME}
SPHINX_RUN?=	/var/run/${PORTNAME}
SPHINX_LOG?=	/var/log/${PORTNAME}

# Yes, the conflation of CPPFLAGS and CXXFLAGS is deliberate.  No,
# don't ask.

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CC=${CC} CPPFLAGS="${CXXFLAGS}"
CFGFILE=	${PREFIX}/etc/sphinx.conf
USE_RC_SUBR=	sphinxsearch.sh
SUB_LIST+=	PORTNAME=${PORTNAME}     \
		CFGFILE=${CFGFILE}       \
		SPHINX_USR=${SPHINX_USR} \
		SPHINX_UID=${SPHINX_UID} \
		SPHINX_GRP=${SPHINX_GRP} \
		SPHINX_GID=${SPHINX_GID} \
		SPHINX_DIR=${SPHINX_DIR} \
		SPHINX_RUN=${SPHINX_RUN} \
		SPHINX_LOG=${SPHINX_LOG}
SUB_FILES+=	pkg-install pkg-deinstall

.if !defined(NOPORTDOCS)
DOCS=		doc/sphinx.css doc/sphinx.html doc/sphinx.txt doc/sphinx.xml
.endif

.if !defined(NOPORTEXAMPLES)
EXAMPLES=	example.sql api/sphinxapi.php api/test.php api/test2.php
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" && ${OSVERSION} < 700000
BROKEN=		Does not build on sparc64-6
.endif

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
	@${REINPLACE_CMD} \
	    -e "s!@CONFDIR@/log/searchd.pid!${SPHINX_RUN}/searchd.pid!"    \
	    -e "s!@CONFDIR@/log/query.log!${SPHINX_LOG}/sphinx-query.log!" \
	    -e "s!@CONFDIR@/log/searchd.log!${SPHINX_LOG}/searchd.log!"    \
	    -e "s!@CONFDIR@!${SPHINX_DIR}!"                                \
	    ${WRKSRC}/sphinx.conf.in

pre-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

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
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for example in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${example} ${EXAMPLESDIR}
.endfor
.endif

post-install: post-install-cfg
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

post-install-cfg:
	@if [ ! -f ${CFGFILE} ]; then \
	  ${CP} -p ${CFGFILE}.sample ${CFGFILE} ; \
	fi

.include <bsd.port.post.mk>
