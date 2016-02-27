# $FreeBSD$

PKGNAMESUFFIX=	-saslauthd
PORTREVISION=	3

COMMENT=	SASL authentication server for cyrus-sasl2

LIB_DEPENDS=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2

INSTALL_WRKSRC=	${WRKSRC}/saslauthd

USE_RC_SUBR=	saslauthd

CONFIGURE_ARGS=	--enable-login \
		--enable-auth-sasldb \
		--with-saslauthd=${SASLAUTHD_RUNPATH}
CONFIGURE_ENV+=	andrew_cv_runpath_switch=none

OPTIONS_DEFINE=		BDB DOCS OPENLDAP HTTPFORM
BDB_CONFIGURE_ON=	--with-dblib=berkeley \
			--with-bdb-libdir=${BDB_LIB_DIR} \
			--with-bdb-incdir=${BDB_INCLUDE_DIR} \
			--with-bdb=${BDB_LIB_NAME}
BDB_USE=		BDB=yes
BDB_CONFIGURE_OFF=	--with-dblib=ndbm
OPENLDAP_DESC=		Use OpenLDAP
OPENLDAP_USE=		OPENLDAP=yes
OPENLDAP_CONFIGURE_ON=	--with-ldap=${LOCALBASE}
HTTPFORM_DESC=		Enable HTTP form authentication
HTTPFORM_CONFIGURE_ENABLE=httpform

OPTIONS_RADIO=		GSSAPI
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

.include "${.CURDIR}/../../security/cyrus-sasl2/Makefile.common"
