# Created by: dwcjr@inethouston.net
# $FreeBSD$

PORTNAME=	openssh
DISTVERSION=	8.0p1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	OPENBSD/OpenSSH/portable
PKGNAMESUFFIX?=	-portable

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	The portable version of OpenBSD's OpenSSH

#LICENSE=      BSD2,BSD3,MIT,public domain,BSD-Style,BEER-WARE,"any purpose with notice intact",ISC-Style
#LICENSE_FILE= ${WRKSRC}/LICENCE

CONFLICTS?=		openssh-3.* ssh-1.* ssh2-3.* openssh-portable-devel-*

USES=			alias autoreconf ncurses ssl
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		ac_cv_func_strnvis=no
CONFIGURE_ARGS=		--prefix=${PREFIX} --with-md5-passwords \
			--without-zlib-version-check --with-ssl-engine \
			--with-mantype=man

ETCOLD=			${PREFIX}/etc

FLAVORS=			default hpn gssapi x509
default_CONFLICTS_INSTALL=	openssh-portable-hpn openssh-portable-gssapi \
				openssh-portable-x509
hpn_CONFLICTS_INSTALL=		openssh-portable openssh-portable-gssapi \
				openssh-portable-x509
hpn_PKGNAMESUFFIX=		-portable-hpn
gssapi_CONFLICTS_INSTALL=	openssh-portable openssh-portable-hpn \
				openssh-portable-x509
gssapi_PKGNAMESUFFIX=		-portable-gssapi
x509_CONFLICTS_INSTALL=		openssh-portable openssh-portable-hpn \
				openssh-portable-gssapi
x509_PKGNAMESUFFIX=		-portable-x509

x509_BROKEN=		X509 not yet updated for ${DISTVERSION} - Does anyone use this? Contact maintainer bdrewery@FreeBSD.org
OPTIONS_DEFINE=		DOCS PAM TCP_WRAPPERS LIBEDIT BSM \
			HPN X509 KERB_GSSAPI \
			LDNS NONECIPHER XMSS
OPTIONS_DEFAULT=	LIBEDIT PAM TCP_WRAPPERS LDNS
.if ${FLAVOR:U} == hpn
OPTIONS_DEFAULT+=	HPN NONECIPHER
.endif
.if ${FLAVOR:U} == gssapi
OPTIONS_DEFAULT+=	KERB_GSSAPI MIT
.endif
.if ${FLAVOR:U} == x509
OPTIONS_DEFAULT+=	X509
.endif
OPTIONS_RADIO=		KERBEROS
OPTIONS_RADIO_KERBEROS=	MIT HEIMDAL HEIMDAL_BASE
TCP_WRAPPERS_DESC=	tcp_wrappers support
BSM_DESC=		OpenBSM Auditing
KERB_GSSAPI_DESC=	Kerberos/GSSAPI patch (req: GSSAPI)
HPN_DESC=		HPN-SSH patch
LDNS_DESC=		SSHFP/LDNS support
X509_DESC=		x509 certificate patch
HEIMDAL_DESC=		Heimdal Kerberos (security/heimdal)
HEIMDAL_BASE_DESC=	Heimdal Kerberos (base)
MIT_DESC=		MIT Kerberos (security/krb5)
NONECIPHER_DESC=	NONE Cipher support
XMSS_DESC=		XMSS key support (experimental)

OPTIONS_SUB=		yes

TCP_WRAPPERS_EXTRA_PATCHES=${FILESDIR}/extra-patch-tcpwrappers

LDNS_CONFIGURE_WITH=	ldns=${LOCALBASE}
LDNS_LIB_DEPENDS=	libldns.so:dns/ldns
LDNS_EXTRA_PATCHES=	${FILESDIR}/extra-patch-ldns
LDNS_CFLAGS=		-I${LOCALBASE}/include
LDNS_CONFIGURE_ON=	--with-ldflags='-L${LOCALBASE}/lib'

HPN_CONFIGURE_WITH=		hpn
NONECIPHER_CONFIGURE_WITH=	nonecipher

