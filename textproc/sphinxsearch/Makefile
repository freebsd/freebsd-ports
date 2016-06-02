# Created by: Matthew Seaman
# $FreeBSD$

# Note: the Sphinx Storage Engine MySQL plugin is not supported by
# this port.  You need a patched version of mysql server for that.
# See http://www.infracaninophile.co.uk/articles/sphinxse.html

PORTNAME=	sphinxsearch
PORTVERSION=	2.2.10
PORTREVISION=	1
CATEGORIES=	textproc databases
MASTER_SITES=	http://sphinxsearch.com/files/ \
		http://snowball.tartarus.org/dist/:libstemmer
DISTNAME=	sphinx-${PORTVERSION}-release
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Sphinx Full-Text Search Engine

LICENSE=	GPLv2

# If expat is present on the system and configure finds it, it will
# unconditionally link the output binary against it.  There's no way
# of turning this off.  So for consistency, make sure it's always on.
LIB_DEPENDS=	libexpat.so:textproc/expat2

OPTIONS_DEFINE=	ICONV ID64 LIBSTEMMER MYSQL OPTIMIZED_CFLAGS PGSQL \
		RE2 SYSLOG UNIXODBC DOCS EXAMPLES
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
OPTIONS_SET_FORCE=	LIBSTEMMER
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

# Why does this insist on linking against the libre2.a static library?

RE2_DESC=		Enable re2 regular expression library
RE2_CONFIGURE_WITH=	re2
RE2_BUILD_DEPENDS=	${LOCALBASE}/lib/libre2.a:devel/re2

SYSLOG_DESC=		Enable logging via syslog
SYSLOG_CONFIGURE_WITH=	syslog

UNIXODBC_CONFIGURE_WITH=unixodbc
UNIXODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC

CONFLICTS=	sphinxsearch-devel-[0-9]* dpsearch-[0-9]* rdb-[0-9]* \
		swish++-[0-9]* xaira-[0-9]*

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

BINS=		indexer indextool spelldump wordbreaker

EXAMPLES=	example.sql api

DOCS=		doc/sphinx.css doc/sphinx.html doc/sphinx.txt doc/sphinx.xml \
		sphinx-min.conf.dist
DOCSRC=		${WRKSRC}/doc

MAN1SRC=	indexer.1 indextool.1 spelldump.1
MAN8SRC=	searchd.8

post-extract-LIBSTEMMER-on:
	@( cd ${WRKDIR} && ${COPYTREE_SHARE} ${LIBSTEMMER_DISTNAME} ${WRKSRC} )

# Fix up the sample configuration file to correspond to FreeBSD norms
post-patch:
	@${REINPLACE_CMD} \
	    -e "s!@CONFDIR@/log/searchd.pid!${SPHINX_RUN}/searchd.pid!"	   \
	    -e "s!@CONFDIR@/log/query.log!${SPHINX_LOG}/sphinx-query.log!" \
	    -e "s!@CONFDIR@/log/searchd.log!${SPHINX_LOG}/searchd.log!"	   \
	    -e "s!@CONFDIR@!${SPHINX_DIR}!"				   \
	    ${WRKSRC}/sphinx.conf.in
	${SED} -e 's/"1"/"8"/' ${DOCSRC}/searchd.1 > ${DOCSRC}/searchd.8
.for man in ${MAN1}
	${SED} -i~ -e 's/\\fBsearchd\\fR(1)/\\fBsearchd\\fR(8)/' \
		${DOCSRC}/${man}
.endfor

do-install:
.for bin in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${bin} ${STAGEDIR}${PREFIX}/bin/${bin}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/src/searchd ${STAGEDIR}${PREFIX}/sbin/searchd
	${INSTALL_DATA}	   ${WRKSRC}/sphinx.conf.dist ${STAGEDIR}${CFGFILE}.sample
.for man in ${MAN1SRC}
	${INSTALL_MAN} ${DOCSRC}/${man} ${STAGEDIR}${MANPREFIX}/man/man1/${man}
.endfor
.for man in ${MAN8SRC}
	${INSTALL_MAN} ${DOCSRC}/${man} ${STAGEDIR}${MANPREFIX}/man/man8/${man}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for example in ${EXAMPLES}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${example} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
