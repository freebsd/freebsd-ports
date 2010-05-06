# ex:ts=8
# Ports collection makefile for:    dhcp
# Date created:         7 Mar 1996
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	dhcp
PORTVERSION=	3.0.7
PORTREVISION=	${DHCP_PORTREVISION}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_ISC}
MASTER_SITE_SUBDIR=	dhcp dhcp/dhcp-3.0-history
PKGNAMEPREFIX=	isc-
PKGNAMESUFFIX=	30-${SUBSYS}
DISTNAME=	${PORTNAME}-${RELEASE}${VERSION}${PATCHLEVEL}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT?=	The ISC Dynamic Host Configuration Protocol server

DEPRECATED=	End-of-life by authors. Please use one of the other DHCP ports
EXPIRATION_DATE=	2010-06-03

PORTREVISION_SERVER=	6
PORTREVISION_CLIENT=	2
PORTREVISION_RELAY=	1
PORTREVISION_DEVEL=	1

SUBSYS?=	server

UNIQUENAME=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
.if ${SUBSYS} == client
OPTIONS=	INTERFACE_POLLING "interface polling support" on
.endif
.if ${SUBSYS} == server
OPTIONS=	DHCP_PARANOIA "add -user, -group and -chroot options" on \
		DHCP_JAIL "add -chroot and -jail options" on \
		DHCP_SOCKETS "use sockets instead of /dev/bpf (jail-only)" off \
		DHCP_LDAP "add experimental LDAP backend support" off \
		DHCP_LDAP_SSL "support LDAP connection over SSL/TLS" on \
		OPENSSL_BASE "use the base system OpenSSL (required by TLS)" on \
		OPENSSL_PORT "use OpenSSL from ports (required by TLS)" off \
		DHCP_LQ "DHCPLEASEQUERY support used by Cisco uBR's" off
.endif

# PORTREVISION handling
.if ${SUBSYS} == client
CONFLICTS=	isc-dhcp31-client* isc-dhcp41-client*
DHCP_PORTREVISION=	${PORTREVISION_CLIENT}
.elif ${SUBSYS} == relay
CONFLICTS=	isc-dhcp31-relay* isc-dhcp41-relay*
DHCP_PORTREVISION=	${PORTREVISION_RELAY}
.elif ${SUBSYS} == devel
DHCP_PORTREVISION=	${PORTREVISION_DEVEL}
.else
CONFLICTS=	isc-dhcp31-server* isc-dhcp41-server*
DHCP_PORTREVISION=	${PORTREVISION_SERVER}
.endif

.include <bsd.port.pre.mk>

.if ${SUBSYS} == server && defined(WITH_DHCP_LDAP)
# Based on patch from Brian Masney :
PATCH_SITES=	http://www.newwave.net/~masneyb/:ldap \
		ftp://ftp.frm2.tum.de/pub/jpulz/FreeBSD/:ldap
PATCHFILES=	${PORTNAME}-${RELEASE}${VERSION}${PATCHLEVEL}-ldap-patch:ldap
PATCH_DIST_STRIP=	-p1

USE_PERL5_RUN=	yes
USE_OPENLDAP=	yes

.if !defined(WITHOUT_DHCP_LDAP_SSL)
. if !defined(WITHOUT_OPENSSL_BASE)
.  if defined(WITH_OPENSSL_PORT)
BROKEN=		Multiple OpenSSL versions selected. Run 'make config' again!
.  endif
. else
.  if !defined(WITH_OPENSSL_PORT)
BROKEN=		No OpenSSL versions selected. Run 'make config' again!
.  endif
. endif
USE_OPENSSL=	yes
# hack to get bsd.openssl.mk included at this late state
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.endif
.endif

.if ${SUBSYS} == server && defined(WITH_DHCP_LQ)
# Based on patch from Dmitry Sukhodoev :
PATCH_SITES+=	http://bingo.ru/~raven/FreeBSD/patches/:dlq \
		ftp://ftp.frm2.tum.de/pub/jpulz/FreeBSD/:dlq
PATCHFILES+=	${PORTNAME}-${RELEASE}${VERSION}${PATCHLEVEL}-dlq-patch:dlq
.endif

# Global variables
#

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--subsys ${SUBSYS}
ALL_TARGET=	all.${SUBSYS}
INSTALL_TARGET=	install.${SUBSYS}
SCRIPTS_ENV+=	PKG_PREFIX=${PREFIX}

.if ${SUBSYS} == client
MAN5=		dhclient.conf.5 dhclient.leases.5
MAN8=		dhclient.8 dhclient-script.8
.elif ${SUBSYS} == server
MAN1=		omshell.1
MAN5=		dhcpd.conf.5 dhcpd.leases.5
MAN8=		dhcpd.8
.elif ${SUBSYS} == relay
MAN8=		dhcrelay.8
.else
MAN3=		dhcpctl.3 omapi.3
.endif
.if ${SUBSYS} != relay
MAN5+=		dhcp-eval.5 dhcp-options.5
.endif

