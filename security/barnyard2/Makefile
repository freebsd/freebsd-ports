# $FreeBSD$

PORTNAME=	barnyard2
PORTVERSION=	1.10
PORTREVISION?=	0
CATEGORIES=	security

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Interpreter for Snort unified2 binary output files

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	firnsy
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	v2-${PORTVERSION}
GH_COMMIT=	2f5d496

OPTIONS_DEFINE=	MYSQL PGSQL BRO SNORT SNORTSAM SURICATA
OPTIONS_DEFAULT=#empty
NO_OPTIONS_SORT=yes

BRO_DESC=	Depend on security/bro
MYSQL_DESC=	Enable MySQL support
PGSQL_DESC=	Enable PostgreSQL support
SNORT_DESC=	Depend on security/snort
SNORTSAM_DESC=	Depend on security/snortsam
SURICATA_DESC=	Depend on security/suricata

.if !defined(SLAVE)
OPTIONS_DEFINE+=TCL
.endif

USE_AUTOTOOLS=	libtoolize aclocal autoheader automake autoconf
LIBTOOLIZE_ARGS=--copy --force
AUTOMAKE_ARGS=	--add-missing --copy
ACLOCAL_ARGS=	-I m4 -I ${LOCALBASE}/share/aclocal

USE_RC_SUBR=	barnyard2
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

SUB_FILES=	pkg-message

PORTDOCS1=	README RELEASE.NOTES
PORTDOCS2=	INSTALL README.aruba README.database README.sguil README.snortsam
PORTEXAMPLES=	create_db2 create_mysql	create_postgresql SCHEMA_ACCESS	create_mssql create_oracle.sql
PORTDOCS=	${PORTDOCS1} ${PORTDOCS2}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql \
			--with-mysql-includes=${LOCALBASE}/include/mysql \
			--with-mysql-libraries=${LOCALBASE}/lib/mysql
SUB_LIST+=		MYSQL=" mysql"
.else
CONFIGURE_ARGS+=	--without-mysql
SUB_LIST+=		MYSQL=""
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgresql=${LOCALBASE}
SUB_LIST+=		PGSQL=" postgresql"
.else
CONFIGURE_ARGS+=	--without-postgresql
SUB_LIST+=		PGSQL=""
.endif

.if ${PORT_OPTIONS:MBRO}
RUN_DEPENDS+=		${LOCALBASE}/bin/bro:${PORTSDIR}/security/bro
.endif

.if ${PORT_OPTIONS:MSNORT}
RUN_DEPENDS+=		${LOCALBASE}/bin/snort:${PORTSDIR}/security/snort
.endif

.if ${PORT_OPTIONS:MSNORTSAM}
RUN_DEPENDS+=		${LOCALBASE}/bin/snortsnam:${PORTSDIR}/security/snortsam
.endif

.if ${PORT_OPTIONS:MSURICATA}
RUN_DEPENDS+=		${LOCALBASE}/bin/suricata:${PORTSDIR}/security/suricata
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
