# Created by: Matthew Seaman
# $FreeBSD$

# Note: the Sphinx Storage Engine MySQL plugin is not supported by
# this port.  You need a patched version of mysql server for that.
# See http://www.infracaninophile.co.uk/articles/sphinxse.html

PORTNAME=	sphinxsearch
PORTVERSION=	2.1.3
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
LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

OPTIONS_DEFINE=	ICONV ID64 LIBSTEMMER MYSQL OPTIMIZED_CFLAGS PGSQL \
		SYSLOG UNIXODBC

#ICONV_DESC=		Iconv support
ID64_DESC=		use 64-bit document and word IDs
LIBSTEMMER_DESC=	compile with libstemmer support
#MYSQL_DESC=		MySQL support
#OPTIMIZED_CFLAGS_DESC=	Use compiler optimization (-O3)
#PGSQL_DESC=		PostgreSQL support
SYSLOG_DESC=		enable logging via syslog
UNIXODBC_DESC=		unixODBC support

OPTIONS_DEFAULT=	ICONV MYSQL SYSLOG

CONFLICTS=	sphinxsearch-devel-[0-9]* dpsearch-[0-9]* rdb-[0-9]* \
		swish++-[0-9]* xaira-[0-9]*

.include <bsd.port.options.mk>

# The port will successfully compile with both PGSQL and MYSQL support
# simultaneously.  Not sure how useful that is in practice though.

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--with-mysql \
			--with-mysql-includes=${LOCALBASE}/include/mysql \
			--with-mysql-libs=${LOCALBASE}/lib/mysql
USE_MYSQL=		yes
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
CONFIGURE_ARGS+=	--with-pgsql \
			--with-pgsql-includes=${LOCALBASE}/include \
			--with-pgsql-libs=${LOCALBASE}/lib
USE_PGSQL=		yes
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif

.if ${PORT_OPTIONS:MICONV}
CONFIGURE_ARGS+=	--with-iconv
USES+=			iconv
LDFLAGS+=		${ICONV_LIB}
.else
CONFIGURE_ARGS+=	--without-iconv
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CXXFLAGS+=		-O3 -fomit-frame-pointer
.endif

# Changes document and word IDs to a 64bit type, useful if you have
# more than about 4.2E9 such items to deal with.  Means corresponding
# changes in DB schema.  Disabled by default.
.if ${PORT_OPTIONS:MID64}
CONFIGURE_ARGS+=	--enable-id64
.endif

.if ${PORT_OPTIONS:MUNIXODBC}
CONFIGURE_ARGS+=	--with-unixodbc
LIB_DEPENDS+=		odbc:${PORTSDIR}/databases/unixODBC
.else
CONFIGURE_ARGS+=	--without-unixodbc
.endif

.if ${PORT_OPTIONS:MSYSLOG}
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

.if ${PORT_OPTIONS:MLIBSTEMMER} || make(makesum) || defined(FETCH_ALL)
MASTER_SITES+=	http://snowball.tartarus.org/dist/:libstemmer
LIBSTEMMER_TGZ=	libstemmer_c.tgz
DISTFILES+=	${LIBSTEMMER_TGZ}:libstemmer
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

.if ${PORT_OPTIONS:MLIBSTEMMER}
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
	@( cd ${WRKSRC} && \
	    ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${LIBSTEMMER_TGZ} \
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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

install-man:
.if ${PORT_OPTIONS:MDOCS}
.for man in ${MAN1SRC}
	${INSTALL_MAN} ${DOCSRC}/${man} ${STAGEDIR}${MANPREFIX}/man/man1/${man}
.endfor
.for man in ${MAN8SRC}
	${INSTALL_MAN} ${DOCSRC}/${man} ${STAGEDIR}${MANPREFIX}/man/man8/${man}
.endfor
.endif

install-examples:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for example in ${EXAMPLES}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${example} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
