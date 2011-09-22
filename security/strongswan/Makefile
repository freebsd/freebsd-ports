# New ports collection makefile for:	strongswan
# Date created:				30 May 2010
# Whom:					<riaank@gmail.com>
#
# $FreeBSD$

PORTNAME=	strongswan
PORTVERSION=	4.5.3
CATEGORIES=	security
MASTER_SITES=	http://download.strongswan.org/ \
		http://download2.strongswan.org/

MAINTAINER=	riaank@gmail.com
COMMENT=	Open Source IKEv2 IPsec-based VPN solution

OPTIONS=	SQLITE		"Enable SQLite" off \
		MYSQL		"Enable MySQL" off \
		CURL		"Enable CURL to fetch CRL/OCSP" off \
		EAPAKA3GPP2	"Enable EAP AKA with 3gpp2 backend" off \
		EAPSIMFILE	"Enable EAP SIM with filebased backend" off

USE_RC_SUBR=	strongswan
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--enable-kernel-pfkey \
		--enable-kernel-pfroute  \
		--disable-kernel-netlink  \
		--disable-tools  \
		--disable-scripts  \
		--disable-pluto  \
		--disable-gmp \
		--enable-openssl \
		--enable-eap-identity \
		--enable-eap-md5 \
		--enable-eap-tls \
		--enable-eap-mschapv2 \
		--enable-md4 \
		--enable-blowfish \
		--enable-addrblock \
		--enable-whitelist \
		--with-group=wheel  \
		--with-lib-prefix=${PREFIX}

# Man pages with default install
MAN3=	anyaddr.3 atoaddr.3 atoasr.3 atoul.3 goodmask.3 initaddr.3 \
	initsubnet.3 portof.3 rangetosubnet.3 sameaddr.3 subnetof.3 \
	ttoaddr.3 ttodata.3 ttosa.3 ttoul.3
MAN5=	ipsec.conf.5 ipsec.secrets.5 strongswan.conf.5
MAN8=	ipsec.8 _updown.8 _updown_espmark.8

.include <bsd.port.pre.mk>

# Requires FreeBSD 8 and above to work
.if ${OSVERSION} < 800000
IGNORE=		requires at least FreeBSD 8.X
.endif

# Extra options
.if defined(WITH_SQLITE) || defined (WITH_MYSQL)
CONFIGURE_ARGS+=	--enable-attr-sql
CONFIGURE_ARGS+=	--enable-sql
PLIST_SUB+=	SQL=""
.else
PLIST_SUB+=	SQL="@comment "
.endif

.if defined(WITH_SQLITE)
CONFIGURE_ARGS+=	--enable-sqlite
LIB_DEPENDS += sqlite3.8:${PORTSDIR}/databases/sqlite3
PLIST_SUB+=	SQLITE=""
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--enable-mysql
USE_MYSQL=	yes
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_CURL)
CONFIGURE_ARGS+=	--enable-curl
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
PLIST_SUB+=	CURL=""
.else
PLIST_SUB+=	CURL="@comment "
.endif

.if defined(WITH_EAPSIMFILE)
CONFIGURE_ARGS+=	--enable-eap-sim
CONFIGURE_ARGS+=	--enable-eap-sim-file
PLIST_SUB+=	EAPSIMFILE=""
.else
PLIST_SUB+=	EAPSIMFILE="@comment "
.endif

.if defined(WITH_EAPAKA3GPP2)
CONFIGURE_ARGS+=	--enable-eap-aka
CONFIGURE_ARGS+=	--enable-eap-aka-3gpp2
CONFIGURE_ARGS+=	--enable-gmp
LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp
PLIST_SUB+=	EAPAKA3GPP2=""
.else
PLIST_SUB+=	EAPAKA3GPP2="@comment "
.endif

.include <bsd.port.post.mk>
