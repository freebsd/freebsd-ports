# Ports collection Makefile for:	heimdal
# Date created:						10/23/1999
# Whom:								nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=		heimdal
PORTVERSION=	0.5.1
PORTREVISION=	0
CATEGORIES=		security ipv6
MASTER_SITES=	ftp://ftp.pdc.kth.se/pub/heimdal/src/ \
				ftp://ftp.replay.com/pub/replay/crypto/APPS/kerberos/heimdal/ \
				ftp://ftp.tuniv.szczecin.pl/dsk4/ftp.replay.com/pub/crypto/APPS/kerberos/heimdal/ \
				ftp://ftp.hacktic.nl/pub/replay/crypto/APPS/kerberos/heimdal/
DISTNAME=		heimdal-${PORTVERSION}

MAINTAINER=		nectar@FreeBSD.ORG

.if defined(WITH_LDAP)
LIB_DEPENDS+=	ldap.2:${PORTSDIR}/net/openldap2
.endif
.if defined(WITH_CRACKLIB)
BUILD_DEPENDS+= ${LOCALBASE}/lib/libcrack.a:${PORTSDIR}/security/cracklib
.endif

RESTRICTED=		"Crypto; export-controlled"

USE_LIBTOOL=		no	# Uses included version.
USE_OPENSSL=		yes
GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes
CONFIGURE_ARGS+=	--enable-shared
.if defined(WITH_LDAP)
CONFIGURE_ARGS+=	--with-openldap=${LOCALBASE}
.endif

.if defined(HEIMDAL_HOME)
PREFIX=				${HEIMDAL_HOME}
.endif

.if exists(${X11BASE}/lib/libX11.a) && !defined(WITHOUT_X11)
USE_XLIB=			yes
.endif

.if defined(USE_XLIB)
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if exists(/usr/lib/libkrb.a) && !defined(WITHOUT_KRB4)
CONFIGURE_ENV+=		LIBS="-lcom_err"
CONFIGURE_ARGS+=	--with-krb4-include=/usr/include --with-krb4-lib=/usr/lib
.elif !defined(KRB5_KRB4_COMPAT)
CONFIGURE_ARGS+=	--without-krb4
.endif

PLIST:=				${WRKDIR}/PLIST

pre-configure:
.if !defined(WITH_CRACKLIB)
	@${ECHO_MSG}
	@${ECHO_MSG} You can utilize CrackLib for the kpasswdd by defining
	@${ECHO_MSG} WITH_CRACKLIB and uncommenting the appropriate lines in
	@${ECHO_MSG} ${PREFIX}/etc/rc.d/kdc.sh.
	@${ECHO_MSG}
.endif

post-build:
.if defined(WITH_CRACKLIB)
	sed -e "s;%%LOCALBASE%%;${LOCALBASE};g" \
	${FILESDIR}/kpasswdd-cracklib.c.in > ${WRKSRC}/kpasswdd-cracklib.c
	(cd ${WRKSRC} && \
	${CC} ${CFLAGS} -fPIC -shared -I${LOCALBASE}/include -I./include \
	-L${LOCALBASE}/lib -o ./kpasswdd-cracklib.so ./kpasswdd-cracklib.c -lcrack)
.endif

pre-install:
	@${CP} ${PKGDIR}/pkg-plist ${PLIST}
.if exists(/usr/lib/libkrb.a) && !defined(WITHOUT_KRB4)
	@${CAT} ${PKGDIR}/pkg-plist.krb4 >> ${PLIST}
.endif
.if defined(USE_XLIB)
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
	install-info ${PREFIX}/info/heimdal.info ${PREFIX}/info/dir
	${SED} 's;%%PREFIX%%;${PREFIX};g' ${FILESDIR}/kdc.sh > \
		${PREFIX}/etc/rc.d/kdc.sh.sample

.include <bsd.port.mk>
