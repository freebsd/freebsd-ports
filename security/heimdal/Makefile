# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=	heimdal
PORTVERSION=	1.5.2
PORTREVISION=	4
CATEGORIES=	security ipv6
MASTER_SITES=	http://www.h5l.org/dist/src/ \
		http://ftp.pdc.kth.se/pub/heimdal/src/ \
		ftp://ftp.pdc.kth.se/pub/heimdal/src/ \
		ftp://ftp.sunet.se/pub/unix/admin/mirror-pdc/heimdal/src/

MAINTAINER=	Joerg.Pulz@frm2.tum.de
COMMENT=	Popular BSD-licensed implementation of Kerberos 5

CONFLICTS=	krb4-[0-9]* krb5-[0-9]* krb5-maint-[0-9]* srp-[0-9]*

OPTIONS_DEFINE=	IPV6 KCM BDB SQLITE LDAP PKINIT DIGEST KX509 CRACKLIB X11
OPTIONS_DEFAULT=	KCM BDB PKINIT DIGEST KX509
KCM_DESC=	Enable Kerberos Credentials Manager
BDB_DESC=	Enable BerkeleyDB KDC backend support
SQLITE_DESC=	Enable SQLite KDC backend support
LDAP_DESC=	Enable OpenLDAP KDC backend support
PKINIT_DESC=	Enable PK-INIT support
DIGEST_DESC=	Enable DIGEST support
KX509_DESC=	Enable kx509 support
CRACKLIB_DESC=	Use CrackLib for password quality checking
X11_DESC=	Build X11 utilies

USE_AUTOTOOLS=	autoconf autoheader libtool
USE_OPENSSL=	yes
USES=		gettext pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=	--with-libintl=${LOCALBASE} \
			--with-readline=${DESTDIR}/usr \
			--enable-pthread-support \
			--with-hdbdir=/var/db/${PORTNAME} \
			--sysconfdir=${PREFIX}/etc
MAKE_ENV+=	INSTALL_CATPAGES=no

INFO=		heimdal hx509
PLIST=		${WRKDIR}/PLIST

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.if ${OSVERSION} >= 700000
PLIST_SUB+=	HCRYPTO="@comment "
.else
PLIST_SUB+=	HCRYPTO=""
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif

.if ${PORT_OPTIONS:MKCM}
CONFIGURE_ARGS+=	--enable-kcm
PLIST_SUB+=	KCM=""
.else
CONFIGURE_ARGS+=	--disable-kcm
PLIST_SUB+=	KCM="@comment "
.endif

.if ${PORT_OPTIONS:MBDB}
USE_BDB=	yes
CFLAGS+=	-I${BDB_INCLUDE_DIR}
CPPFLAGS+=	-I${BDB_INCLUDE_DIR}
LDFLAGS+=	-L${BDB_LIB_DIR}
CONFIGURE_ARGS+=	--with-berkeley-db=${LOCALBASE} \
			--with-berkeley-db-include=${BDB_INCLUDE_DIR}
.else
CONFIGURE_ARGS+=	--with-berkeley-db=no
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	yes
CONFIGURE_ARGS+=	--with-sqlite3=${LOCALBASE}
PLIST_SUB+=	SQLITE="@comment "
.else
CONFIGURE_ARGS+=	--without-sqlite3
PLIST_SUB+=	SQLITE=""
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-openldap=${LOCALBASE}
.  if defined(LDAP_SOCKET_PATH)
_SOCK=		${LDAP_SOCKET_PATH:C|/|%2f|g}
.  else
LDAP_RUN_DIR?=	/var/run/openldap
_SOCK=		${LDAP_RUN_DIR:C|/|%2f|g}%2fldapi
.  endif
.else
CONFIGURE_ARGS+=	--without-openldap
.endif

.if ! ${PORT_OPTIONS:MPKINIT}
CONFIGURE_ARGS+=	--disable-pk-init
.else
CONFIGURE_ARGS+=	--enable-pk-init
.endif

.if ! ${PORT_OPTIONS:MDIGEST}
CONFIGURE_ARGS+=	--disable-digest
.else
CONFIGURE_ARGS+=	--enable-digest
.endif

.if ! ${PORT_OPTIONS:MKX509}
CONFIGURE_ARGS+=	--disable-kx509
.else
CONFIGURE_ARGS+=	--enable-kx509
.endif

.if ${PORT_OPTIONS:MCRACKLIB}
BUILD_DEPENDS+=		${LOCALBASE}/lib/libcrack.a:${PORTSDIR}/security/cracklib
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=		x11 xt
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if defined(HEIMDAL_HOME)
PREFIX=		${HEIMDAL_HOME}
.else
CONFLICTS+=	wu-ftpd-[0-9]* wu-ftpd+ipv6-[0-9]*
.endif

post-patch:
.if ${PORT_OPTIONS:MLDAP}
	@${REINPLACE_CMD} -e 's|%%LDAP_SOCKET%%|${_SOCK:Q}|g' \
		${WRKSRC}/lib/hdb/hdb-ldap.c
.endif
	@${REINPLACE_CMD} -e 's|$$ac_cv_header_fnmatch_h|yes|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|@LDFLAGS@|@LDFLAGS@ \$$\(PTHREADS_LIBADD\)|g' \
		${WRKSRC}/lib/ipc/Makefile.in

post-build:
.if ${PORT_OPTIONS:MCRACKLIB}
	${SED} -e "s;%%LOCALBASE%%;${LOCALBASE};g" \
		${FILESDIR}/kpasswdd-cracklib.c.in > ${WRKSRC}/kpasswdd-cracklib.c
	(cd ${WRKSRC} && \
		${CC} ${CFLAGS} -fPIC -shared -I${LOCALBASE}/include -I./include \
		-L${LOCALBASE}/lib -o ./kpasswdd-cracklib.so ./kpasswdd-cracklib.c -lcrack)
.endif

pre-install:
	@${CP} ${PKGDIR}/pkg-plist ${PLIST}
	@if [ -f ${WRKSRC}/lib/com_err/.libs/compile_et ]; then \
		${CAT} ${PKGDIR}/pkg-plist.com_err >> ${PLIST}; \
	fi
.if ${PORT_OPTIONS:MX11}
	@${CAT} ${PKGDIR}/pkg-plist.x11 >> ${PLIST}
.endif
.if !exists(/usr/include/ifaddrs.h)
	@${ECHO_CMD} include/ifaddrs.h >> ${PLIST}
.endif
.if ${PORT_OPTIONS:MCRACKLIB}
	${INSTALL_PROGRAM} ${WRKSRC}/kpasswdd-cracklib.so ${PREFIX}/lib/
	@${ECHO_CMD} lib/kpasswdd-cracklib.so >> ${PLIST}
.endif

.include "Makefile.man"

post-install:
	${SED} 's;%%PREFIX%%;${PREFIX};g' ${FILESDIR}/kdc.sh > \
		${PREFIX}/etc/rc.d/kdc.sh.sample

.include <bsd.port.mk>