MSG_FILE=	${.CURDIR}/pkg-message
DESCR=		${.CURDIR}/pkg-descr
PKGINSTALL=	${.CURDIR}/pkg-install
PKGDEINSTALL=	${PKGINSTALL}
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST=		${.CURDIR}/pkg-plist

# Local variables
#

# for instance, possible versions are:
#	1.2.r3.4 (or 1.2.b3.4), 1.2.r3 (or 1.2.b3), 1.2.3, 1.2
# which have to become:
#	1.2rc3pl4 (or 1.2beta3pl4), 1.2rc3 (or 1.2beta3), 1.2.3, 1.2
# so, the magic things are:
VERSION=
PATCHLEVEL=
.if ${PORTVERSION:R:E:M[br]*} != ""
RELEASE=	${PORTVERSION:R:R}
VERSION=	${PORTVERSION:R:E:S/b/beta/:S/r/rc/}
PATCHLEVEL=	pl${PORTVERSION:E}
.elif ${PORTVERSION:E:M[br]*} != ""
RELEASE=	${PORTVERSION:R}
VERSION=	${PORTVERSION:E:S/b/beta/:S/r/rc/}
#.elif ${PORTVERSION:R:E} != ""
#RELEASE=	${PORTVERSION:R}
#PATCHLEVEL=	pl${PORTVERSION:E}
.else
RELEASE=	${PORTVERSION}
.endif

PATCH_SUBDIRS=	common minires dst omapip
.if ${SUBSYS} == server || ${SUBSYS} == devel
PATCH_SUBDIRS+=	dhcpctl
.endif
.if ${SUBSYS} != devel
PATCH_SUBDIRS+=	${SUBSYS}
.endif
.if ${SUBSYS} == server
PATCH_SUBDIRS+=	omshell
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	LICENSE README RELNOTES
.endif
.if ${SUBSYS} == client
BIN_FILES=	dhclient
LOCAL_CONF_FILES=	dhclient.conf
SAMP_FILES=	client/dhclient.conf
DATA_FILES=	dhclient.leases
.elif ${SUBSYS} == server
BIN_FILES=	dhcpd omshell
USE_RC_SUBR=	isc-dhcpd
SAMP_FILES=	server/dhcpd.conf
DATA_FILES=	dhcpd.leases
.if defined(WITH_DHCP_LDAP)
PORTDOCS+=	README.ldap
LDAP_SCRIPT=	contrib/dhcpd-conf-to-ldap.pl
LDAP_SCHEMA=	contrib/dhcp.schema
.endif
.elif ${SUBSYS} == relay
BIN_FILES=	dhcrelay
USE_RC_SUBR=	isc-dhcrelay
.endif

SAMP_SUFX=	.sample

CONF_DIR=	${PREFIX}/etc
SCHEMA_DIR=	${PREFIX}/share/${PKGBASE}
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
DATADIR=	/var/db

PLIST_SUB+=	SCHEMA_DIR="${SCHEMA_DIR:S,^${PREFIX}/,,}"
.if defined(WITH_DHCP_LDAP)
PLIST_SUB+=	LDAP=""
.else
PLIST_SUB+=	LDAP="@comment "
.endif
REINPLACE_SUB=	PREFIX=${PREFIX}
.if !defined(WITHOUT_DHCP_PARANOIA)
SUB_LIST+=	PARANOIA=YES
.else
SUB_LIST+=	PARANOIA=NO
.endif
.if !defined(WITHOUT_DHCP_JAIL)
SUB_LIST+=	JAIL=YES
.else
SUB_LIST+=	JAIL=NO
.endif
PKGMESSAGE_SUB=	PREFIX="${PREFIX}" MAN1PREFIX="${MAN1PREFIX}" \
		DOCSDIR="${DOCSDIR}" SCHEMA_DIR="${SCHEMA_DIR}"

# Post-extract
#

post-extract: extract-omshell extract-script

extract-omshell:
	@${MKDIR} ${WRKSRC}/omshell
	@${MV} ${WRKSRC}/dhcpctl/omshell.? ${WRKSRC}/omshell
	@${CP} ${FILESDIR}/omshell::Makefile.dist \
		${WRKSRC}/omshell/Makefile.dist

extract-script:
	@${CP} ${FILESDIR}/client::scripts::freebsd ${WRKSRC}/client/scripts/freebsd

# Post-patch
#

post-patch: patch-scripts patch-makefile-conf \
	    patch-makefiles-dist patch-man-pages \
	    patch-pkgmessage patch-site-conf \
	    patch-dlq

