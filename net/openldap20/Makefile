# New ports collection makefile for:    OpenLDAP 2.x
# Date created:		20 Sep 1998
# Whom:			Lachlan O'Dea
#
# $FreeBSD$
#

PORTNAME=	openldap20
PORTVERSION=	2.0.27
CATEGORIES=	net databases
MASTER_SITES=	ftp://ftp.OpenLDAP.org/pub/OpenLDAP/%SUBDIR%/ \
		http://www.PlanetMirror.com/pub/openldap/%SUBDIR%/ \
		ftp://gd.tuwien.ac.at/infosys/network/OpenLDAP/%SUBDIR%/ \
		ftp://ftp.matrix.com.br/pub/openldap/%SUBDIR%/ \
		ftp://ftp.ucr.ac.cr/pub/Unix/openldap/%SUBDIR%/ \
		ftp://ftp.ntua.gr/mirror/OpenLDAP/%SUBDIR%/ \
		ftp://ftp.dti.ad.jp/pub/net/OpenLDAP/%SUBDIR%/ \
		ftp://ftp.u-aizu.ac.jp/pub/net/openldap/%SUBDIR%/ \
		ftp://ftp.holywar.net/pub/OpenLDAP/%SUBDIR%/ \
		ftp://ftp.nl.uu.net/pub/unix/db/openldap/%SUBDIR%/ \
		ftp://ftp.linux.pt/pub/mirrors/OpenLDAP/%SUBDIR%/ \
		ftp://ftp.si.uniovi.es/mirror/OpenLDAP/%SUBDIR%/ \
		ftp://sunsite.cnlab-switch.ch/mirror/OpenLDAP/%SUBDIR%/ \
		ftp://ftp.plig.org/pub/OpenLDAP/%SUBDIR%/
MASTER_SITE_SUBDIR=	openldap-release
DISTNAME=	openldap-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	eikemeier@fillmore-labs.com
COMMENT=	Open source LDAP client and server software

.if !defined(WITH_BDB_VER) || ${WITH_BDB_VER} == 3
LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3
.elif defined(WITH_BDB_VER) && ${WITH_BDB_VER} == 4
LIB_DEPENDS=	db4.0:${PORTSDIR}/databases/db4
.else
.error WITH_BDB_VER must be 3 or 4
.endif
.if defined(WITH_SASL)
LIB_DEPENDS+=	sasl.8:${PORTSDIR}/security/cyrus-sasl
.endif
.if defined(WITH_ODBC)
LIB_DEPENDS+=	iodbc.3:${PORTSDIR}/databases/libiodbc
.endif

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_REINPLACE=	yes
CONFIGURE_TARGET=

LATEST_LINK=	openldap2

WITH_BDB_VER?=	3

LOCALSTATEDIR?=	/var/db
LDAP_RUN_DIR?=	/var/run

PLIST_SUB+=	LOCALSTATEDIR=${LOCALSTATEDIR}

CONFIGURE_ARGS=	--localstatedir=${LOCALSTATEDIR} \
		--with-threads \
		--enable-shared \
		--enable-dnssrv \
		--enable-ldap \
		--enable-shell \
		--with-tls=openssl

# Include tcp-wrapper support
.if !defined(WITHOUT_TCP_WRAPPERS) && exists(/usr/include/tcpd.h)
CONFIGURE_ARGS+=	--enable-wrappers
.endif

# math.h uses _REENTRANT and stdio.h uses _THREAD_SAFE, so define both.
CPPFLAGS+=	-D_REENTRANT ${PTHREAD_CFLAGS} \
		-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/db${WITH_BDB_VER}
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-ldb${WITH_BDB_VER}

.if defined(WITH_SASL)
CPPFLAGS+=	-I${LOCALBASE}/include/sasl1
.else
CONFIGURE_ARGS+=	--without-cyrus-sasl
.endif

.if defined(WITH_ODBC)
CONFIGURE_ARGS+=--enable-sql
.endif

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		LIBS="${LIBS}"

INSTALLS_SHLIB=	yes

BINS=		bin/ldapadd \
		bin/ldapdelete \
		bin/ldapmodify \
		bin/ldapmodrdn \
		bin/ldappasswd \
		bin/ldapsearch \
		bin/ud \
		libexec/fax500 \
		libexec/go500 \
		libexec/go500gw \
		libexec/in.xfingerd \
		libexec/mail500 \
		libexec/maildap \
		libexec/rcpt500 \
		libexec/rp500 \
		libexec/slapd \
		libexec/slurpd

.include <bsd.port.pre.mk>
.include "${FILESDIR}/manpages"

.if exists(${LOCALBASE}/lib/libdb4.so) && ${WITH_BDB_VER} != 4
pre-everything::
	@${ECHO_CMD} "=================================================="
	@${ECHO_CMD}
	@${ECHO_CMD} "If you want to build OpenLDAP with Berkeley DB 4.0"
	@${ECHO_CMD} "hit Ctrl-C right now and type \"make WITH_BDB_VER=4\""
	@${ECHO_CMD}
	@${ECHO_CMD} "=================================================="
	@${ECHO_CMD}
.endif

pre-build:
	@cd ${WRKSRC} ; ${MAKE} depend

post-build:
	@${REINPLACE_CMD} -e 's,${LOCALSTATEDIR}/slapd\.,${LDAP_RUN_DIR}/slapd.,g' \
		${WRKSRC}/servers/slapd/slapd.conf.tmp
	@${SED} -e 's,@@PREFIX@@,${PREFIX},g' -e 's,@@LDAP_RUN_DIR@@,${LDAP_RUN_DIR},g' \
		${FILESDIR}/slapd.sh >${WRKDIR}/slapd.sh.sample
	@${SED} -e 's,@@PREFIX@@,${PREFIX},g' -e 's,@@LDAP_RUN_DIR@@,${LDAP_RUN_DIR},g' \
		${FILESDIR}/slurpd.sh >${WRKDIR}/slurpd.sh.sample

post-install:
.for f in ${BINS}
	@strip ${PREFIX}/${f}
.endfor
	@${INSTALL_SCRIPT} ${WRKDIR}/slapd.sh.sample ${WRKDIR}/slurpd.sh.sample ${PREFIX}/etc/rc.d
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
