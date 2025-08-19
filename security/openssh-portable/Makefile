PORTNAME=	openssh
DISTVERSION=	10.0p1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	OPENBSD/OpenSSH/portable
PKGNAMESUFFIX?=	-portable

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	The portable version of OpenBSD's OpenSSH
WWW=		https://www.openssh.com/portable.html

LICENSE=	OPENSSH
LICENSE_NAME=	OpenSSH Licenses
LICENSE_FILE=	${WRKSRC}/LICENCE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CONFLICTS?=		openssh-3.* ssh-1.* ssh2-3.* openssh-portable-devel

USES=			alias autoreconf compiler:c11 cpe localbase ncurses \
			pkgconfig ssl
GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=		--prefix=${PREFIX} \
			--without-zlib-version-check \
			--with-ssl-engine \
			--with-mantype=man

ETCOLD=			${PREFIX}/etc

CPE_VENDOR=		openbsd

FLAVORS=			default hpn gssapi
default_CONFLICTS_INSTALL=	openssh-portable-hpn openssh-portable-gssapi \
				openssh-portable-x509
hpn_CONFLICTS_INSTALL=		openssh-portable openssh-portable-gssapi \
				openssh-portable-x509
hpn_PKGNAMESUFFIX=		-portable-hpn
gssapi_CONFLICTS_INSTALL=	openssh-portable openssh-portable-hpn \
				openssh-portable-x509
gssapi_PKGNAMESUFFIX=		-portable-gssapi

OPTIONS_DEFINE=		DOCS PAM TCP_WRAPPERS LIBEDIT BSM \
			HPN KERB_GSSAPI \
			LDNS NONECIPHER XMSS FIDO_U2F BLACKLISTD
OPTIONS_DEFAULT=	LIBEDIT PAM TCP_WRAPPERS LDNS FIDO_U2F
.if ${FLAVOR:U} == hpn
OPTIONS_DEFAULT+=	HPN NONECIPHER
.endif
.if ${FLAVOR:U} == gssapi
OPTIONS_DEFAULT+=	KERB_GSSAPI MIT
.endif
OPTIONS_RADIO=		KERBEROS
OPTIONS_RADIO_KERBEROS=	MIT HEIMDAL HEIMDAL_BASE
TCP_WRAPPERS_DESC=	tcp_wrappers support
BSM_DESC=		OpenBSM Auditing
KERB_GSSAPI_DESC=	Kerberos/GSSAPI patch (req: GSSAPI)
HPN_DESC=		HPN-SSH patch
LDNS_DESC=		SSHFP/LDNS support
HEIMDAL_DESC=		Heimdal Kerberos (security/heimdal)
HEIMDAL_BASE_DESC=	Heimdal Kerberos (base)
MIT_DESC=		MIT Kerberos (security/krb5)
NONECIPHER_DESC=	NONE Cipher support
XMSS_DESC=		XMSS key support (experimental)
FIDO_U2F_DESC=		FIDO/U2F support (security/libfido2)
BLACKLISTD_DESC=	FreeBSD blacklistd(8) support

OPTIONS_SUB=		yes

PAM_EXTRA_PATCHES=	${FILESDIR}/extra-patch-pam-sshd_config

TCP_WRAPPERS_EXTRA_PATCHES=${FILESDIR}/extra-patch-tcpwrappers

LDNS_CONFIGURE_WITH=	ldns=${LOCALBASE}
LDNS_LIB_DEPENDS=	libldns.so:dns/ldns

HPN_CONFIGURE_WITH=		hpn
NONECIPHER_CONFIGURE_WITH=	nonecipher

MIT_LIB_DEPENDS=		libkrb5.so.3:security/krb5
HEIMDAL_LIB_DEPENDS=		libkrb5.so.26:security/heimdal

PAM_CONFIGURE_WITH=	pam
TCP_WRAPPERS_CONFIGURE_WITH=	tcp-wrappers

LIBEDIT_CONFIGURE_WITH=	libedit
LIBEDIT_USES=		libedit
BSM_CONFIGURE_ON=	--with-audit=bsm

