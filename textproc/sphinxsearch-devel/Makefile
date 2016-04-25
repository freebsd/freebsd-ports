# Created by: Daniel Gerzo <danger@FreeBSD.org>
# $FreeBSD$

# Note: the Sphinx Storage Engine MySQL plugin is not supported by
# this port.  You need a patched version of mysql server for that.
# See http://www.infracaninophile.co.uk/articles/sphinxse.html

PORTNAME=	sphinxsearch
PORTVERSION=	2.2.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	textproc databases
MASTER_SITES=	http://sphinxsearch.com/files/ \
		http://snowball.tartarus.org/dist/:libstemmer
PKGNAMESUFFIX?=	-devel
DISTNAME=	sphinx-${PORTVERSION}-beta
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danger@FreeBSD.org
COMMENT=	Sphinx Full-Text Search Engine

LICENSE=	GPLv2

# If expat is present on the system and configure finds it, it will
# unconditionally link the output binary against it.  There's no way
# of turning this off.  So for consistency, make sure it's always on.
LIB_DEPENDS=	libexpat.so:textproc/expat2

OPTIONS_DEFINE=	ICONV ID64 LIBSTEMMER MYSQL OPTIMIZED_CFLAGS PGSQL \
		SYSLOG UNIXODBC DOCS EXAMPLES
OPTIONS_DEFAULT=ICONV MYSQL SYSLOG

ICONV_CONFIGURE_WITH=	iconv
ICONV_USES=		iconv
ICONV_LDFLAGS=		${ICONV_LIB}

# Changes document and word IDs to a 64bit type, useful if you have
# more than about 4.2E9 such items to deal with.  Means corresponding
# changes in DB schema.  Disabled by default.
ID64_DESC=		Use 64-bit document and word IDs
ID64_CONFIGURE_ENABLE=	id64

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
LIBSTEMMER_DESC=	Compile with libstemmer support
LIBSTEMMER_CONFIGURE_WITH=libstemmer
LIBSTEMMER_DISTNAME=	libstemmer_c
LIBSTEMMER_DISTFILES=	${LIBSTEMMER_DISTNAME}.tgz:libstemmer

.if make(makesum) || defined(FETCH_ALL)
OPTIONS_SET_FORCE= LIBSTEMMER
.endif

# The port will successfully compile with both PGSQL and MYSQL support
# simultaneously.  Not sure how useful that is in practice though.

MYSQL_CONFIGURE_WITH=	mysql
MYSQL_CONFIGURE_ON=	--with-mysql-includes=${LOCALBASE}/include/mysql \
			--with-mysql-libs=${LOCALBASE}/lib/mysql
MYSQL_USES=		mysql

OPTIMIZED_CFLAGS_CXXFLAGS=-O3 -fomit-frame-pointer

PGSQL_CONFIGURE_WITH=	pgsql
PGSQL_CONFIGURE_ON=	--with-pgsql-includes=${LOCALBASE}/include \
			--with-pgsql-libs=${LOCALBASE}/lib
PGSQL_USES=		pgsql

SYSLOG_DESC=		Enable logging via syslog
SYSLOG_CONFIGURE_WITH=	syslog

UNIXODBC_CONFIGURE_WITH=unixodbc
UNIXODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC

CONFLICTS=	sphinxsearch-[0-9]* dpsearch-[0-9]* rdb-[0-9]* \
		swish++-[0-9]* xaira-[0-9]*

.include <bsd.port.options.mk>

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
USE_RC_SUBR=	sphinxsearch
SUB_LIST+=	PORTNAME=${PORTNAME}	 \
		CFGFILE=${CFGFILE}	 \
		SPHINX_USR=${USERS}	 \
		SPHINX_GRP=${GROUPS}	 \
		SPHINX_DIR=${SPHINX_DIR} \
		SPHINX_RUN=${SPHINX_RUN} \
		SPHINX_LOG=${SPHINX_LOG}
SUB_FILES+=	pkg-deinstall

.if ${PORT_OPTIONS:MEXAMPLES}
EXAMPLES=	example.sql api
PORTEXAMPLES=	*
.endif

.if ${PORT_OPTIONS:MDOCS}
DOCS=		doc/sphinx.css doc/sphinx.html doc/sphinx.txt doc/sphinx.xml
DOCSRC=		${WRKSRC}/doc
MAN1SRC=	indexer.1 indextool.1 search.1 spelldump.1
MAN8SRC=	searchd.8
.endif

post-extract:
.if ${PORT_OPTIONS:MLIBSTEMMER}
	@( cd ${WRKDIR} && ${COPYTREE_SHARE} ${LIBSTEMMER_DISTNAME} ${WRKSRC} )
.endif

# Fix up the sample configuration file to correspond to FreeBSD norms
post-patch:
	@${REINPLACE_CMD} \
	    -e "s!@CONFDIR@/log/searchd.pid!${SPHINX_RUN}/searchd.pid!"	   \
	    -e "s!@CONFDIR@/log/query.log!${SPHINX_LOG}/sphinx-query.log!" \
	    -e "s!@CONFDIR@/log/searchd.log!${SPHINX_LOG}/searchd.log!"	   \
	    -e "s!@CONFDIR@!${SPHINX_DIR}!"				   \
	    ${WRKSRC}/sphinx.conf.in
.if ${PORT_OPTIONS:MDOCS}
	${SED} -e 's/"1"/"8"/' ${DOCSRC}/searchd.1 > ${DOCSRC}/searchd.8
.for man in ${MAN1}
	${SED} -i~ -e 's/\\fBsearchd\\fR(1)/\\fBsearchd\\fR(8)/' \
		${DOCSRC}/${man}
.endfor
.endif

do-install: install-bin install-docs install-man install-examples

install-bin:
	${INSTALL_PROGRAM} ${WRKSRC}/src/indexer   ${STAGEDIR}${PREFIX}/bin/indexer
	${INSTALL_PROGRAM} ${WRKSRC}/src/indextool ${STAGEDIR}${PREFIX}/bin/indextool
	${INSTALL_PROGRAM} ${WRKSRC}/src/search	   ${STAGEDIR}${PREFIX}/bin/search
	${INSTALL_PROGRAM} ${WRKSRC}/src/spelldump ${STAGEDIR}${PREFIX}/bin/spelldump
	${INSTALL_PROGRAM} ${WRKSRC}/src/searchd   ${STAGEDIR}${PREFIX}/sbin/searchd
	${INSTALL_DATA}	   ${WRKSRC}/sphinx.conf.dist ${STAGEDIR}${CFGFILE}.sample

install-docs:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}/${DOCSDIR})

install-man:
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MAN1SRC} ${STAGEDIR}${MANPREFIX}/man/man1)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MAN8SRC} ${STAGEDIR}${MANPREFIX}/man/man8)

install-examples:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${EXAMPLES}" ${STAGEDIR}${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