patch-scripts:
	@${REINPLACE_CMD} ${REINPLACE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/client/dhclient.conf \
		${WRKSRC}/client/scripts/freebsd

patch-site-conf:
.if ${SUBSYS} == client && !defined(WITHOUT_INTERFACE_POLLING)
	@${ECHO_CMD} CFLAGS += -DENABLE_POLLING_MODE >> ${WRKSRC}/site.conf
.endif
.if ${SUBSYS} == server
.if !defined(WITHOUT_DHCP_PARANOIA)
	@${ECHO_CMD} CFLAGS += -DPARANOIA >> ${WRKSRC}/site.conf
.endif
.if !defined(WITHOUT_DHCP_JAIL)
	@${ECHO_CMD} CFLAGS += -DJAIL >> ${WRKSRC}/site.conf
.if defined(WITH_DHCP_SOCKETS)
	@${ECHO_CMD} CFLAGS += -DUSE_SOCKETS >> ${WRKSRC}/site.conf
.endif
.endif
.if defined(WITH_DHCP_LDAP)
	@${ECHO_CMD} CFLAGS += -I${LOCALBASE}/include >> ${WRKSRC}/site.conf
	@${ECHO_CMD} LIBS += -L${LOCALBASE}/lib >> ${WRKSRC}/site.conf
.if !defined(WITHOUT_DHCP_LDAP_SSL)
	@${ECHO_CMD} CFLAGS += -DUSE_SSL -I${OPENSSLINC} >> ${WRKSRC}/site.conf
	@${ECHO_CMD} LIBS += -L${OPENSSLLIB} >> ${WRKSRC}/site.conf
	@${ECHO_CMD} LIBS += -lcrypto -lssl >> ${WRKSRC}/site.conf
.endif
.endif
.endif

patch-makefile-conf:
	@${REINPLACE_CMD} -e 's|^DEBUG[ 	]*=|# DEBUG ?=|g' \
		${WRKSRC}/Makefile.conf

patch-makefiles-dist:
.for subdir in ${PATCH_SUBDIRS}
	@${REINPLACE_CMD} -e 's|^CFLAGS[ 	]*=|CFLAGS +=|g' \
		${WRKSRC}/${subdir}/Makefile.dist
.endfor

# temporary hack - no patch file needed for this typo.
patch-man-pages:
	@${REINPLACE_CMD} -e '/^\.Fd$$/d' ${WRKSRC}/dhcpctl/dhcpctl.3

patch-pkgmessage:
.if ${SUBSYS} != devel
	@${SED} ${PKGMESSAGE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${MSG_FILE} > ${PKGMESSAGE}
.if defined(WITH_DHCP_LDAP)
	@${REINPLACE_CMD} -e 's|^%%LDAP%%||g' ${PKGMESSAGE}
.else
	@${REINPLACE_CMD} -e '/^%%LDAP%%/d' ${PKGMESSAGE}
.endif
.endif

patch-dlq:
.if ${SUBSYS} == server && defined(WITH_DHCP_LQ)
.if defined(WITH_DHCP_LDAP)
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-dlq-ldap
.else
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-dlq
.endif
.endif

# Post-install
#

POST-INSTALL=	parallel-post-install install-rc-script configure-package \
		display-message
.ORDER: ${POST-INSTALL}
post-install: ${POST-INSTALL}

parallel-post-install: \
	strip-binary-files \
	install-doc-files install-ldap-files install-sample-files \
	create-conf-files create-data-files

strip-binary-files:
.for f in ${BIN_FILES}
.if exists(${PREFIX}/bin/${f})
	@${STRIP_CMD} ${PREFIX}/bin/${f}
.endif
.if exists(${PREFIX}/sbin/${f})
	@${STRIP_CMD} ${PREFIX}/sbin/${f}
.endif
.endfor

install-doc-files:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

install-ldap-files:
.if ${SUBSYS} == server && defined(WITH_DHCP_LDAP)
	@${INSTALL_SCRIPT} ${WRKSRC}/${LDAP_SCRIPT} ${PREFIX}/bin
	@${MKDIR} ${SCHEMA_DIR}
	@${INSTALL_DATA} ${WRKSRC}/${LDAP_SCHEMA} ${SCHEMA_DIR}
.endif

install-sample-files:
.for f in ${SAMP_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${CONF_DIR}/${f:T}${SAMP_SUFX}
.endfor

create-conf-files:
.for f in ${LOCAL_CONF_FILES}
.if !exists(${CONF_DIR}/${f})
	@${TOUCH} ${CONF_DIR}/${f}
.endif
.endfor

create-data-files:
.for f in ${DATA_FILES}
.if !exists(${DATADIR}/${f})
	@${TOUCH} ${DATADIR}/${f}
.endif
.endfor

configure-package:
.if ${SUBSYS} == server
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

display-message:
.if ${SUBSYS} != devel
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