# See http://www.roumenpetrov.info/openssh/
X509_VERSION=		11.5
X509_PATCH_SITES=	http://www.roumenpetrov.info/openssh/x509-${X509_VERSION}/:x509
X509_EXTRA_PATCHES+=	${FILESDIR}/extra-patch-x509-glue
X509_PATCHFILES=	${PORTNAME}-7.9p1+x509-${X509_VERSION}.diff.gz:-p1:x509

MIT_LIB_DEPENDS=		libkrb5.so.3:security/krb5
HEIMDAL_LIB_DEPENDS=		libkrb5.so.26:security/heimdal

PAM_CONFIGURE_WITH=	pam
TCP_WRAPPERS_CONFIGURE_WITH=	tcp-wrappers

LIBEDIT_CONFIGURE_WITH=	libedit
LIBEDIT_USES=		libedit
BSM_CONFIGURE_ON=	--with-audit=bsm

ETCDIR?=		${PREFIX}/etc/ssh

.include <bsd.port.pre.mk>

PATCH_SITES+=	http://mirror.shatow.net/freebsd/${PORTNAME}/:DEFAULT,x509,hpn,gsskex

# X509 patch includes TCP Wrapper support already
.if ${PORT_OPTIONS:MX509}
EXTRA_PATCHES:=		${EXTRA_PATCHES:N${TCP_WRAPPERS_EXTRA_PATCHES}}
.endif

# Must add this patch before HPN due to conflicts
.if ${PORT_OPTIONS:MKERB_GSSAPI}
#BROKEN=	KERB_GSSAPI No patch for ${DISTVERSION} yet.
.  if ${PORT_OPTIONS:MHPN} || ${PORT_OPTIONS:MNONECIPHER}
# Needed glue for applying HPN patch without conflict
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-hpn-gss-glue
.  endif
# - See https://sources.debian.org/data/main/o/openssh/ for which subdir to
# pull from.
GSSAPI_DEBIAN_SUBDIR=	${DISTVERSION}-3
# - Debian does not use a versioned filename so we trick fetch to make one for
# us with the ?<anything>=/ trick.
PATCH_SITES+=	https://sources.debian.org/data/main/o/openssh/1:${GSSAPI_DEBIAN_SUBDIR}/debian/patches/gssapi.patch?dummy=/:gsskex
# Bump this when updating the patch location
GSSAPI_UPDATE_DATE=	20190719
PATCHFILES+=	openssh-${DISTVERSION}-gsskex-all-20141021-debian-rh-${GSSAPI_UPDATE_DATE}.patch:-p1:gsskex
.endif

# https://www.psc.edu/hpn-ssh https://github.com/rapier1/openssh-portable/tree/hpn-openssl1.1-7_7_P1
.if ${PORT_OPTIONS:MHPN} || ${PORT_OPTIONS:MNONECIPHER}
#BROKEN=			HPN: Not yet updated for ${DISTVERSION} yet.
PORTDOCS+=		HPN-README
HPN_VERSION=		14v15
HPN_DISTVERSION=	7.7p1
#PATCH_SITES+=		SOURCEFORGE/hpnssh/HPN-SSH%20${HPN_VERSION}%20${HPN_DISTVERSION}/:hpn
#PATCHFILES+=		${PORTNAME}-${HPN_DISTVERSION}-hpnssh${HPN_VERSION}.diff.gz:-p1:hpn
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-hpn:-p2
.elif !${PORT_OPTIONS:MHPN} && !${PORT_OPTIONS:MNONECIPHER}
# Apply compatibility patch
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-hpn-compat
.endif

CONFIGURE_LIBS+=	-lutil

CONFIGURE_ARGS+=	--disable-utmp --disable-wtmp --disable-wtmpx --without-lastlog

# Keep this last
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-version-addendum

.if ${PORT_OPTIONS:MX509}
.  if ${PORT_OPTIONS:MHPN} || ${PORT_OPTIONS:MNONECIPHER}
BROKEN=		X509 patch and HPN patch do not apply cleanly together
.  endif

.  if ${PORT_OPTIONS:MKERB_GSSAPI}
BROKEN=		X509 patch incompatible with KERB_GSSAPI patch
.  endif

.endif

