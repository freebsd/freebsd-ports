# $FreeBSD$

PORTNAME=	barnyard2
PORTVERSION=	1.13
DISTVERSIONPREFIX=	v2-
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Interpreter for Snort unified2 binary output files

LICENSE=	GPLv2

USES=		autoreconf libtool

USE_GITHUB=	yes
GH_ACCOUNT=	firnsy

OPTIONS_DEFINE=	64BIT ARUBA BRO GRE IPV6 MPLS PORT_PCAP DOCS EXAMPLES
OPTIONS_RADIO=	DATABASE
OPTIONS_RADIO_DATABASE=	MYSQL MYSQL_SSL ODBC PGSQL
NO_OPTIONS_SORT=yes

64BIT_DESC=	Enable 64bit compilation (experimental)
ARUBA_DESC=	Enable aruba support
BRO_DESC=	Enable bro support (libbroccoli)
GRE_DESC=	Enable gre support
MYSQL_SSL_DESC=	Enable mysql ssl support (experimental)
PORT_PCAP_DESC=	Use libpcap from ports

.if defined(SLAVE)
OPTIONS_DEFINE+=	TCL
TCL_DESC=	Enable tcl support for sguil
OPTIONS_DEFAULT+=	TCL
.endif

USE_RC_SUBR=	barnyard2
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

PORTDOCS1=	README RELEASE.NOTES
PORTDOCS2=	INSTALL README.aruba README.database README.sguil README.sig_suppress README.snortsam
EXAMPLES=	SCHEMA_ACCESS create_db2 create_mssql create_mysql create_oracle.sql create_postgresql

64BIT_CONFIGURE_ENABLE=	64bit-gcc
ARUBA_CONFIGURE_ENABLE=	aruba
BRO_LIB_DEPENDS=	libbroccoli.so:security/broccoli
BRO_CONFIGURE_ON=	--with-broccoli=${LOCALBASE}/lib
BRO_CONFIGURE_ENABLE=	bro
GRE_CONFIGURE_ENABLE=	gre
IPV6_CONFIGURE_ENABLE=	ipv6
MPLS_CONFIGURE_ENABLE=	mpls
MYSQL_USES=		mysql
MYSQL_CONFIGURE_WITH=	mysql
MYSQL_CONFIGURE_ON=	--with-mysql-includes=${LOCALBASE}/include/mysql \
			--with-mysql-libraries=${LOCALBASE}/lib/mysql
MYSQL_SSL_CONFIGURE_ENABLE=	mysql-ssl-support
ODBC_BROKEN=		fails to build with ODBC=on
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
ODBC_CONFIGURE_WITH=	odbc
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-postgresql=${LOCALBASE}/bin/pg_config --with-pgsql-includes=${LOCALBASE}/include/postgresql/server
PGSQL_CONFIGURE_OFF=	--without-postgresql
TCL_USES=		tcl
TCL_CONFIGURE_ON=	--with-tcl=${LOCALBASE}/lib/tcl${TCL_VER}
TCL_CONFIGURE_OFF=	--without-tcl
PORT_PCAP_LIB_DEPENDS=	libpcap.so.1:net/libpcap
PORT_PCAP_CONFIGURE_ON=	--with-libpcap-includes=${LOCALBASE}/include \
			--with-libpcap-libraries=${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} 's|/etc|${LOCALBASE}/etc|' \
		${WRKSRC}/etc/barnyard2.conf

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS1:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS2:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/schemas/|} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/barnyard2 ${STAGEDIR}${PREFIX}/bin/
	${CP} ${WRKSRC}/etc/barnyard2.conf ${STAGEDIR}${PREFIX}/etc/barnyard2.conf.sample

.include <bsd.port.mk>
