PORTNAME=			samba422
DISTVERSION=			4.22.6
PORTREVISION=			6
CATEGORIES?=			net
MASTER_SITES=			SAMBA/samba/stable SAMBA/samba/rc
DISTNAME=			samba-${DISTVERSION:S|.p|pre|:S|.r|rc|:S|.t|tp|:S|.a|alpha|}

MAINTAINER=			samba@FreeBSD.org
COMMENT=			Free SMB/CIFS and AD/DC server and client for Unix
WWW=				https://gitlab.com/samba-freebsd/

LICENSE=			GPLv3+
LICENSE_FILE=			${WRKSRC}/COPYING

# The SAMBA4_BUNDLED_* variables are deprecated.
.for bvar in SAMBA4_BUNDLED_CMOCKA SAMBA4_BUNDLED_TALLOC SAMBA4_BUNDLED_TDB SAMBA4_BUNDLED_TEVENT
.  if defined(${bvar}) && ${${bvar}} == yes
IGNORE=				does not support bundling dependencies via ${bvar}; use option ${bvar:S/^SAMBA4_//} instead
.  endif
.endfor

BUILD_DEPENDS=			${_JANSSON_DEPENDS} \
				${_LIBARCHIVE_DEPENDS} \
				${_TASN1_DEPENDS} \
				p5-Parse-Yapp>=0:devel/p5-Parse-Yapp
# Unconditional dependencies which can't be switched off if present:
# - GnuTLS: libgnutls.so and libgcrypt.so
# - Iconv
# - inotify
# - libsunacl: provides NFSv4 ACL glue.
# - libicu
# - unwind
# - p5-Parse-Yapp: needed for the IDL compiler.
# - popt
# - Readline: required by Python; USES=readline pollutes CPPFLAGS, so we add
#   devel/readline to LIB_DEPENDS explicitly instead.
LIB_DEPENDS=			libgnutls.so:security/gnutls \
				libgcrypt.so:security/libgcrypt \
				libiconv.so:converters/libiconv \
				libinotify.so:devel/libinotify \
				libsunacl.so:sysutils/libsunacl \
				libreadline.so:devel/readline \
				libpopt.so:devel/popt \
				libunwind.so:devel/libunwind \
				libicui18n.so:devel/icu \
				libicuuc.so:devel/icu \
				${_VFS_SNAPPER_LIB_DEPENDS}
RUN_DEPENDS=			${_JANSSON_DEPENDS} \
				${_LIBARCHIVE_DEPENDS} \
				${_TASN1_DEPENDS}
TEST_DEPENDS=			bash:shells/bash \
				tshark:net/wireshark@nox11

USES=				cpe compiler:c++11-lang iconv \
				localbase:ldflags ncurses perl5 pkgconfig \
				shebangfix waf gettext-runtime samba:self
CPE_VENDOR=			samba
CPE_PRODUCT=			samba
USE_LDCONFIG=			${SAMBA_LIBDIR}
USE_PERL5=			build
USE_RC_SUBR=			samba_server
WAF_CMD=			buildtools/bin/waf
# Make sure that the right version of Python is used by the tools
# https://bugzilla.samba.org/show_bug.cgi?id=7305
SHEBANG_FILES=			source3/script* source4/scripting/bin/* selftest/*

CONFIGURE_LOG=			bin/config.log
CONFIGURE_ARGS=			--mandir="${PREFIX}/share/man" \
				--sysconfdir="${_CONFDIR}" \
				--includedir="${SAMBA_INCLUDEDIR}" \
				--datadir="${DATADIR}" \
				--libdir="${SAMBA_LIBDIR}" \
				--with-privatelibdir="${SAMBA_LIBDIR}/private" \
				--with-pammodulesdir="${_PAMDIR}" \
				--with-modulesdir="${SAMBA_MODULESDIR}" \
				--with-ldbmodulesdir="${SAMBA_LDB_MODULESDIR}" \
				--with-pkgconfigdir="${_PKGCONFIGDIR}" \
				--localstatedir="${VARDIR}" \
				--with-piddir="${_RUNDIR}" \
				--with-sockets-dir="${_RUNDIR}" \
				--with-privileged-socket-dir="${_RUNDIR}" \
				--with-lockdir="${_LOCKDIR}" \
				--with-statedir="${_LOCKDIR}" \
				--with-cachedir="${_LOCKDIR}" \
				--with-bind-dns-dir=${_BINDDNSDIR} \
				--with-privatedir="${_PRIVATEDIR}" \
				--with-logfilebase="${_LOGDIR}"
CONFIGURE_ARGS+=		\
				--with-pam \
				--with-iconv \
				--with-libiconv="${ICONV_PREFIX}" \
				--with-winbind \
				--with-regedit \
				--disable-rpath \
				--without-lttng \
				--without-gettext \
				--enable-pthreadpool \
				--without-fake-kaserver \
				--without-systemd \
				--with-libarchive \
				--with-acl-support \
				--with-sendfile-support \
				--disable-ctdb-tests \
				--disable-spotlight
CONFIGURE_ARGS+=		${_PRIVATE_LIBS:D--private-libraries="${_PRIVATE_LIBS:Q:C|(\\\\ )+|,|g:S|\\||g}"}
CONFIGURE_ARGS+=		${_BUNDLED_LIBS:D--bundled-libraries="${_BUNDLED_LIBS:Q:C|(\\\\ )+|,|g:S|\\||g}"}
CONFIGURE_ARGS+=		${_SHARED_MODULES:D--with-shared-modules="${_SHARED_MODULES:C|-|_|:Q:C|(\\\\ )+|,|g:S|\\||g}"}
CONFIGURE_ARGS+=		${WITH_DEBUG:D --verbose --enable-debug}
CONFIGURE_ENV=			PTHREAD_LDFLAGS="-lpthread" \
				PYTHONHASHSEED=1

MAKE_ARGS=			${WITH_DEBUG:D --verbose}
MAKE_ENV=			PYTHONHASHSEED=1 \
				RPCGEN_CPP="${CPP}"
TEST_ENV=			PYTHON="${PYTHON_CMD}" \
				SHA1SUM=/sbin/sha1 \
				SHA256SUM=${SHA256} \
				MD5SUM=${MD5} \
				PYTHONDONTWRITEBYTECODE=1

# No fancy color error messages
CFLAGS+=			${_CFLAGS_${CHOSEN_COMPILER_TYPE}}
.ifnmake portclippy
_CFLAGS_clang=			-fno-color-diagnostics
.endif
CONFIGURE_ENV+=			NOCOLOR=yes WAF_LOG_FORMAT='%(c1)s%(zone)s%(c2)s %(message)s'
MAKE_ENV+=			NOCOLOR=yes WAF_LOG_FORMAT='%(c1)s%(zone)s%(c2)s %(message)s'
# for libexecinfo: (so that __builtin_frame_address() finds the top of the stack)
CFLAGS_amd64+=			-fno-omit-frame-pointer
DEBUG_FLAGS?=			-g -ggdb3 -O0
# Some symbols in samba's linker version scripts are not defined, but since the
# scripts are generated dynamically, suppress errors with lld >= 17 due to these
# undefined symbols.
LDFLAGS+=			-Wl,--undefined-version

CONFLICTS_INSTALL=		ldb2[0-9]-* samba4*

EXTRA_PATCHES=			\
				${PATCHDIR}/0001-Compact-and-simplify-modules-build-and-config-genera.patch:-p1 \
				${PATCHDIR}/0002-Adjust-abi_gen.sh-script-to-run-under-FreeBSD-with-i.patch:-p1 \
				${PATCHDIR}/0003-Mask-CLang-prototype-warnings-in-kadm5-admin.h.patch:-p1 \
				${PATCHDIR}/0004-On-FreeBSD-date-1-has-different-semantics-than-on-Li.patch:-p1 \
				${PATCHDIR}/0005-Include-jemalloc-jemalloc.h-if-ENABLE_JEMALLOC-is-se.patch:-p1 \
				${PATCHDIR}/0006-Install-nss_-modules-into-PAMMODULESDIR-path.patch:-p1 \
				${PATCHDIR}/0007-Use-macro-value-as-a-default-backlog-size-for-the-li.patch:-p1 \
				${PATCHDIR}/0008-Brute-force-work-around-usage-of-Linux-specific-m-fl.patch:-p1 \
				${PATCHDIR}/0009-Make-sure-that-config-checks-fail-if-the-warning-is-.patch:-p1 \
				${PATCHDIR}/0010-Add-option-with-pkgconfigdir-to-specify-alternative-.patch:-p1 \
				${PATCHDIR}/0011-Use-provided-by-port-location-of-the-XML-catalog.patch:-p1 \
				${PATCHDIR}/0012-Create-shared-libraries-according-to-the-FreeBSD-spe.patch:-p1 \
				${PATCHDIR}/0014-Add-option-to-disable-CTDB-tests-failing-on-FreeBSD-.patch:-p1 \
				${PATCHDIR}/0015-Add-extra-debug-class-to-trck-down-DB-locking-code.patch:-p1 \
				${PATCHDIR}/0016-Make-ldb_schema_attribute_compare-a-stable-comparisi.patch:-p1 \
				${PATCHDIR}/0017-Use-arc4random-when-available-to-generate-random-tal.patch:-p1 \
				${PATCHDIR}/0018-Add-configuration-option-that-allows-to-choose-alter.patch:-p1 \
				${PATCHDIR}/0019-From-923bc7a1afeb0b920e60e14846987ae1d2d7dca4-Mon-Se.patch:-p1 \
				${PATCHDIR}/0020-FreeBSD-12-between-r336017-and-r342928-wrongfuly-ret.patch:-p1 \
				${PATCHDIR}/0021-Fix-casting-warnings-in-the-nfs_quota-debug-message.patch:-p1 \
				${PATCHDIR}/0022-Clean-up-UTMP-handling-code-and-add-FreeBSD-support..patch:-p1 \
				${PATCHDIR}/0023-Add-cmd_get_quota-test-function-into-vfstest-to-test.patch:-p1 \
				${PATCHDIR}/0025-From-d9b748869a8f4018ebee302aae8246bf29f60309-Mon-Se.patch:-p1 \
				${PATCHDIR}/0028-s3-lib-system-add-FreeBSD-proc_fd_pattern.patch \

SUB_FILES=			pkg-message README.FreeBSD
SUB_LIST=			PKGCONFIGDIR=${_PKGCONFIGDIR_REL} \
				${_SAMBA_SUB}

# PLIST must be defined here explicitly as we append to PLIST later on to
# handle extra pkg-plist files like pkg-plist.python.
PLIST?=				${PKGDIR}/pkg-plist
PLIST_DIRS=			${SAMBA_MODULESDIR} \
				${_MODULE_CLASSES:S|^|${SAMBA_MODULESDIR}/|}
# ":C|_|/|:C|-|_|" is a workaround for turning "nss-info_*" modules into "nss_info/*".
PLIST_FILES+=			${_SHARED_MODULES:C|_|/|:C|-|_|:S|^|${SAMBA_MODULESDIR}/|:S|$|.so|}
PLIST_SUB=			PKGCONFIGDIR=${_PKGCONFIGDIR_REL} \
				${_SAMBA_SUB}
PORTDOCS=			README.FreeBSD

OPTIONS_DEFINE=			AD_DC ADS CLUSTER CUPS DOCS FAM LDAP GPGME \
				MANPAGES PROFILE PYTHON3 QUOTAS \
				SYSLOG UTMP
OPTIONS_DEFAULT=		AD_DC ADS DOCS FAM LDAP MANPAGES \
				PROFILE PYTHON3 QUOTAS SYSLOG UTMP \
				FRUIT GSSAPI_BUILTIN AVAHI
OPTIONS_GROUP=			BUNDLED_DEPS DEVELOPMENT VFS
OPTIONS_GROUP_BUNDLED_DEPS=	BUNDLED_CMOCKA BUNDLED_TALLOC BUNDLED_TDB BUNDLED_TEVENT
OPTIONS_GROUP_DEVELOPMENT=	DEVELOPER MEMORY_DEBUG PICKY_DEVELOPER TEST
OPTIONS_GROUP_VFS=		FRUIT GLUSTERFS
OPTIONS_SINGLE=			GSSAPI ZEROCONF
OPTIONS_SINGLE_GSSAPI=		GSSAPI_BUILTIN GSSAPI_MIT
OPTIONS_SINGLE_ZEROCONF=	ZEROCONF_NONE AVAHI MDNSRESPONDER
OPTIONS_SUB=			yes

ADS_DESC=			Active Directory client
AD_DC_DESC=			Active Directory Domain Controller(implies PYTHON3)
BUNDLED_CMOCKA_DESC=		Bundle cmocka instead of depending on a standalone port
BUNDLED_DEPS_DESC=		Bundled dependencies
BUNDLED_TALLOC_DESC=		Bundle talloc instead of depending on a standalone port
BUNDLED_TDB_DESC=		Bundle TDB instead of depending on a standalone port
BUNDLED_TEVENT_DESC=		Bundle Tevent instead of depending on a standalone port
CLUSTER_DESC=			Clustering support
DEVELOPER_DESC=			With developer framework
DEVELOPMENT_DESC=		Testing, debugging, and development
FAM_DESC=			File Alteration Monitor
FRUIT_DESC=			MacOSX and TimeMachine support
GLUSTERFS_DESC=			GlusterFS support
GPGME_DESC=			GpgME support
GSSAPI_BUILTIN_DESC=		GSSAPI support via bundled Heimdal
LDAP_DESC=			LDAP client
MEMORY_DEBUG_DESC=		Debug memory allocator
PICKY_DEVELOPER_DESC=		Treat compiler warnings as errors(implies DEVELOPER)
PROFILE_DESC=			Profiling data
QUOTAS_DESC=			Disk quota support
UTMP_DESC=			UTMP accounting
VFS_DESC=			VFS modules
ZEROCONF_DESC=			Zero configuration networking
ZEROCONF_NONE_DESC=		Zeroconf support is absent

ADS_IMPLIES=			LDAP
ADS_CONFIGURE_WITH=		ads
# List of extra modules taken from RHEL build
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=197320
ADS_VARS=			_SHARED_MODULES+="idmap_ad idmap_rfc2307 nss-info_template nss-info_rfc2307 nss-info_sfu nss-info_sfu20"

AD_DC_IMPLIES=			ADS PYTHON3
AD_DC_BUILD_DEPENDS=		${_LMDB_DEPDENDS}
AD_DC_RUN_DEPENDS=		${_LMDB_DEPDENDS}
AD_DC_CONFIGURE_OFF=		--without-ad-dc --without-ldb-lmdb
AD_DC_VARS=			PLIST+=${PKGDIR}/pkg-plist.ad_dc
# samba-tool requires those for *upgrade
AD_DC_BUILD_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}markdown>=3.3.7:textproc/py-markdown@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}dnspython>=2.2.1:dns/py-dnspython@${PY_FLAVOR}
AD_DC_RUN_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}markdown>=3.3.7:textproc/py-markdown@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}dnspython>=2.2.1:dns/py-dnspython@${PY_FLAVOR}

AVAHI_LIB_DEPENDS=		libavahi-client.so:net/avahi-app
AVAHI_CONFIGURE_ENABLE=		avahi
AVAHI_VARS=			_SAMBA_SERVICES+=avahi_daemon

BUNDLED_CMOCKA_BUILD_DEPENDS_OFF=	cmocka>=1.1.3:sysutils/cmocka
BUNDLED_CMOCKA_TEST_DEPENDS_OFF=	cmocka>=1.1.3:sysutils/cmocka
BUNDLED_CMOCKA_CONFLICTS_INSTALL=	cmocka-1.*
BUNDLED_CMOCKA_VARS=			_BUNDLED_LIBS+=cmocka \
					_BUNDLED_LIB_replace=replace
BUNDLED_CMOCKA_VARS_OFF=		_BUNDLED_LIBS+=!cmocka

BUNDLED_TALLOC_BUILD_DEPENDS_OFF=	talloc243>=2.4.3:devel/talloc243
BUNDLED_TALLOC_RUN_DEPENDS_OFF=		talloc243>=2.4.3:devel/talloc243
BUNDLED_TALLOC_CONFLICTS_INSTALL=	talloc-* talloc2*
BUNDLED_TALLOC_VARS=			_BUNDLED_LIBS+=talloc \
					_BUNDLED_LIB_replace=replace
BUNDLED_TALLOC_VARS_OFF=		_BUNDLED_LIBS+=!talloc

BUNDLED_TDB_BUILD_DEPENDS_OFF=		tdb1413>=1.4.13:databases/tdb1413
BUNDLED_TDB_RUN_DEPENDS_OFF=		tdb1413>=1.4.13:databases/tdb1413
BUNDLED_TDB_CONFLICTS_INSTALL=		tdb-* tdb1*
BUNDLED_TDB_VARS=			_BUNDLED_LIBS+=tdb \
					_BUNDLED_LIB_replace=replace
BUNDLED_TDB_VARS_OFF=			_BUNDLED_LIBS+=!tdb

BUNDLED_TEVENT_BUILD_DEPENDS_OFF=	tevent017>=0.17:devel/tevent017
BUNDLED_TEVENT_RUN_DEPENDS_OFF=		tevent017>=0.17:devel/tevent017
BUNDLED_TEVENT_CONFLICTS_INSTALL=	tevent-* tevent0*
BUNDLED_TEVENT_VARS=			_BUNDLED_LIBS+=tevent \
					_BUNDLED_LIB_replace=replace
BUNDLED_TEVENT_VARS_OFF=		_BUNDLED_LIBS+=!tevent

CLUSTER_LIB_DEPENDS=		libpcap.so:net/libpcap
CLUSTER_CONFIGURE_WITH=		cluster-support
CLUSTER_VARS=			PLIST+=${PKGDIR}/pkg-plist.cluster

CUPS_LIB_DEPENDS=		libcups.so:print/cups
CUPS_CONFIGURE_ENABLE=		cups iprint

DEVELOPER_BUILD_DEPENDS=	${_LMDB_DEPDENDS} \
				${_GDB_CMD}:devel/gdb
DEVELOPER_RUN_DEPENDS=		${_LMDB_DEPDENDS}
DEVELOPER_TEST_DEPENDS=		${_GDB_CMD}:devel/gdb
DEVELOPER_CONFIGURE_ON=		--enable-developer --enable-selftest --abi-check-disable
DEVELOPER_CONFIGURE_ENV=	WAF_CMD_FORMAT=string
DEVELOPER_VARS=			_SHARED_MODULES+="auth_skel pdb_test gpext_security gpext_registry \
				gpext_scripts perfcount_test vfs_fake_dfq \
				vfs_skel_opaque vfs_skel_transparent \
				vfs_shadow_copy_test vfs_fake_acls \
				vfs_nfs4acl_xattr vfs_error_inject vfs_delay_inject"
DEVELOPER_VARS_OFF=		_GDB_CMD=true

# https://bugzilla.samba.org/show_bug.cgi?id=9545
FAM_USES=			fam
FAM_CONFIGURE_WITH=		fam

FRUIT_PREVENTS=			ZEROCONF_NONE
FRUIT_PREVENTS_MSG=		MacOSX support requires Zeroconf(AVAHI or MDNSRESPONDER)
FRUIT_PLIST_FILES=		%%MANPAGES%%share/man/man8/vfs_fruit.8.gz
FRUIT_VARS=			_SHARED_MODULES+=vfs_fruit

GLUSTERFS_LIB_DEPENDS=		libglusterfs.so:net/glusterfs
GLUSTERFS_CONFIGURE_ENABLE=	glusterfs
GLUSTERFS_PLIST_FILES=		%%MANPAGES%%share/man/man8/vfs_glusterfs.8.gz
GLUSTERFS_VARS=			_SHARED_MODULES+=vfs_glusterfs

GPGME_LIB_DEPENDS=		libgpgme.so:security/gpgme
GPGME_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}gpg>=2.0.0:security/py-gpg@${PY_FLAVOR}
GPGME_CONFIGURE_WITH=		gpgme

GSSAPI_BUILTIN_USES=		bison

GSSAPI_MIT_USES=		bison gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	--with-system-mitkrb5 ${GSSAPIBASEDIR} \
				--with-system-mitkdc=${GSSAPIBASEDIR}/sbin/krb5kdc \
				--with-experimental-mit-ad-dc
GSSAPI_MIT_PLIST_FILES=		${SAMBA_MODULESDIR}/krb5/winbind_krb5_localauth.so \
				%%MANPAGES%%share/man/man8/winbind_krb5_localauth.8.gz \
				%%AD_DC%%${SAMBA_LIBDIR}/krb5/plugins/kdb/samba.so

LDAP_USES=			ldap
LDAP_CONFIGURE_WITH=		ldap
LDAP_VARS=			_SHARED_MODULES+=idmap_ldap

MANPAGES_BUILD_DEPENDS=		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
				xsltproc:textproc/libxslt
MANPAGES_CONFIGURE_ENV_OFF=	XSLTPROC="false"

MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder
MDNSRESPONDER_CONFIGURE_ENABLE=	dnssd
MDNSRESPONDER_VARS=		_SAMBA_SERVICES+=mdnsd

MEMORY_DEBUG_IMPLIES=		DEBUG
MEMORY_DEBUG_LIB_DEPENDS=	libjemalloc.so.2:devel/jemalloc
MEMORY_DEBUG_CONFIGURE_ENV=	ADDITIONAL_CFLAGS="-DENABLE_JEMALLOC `pkg-config --cflags jemalloc`" ADDITIONAL_LDFLAGS="`pkg-config --libs jemalloc`"

# https://bugzilla.samba.org/show_bug.cgi?id=8969
PICKY_DEVELOPER_IMPLIES=	DEVELOPER
PICKY_DEVELOPER_CONFIGURE_ON=	--picky-developer

PROFILE_CONFIGURE_WITH=		profiling-data

PYTHON3_USES=			python
PYTHON3_USES_OFF=		python:build,test
# Don't cache Python modules
PYTHON3_CONFIGURE_ON=		--nopycache
# Use PYTHON3_CONFIGURE_OFF instead of PYTHON3_CONFIGURE_ENABLE=python because
# Samba's configure script does not recognize --enable-python.
PYTHON3_CONFIGURE_OFF=		--disable-python
PYTHON3_MAKE_ENV=		PYTHONDONTWRITEBYTECODE=1
PYTHON3_VARS=			PLIST+=${PKGDIR}/pkg-plist.python \
				_BUNDLED_LIBS+="pyldb pyldb-util"

QUOTAS_CONFIGURE_WITH=		quotas

SYSLOG_CONFIGURE_WITH=		syslog

TEST_BUILD_DEPENDS=		${_ISO8601_DEPENDS}
TEST_RUN_DEPENDS=		${_ISO8601_DEPENDS}

UTMP_CONFIGURE_WITH=		utmp

ZEROCONF_NONE_MAKE_ENV=		ZEROCONF=none

.ifnmake portclippy
.  if !defined(WANT_EXP_MODULES) || empty(WANT_EXP_MODULES)
WANT_EXP_MODULES=		vfs_cacheprime
.  endif
.endif

# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=194046
_GDB_CMD=			${LOCALBASE}/bin/gdb

_ISO8601_DEPENDS=		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${PY_FLAVOR}
_JANSSON_DEPENDS=		jansson>=2.10:devel/jansson
_LIBARCHIVE_DEPENDS=		libarchive>=3.1.2:archivers/libarchive
_TASN1_DEPENDS=			libtasn1>=3.8:security/libtasn1
.if ${WANT_EXP_MODULES:Mvfs_snapper}
_VFS_SNAPPER_LIB_DEPENDS=	libdbus-1.so:devel/dbus \
				libdbus-glib-1.so:devel/dbus-glib
.endif

_BUNDLED_LIBS=			!libarchive \
				com_err \
				${_BUNDLED_LIB_replace}

_MODULE_CLASSES=		auth bind9 gensec gpext idmap ldb nss_info \
				pdb perfcount process_model service vfs
_PRIVATE_LIBS=			!ldb
_SHARED_MODULES+=		${WANT_EXP_MODULES}
_SHARED_MODULES+=		krb5_async_dns_krb5_locator krb5_winbind_krb5_locator idmap_nss idmap_autorid \
				idmap_rid idmap_hash idmap_tdb idmap_tdb2 idmap_script \
				nss-info_hash
_SHARED_MODULES+=		vfs_freebsd
_SHARED_MODULES+=		vfs_acl_tdb vfs_acl_xattr vfs_aio_fork vfs_aio_pthread \
				vfs_audit vfs_cap vfs_catia vfs_commit vfs_crossrename \
				vfs_default_quota vfs_dirsort vfs_expand_msdfs \
				vfs_extd_audit vfs_fake_perms vfs_full_audit \
				vfs_linux_xfs_sgid vfs_media_harmony vfs_offline \
				vfs_preopen vfs_readahead vfs_readonly vfs_recycle \
				vfs_shadow_copy vfs_shadow_copy2 vfs_shell_snap \
				vfs_streams_depot vfs_streams_xattr vfs_syncops \
				vfs_time_audit vfs_unityed_media vfs_virusfilter \
				vfs_widelinks vfs_worm vfs_xattr_tdb vfs_zfsacl

_SAMBA_MAJVERNAME=		samba4
_SAMBA_SUB=			SAMBA4_LOGDIR="${_LOGDIR}" \
				SAMBA4_RUNDIR="${_RUNDIR}" \
				SAMBA4_LOCKDIR="${_LOCKDIR}" \
				SAMBA4_LIBDIR="${SAMBA_LIBDIR}" \
				SAMBA4_MODULEDIR="${SAMBA_MODULESDIR}" \
				SAMBA_LDB_MODULESDIR="${SAMBA_LDB_MODULESDIR}" \
				SAMBA4_BINDDNSDIR="${_BINDDNSDIR}" \
				SAMBA4_PRIVATEDIR="${_PRIVATEDIR}" \
				SAMBA4_CONFDIR="${_CONFDIR}" \
				SAMBA4_CONFIG="${_SAMBA_CONFIG}" \
				SAMBA4_SERVICES="${_SAMBA_SERVICES}"

_SAMBA_CONFIG=			smb4.conf

# XXX: Instead of defining _CONFDIR we could probably just set ETCDIR.
_CONFDIR=			${PREFIX}/etc
_BINDDNSDIR=			${_LOCKDIR}/bind-dns
_LOCKDIR=			${_VARDIR}/db/${_SAMBA_MAJVERNAME}
_LOGDIR=			${_VARDIR}/log/${_SAMBA_MAJVERNAME}
_PAMDIR=			${PREFIX}/lib
_PKGCONFIGDIR=			${PREFIX}/${_PKGCONFIGDIR_REL}
_PKGCONFIGDIR_REL=		libdata/pkgconfig
_PRIVATEDIR=			${_LOCKDIR}/private
_RUNDIR=			${_VARDIR}/run/${_SAMBA_MAJVERNAME}
_VARDIR=			${DESTDIR}/var

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON3}
_BUNDLED_LIBS+=			${"${PORT_OPTIONS:MBUNDLED_TALLOC}" == "BUNDLED_TALLOC":?:!}pytalloc-util
_BUNDLED_LIBS+=			${"${PORT_OPTIONS:MBUNDLED_TEVENT}" == "BUNDLED_TEVENT":?:!}pytevent
_BUNDLED_LIBS+=			${"${PORT_OPTIONS:MBUNDLED_TDB}" == "BUNDLED_TDB":?:!}pytdb
.endif

# Only for 64-bit architectures
.if ${ARCH} != armv6 && ${ARCH} != armv7 && ${ARCH} != i386 && ${ARCH} != mips && ${ARCH} != powerpc && ${ARCH} != powerpcspe
.	if (${PORT_OPTIONS:MAD_DC} || ${PORT_OPTIONS:MDEVELOPER})
# LMDB
_LMDB_DEPDENDS=			lmdb>=0.9.16:databases/lmdb
PLIST_FILES+=			${SAMBA_LIBDIR}/private/libldb-mdb-int-private-samba.so \
				${SAMBA_LDB_MODULESDIR}/mdb.so
.	endif
.endif

post-extract:
	@${RM} -r ${WRKSRC}/pidl/lib/Parse/Yapp

post-patch:
	@${REINPLACE_CMD} -e 's|$${PKGCONFIGDIR}|${_PKGCONFIGDIR}|g' \
		${PATCH_WRKSRC}/buildtools/wafsamba/pkgconfig.py
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/buildtools/wafsamba/wafsamba.py
	@${REINPLACE_CMD} -e 's|%%GDB_CMD%%|${_GDB_CMD}|g' \
		${PATCH_WRKSRC}/buildtools/scripts/abi_gen.sh
	@${REINPLACE_CMD} -e 's|%%SAMBA4_CONFIG%%|${_SAMBA_CONFIG}|g' \
		${PATCH_WRKSRC}/dynconfig/wscript

post-install:
	${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/samba/third_party
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name __pycache__ \
		-type d -print0 | ${XARGS} -0 -n 1 -t ${RM} -r
	${FIND} ${STAGEDIR} -type f -empty -delete

.for dir in ${_LOGDIR} ${_RUNDIR} ${_LOCKDIR} ${SAMBA_MODULESDIR}
	${INSTALL} -d -m 0755 "${STAGEDIR}${dir}"
.endfor
	${INSTALL} -d -m 0750 "${STAGEDIR}${_BINDDNSDIR}"
	${INSTALL} -d -m 0750 "${STAGEDIR}${_PRIVATEDIR}"
.for module_class in ${_MODULE_CLASSES}
	${INSTALL} -d -m 0755 "${STAGEDIR}${SAMBA_MODULESDIR}/${module_class}"
.endfor
.if !defined(WITH_DEBUG)
	-${FIND} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/sbin ${STAGEDIR}${PREFIX}/libexec \
		-type f -print0 | ${XARGS} -0 -n 1 -t ${STRIP_CMD}
	-${FIND} ${STAGEDIR}${PREFIX}/lib -name '*.so*' \
		-type f -print0 | ${XARGS} -0 -n 1 -t ${STRIP_CMD}
.endif

post-install-BUNDLED_TALLOC-on:
.if ${PORT_OPTIONS:MMANPAGES}
.  for f in talloc.3
	${MV} ${STAGEDIR}${PREFIX}/share/man/man3/${f} ${STAGEDIR}${PREFIX}/share/man/man3/samba-${f}
.  endfor
.endif

post-install-BUNDLED_TDB-on:
.if ${PORT_OPTIONS:MMANPAGES}
.  for f in tdbbackup.8 tdbdump.8 tdbrestore.8 tdbtool.8
	${MV} ${STAGEDIR}${PREFIX}/share/man/man8/${f} ${STAGEDIR}${PREFIX}/share/man/man8/samba-${f}
.  endfor
.endif

post-install-CLUSTER-on:
	${RLN} ${STAGEDIR}${PREFIX}/share/ctdb/events/legacy/00.ctdb.script ${STAGEDIR}${PREFIX}/etc/ctdb/events/legacy/00.ctdb.script
	${RLN} ${STAGEDIR}${PREFIX}/share/ctdb/events/legacy/01.reclock.script ${STAGEDIR}${PREFIX}/etc/ctdb/events/legacy/01.reclock.script
	${RLN} ${STAGEDIR}${PREFIX}/share/ctdb/events/legacy/05.system.script ${STAGEDIR}${PREFIX}/etc/ctdb/events/legacy/05.system.script
	${RLN} ${STAGEDIR}${PREFIX}/share/ctdb/events/legacy/10.interface.script ${STAGEDIR}${PREFIX}/etc/ctdb/events/legacy/10.interface.script
	${RLN} ${STAGEDIR}${PREFIX}/share/ctdb/events/legacy/95.database.script ${STAGEDIR}${PREFIX}/etc/ctdb/events/legacy/95.database.script

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-FRUIT-off:
	${RM} ${STAGEDIR}${SAMBA_MODULESDIR}/vfs/fruit.so
	${RM} ${STAGEDIR}${PREFIX}/share/man/man8/vfs_fruit.8

post-install-MANPAGES-on:
	${RLN} ${STAGEDIR}${PREFIX}/share/man/man5/smb.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5/smb4.conf.5

.for f in vfs_aio_linux.8 vfs_btrfs.8 vfs_ceph.8 vfs_gpfs.8
	${RM} ${STAGEDIR}${PREFIX}/share/man/man8/${f}
.endfor

.include <bsd.port.mk>