.if ${PORT_OPTIONS:MHEIMDAL_BASE} && ${PORT_OPTIONS:MKERB_GSSAPI}
BROKEN=		KERB_GSSAPI Requires either MIT or HEMIDAL, does not build with base Heimdal currently
.endif

.if ${PORT_OPTIONS:MHEIMDAL_BASE} && !exists(/usr/lib/libkrb5.so)
IGNORE=		you have selected HEIMDAL_BASE but do not have heimdal installed in base
.endif

.if ${PORT_OPTIONS:MMIT} || ${PORT_OPTIONS:MHEIMDAL} || ${PORT_OPTIONS:MHEIMDAL_BASE}
.	if ${PORT_OPTIONS:MHEIMDAL_BASE}
CONFIGURE_LIBS+=	-lgssapi_krb5
CONFIGURE_ARGS+=	--with-kerberos5=/usr
.	else
CONFIGURE_ARGS+=	--with-kerberos5=${LOCALBASE}
.	endif
.	if ${OPENSSLBASE} == "/usr"
CONFIGURE_ARGS+=	--without-rpath
LDFLAGS=		# empty
.	endif
.else
.	if ${PORT_OPTIONS:MKERB_GSSAPI}
IGNORE=	KERB_GSSAPI requires one of MIT HEIMDAL or HEIMDAL_BASE
.	endif
.endif

.if ${OPENSSLBASE} != "/usr"
CONFIGURE_ARGS+=	--with-ssl-dir=${OPENSSLBASE}
.endif

EMPTYDIR=		/var/empty

USE_RC_SUBR=		openssh

# After all
CONFIGURE_ARGS+=	--sysconfdir=${ETCDIR} --with-privsep-path=${EMPTYDIR}
.if !empty(CONFIGURE_LIBS)
CONFIGURE_ARGS+=	--with-libs='${CONFIGURE_LIBS}'
.endif

CONFIGURE_ARGS+=	--with-xauth=${LOCALBASE}/bin/xauth

RC_SCRIPT_NAME=		openssh
VERSION_ADDENDUM_DEFAULT?=	${OPSYS}-${PKGNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|-ldes|-lcrypto|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} \
	    -e 's|install: \(.*\) host-key check-config|install: \1|g' \
	    ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${LOCALBASE}|' \
		-e 's|%%RC_SCRIPT_NAME%%|${RC_SCRIPT_NAME}|' ${WRKSRC}/sshd.8
	@${REINPLACE_CMD} \
	    -e 's|\(VersionAddendum\) none|\1 ${VERSION_ADDENDUM_DEFAULT}|' \
	    ${WRKSRC}/sshd_config
	@${REINPLACE_CMD} \
	    -e 's|%%SSH_VERSION_FREEBSD_PORT%%|${VERSION_ADDENDUM_DEFAULT}|' \
	    ${WRKSRC}/sshd_config.5
	@${ECHO_CMD} '#define SSH_VERSION_FREEBSD_PORT	"${VERSION_ADDENDUM_DEFAULT}"' >> \
		${WRKSRC}/version.h

post-configure-XMSS-on:
	@${ECHO_CMD} "#define WITH_XMSS 1" >> ${WRKSRC}/config.h

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/ssh_config \
	    ${STAGEDIR}${ETCDIR}//ssh_config.sample
	${MV} ${STAGEDIR}${ETCDIR}/sshd_config \
	    ${STAGEDIR}${ETCDIR}/sshd_config.sample
.if ${PORT_OPTIONS:MHPN} || ${PORT_OPTIONS:MNONECIPHER}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/HPN-README ${STAGEDIR}${DOCSDIR}
.endif

test: build
	cd ${WRKSRC} && ${SETENV} -i \
		OBJ=${WRKDIR} ${MAKE_ENV} \
		TEST_SHELL=${SH} \
		SUDO="${SUDO}" \
		LOGNAME="${LOGNAME}" \
		TEST_SSH_TRACE=yes \
		PATH=${WRKSRC}:${PREFIX}/bin:${PREFIX}/sbin:${PATH} \
		${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} tests

.include <bsd.port.post.mk>