FIDO_U2F_LIB_DEPENDS=	libfido2.so:security/libfido2
FIDO_U2F_CONFIGURE_ON=	--with-security-key-builtin
FIDO_U2F_CONFIGURE_OFF=	--disable-security-key

BLACKLISTD_EXTRA_PATCHES=	${FILESDIR}/extra-patch-blacklistd

ETCDIR?=		${PREFIX}/etc/ssh

.include <bsd.port.pre.mk>

PATCH_SITES+=	http://mirror.shatow.net/freebsd/${PORTNAME}/:DEFAULT,hpn,gsskex

# Must add this patch before HPN due to conflicts
.if ${PORT_OPTIONS:MKERB_GSSAPI} || ${FLAVOR:U} == gssapi
.  if ${PORT_OPTIONS:MHPN} || ${PORT_OPTIONS:MNONECIPHER}
# Needed glue for applying HPN patch without conflict
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-hpn-gss-glue
.  endif
# - See https://sources.debian.org/data/main/o/openssh/ for which subdir to
# pull from.
GSSAPI_DEBIAN_VERSION=	10.0p1
GSSAPI_DEBIAN_SUBDIR=	${GSSAPI_DEBIAN_VERSION:U${DISTVERSION}}-5
# - Debian does not use a versioned filename so we trick fetch to make one for
# us with the ?<anything>=/ trick.
PATCH_SITES+=	https://sources.debian.org/data/main/o/openssh/1:${GSSAPI_DEBIAN_SUBDIR}/debian/patches/gssapi.patch?dummy=/:gsskex
# Bump this when updating the patch location
GSSAPI_DISTVERSION=	10.0p1
PATCHFILES+=	openssh-${GSSAPI_DISTVERSION:U${DISTVERSION}}-gsskex-all-debian-rh-${GSSAPI_DISTVERSION}.patch:-p1:gsskex
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-gssapi-kexgssc.c
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-gssapi-kexgsss.c
.endif

.if ${PORT_OPTIONS:MBLACKLISTD}
CONFIGURE_LIBS+=	-lblacklist
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

CONFIGURE_ARGS+=	--disable-utmp --disable-wtmp --disable-wtmpx --without-lastlog

# Keep this last
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-version-addendum

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
CONFIGURE_LIBS+=	-lgssapi_krb5
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

CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_gcc=	-Wno-stringop-truncation -Wno-stringop-overflow

SSH_ASKPASS_PATH?=	${LOCALBASE}/bin/ssh-askpass

post-patch:
	@${REINPLACE_CMD} \
	    -e 's|install: \(.*\) host-key check-config|install: \1|g' \
	    ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} \
	    -e 's|$$[{(]libexecdir[})]/ssh-askpass|${SSH_ASKPASS_PATH}|' \
	    ${WRKSRC}/Makefile.in ${WRKSRC}/configure.ac
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

post-configure-BLACKLISTD-on:
	@${ECHO_CMD} "#define USE_BLACKLIST 1" >> ${WRKSRC}/config.h

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/moduli \
	    ${STAGEDIR}${ETCDIR}/moduli.sample
	${MV} ${STAGEDIR}${ETCDIR}/ssh_config \
	    ${STAGEDIR}${ETCDIR}/ssh_config.sample
	${MV} ${STAGEDIR}${ETCDIR}/sshd_config \
	    ${STAGEDIR}${ETCDIR}/sshd_config.sample
	${MKDIR} ${STAGEDIR}${ETCDIR}/ssh_config.d \
		 ${STAGEDIR}${ETCDIR}/sshd_config.d
.if ${PORT_OPTIONS:MHPN} || ${PORT_OPTIONS:MNONECIPHER}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/HPN-README ${STAGEDIR}${DOCSDIR}
.endif

test: build
	cd ${WRKSRC} && ${SETENV} -i \
		OBJ=${WRKDIR} ${MAKE_ENV:NHOME=*} \
		TEST_SHELL=${SH} \
		SUDO="${SUDO}" \
		LOGNAME="${LOGNAME}" \
		HOME="${HOME}" \
		TEST_SSH_TRACE=yes \
		PATH=${WRKSRC}:${PREFIX}/bin:${PREFIX}/sbin:${PATH} \
		${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} tests

.include <bsd.port.post.mk>
