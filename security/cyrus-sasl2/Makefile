# $FreeBSD$

PORTREVISION=	1

COMMENT=	RFC 2222 SASL (Simple Authentication and Security Layer)

USES=		cpe libtool:keepla pathfix perl5
USE_PERL5=	patch

CYRUS_CONFIGURE_ARGS=	--with-saslauthd=${SASLAUTHD_RUNPATH}

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=		ALWAYSTRUE AUTHDAEMOND DOCS KEEP_DB_OPEN \
			OBSOLETE_CRAM_ATTR OBSOLETE_DIGEST_ATTR
OPTIONS_RADIO=		SASLDB
OPTIONS_RADIO_SASLDB=	BDB1 BDB GDBM LMDB
OPTIONS_GROUP=		PLUGIN
OPTIONS_GROUP_PLUGIN=	ANONYMOUS CRAM DIGEST LOGIN NTLM OTP PLAIN SCRAM
OPTIONS_DEFAULT=	ANONYMOUS AUTHDAEMOND BDB1 OBSOLETE_CRAM_ATTR CRAM \
			OBSOLETE_DIGEST_ATTR DIGEST LOGIN NTLM OTP PLAIN SCRAM
OPTIONS_SUB=		yes
ALWAYSTRUE_DESC=	Alwaystrue password verifier (discouraged)
ALWAYSTRUE_CONFIGURE_ENABLE=alwaystrue
AUTHDAEMOND_DESC=	Use of authdaemon
AUTHDAEMOND_CONFIGURE_ON=--with-authdaemond=/var/run/authdaemond/socket
AUTHDAEMOND_CONFIGURE_OFF=--with-authdaemond=no
KEEP_DB_OPEN_DESC=	Keep handle to Berkeley DB open
KEEP_DB_OPEN_CONFIGURE_ENABLE=keep-db-open
OBSOLETE_CRAM_ATTR_DESC=cmusaslsecretCRAM-MD5 auxprop property
OBSOLETE_CRAM_ATTR_CONFIGURE_OFF=--enable-obsolete_cram_attr=no
OBSOLETE_DIGEST_ATTR_DESC=cmusaslsecretDIGEST-MD5 auxprop property
OBSOLETE_DIGEST_ATTR_CONFIGURE_OFF=--enable-obsolete_digest_attr=no
SASLDB_DESC=		SASLdb auxprop plugin
BDB_USES=		bdb
BDB_CONFIGURE_ON=	--with-dblib=berkeley \
			--with-bdb-libdir=${BDB_LIB_DIR} \
			--with-bdb-incdir=${BDB_INCLUDE_DIR} \
			--with-bdb=${BDB_LIB_NAME}
BDB1_CONFIGURE_ON=	--with-dblib=ndbm
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_CONFIGURE_ON=	--with-dblib=gdbm \
			--with-gdbm=${LOCALBASE}
LMDB_DESC=		OpenLDAP Lightning Memory-Mapped Database support
LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb
LMDB_CONFIGURE_ON=	--with-dblib=lmdb
LMDB_CFLAGS=		-I${LOCALBASE}/include
LMDB_LDFLAGS=		-L${LOCALBASE}/lib
ANONYMOUS_DESC=			ANONYMOUS authentication
ANONYMOUS_CONFIGURE_ENABLE=	anon
CRAM_DESC=		CRAM-MD5 authentication
CRAM_CONFIGURE_ENABLE=	cram
DIGEST_DESC=		DIGEST-MD5 authentication
DIGEST_CONFIGURE_ENABLE=digest
LOGIN_DESC=		LOGIN authentication
LOGIN_CONFIGURE_ENABLE=	login
NTLM_DESC=		NTLM authentication
NTLM_CONFIGURE_ENABLE=	ntlm
OTP_DESC=		OTP authentication
OTP_CONFIGURE_ENABLE=	otp
PLAIN_DESC=		PLAIN authentication
PLAIN_CONFIGURE_ENABLE=	plain
SCRAM_DESC=		SCRAM authentication
SCRAM_CONFIGURE_ENABLE=	scram

DOCS=	AUTHORS COPYING ChangeLog INSTALL INSTALL.TXT README

.include "${.CURDIR}/../../security/cyrus-sasl2/Makefile.common"
