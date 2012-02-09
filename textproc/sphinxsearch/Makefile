# New ports collection makefile for:  Sphinx full-text search engine
# Date created:		12 November 2006
# Whom:			Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#
# Note: the Sphinx Storage Engine MySQL plugin is not supported by
# this port.  You need a patched version of mysql server for that.
# See http://www.infracaninophile.co.uk/articles/sphinxse.html

PORTNAME=	sphinxsearch
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	textproc databases
MASTER_SITES=	http://sphinxsearch.com/files/
DISTNAME=	sphinx-${PORTVERSION}-release
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Sphinx Full-Text Search Engine

LICENSE=	GPLv2

# If expat is present on the system and configure finds it, it will
# unconditionally link the output binary against it.  There's no way
# of turning this off.  So for consistency, make sure it's always on.
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

OPTIONS=	MYSQL		 "MySQL support"		    on	\
		PGSQL		 "PostgreSQL support"		    off \
		ICONV		 "Iconv support"		    on	\
		OPTIMIZED_CFLAGS "Use compiler optimization (-O3)"  off \
		ID64		 "use 64-bit document and word IDs" off \
		UNIXODBC	 "unixODBC support"		    off \
		SYSLOG		 "enable logging via syslog"	    on  \
		LIBSTEMMER	 "compile with libstemmer support"  off

CONFLICTS=	sphinxsearch-devel-[0-9]*

.include <bsd.port.options.mk>

# The port will successfully compile with both PGSQL and MYSQL support
# simultaneously.  Not sure how useful that is in practice though.

.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-mysql
USE_MYSQL=		yes
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if defined(WITH_PGSQL)
CONFIGURE_ARGS+=	--with-pgsql
USE_PGSQL=		yes
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif

.if defined(WITH_ICONV)
CONFIGURE_ARGS+=	--with-iconv
USE_ICONV=		yes
.else
CONFIGURE_ARGS+=	--without-iconv
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CXXFLAGS+=		-O3 -fomit-frame-pointer
.endif

# Changes document and word IDs to a 64bit type, useful if you have
# more than about 4.2E9 such items to deal with.  Means corresponding
# changes in DB schema.  Disabled by default.
.if defined(WITH_ID64)
CONFIGURE_ARGS+=	--enable-id64
.endif

.if defined(WITH_UNIXODBC)
CONFIGURE_ARGS+=	--with-unixodbc
LIB_DEPENDS+=		odbc.2:${PORTSDIR}/databases/unixODBC
.else
CONFIGURE_ARGS+=	--without-unixodbc
.endif

.if defined(WITH_SYSLOG)
CONFIGURE_ARGS+=	--with-syslog
.else
CONFIGURE_ARGS+=	--without-syslog
.endif

# Note: The snowball project doesn't release numbered versions of it's
# pre-processors.  Instead, at arbitrary but fairly long intervals a
# snapshot of their source repository is turned into a tarball (always
# the same filename) and placed on their web site.  It's like they
# want to make it as hard as possible for anyone to package and use
# their software.
#
# Adds support for two additional word stemmming pre-processors from
# the Snowball project (http://snowball.tartarus.org/) -- these
# essentially do exactly the same thing as the built in English,
# Russian and Czech stemmers but also support French, Spanish,
# Portuguese, Italian, Romanian, German, Dutch, Swedish, Norwegian,
# Danish, Finnish, Hungarian.  Disabled by default.

.if defined(WITH_LIBSTEMMER) || make(makesum) || defined(FETCH_ALL)
MASTER_SITES+=	http://snowball.tartarus.org/dist/:libstemmer
LIBSTEMMER_TGZ=	libstemmer_c.tgz
DISTFILES+=	${LIBSTEMMER_TGZ}:libstemmer
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

.if defined(WITH_LIBSTEMMER)
CONFIGURE_ARGS+=	--with-libstemmer
.else
CONFIGURE_ARGS+=	--without-libstemmer
.endif

USERS?=		_sphinx
GROUPS?=	_sphinx

SPHINX_DIR?=	/var/db/${PORTNAME}
SPHINX_RUN?=	/var/run/${PORTNAME}
SPHINX_LOG?=	/var/log/${PORTNAME}

# Yes, the conflation of CPPFLAGS and CXXFLAGS is deliberate.  No,
# don't ask.

GNU_CONFIGURE=	yes
CPPFLAGS+=	${CXXFLAGS}
CFGFILE=	${PREFIX}/etc/sphinx.conf
USE_RC_SUBR=	sphinxsearch.sh
SUB_LIST+=	PORTNAME=${PORTNAME}	 \
		CFGFILE=${CFGFILE}	 \
		SPHINX_USR=${USERS}	 \
		SPHINX_GRP=${GROUPS}	 \
		SPHINX_DIR=${SPHINX_DIR} \
		SPHINX_RUN=${SPHINX_RUN} \
		SPHINX_LOG=${SPHINX_LOG}
SUB_FILES+=	pkg-deinstall

.if !defined(NOPORTEXAMPLES)
EXAMPLES=	example.sql api
PORTEXAMPLES=	*
.endif

.if !defined(NOPORTDOCS)
DOCS=		doc/sphinx.css doc/sphinx.html doc/sphinx.txt doc/sphinx.xml
.endif

post-extract:
.if defined(WITH_LIBSTEMMER)
	@( cd ${WRKSRC} && \
	    ${GZIP_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${LIBSTEMMER_TGZ} \
	    ${EXTRACT_AFTER_ARGS} )
.endif

# Fix up the sample configuration file to correspond to FreeBSD norms
post-patch:
	@${REINPLACE_CMD} \
	    -e "s!@CONFDIR@/log/searchd.pid!${SPHINX_RUN}/searchd.pid!"	   \
	    -e "s!@CONFDIR@/log/query.log!${SPHINX_LOG}/sphinx-query.log!" \
	    -e "s!@CONFDIR@/log/searchd.log!${SPHINX_LOG}/searchd.log!"	   \
	    -e "s!@CONFDIR@!${SPHINX_DIR}!"				   \
	    ${WRKSRC}/sphinx.conf.in

do-install: install-bin install-docs install-examples

install-bin:
	${INSTALL_PROGRAM} ${WRKSRC}/src/indexer ${PREFIX}/bin/indexer
	${INSTALL_PROGRAM} ${WRKSRC}/src/search	 ${PREFIX}/bin/search
	${INSTALL_PROGRAM} ${WRKSRC}/src/spelldump ${PREFIX}/bin/spelldump
	${INSTALL_PROGRAM} ${WRKSRC}/src/searchd ${PREFIX}/sbin/searchd
	${INSTALL_DATA}	   ${WRKSRC}/sphinx.conf.dist ${CFGFILE}.sample

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
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${example} ${EXAMPLESDIR}
.endfor
.endif

post-install-cfg:
	@if [ ! -f ${CFGFILE} ]; then \
	  ${CP} -p ${CFGFILE}.sample ${CFGFILE} ; \
	fi

.include <bsd.port.mk>
