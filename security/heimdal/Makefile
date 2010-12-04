# Ports collection Makefile for:	heimdal
# Date created:						10/23/1999
# Whom:								nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	heimdal
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	security ipv6
MASTER_SITES=	http://www.h5l.org/dist/src/ \
		http://ftp.pdc.kth.se/pub/heimdal/src/ \
		ftp://ftp.pdc.kth.se/pub/heimdal/src/ \
		ftp://ftp.sunet.se/pub/unix/admin/mirror-pdc/heimdal/src/ \
		ftp://ftp.ayamura.org/pub/heimdal/

MAINTAINER=	Joerg.Pulz@frm2.tum.de
COMMENT=	A popular BSD-licensed implementation of Kerberos 5

CONFLICTS=	krb4-[0-9]* krb5-[0-9]* srp-[0-9]*

OPTIONS=	IPV6	"Enable IPV6 support"				on \
		KCM	"Enable Kerberos Credentials Manager"		on \
		BDB	"Enable BerkeleyDB KDC backend support"		off \
		SQLITE	"Enable SQLite KDC backend support"		off \
		LDAP	"Enable OpenLDAP KDC backend support"		off \
		PKINIT	"Enable PK-INIT support"			on \
		DIGEST	"Enable DIGEST support"				on \
		KX509	"Enable kx509 support"				on \
		KRB4	"Enable krb4 support"				off \
		CRACKLIB "Use CrackLib for password quality checking"	off \
		X11	 "Build X11 utilies"				off

USE_AUTOTOOLS=	autoconf autoheader libtool
USE_GNOME=	gnomehack pkgconfig
USE_OPENSSL=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=	--with-libintl=${LOCALBASE} \
			--with-readline=${DESTDIR}/usr \
			--enable-pthread-support

INFO=		heimdal hx509
PLIST=		${WRKDIR}/PLIST

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.if ${OSVERSION} >= 700000
PLIST_SUB+=	HCRYPTO="@comment "
.else
PLIST_SUB+=	HCRYPTO=""
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--without-ipv6
.else
CONFIGURE_ARGS+=	--with-ipv6
.endif

.if !defined(WITHOUT_KCM)
CONFIGURE_ARGS+=	--enable-kcm
PLIST_SUB+=	KCM=""
.else
CONFIGURE_ARGS+=	--disable-kcm
PLIST_SUB+=	KCM="@comment "
.endif

.if defined(WITH_BDB)
USE_BDB=	yes
CFLAGS+=	-I${BDB_INCLUDE_DIR}
LDFLAGS+=	-L${BDB_LIB_DIR}
CONFIGURE_ARGS+=	--with-berkeley-db=${LOCALBASE}
#			--with-berkeley-db-include=${BDB_INCLUDE_DIR}
.else
CONFIGURE_ARGS+=	--without-berkeley-db
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=	yes
CONFIGURE_ARGS+=	--with-sqlite3=${LOCALBASE}
PLIST_SUB+=	SQLITE="@comment "
.else
CONFIGURE_ARGS+=	--without-sqlite3
PLIST_SUB+=	SQLITE=""
.endif

.if defined(WITH_LDAP)
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

.if defined(WITHOUT_PKINIT)
CONFIGURE_ARGS+=	--disable-pk-init
.else
CONFIGURE_ARGS+=	--enable-pk-init
.endif

.if defined(WITHOUT_DIGEST)
CONFIGURE_ARGS+=	--disable-digest
.else
CONFIGURE_ARGS+=	--enable-digest
.endif

.if defined(WITHOUT_KX509)
CONFIGURE_ARGS+=	--disable-kx509
.else
CONFIGURE_ARGS+=	--enable-kx509
.endif

.if !defined(WITH_KRB4)
CONFIGURE_ARGS+=	--disable-krb4
.else
CONFIGURE_ARGS+=	--enable-krb4
.endif

.if defined(WITH_CRACKLIB)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libcrack.a:${PORTSDIR}/security/cracklib
.endif

.if defined(WITH_X11)
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
.if defined(WITH_LDAP)
	@${REINPLACE_CMD} -e 's|%%LDAP_SOCKET%%|${_SOCK:Q}|g' \
		${WRKSRC}/lib/hdb/hdb-ldap.c
.endif
	@${REINPLACE_CMD} -e 's|$$ac_cv_header_fnmatch_h|yes|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|@LDFLAGS@|@LDFLAGS@ \$$\(PTHREADS_LIBADD\)|g' \
		${WRKSRC}/lib/ipc/Makefile.in

# These will be fixed in the next release. Looks like they were forgot in this
# release.
post-configure:
	@${CP} ${FILESDIR}/lib__otp__version-script.map \
		${WRKSRC}/lib/otp/version-script.map
	@${CP} ${FILESDIR}/lib__hcrypto__libtommath__tommath.h \
		${WRKSRC}/lib/hcrypto/libtommath/tommath.h
	@${CP} ${FILESDIR}/lib__hcrypto__libtommath__tommath_class.h \
		${WRKSRC}/lib/hcrypto/libtommath/tommath_class.h
	@${CP} ${FILESDIR}/lib__hcrypto__libtommath__tommath_superclass.h \
		${WRKSRC}/lib/hcrypto/libtommath/tommath_superclass.h
	@${CP} ${FILESDIR}/lib__gssapi__mech__gss_pname_to_uid.c \
		${WRKSRC}/lib/gssapi/mech/gss_pname_to_uid.c

post-build:
.if defined(WITH_CRACKLIB)
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
.if defined(WITH_X11)
	@${CAT} ${PKGDIR}/pkg-plist.x11 >> ${PLIST}
.endif
.if !exists(/usr/include/ifaddrs.h)
	@${ECHO_CMD} include/ifaddrs.h >> ${PLIST}
.endif
.if defined(WITH_CRACKLIB)
	${INSTALL_PROGRAM} ${WRKSRC}/kpasswdd-cracklib.so ${PREFIX}/lib/
	@${ECHO_CMD} lib/kpasswdd-cracklib.so >> ${PLIST}
.endif

.include "Makefile.man"

post-install:
	${SED} 's;%%PREFIX%%;${PREFIX};g' ${FILESDIR}/kdc.sh > \
		${PREFIX}/etc/rc.d/kdc.sh.sample

.include <bsd.port.post.mk>
