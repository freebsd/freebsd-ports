# Created by: Daniel Gerzo <danger@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sphinxsearch
PORTVERSION=	2.0.1b
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	textproc databases
MASTER_SITES=	http://sphinxsearch.com/files/
PKGNAMESUFFIX?=	-devel
DISTNAME=	sphinx-2.0.1-beta

PATCH_DIST_STRIP=-p1

MAINTAINER=	danger@FreeBSD.org
COMMENT=	Sphinx Full-Text Search Engine

LICENSE=	GPLv2

LATEST_LINK=	sphinxsearch-devel

CONFLICTS=	sphinxsearch-[0-9]* \
		dpsearch-[0-9]* \
		rdb-[0-9]* \
		swish++-[0-9]* \
		xaira-[0-9]*

# If expat is present on the system and configure finds it, it will
# unconditionally link the output binary against it.  There's no way
# of turning this off. So for consistency, make sure it's always on.
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

OPTIONS_DEFINE=	MYSQL PGSQL ICONV OPTIMIZED_CFLAGS ID64 UNIXODBC \
		DOCS EXAMPLES
ID64_DESC=	64-bit document and word IDs
OPTIONS_DEFAULT=	MYSQL ICONV

NO_STAGE=	yes
.include <bsd.port.options.mk>

# The port will successfully compile with both PGSQL and MYSQL support
# simultaneously.  Not sure how useful that is in practice though.

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--with-mysql
USE_MYSQL=		yes
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
CONFIGURE_ARGS+=	--with-pgsql
USE_PGSQL=		yes
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif

.if ${PORT_OPTIONS:MICONV}
CONFIGURE_ARGS+=        --with-iconv
USES+=              	iconv
.else
CONFIGURE_ARGS+=        --without-iconv
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CXXFLAGS+=              -O3 -fomit-frame-pointer
.endif

# Changes document and word IDs to a 64bit type, useful if you have
# more than about 4.2E9 such items to deal with.  Means corresponding
# changes in DB schema.  Disabled by default.
.if ${PORT_OPTIONS:MID64}
CONFIGURE_ARGS+=        --enable-id64
.endif

.if ${PORT_OPTIONS:MUNIXODBC}
CONFIGURE_ARGS+=        --with-unixodbc
LIB_DEPENDS+=           odbc.2:${PORTSDIR}/databases/unixODBC
.else
CONFIGURE_ARGS+=        --without-unixodbc
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
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
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
	${INSTALL_PROGRAM} ${WRKSRC}/src/search  ${PREFIX}/bin/search
	${INSTALL_PROGRAM} ${WRKSRC}/src/searchd ${PREFIX}/sbin/searchd
	${INSTALL_DATA}	   ${WRKSRC}/sphinx.conf.dist ${CFGFILE}.sample

install-docs:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

install-examples:
.if ${PORT_OPTIONS:MEXAMPLES}
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
