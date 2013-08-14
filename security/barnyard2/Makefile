# $FreeBSD$

PORTNAME=	barnyard2
PORTVERSION=	1.12
CATEGORIES=	security

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Interpreter for Snort unified2 binary output files

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	firnsy
GH_TAGNAME=	v2-${PORTVERSION}
GH_COMMIT=	3c1f553

OPTIONS_DEFINE=	64BIT ARUBA BRO GRE IPV6 MPLS MYSQL MYSQL_SSL ODBC PRELUDE PGSQL
NO_OPTIONS_SORT=yes

64BIT_DESC=	Enable 64bit compilation (experimental)
ARUBA_DESC=	Enable aruba support
BRO_DESC=	Enable bro support (libbroccoli)
GRE_DESC=	Enable gre support
MYSQL_SSL_DESC=	Enable mysql ssl support (experimental)
PRELUDE_DESC=	Enable prelude support

.if defined(SLAVE)
OPTIONS_DEFINE+=	TCL
OPTIONS_DESC=	Enable tcl support for sguil
OPTIONS_DEFAULT+=	TCL
.endif

USE_AUTOTOOLS=	libtoolize aclocal autoheader automake autoconf
LIBTOOLIZE_ARGS=--copy --force
AUTOMAKE_ARGS=	--add-missing --copy
ACLOCAL_ARGS=	-I m4 -I ${LOCALBASE}/share/aclocal

USE_RC_SUBR=	barnyard2
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

PORTDOCS1=	README RELEASE.NOTES
PORTDOCS2=	INSTALL README.aruba README.database README.sguil README.snortsam
PORTDOCS=	${PORTDOCS1} ${PORTDOCS2}
PORTEXAMPLES=	SCHEMA_ACCESS create_db2 create_mssql create_mysql create_oracle.sql create_postgresql

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:M64BIT}
CONFIGURE_ARGS+=	--enable-64bit-gcc
.else
CONFIGURE_ARGS+=	--disable-64bit-gcc
.endif

.if ${PORT_OPTIONS:MARUBA}
CONFIGURE_ARGS+=	--enable-aruba
.else
CONFIGURE_ARGS+=	--disable-aruba
.endif

.if ${PORT_OPTIONS:MBRO}
BROKEN=			Bro port is in transition right now, so this is not supported at this time
BUILD_DEPENDS+=		bro:${PORTSDIR}/security/bro-barnyard2
CONFIGURE_ARGS+=	--enable-bro --with-broccoli=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-bro
.endif

.if ${PORT_OPTIONS:MGRE}
CONFIGURE_ARGS+=	--enable-gre
.else
CONFIGURE_ARGS+=	--disable-gre
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MMPLS}
CONFIGURE_ARGS+=	--enable-mpls
.else
CONFIGURE_ARGS+=	--disable-mpls
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql \
			--with-mysql-includes=${LOCALBASE}/include/mysql \
			--with-mysql-libraries=${LOCALBASE}/lib/mysql
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if ${PORT_OPTIONS:MMYSQL_SSL}
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--enable-mysql-ssl-support
.else
CONFIGURE_ARGS+=	--disable-mysql-ssl-support
.endif

.if ${PORT_OPTIONS:MODBC}
LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc
.else
CONFIGURE_ARGS+=	--without-odbc
.endif

.if ${PORT_OPTIONS:MPRELUDE}
BUILD_DEPENDS+=	prelude-manager:${PORTSDIR}/security/prelude-manager
CONFIGURE_ARGS+=	--enable-prelude
.else
CONFIGURE_ARGS+=	--disable-prelude
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=		yes
WANT_PGSQL_VER=		92+
CONFIGURE_ARGS+=	--with-postgresql=${LOCALBASE}/bin/pg_config --with-pgsql-includes=${LOCALBASE}/include/postgresql/server
.else
CONFIGURE_ARGS+=	--without-postgresql
.endif

.if ${PORT_OPTIONS:MTCL}
USE_TCL=		yes
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/lib/tcl${TCL_VER}
.else
CONFIGURE_ARGS+=	--without-tcl
.endif

post-patch:
	@${REINPLACE_CMD} 's|/etc|${LOCALBASE}/etc|' \
		${WRKSRC}/etc/barnyard2.conf

post-install:
	@${CP} ${WRKSRC}/etc/barnyard2.conf ${PREFIX}/etc/barnyard2.conf.sample
	if [ ! -f ${PREFIX}/etc/barnyard2.conf ]; then \
		${CP} -p ${PREFIX}/etc/barnyard2.conf.sample ${PREFIX}/etc/barnyard2.conf; \
	fi

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS1} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS2} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/schemas && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
