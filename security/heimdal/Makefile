# Ports collection Makefile for:	heimdal
# Date created:						10/23/1999
# Whom:								nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=		heimdal
PORTVERSION=	0.6.3
PORTREVISION=	2
CATEGORIES=		security ipv6
MASTER_SITES=	ftp://ftp.pdc.kth.se/pub/heimdal/src/ \
		ftp://ftp.sunet.se/pub/unix/admin/mirror-pdc/pub/heimdal/src/ \
		ftp://ftp.ayamura.org/pub/heimdal/
DISTNAME=		heimdal-${PORTVERSION}

MAINTAINER=		nectar@FreeBSD.ORG
COMMENT=		A re-implementation of Kerberos V

OPTIONS+=		LDAP     "Use OpenLDAP as the KDC backend" off
OPTIONS+=		CRACKLIB "Use CrackLib for password quality checking" off
OPTIONS+=		X11      "Build X11 utilies" off

USE_OPENSSL=		yes
GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes
CONFIGURE_ENV+=		CFLAGS="${CFLAGS}"
CONFIGURE_ARGS+=	--enable-shared --without-krb4

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=			"Incomplete pkg-plist on 4.x"
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-openldap=${LOCALBASE}
.endif
.if defined(WITH_CRACKLIB)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libcrack.a:${PORTSDIR}/security/cracklib
.endif
.if defined(WITH_X11)
USE_XLIB=			yes
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if defined(HEIMDAL_HOME)
PREFIX=				${HEIMDAL_HOME}
.else
CONFLICTS=			wu-ftpd-[0-9]* wu-ftpd+ipv6-[0-9]*
.endif

INFO=				heimdal
PLIST:=				${WRKDIR}/PLIST

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
.if exists(${WRKSRC}/lib/com_err/.libs/compile_et)
	@${CAT} ${PKGDIR}/pkg-plist.com_err >> ${PLIST}
.endif
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
	install-info ${PREFIX}/info/heimdal.info ${PREFIX}/info/dir
	${SED} 's;%%PREFIX%%;${PREFIX};g' ${FILESDIR}/kdc.sh > \
		${PREFIX}/etc/rc.d/kdc.sh.sample

.if ${ARCH} == "amd64"
CFLAGS+= -fPIC
.endif
.include <bsd.port.post.mk>
