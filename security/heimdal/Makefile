# Ports collection Makefile for:	heimdal
# Date created:						10/23/1999
# Whom:								nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	heimdal
PORTVERSION=	1.0.1
CATEGORIES=	security ipv6
MASTER_SITES=	http://ftp.pdc.kth.se/pub/heimdal/src/ \
		ftp://ftp.pdc.kth.se/pub/heimdal/src/ \
		ftp://ftp.sunet.se/pub/unix/admin/mirror-pdc/pub/heimdal/src/ \
		ftp://ftp.ayamura.org/pub/heimdal/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A popular BSD-licensed implementation of Kerberos 5

CONFLICTS=	krb4-[0-9]* krb5-[0-9]* srp-[0-9]*

OPTIONS+=	LDAP	 "Use OpenLDAP as the KDC backend"		off
OPTIONS+=	CRACKLIB "Use CrackLib for password quality checking"	off
OPTIONS+=	X11	 "Build X11 utilies"				off

USE_AUTOTOOLS=	libtool:22
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}"
CONFIGURE_ARGS+=	--enable-shared --without-krb4

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

.if defined(WITH_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-openldap=${LOCALBASE}
#EXTRA_PATCHES+=		${FILESDIR}/extrapatch-lib_hdb_hdb-ldap.c
.  if defined(LDAP_SOCKET_PATH)
_SOCK=		${LDAP_SOCKET_PATH:C|/|%2f|g}
.  else
LDAP_RUN_DIR?=	/var/run/openldap
_SOCK=		${LDAP_RUN_DIR:C|/|%2f|g}%2fldapi
.  endif
.endif

.if defined(WITH_CRACKLIB)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libcrack.a:${PORTSDIR}/security/cracklib
.endif

.if defined(WITH_X11)
USE_XORG=		x11
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
