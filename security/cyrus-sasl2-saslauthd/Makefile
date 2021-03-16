# $FreeBSD$

PKGNAMESUFFIX=	-saslauthd
PORTREVISION=	1

COMMENT=	SASL authentication server for cyrus-sasl2

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

INSTALL_WRKSRC=	${WRKSRC}/saslauthd

USE_RC_SUBR=	saslauthd

CYRUS_CONFIGURE_ARGS=	--with-saslauthd=${SASLAUTHD_RUNPATH}
CONFIGURE_ENV+=		andrew_cv_runpath_switch=none

OPTIONS_DEFINE=		DOCS HTTPFORM OPENLDAP OPENLDAP_SASL
OPTIONS_RADIO=		GSSAPI SASLDB
OPTIONS_RADIO_SASLDB=	BDB1 BDB GDBM LMDB
OPTIONS_DEFAULT=	BDB1

HTTPFORM_DESC=		Enable HTTP form authentication
HTTPFORM_CONFIGURE_ENABLE=httpform
OPENLDAP_DESC=		Use OpenLDAP
OPENLDAP_USE=		OPENLDAP=yes
OPENLDAP_CONFIGURE_ON=	--with-ldap=${LOCALBASE}
OPENLDAP_SASL_DESC=	OpenLDAP client with SASL2 support
OPENLDAP_SASL_VARS=	WANT_OPENLDAP_SASL=yes

SASLDB_DESC=		Experimental SASLdb authentication module
BDB_USES=		bdb
BDB_CONFIGURE_ON=	--enable-auth-sasldb \
			--with-dblib=berkeley \
			--with-bdb-libdir=${BDB_LIB_DIR} \
			--with-bdb-incdir=${BDB_INCLUDE_DIR} \
			--with-bdb=${BDB_LIB_NAME}
BDB1_CONFIGURE_ON=	--enable-auth-sasldb \
			--with-dblib=ndbm
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_CONFIGURE_ON=	--enable-auth-sasldb \
			--with-dblib=gdbm \
			--with-gdbm=${LOCALBASE}
LMDB_DESC=		OpenLDAP Lightning Memory-Mapped Database support
LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb
LMDB_CONFIGURE_ON=	--enable-auth-sasldb \
			--with-dblib=lmdb
LMDB_CFLAGS=		-I${LOCALBASE}/include
LMDB_LDFLAGS=		-L${LOCALBASE}/lib

.if exists(/usr/lib/libkrb5.a)
OPTIONS_RADIO_GSSAPI+=	GSSAPI_BASE
OPTIONS_DEFAULT+=	GSSAPI_BASE
.endif
OPTIONS_RADIO_GSSAPI+=	GSSAPI_HEIMDAL GSSAPI_MIT
GSSAPI_BASE_USES=		gssapi:base
GSSAPI_BASE_CONFIGURE_ON=	--enable-gssapi="${GSSAPIBASEDIR}" \
				--with-gss_impl=heimdal
GSSAPI_HEIMDAL_USES=		gssapi:heimdal,flags
GSSAPI_HEIMDAL_CONFIGURE_ON=	--enable-gssapi="${GSSAPIBASEDIR}" \
				--with-gss_impl=heimdal
GSSAPI_MIT_USES=		gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	--enable-gssapi="${GSSAPIBASEDIR}" \
				--with-gss_impl=mit

DOCS=		COPYING ChangeLog LDAP_SASLAUTHD

.include "${.CURDIR}/../../security/cyrus-sasl2/Makefile.common"
