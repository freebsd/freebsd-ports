# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=	heimdal
PORTVERSION=	1.5.3
PORTREVISION=	7
CATEGORIES=	security ipv6
MASTER_SITES=	http://www.h5l.org/dist/src/ \
		http://ftp.pdc.kth.se/pub/heimdal/src/ \
		ftp://ftp.pdc.kth.se/pub/heimdal/src/ \
		ftp://ftp.sunet.se/pub/unix/admin/mirror-pdc/heimdal/src/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Popular BSD-licensed implementation of Kerberos 5

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS=	krb4-[0-9]* krb5-[0-9]* krb5-maint-[0-9]* srp-[0-9]* \
		wu-ftpd-[0-9]* wu-ftpd+ipv6-[0-9]*

USES=		gettext gssapi:bootstrap,heimdal libtool pathfix pkgconfig \
		readline makeinfo ssl
USE_LDCONFIG=	${GSSAPILIBDIR}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ENV=	ac_cv_header_fnmatch_h=yes \
		ac_cv_header_db_h=no \
		ac_cv_header_db3_db_h=no \
		ac_cv_header_db4_db_h=no \
		ac_cv_header_db5_db_h=no \
		ac_cv_header_db5_h=no \
		ac_cv_prog_COMPILE_ET=${WRKSRC}/lib/com_err/compile_et
CONFIGURE_ARGS=	--with-libintl \
		--with-libintl-include="${LOCALBASE}/include" \
		--with-libintl-lib="${LOCALBASE}/lib" \
		--libdir="${GSSAPILIBDIR}" \
		--includedir="${GSSAPIINCDIR}" \
		--with-kcm \
		--with-openssl \
		--with-openssl-include="${OPENSSLINC}" \
		--with-openssl-lib="${OPENSSLLIB}" \
		--enable-otp \
		--enable-pthread-support \
		--with-readline="${LOCALBASE}" \
		--with-hdbdir="/var/${PORTNAME}" \
		--sysconfdir="${PREFIX}/etc"
# XXX --with-readline picks up libreadline even if found in /usr/lib.
MAKE_ENV=	INSTALL_CATPAGES=no
.if !exists(/etc/rc.d/ipropd_master)
USE_RC_SUBR=	ipropd_master ipropd_slave
.endif
INFO=		heimdal hx509

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	IPV6 BDB SQLITE LDAP PKINIT DIGEST KX509 CRACKLIB X11
OPTIONS_DEFAULT=     BDB             PKINIT DIGEST KX509
OPTIONS_SUB=	yes

IPV6_CONFIGURE_WITH=	ipv6

BDB_DESC=		Enable BerkeleyDB KDC backend support
BDB_USES=		bdb:5 localbase
BDB_CONFIGURE_WITH=	berkeley-db
BDB_CONFIGURE_ENV=	ac_cv_header_db${BDB_VER}_db_h=yes \
			ac_cv_func_db_create=yes \
			ac_cv_funclib_db_create="-l${BDB_LIB_NAME}"
BDB_CONFIGURE_ON=	--disable-ndbm-db

SQLITE_DESC=		Enable SQLite KDC backend support
SQLITE_USES=		sqlite
SQLITE_CONFIGURE_ON=	--with-sqlite3-include="${LOCALBASE}/include" \
			--with-sqlite3-lib="${LOCALBASE}/lib"
SQLITE_CONFIGURE_WITH=	sqlite3

LDAP_DESC=		Enable OpenLDAP KDC backend support
LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_ON= 	--with-openldap-include="${LOCALBASE}/include" \
			--with-openldap-lib="${LOCALBASE}/lib"
LDAP_CONFIGURE_WITH=	openldap

PKINIT_DESC=		Enable PK-INIT support
PKINIT_CONFIGURE_ENABLE=pk-init

DIGEST_DESC=		Enable DIGEST support
DIGEST_CONFIGURE_ENABLE=digest

KX509_DESC=		Enable kx509 support
KX509_CONFIGURE_ENABLE=	kx509

CRACKLIB_DESC=		Use CrackLib for password quality checking
CRACKLIB_BUILD_DEPENDS=	${LOCALBASE}/lib/libcrack.a:security/cracklib

X11_DESC=		Build X11 utilies
X11_USE=		XORG=x11,xt
X11_CONFIGURE_WITH=	x

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
WANT_OPENLDAP_SASL?=	yes
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/kpasswdd-cracklib
	${INSTALL_DATA} ${FILESDIR}/kpasswdd-cracklib.c \
	    ${WRKSRC}/kpasswdd-cracklib
	${INSTALL_DATA} ${FILESDIR}/kpasswdd-Makefile \
	    ${WRKSRC}/kpasswdd-cracklib/Makefile

.if ${PORT_OPTIONS:MCRACKLIB}
post-build:
	cd ${WRKSRC}/kpasswdd-cracklib && \
	    ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} ${BUILD_TARGET}

post-install:
	cd ${WRKSRC}/kpasswdd-cracklib && \
	    ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} ${INSTALL_TARGET}
.endif

.include <bsd.port.mk>
