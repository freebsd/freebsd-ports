PORTNAME=			${SAMBA4_BASENAME}420
PORTVERSION=			${SAMBA4_VERSION}
PORTREVISION=			6
CATEGORIES?=			net
MASTER_SITES=			SAMBA/samba/stable SAMBA/samba/rc
DISTNAME=			${SAMBA4_DISTNAME}

MAINTAINER=			samba@FreeBSD.org
COMMENT=			Free SMB/CIFS and AD/DC server and client for Unix
WWW=				https://gitlab.com/samba-freebsd/

LICENSE=			GPLv3+
LICENSE_FILE=			${WRKSRC}/COPYING

USES=				cpe

CONFLICTS_INSTALL?=		samba4*

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
				${PATCHDIR}/0013-Pass-additional-msg-parameter-to-CHECK_LIB-so-it-can.patch:-p1 \
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
				${PATCHDIR}/0024-Cherry-pick-ZFS-provisioning-code-by-iXsystems-Inc.patch:-p1 \
				${PATCHDIR}/0025-From-d9b748869a8f4018ebee302aae8246bf29f60309-Mon-Se.patch:-p1 \
				${PATCHDIR}/0026-vfs-add-a-compatibility-option-to-the-vfs_streams_xa.patch:-p1 \
				${PATCHDIR}/0027-Add-VFS-module-vfs_freebsd-that-implements-FreeBSD-s.patch:-p1 \
				${PATCHDIR}/0028-Fix-rl_completion_func_t.patch:-p1 \
				${PATCHDIR}/0028-s3-lib-system-add-FreeBSD-proc_fd_pattern.patch \
				${PATCHDIR}/0100-Fix-pathref-handling-for-FreeBSD-13plus_samba42x.patch:-p1 \
				${PATCHDIR}/0101-FreeBSD-add-fdescfs-paths-workaround.patch:-p1 \
				${PATCHDIR}/0102-FreeBSD-vfs_freebsd-fix-sys_proc_fd_path-args.patch:-p1

SAMBA4_BASENAME=		samba
SAMBA4_PORTNAME=		${SAMBA4_BASENAME}4
SAMBA4_VERSION=			4.20.7
SAMBA4_DISTNAME=		${SAMBA4_BASENAME}-${SAMBA4_VERSION:S|.p|pre|:S|.r|rc|:S|.t|tp|:S|.a|alpha|}

WRKSRC?=			${WRKDIR}/${DISTNAME}
PLIST?=				${PKGDIR}/pkg-plist

CPE_VENDOR=			samba
CPE_PRODUCT=			samba
# Directories
VARDIR=				${DESTDIR}/var
SAMBA4_RUNDIR=			${VARDIR}/run/${SAMBA4_PORTNAME}
SAMBA4_LOGDIR=			${VARDIR}/log/${SAMBA4_PORTNAME}
SAMBA4_LOCKDIR=			${VARDIR}/db/${SAMBA4_PORTNAME}
SAMBA4_BINDDNSDIR=		${SAMBA4_LOCKDIR}/bind-dns
SAMBA4_PRIVATEDIR=		${SAMBA4_LOCKDIR}/private
SAMBA4_PAMDIR=			${PREFIX}/lib
SAMBA4_LIBDIR=			${PREFIX}/lib/${SAMBA4_PORTNAME}
SAMBA4_INCLUDEDIR=		${PREFIX}/include/${SAMBA4_PORTNAME}
SAMBA4_CONFDIR=			${PREFIX}/etc
SAMBA4_CONFIG=			smb4.conf
SAMBA4_MODULES_CLASS=		auth bind9 gensec gpext idmap ldb nss_info \
				pdb perfcount process_model service vfs

CONFIGURE_ARGS=			--mandir="${PREFIX}/share/man" \
				--sysconfdir="${SAMBA4_CONFDIR}" \
				--includedir="${SAMBA4_INCLUDEDIR}" \
				--datadir="${DATADIR}" \
				--libdir="${SAMBA4_LIBDIR}" \
				--with-privatelibdir="${SAMBA4_LIBDIR}/private" \
				--with-pammodulesdir="${SAMBA4_PAMDIR}" \
				--with-modulesdir="${SAMBA4_MODULEDIR}" \
				--with-pkgconfigdir="${PKGCONFIGDIR}" \
				--localstatedir="${VARDIR}" \
				--with-piddir="${SAMBA4_RUNDIR}" \
				--with-sockets-dir="${SAMBA4_RUNDIR}" \
				--with-privileged-socket-dir="${SAMBA4_RUNDIR}" \
				--with-lockdir="${SAMBA4_LOCKDIR}" \
				--with-statedir="${SAMBA4_LOCKDIR}" \
				--with-cachedir="${SAMBA4_LOCKDIR}" \
				--with-bind-dns-dir=${SAMBA4_BINDDNSDIR} \
				--with-privatedir="${SAMBA4_PRIVATEDIR}" \
				--with-logfilebase="${SAMBA4_LOGDIR}"
# XXX: Flags
CONFIGURE_ENV=			PTHREAD_LDFLAGS="-lpthread" \
				PYTHONHASHSEED=1
MAKE_ENV=			PYTHONHASHSEED=1

USES=				compiler:c++11-lang iconv localbase:ldflags \
				perl5 pkgconfig shebangfix waf gettext-runtime
USE_PERL5=			build
USE_LDCONFIG=			${SAMBA4_LIBDIR}
WAF_CMD=			buildtools/bin/waf
CONFIGURE_LOG=			bin/config.log

# Make sure that the right version of Python is used by the tools
# https://bugzilla.samba.org/show_bug.cgi?id=7305
SHEBANG_FILES=			source3/script* source4/scripting/bin/* selftest/*

PKGCONFIGDIR?=			${PREFIX}/libdata/pkgconfig
PKGCONFIGDIR_REL?=		${PKGCONFIGDIR:S,^${PREFIX}/,,}
PLIST_SUB=			PKGCONFIGDIR=${PKGCONFIGDIR_REL}
SUB_LIST=			PKGCONFIGDIR=${PKGCONFIGDIR_REL}
##############################################################################
OPTIONS_SUB=			yes

OPTIONS_DEFINE=			AD_DC ADS CLUSTER CUPS DOCS FAM GPGME \
				LDAP MANPAGES PROFILE PYTHON3 QUOTAS \
				SYSLOG UTMP
#OPTIONS_DEFINE+=		DEVELOPER MEMORY_DEBUG

OPTIONS_GROUP=			VFS
OPTIONS_GROUP_VFS=		FRUIT GLUSTERFS

OPTIONS_SINGLE=			GSSAPI ZEROCONF

OPTIONS_SINGLE_GSSAPI=		GSSAPI_BUILTIN GSSAPI_MIT
#GSSAPI_HEIMDAL
OPTIONS_SINGLE_ZEROCONF=	ZEROCONF_NONE AVAHI MDNSRESPONDER

# Make those default options
OPTIONS_DEFAULT=		AD_DC ADS DOCS FAM LDAP MANPAGES \
				PROFILE PYTHON3 QUOTAS SYSLOG UTMP \
				FRUIT GSSAPI_BUILTIN AVAHI
##############################################################################
ADS_DESC=			Active Directory client(implies LDAP)
AD_DC_DESC=			Active Directory Domain Controller(implies PYTHON3)
CLUSTER_DESC=			Clustering support
DEVELOPER_DESC=			With developer framework
FAM_DESC=			File Alteration Monitor
GPGME_DESC=			GpgME support
LDAP_DESC=			LDAP client
LIBZFS_DESC=			LibZFS
MEMORY_DEBUG_DESC=		Debug memory allocator
PICKY_DEVELOPER_DESC=		Treat compiler warnings as errors(implies DEVELOPER)
PROFILE_DESC=			Profiling data
QUOTAS_DESC=			Disk quota support
UTMP_DESC=			UTMP accounting

VFS_DESC=			VFS modules
FRUIT_DESC=			MacOSX and TimeMachine support
GLUSTERFS_DESC=			GlusterFS support

GSSAPI_BUILTIN_DESC=		GSSAPI support via bundled Heimdal

ZEROCONF_DESC=			Zero configuration networking
ZEROCONF_NONE_DESC=		Zeroconf support is absent
##############################################################################
# XXX: Unconditional dependencies which can't be switched off(if present in
# the system)

# Iconv(picked up unconditionaly)
LIB_DEPENDS=			libiconv.so:converters/libiconv
# unwind
LIB_DEPENDS+=			libunwind.so:devel/libunwind
# Readline(sponsored by Python)
# XXX: USES=readline pollutes CPPFLAGS, so we explicitly put dependency
LIB_DEPENDS+=			libreadline.so:devel/readline
# popt
LIB_DEPENDS+=			libpopt.so:devel/popt
# inotify
LIB_DEPENDS+=			libinotify.so:devel/libinotify
# GNUTLS
LIB_DEPENDS+=			libgnutls.so:security/gnutls
LIB_DEPENDS+=			libgcrypt.so:security/libgcrypt
# NFSv4 ACL glue
LIB_DEPENDS+=			libsunacl.so:sysutils/libsunacl
# Jansson
BUILD_DEPENDS+=			jansson>=2.10:devel/jansson
RUN_DEPENDS+=			jansson>=2.10:devel/jansson
# tasn1
BUILD_DEPENDS+=			libtasn1>=3.8:security/libtasn1
RUN_DEPENDS+=			libtasn1>=3.8:security/libtasn1
# External Samba dependencies
# Needed for IDL compiler
BUILD_DEPENDS+=			p5-Parse-Yapp>=0:devel/p5-Parse-Yapp

# Libarchive
SAMBA4_BUNDLED_LIBS=		!libarchive
BUILD_DEPENDS+=			libarchive>=3.1.2:archivers/libarchive
RUN_DEPENDS+=			libarchive>=3.1.2:archivers/libarchive

### Bundled libraries
SAMBA4_BUNDLED_CMOCKA?=		no
SAMBA4_BUNDLED_TALLOC?=		no
SAMBA4_BUNDLED_TEVENT?=		no
SAMBA4_BUNDLED_TDB?=		no
SAMBA4_BUNDLED_LDB?=		no
# cmocka
.if defined(SAMBA4_BUNDLED_CMOCKA) && ${SAMBA4_BUNDLED_CMOCKA} == yes
SAMBA4_BUNDLED_LIBS+=		cmocka
CONFLICTS_INSTALL+=		cmocka-1.*
PLIST_SUB+=			SAMBA4_BUNDLED_CMOCKA=""
SUB_LIST+=			SAMBA4_BUNDLED_CMOCKA=""
.else
SAMBA4_BUNDLED_LIBS+=		!cmocka
BUILD_DEPENDS+=			cmocka>=1.1.3:sysutils/cmocka
TEST_DEPENDS+=			cmocka>=1.1.3:sysutils/cmocka
PLIST_SUB+=			SAMBA4_BUNDLED_CMOCKA="@comment "
SUB_LIST+=			SAMBA4_BUNDLED_CMOCKA="@comment "
.endif
# talloc
.if defined(SAMBA4_BUNDLED_TALLOC) && ${SAMBA4_BUNDLED_TALLOC} == yes
SAMBA4_BUNDLED_LIBS+=		talloc
PLIST_SUB+=			SAMBA4_BUNDLED_TALLOC=""
SUB_LIST+=			SAMBA4_BUNDLED_TALLOC=""
.else
SAMBA4_BUNDLED_LIBS+=		!talloc
BUILD_DEPENDS+=			talloc242>=2.4.2:devel/talloc242
RUN_DEPENDS+=			talloc242>=2.4.2:devel/talloc242
PLIST_SUB+=			SAMBA4_BUNDLED_TALLOC="@comment "
SUB_LIST+=			SAMBA4_BUNDLED_TALLOC="@comment "
.endif
# tevent
.if defined(SAMBA4_BUNDLED_TEVENT) && ${SAMBA4_BUNDLED_TEVENT} == yes
SAMBA4_BUNDLED_LIBS+=		tevent
CONFLICTS_INSTALL+=		tevent-* tevent1-*
PLIST_SUB+=			SAMBA4_BUNDLED_TEVENT=""
SUB_LIST+=			SAMBA4_BUNDLED_TEVENT=""
.else
SAMBA4_BUNDLED_LIBS+=		!tevent
BUILD_DEPENDS+=			tevent016>=0.16.1:devel/tevent016
RUN_DEPENDS+=			tevent016>=0.16.1:devel/tevent016
PLIST_SUB+=			SAMBA4_BUNDLED_TEVENT="@comment "
SUB_LIST+=			SAMBA4_BUNDLED_TEVENT="@comment "
.endif
# tdb
.if defined(SAMBA4_BUNDLED_TDB) && ${SAMBA4_BUNDLED_TDB} == yes
SAMBA4_BUNDLED_LIBS+=		tdb
CONFLICTS_INSTALL+=		tdb-* tdb1-*
PLIST_SUB+=			SAMBA4_BUNDLED_TDB=""
SUB_LIST+=			SAMBA4_BUNDLED_TDB=""
.else
SAMBA4_BUNDLED_LIBS+=		!tdb
BUILD_DEPENDS+=			tdb1410>=1.4.10:databases/tdb1410
RUN_DEPENDS+=			tdb1410>=1.4.10:databases/tdb1410
PLIST_SUB+=			SAMBA4_BUNDLED_TDB="@comment "
SUB_LIST+=			SAMBA4_BUNDLED_TDB="@comment "
.endif
# ldb
.if defined(SAMBA4_BUNDLED_LDB) && ${SAMBA4_BUNDLED_LDB} == yes
SAMBA4_BUNDLED_LDB=		yes
SAMBA4_BUNDLED_LIBS+=		ldb
PLIST_SUB+=			SAMBA4_BUNDLED_LDB=""
SUB_LIST+=			SAMBA4_BUNDLED_LDB=""
SAMBA4_MODULEDIR=		${SAMBA4_LIBDIR}/modules
.else
SAMBA4_BUNDLED_LIBS+=		!ldb
BUILD_DEPENDS+=			ldb29>=2.9.1:databases/ldb29
RUN_DEPENDS+=			ldb29>=2.9.1:databases/ldb29
PLIST_SUB+=			SAMBA4_BUNDLED_LDB="@comment "
SUB_LIST+=			SAMBA4_BUNDLED_LDB="@comment "
SAMBA4_MODULEDIR=		${PREFIX}/lib/shared-modules
.endif

.if (defined(SAMBA4_BUNDLED_TALLOC) && ${SAMBA4_BUNDLED_TALLOC} == yes) \
	|| (defined(SAMBA4_BUNDLED_TDB) && ${SAMBA4_BUNDLED_TDB} == yes) \
	|| (defined(SAMBA4_BUNDLED_LDB) && ${SAMBA4_BUNDLED_LDB} == yes) \
	|| (defined(SAMBA4_BUNDLED_TEVENT) && ${SAMBA4_BUNDLED_TEVENT} == yes)
SAMBA4_BUNDLED_LIBS+=		replace
.endif
# Don't use external libcom_err
SAMBA4_BUNDLED_LIBS+=		com_err
# Set the test environment variables
TEST_USES=			python
TEST_ENV=			PYTHON="${PYTHON_CMD}" \
				SHA1SUM=/sbin/sha1 \
				SHA256SUM=/sbin/sha256 \
				MD5SUM=/sbin/md5 \
				PYTHONDONTWRITEBYTECODE=1

TEST_DEPENDS=			bash:shells/bash \
				tshark:net/wireshark@nox11
# External Python modules
TEST_BUILD_DEPENDS=		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${PY_FLAVOR}
TEST_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${PY_FLAVOR}
##############################################################################
CONFIGURE_ARGS+=		\
				--with-pam \
				--with-iconv \
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
#				${ICONV_CONFIGURE_BASE}
##############################################################################
FRUIT_PREVENTS=			ZEROCONF_NONE
FRUIT_PREVENTS_MSG=		MacOSX support requires Zeroconf(AVAHI or MDNSRESPONDER)
FRUIT_VARS=			SAMBA4_MODULES+=vfs_fruit

GLUSTERFS_CONFIGURE_ENABLE=	glusterfs
GLUSTERFS_LIB_DEPENDS=		libglusterfs.so:net/glusterfs
GLUSTERFS_VARS=			SAMBA4_MODULES+=vfs_glusterfs

ZEROCONF_NONE_MAKE_ENV=		ZEROCONF=none
##############################################################################
AVAHI_CONFIGURE_ENABLE=		avahi
AVAHI_LIB_DEPENDS=		libavahi-client.so:net/avahi-app
AVAHI_VARS=			SAMBA4_SERVICES+=avahi_daemon

MDNSRESPONDER_CONFIGURE_ENABLE=	dnssd
MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder
MDNSRESPONDER_VARS=		SAMBA4_SERVICES+=mdnsd
##############################################################################
MEMORY_DEBUG_IMPLIES=		DEBUG
MEMORY_DEBUG_CONFIGURE_ENV=	ADDITIONAL_CFLAGS="-DENABLE_JEMALLOC `pkg-config --cflags jemalloc`" ADDITIONAL_LDFLAGS="`pkg-config --libs jemalloc`"
MEMORY_DEBUG_LIB_DEPENDS=	libjemalloc.so.2:devel/jemalloc
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=194046
GDB_CMD?=			${LOCALBASE}/bin/gdb
# https://bugzilla.samba.org/show_bug.cgi?id=8969
PICKY_DEVELOPER_IMPLIES=	DEVELOPER
PICKY_DEVELOPER_CONFIGURE_ON=	--picky-developer

DEVELOPER_CONFIGURE_ON=		--enable-developer --enable-selftest --abi-check-disable
DEVELOPER_CONFIGURE_ENV=	WAF_CMD_FORMAT=string
DEVELOPER_BUILD_DEPENDS=	${SAMBA4_LMDB_DEPENDS} \
				${GDB_CMD}:devel/gdb
DEVELOPER_RUN_DEPENDS=		${SAMBA4_LMDB_DEPENDS}
DEVELOPER_TEST_DEPENDS=		${GDB_CMD}:devel/gdb
DEVELOPER_VARS_OFF=		GDB_CMD=true
##############################################################################
AD_DC_IMPLIES=			PYTHON3
AD_DC_CONFIGURE_OFF=		--without-ad-dc
AD_DC_BUILD_DEPENDS=		${SAMBA4_LMDB_DEPENDS}
AD_DC_RUN_DEPENDS=		${SAMBA4_LMDB_DEPENDS}
AD_DC_VARS=			PLIST+=${PKGDIR}/pkg-plist.ad_dc
# samba-tool requires those for *upgrade
AD_DC_BUILD_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}markdown>=3.3.7:textproc/py-markdown@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}dnspython>=2.2.1:dns/py-dnspython@${PY_FLAVOR}
AD_DC_RUN_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}markdown>=3.3.7:textproc/py-markdown@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}dnspython>=2.2.1:dns/py-dnspython@${PY_FLAVOR}

ADS_IMPLIES=			LDAP
ADS_CONFIGURE_WITH=		ads

CLUSTER_CONFIGURE_WITH=		cluster-support
CLUSTER_VARS=			PLIST+=${PKGDIR}/pkg-plist.cluster

CUPS_CONFIGURE_ENABLE=		cups iprint
CUPS_LIB_DEPENDS=		libcups.so:print/cups
# https://bugzilla.samba.org/show_bug.cgi?id=9545
FAM_USES=			fam
FAM_CONFIGURE_WITH=		fam

GPGME_CONFIGURE_WITH=		gpgme
GPGME_LIB_DEPENDS=		libgpgme.so:security/gpgme
GPGME_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}gpg>=2.0.0:security/py-gpg@${PY_FLAVOR}

GSSAPI_BUILTIN_USES=		bison
GSSAPI_BUILTIN_BUILD_DEPENDS=	p5-JSON>=4.0:converters/p5-JSON

GSSAPI_MIT_CONFIGURE_ON=	--with-system-mitkrb5 ${GSSAPIBASEDIR} \
				--with-system-mitkdc=${GSSAPIBASEDIR}/sbin/krb5kdc \
				--with-experimental-mit-ad-dc
GSSAPI_MIT_USES=		gssapi:mit

GSSAPI_HEIMDAL_CONFIGURE_ON=	--with-system-heimdalkrb5 ${GSSAPIBASEDIR}
GSSAPI_HEIMDAL_USES=		gssapi:heimdal
GSSAPI_HEIMDAL_PREVENTS=	AD_DC
GSSAPI_HEIMDAL_PREVENTS_MSG=	GSSAPI_HEIMDAL and AD_DC enable conflicting options

LDAP_CONFIGURE_WITH=		ldap
LDAP_CONFIGURE_ON=		--with-openldap=${LOCALBASE}
LDAP_USES=			ldap
LDAP_VARS=			SAMBA4_MODULES+=idmap_ldap

LIBZFS_CONFIGURE_WITH=		libzfs
LIBZFS_VARS=			SAMBA4_MODULES+=vfs_zfs_space

MANPAGES_BUILD_DEPENDS=		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
				xsltproc:textproc/libxslt
MANPAGES_CONFIGURE_ENV_OFF=	XSLTPROC="false"

PROFILE_CONFIGURE_WITH=		profiling-data

QUOTAS_CONFIGURE_WITH=		quotas

SYSLOG_CONFIGURE_WITH=		syslog

UTMP_CONFIGURE_WITH=		utmp

##############################################################################
.include <bsd.port.options.mk>
##############################################################################
.if !${PORT_OPTIONS:MADS} && ${PORT_OPTIONS:MAD_DC}
IGNORE=To disable ADS option you also need to disable AD_DC option
.endif

.if !defined(WANT_EXP_MODULES) || empty(WANT_EXP_MODULES)
WANT_EXP_MODULES=		vfs_cacheprime
.endif

.if ${WANT_EXP_MODULES:Mvfs_snapper}
# snapper needs dbus
LIB_DEPENDS+=			libdbus-1.so:devel/dbus
LIB_DEPENDS+=			libdbus-glib-1.so:devel/dbus-glib
.endif

SAMBA4_MODULES+=		krb5_async_dns_krb5_locator krb5_winbind_krb5_locator idmap_nss idmap_autorid \
				idmap_rid idmap_hash idmap_tdb idmap_tdb2 idmap_script \
				nss-info_hash
# List of extra modules taken from RHEL build
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=197320
.if ${PORT_OPTIONS:MADS}
SAMBA4_MODULES+=		idmap_ad idmap_rfc2307 nss-info_template \
				nss-info_rfc2307 nss-info_sfu nss-info_sfu20
.endif
# This kind of special for this distribution
SAMBA4_MODULES+=		vfs_freebsd

SAMBA4_MODULES+=		vfs_acl_tdb vfs_acl_xattr vfs_aio_fork vfs_aio_pthread \
				vfs_audit vfs_cap vfs_catia vfs_commit vfs_crossrename \
				vfs_default_quota vfs_dirsort vfs_expand_msdfs \
				vfs_extd_audit vfs_fake_perms vfs_full_audit \
				vfs_linux_xfs_sgid vfs_media_harmony vfs_offline \
				vfs_preopen vfs_readahead vfs_readonly vfs_recycle \
				vfs_shadow_copy vfs_shadow_copy2 vfs_shell_snap \
				vfs_streams_depot vfs_streams_xattr vfs_syncops \
				vfs_time_audit vfs_unityed_media vfs_virusfilter \
				vfs_widelinks vfs_worm vfs_xattr_tdb vfs_zfsacl

.if ${PORT_OPTIONS:MDEVELOPER}
SAMBA4_MODULES+=		auth_skel pdb_test gpext_security gpext_registry \
				gpext_scripts perfcount_test vfs_fake_dfq \
				vfs_skel_opaque vfs_skel_transparent \
				vfs_shadow_copy_test vfs_fake_acls \
				vfs_nfs4acl_xattr vfs_error_inject vfs_delay_inject
.endif
# Python bindings
.if ! ${PORT_OPTIONS:MPYTHON3} || defined(NO_PYTHON)
USES+=				python:build,test
CONFIGURE_ARGS+=		--disable-python
.else
USES+=				python
PLIST+=				${PKGDIR}/pkg-plist.python
# Don't cache Python modules
CONFIGURE_ARGS+=		--nopycache
MAKE_ENV+=			PYTHONDONTWRITEBYTECODE=1

.	if defined(SAMBA4_BUNDLED_TALLOC) && ${SAMBA4_BUNDLED_TALLOC} == yes
SAMBA4_BUNDLED_LIBS+=		pytalloc-util
.	else
SAMBA4_BUNDLED_LIBS+=		!pytalloc-util
.	endif

.	if defined(SAMBA4_BUNDLED_TEVENT) && ${SAMBA4_BUNDLED_TEVENT} == yes
SAMBA4_BUNDLED_LIBS+=		pytevent
.	else
SAMBA4_BUNDLED_LIBS+=		!pytevent
.	endif

.	if defined(SAMBA4_BUNDLED_TDB) && ${SAMBA4_BUNDLED_TDB} == yes
SAMBA4_BUNDLED_LIBS+=		pytdb
.	else
SAMBA4_BUNDLED_LIBS+=		!pytdb
.	endif

.	if defined(SAMBA4_BUNDLED_LDB) && ${SAMBA4_BUNDLED_LDB} == yes
SAMBA4_BUNDLED_LIBS+=		pyldb pyldb-util
.	else
SAMBA4_BUNDLED_LIBS+=		!pyldb !pyldb-util
.	endif
.endif

.if defined(WANT_EXP_MODULES) && !empty(WANT_EXP_MODULES)
SAMBA4_MODULES+=		${WANT_EXP_MODULES}
.endif

.if defined(SAMBA4_BUNDLED_LIBS) && !empty(SAMBA4_BUNDLED_LIBS)
CONFIGURE_ARGS+=		--bundled-libraries="${SAMBA4_BUNDLED_LIBS:Q:C|(\\\\ )+|,|g:S|\\||g}"
.endif

.if defined(SAMBA4_MODULES) && !empty(SAMBA4_MODULES)
CONFIGURE_ARGS+=		--with-shared-modules="${SAMBA4_MODULES:C|-|_|:Q:C|(\\\\ )+|,|g:S|\\||g}"
.endif
# XXX: Hack for nss-info_* -> nss_info/* modules
# Add selected modules to the plist
.for module in ${SAMBA4_MODULES}
PLIST_FILES+=			${SAMBA4_MODULEDIR}/${module:C|_|/|:C|-|_|}.so
.endfor

.for module_class in ${SAMBA4_MODULES_CLASS}
PLIST_DIRS+=			${SAMBA4_MODULEDIR}/${module_class}
.endfor
PLIST_DIRS+=			${SAMBA4_MODULEDIR}

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=		--verbose --enable-debug
MAKE_ARGS+=			--verbose
DEBUG_FLAGS?=			-g -ggdb3 -O0
.endif

##############################################################################
.include <bsd.port.pre.mk>
##############################################################################
# Only for 64-bit architectures
.if ${ARCH} != armv6 && ${ARCH} != armv7 && ${ARCH} != i386 && ${ARCH} != mips && ${ARCH} != powerpc && ${ARCH} != powerpcspe
.	if defined(SAMBA4_BUNDLED_LDB) && ${SAMBA4_BUNDLED_LDB} == yes && (${PORT_OPTIONS:MAD_DC} || ${PORT_OPTIONS:MDEVELOPER})
# LMDB
SAMBA4_LMDB_DEPENDS=		lmdb>=0.9.16:databases/lmdb
PLIST_FILES+=			${SAMBA4_LIBDIR}/private/libldb-mdb-int-private-samba.so \
				${SAMBA4_MODULEDIR}/ldb/mdb.so
.	endif
.endif

.if ${PORT_OPTIONS:MGSSAPI_MIT}
PLIST_FILES+=			${SAMBA4_MODULEDIR}/krb5/winbind_krb5_localauth.so
.	if ${PORT_OPTIONS:MMANPAGES}
PLIST_FILES+=			share/man/man8/winbind_krb5_localauth.8.gz
.	endif
.	if ${PORT_OPTIONS:MAD_DC}
PLIST_FILES+=			${SAMBA4_LIBDIR}/krb5/plugins/kdb/samba.so
.	endif
.endif
.if ${PORT_OPTIONS:MFRUIT}
.	if ${PORT_OPTIONS:MMANPAGES}
PLIST_FILES+=			share/man/man8/vfs_fruit.8.gz
.	endif
.endif
.if ${PORT_OPTIONS:MGLUSTERFS}
.	if ${PORT_OPTIONS:MMANPAGES}
PLIST_FILES+=			share/man/man8/vfs_glusterfs.8.gz
.	endif
.endif
# for libexecinfo: (so that __builtin_frame_address() finds the top of the stack)
CFLAGS_amd64+=			-fno-omit-frame-pointer
# No fancy color error messages
CFLAGS+=			${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_clang=			-fno-color-diagnostics
CONFIGURE_ENV+=			NOCOLOR=yes WAF_LOG_FORMAT='%(c1)s%(zone)s%(c2)s %(message)s'
MAKE_ENV+=			NOCOLOR=yes WAF_LOG_FORMAT='%(c1)s%(zone)s%(c2)s %(message)s'
# Allow rpcgen to find proper CPP
MAKE_ENV+=			RPCGEN_CPP="${CPP}"
#.if ${readline_ARGS} == port
#CFLAGS+=			-D_FUNCTION_DEF
#.endif
# Some symbols in samba's linker version scripts are not defined, but since the
# scripts are generated dynamically, suppress errors with lld >= 17 due to these
# undefined symbols.
LDFLAGS+=			-Wl,--undefined-version

SAMBA4_SUB=			SAMBA4_LOGDIR="${SAMBA4_LOGDIR}" \
				SAMBA4_RUNDIR="${SAMBA4_RUNDIR}" \
				SAMBA4_LOCKDIR="${SAMBA4_LOCKDIR}" \
				SAMBA4_LIBDIR="${SAMBA4_LIBDIR}" \
				SAMBA4_MODULEDIR="${SAMBA4_MODULEDIR}" \
				SAMBA4_BINDDNSDIR="${SAMBA4_BINDDNSDIR}" \
				SAMBA4_PRIVATEDIR="${SAMBA4_PRIVATEDIR}" \
				SAMBA4_CONFDIR="${SAMBA4_CONFDIR}" \
				SAMBA4_CONFIG="${SAMBA4_CONFIG}" \
				SAMBA4_SERVICES="${SAMBA4_SERVICES}"

PLIST_SUB+=			${SAMBA4_SUB}
SUB_LIST+=			${SAMBA4_SUB}

USE_RC_SUBR=			samba_server
SUB_FILES=			pkg-message README.FreeBSD

PORTDOCS=			README.FreeBSD

post-extract:
				@${RM} -r ${WRKSRC}/pidl/lib/Parse/Yapp

post-patch:
				@${REINPLACE_CMD} -e 's|$${PKGCONFIGDIR}|${PKGCONFIGDIR}|g' \
					${PATCH_WRKSRC}/buildtools/wafsamba/pkgconfig.py
				@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
					${PATCH_WRKSRC}/buildtools/wafsamba/wafsamba.py
				@${REINPLACE_CMD} -e 's|%%GDB_CMD%%|${GDB_CMD}|g' \
					${PATCH_WRKSRC}/buildtools/scripts/abi_gen.sh
				@${REINPLACE_CMD} -e 's|%%SAMBA4_CONFIG%%|${SAMBA4_CONFIG}|g' \
					${PATCH_WRKSRC}/dynconfig/wscript

# Use threading (or multiprocessing) but not thread (renamed in python 3+).
pre-configure:
.if (!${PORT_OPTIONS:MPYTHON3} || defined(NO_PYTHON)) && ${PORT_OPTIONS:MAD_DC}
				@${ECHO_CMD}; \
				${ECHO_MSG} "===>  AD_DC option requires PYTHON3 to be set"; \
				${ECHO_CMD}; \
				${FALSE}
.endif

post-install-rm-junk:
				${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/samba/third_party
				${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name __pycache__ \
					-type d -print0 | ${XARGS} -0 -n 1 -t ${RM} -r
				${FIND} ${STAGEDIR} -type f -empty -delete

post-install-fix-manpages:
.if ${PORT_OPTIONS:MMANPAGES}
.for f in vfs_aio_linux.8 vfs_btrfs.8 vfs_ceph.8 vfs_gpfs.8
				${RM} ${STAGEDIR}${PREFIX}/share/man/man8/${f}
.endfor
.if defined(SAMBA4_BUNDLED_LDB) && ${SAMBA4_BUNDLED_LDB} == yes
.	for f in ldbadd.1 ldbdel.1 ldbedit.1 ldbmodify.1 ldbrename.1 ldbsearch.1
				${MV} ${STAGEDIR}${PREFIX}/share/man/man1/${f} ${STAGEDIR}${PREFIX}/share/man/man1/samba-${f}
.	endfor
.endif

.if defined(SAMBA4_BUNDLED_TALLOC) && ${SAMBA4_BUNDLED_TALLOC} == yes
.	for f in talloc.3
				${MV} ${STAGEDIR}${PREFIX}/share/man/man3/${f} ${STAGEDIR}${PREFIX}/share/man/man3/samba-${f}
.	endfor
.endif

.if defined(SAMBA4_BUNDLED_TDB) && ${SAMBA4_BUNDLED_TDB} == yes
.	for f in tdbbackup.8 tdbdump.8 tdbrestore.8 tdbtool.8
				${MV} ${STAGEDIR}${PREFIX}/share/man/man8/${f} ${STAGEDIR}${PREFIX}/share/man/man8/samba-${f}
.	endfor
.endif
.endif

post-install: post-install-rm-junk post-install-fix-manpages
.if ${PORT_OPTIONS:MMANPAGES}
				${LN} -sf smb.conf.5.gz ${STAGEDIR}${PREFIX}/share/man/man5/smb4.conf.5.gz
.endif
# Run post-install script
.for dir in			${SAMBA4_LOGDIR} ${SAMBA4_RUNDIR} ${SAMBA4_LOCKDIR} ${SAMBA4_MODULEDIR}
					${INSTALL} -d -m 0755 "${STAGEDIR}${dir}"
.endfor
				${INSTALL} -d -m 0750 "${STAGEDIR}${SAMBA4_BINDDNSDIR}"
				${INSTALL} -d -m 0750 "${STAGEDIR}${SAMBA4_PRIVATEDIR}"
.for module_class in			${SAMBA4_MODULES_CLASS}
					${INSTALL} -d -m 0755 "${STAGEDIR}${SAMBA4_MODULEDIR}/${module_class}"
.endfor
.if !defined(WITH_DEBUG)
				-${FIND} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/sbin ${STAGEDIR}${PREFIX}/libexec \
					-type f -print0 | ${XARGS} -0 -n 1 -t ${STRIP_CMD}
				-${FIND} ${STAGEDIR}${PREFIX}/lib -name '*.so*' \
					-type f -print0 | ${XARGS} -0 -n 1 -t ${STRIP_CMD}
.endif

post-install-FRUIT-off:
				${RM} ${STAGEDIR}${SAMBA4_MODULEDIR}/vfs/fruit.so
.if ${PORT_OPTIONS:MMANPAGES}
				${RM} ${STAGEDIR}${PREFIX}/share/man/man8/vfs_fruit.8
.endif

post-install-DOCS-on:
				${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in			${PORTDOCS}
				${INSTALL_DATA} ${WRKDIR}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-CLUSTER-on:
				${LN} -nfs ../../../../share/ctdb/events/legacy/00.ctdb.script		${STAGEDIR}${PREFIX}/etc/ctdb/events/legacy/00.ctdb.script
				${LN} -nfs ../../../../share/ctdb/events/legacy/10.interface.script	${STAGEDIR}${PREFIX}/etc/ctdb/events/legacy/10.interface.script
				${LN} -nfs ../../../../share/ctdb/events/legacy/05.system.script	${STAGEDIR}${PREFIX}/etc/ctdb/events/legacy/05.system.script
				${LN} -nfs ../../../../share/ctdb/events/legacy/01.reclock.script	${STAGEDIR}${PREFIX}/etc/ctdb/events/legacy/01.reclock.script

.include <bsd.port.post.mk>
