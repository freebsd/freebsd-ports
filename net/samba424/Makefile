PORTNAME=	samba424
DISTVERSION=	4.24.6
PORTREVISION=	2
CATEGORIES?=	net
MASTER_SITES=	SAMBA/samba/stable \
		SAMBA/samba/rc
DISTNAME=	samba-${DISTVERSION:S|.p|pre|:S|.r|rc|:S|.t|tp|:S|.a|alpha|}

MAINTAINER=	samba@FreeBSD.org
COMMENT=	Free SMB/CIFS and AD/DC server and client for Unix
WWW=		https://gitlab.com/samba-freebsd/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

# The SAMBA4_BUNDLED_* variables are deprecated.
.for bvar in SAMBA4_BUNDLED_CMOCKA SAMBA4_BUNDLED_TALLOC SAMBA4_BUNDLED_TDB \
	SAMBA4_BUNDLED_TEVENT
.  if defined(${bvar}) && ${${bvar}} == yes
IGNORE=		does not support bundling dependencies via ${bvar}; use option ${bvar:S/^SAMBA4_//} instead
.  endif
.endfor

BUILD_DEPENDS=	${_JANSSON_DEPENDS} \
		${_LIBARCHIVE_DEPENDS} \
		${_TASN1_DEPENDS} \
		p5-Parse-Yapp>=0:devel/p5-Parse-Yapp
LIB_DEPENDS=	${_VFS_SNAPPER_LIB_DEPENDS} \
		libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls \
		libiconv.so:converters/libiconv \
		libicui18n.so:devel/icu \
		libicuuc.so:devel/icu \
		libinotify.so:devel/libinotify \
		libpopt.so:devel/popt \
		libreadline.so:devel/readline \
		libsunacl.so:sysutils/libsunacl \
		libunwind.so:devel/libunwind
RUN_DEPENDS=	${_JANSSON_DEPENDS} \
		${_LIBARCHIVE_DEPENDS} \
		${_TASN1_DEPENDS}
TEST_DEPENDS=	bash:shells/bash \
		tshark:net/wireshark@nox11

USES=		compiler:c++11-lang cpe gettext-runtime iconv localbase:ldflags \
		ncurses perl5 pkgconfig samba:self shebangfix waf
CPE_VENDOR=	samba
CPE_PRODUCT=	samba
USE_LDCONFIG=	${SAMBA_LIBDIR}
USE_PERL5=	build
USE_RC_SUBR=	samba_server
WAF_CMD=	buildtools/bin/waf
SHEBANG_FILES=	selftest/* source3/script* source4/scripting/bin/*

CONFIGURE_LOG=		bin/config.log
CONFIGURE_ARGS=		--datadir="${DATADIR}" \
			--includedir="${SAMBA_INCLUDEDIR}" \
			--libdir="${SAMBA_LIBDIR}" \
			--localstatedir="${_LOCALSTATEDIR}" \
			--mandir="${PREFIX}/share/man" \
			--sysconfdir="${ETCDIR}" \
			--with-bind-dns-dir=${_BINDDNSDIR} \
			--with-cachedir="${_LOCKDIR}" \
			--with-ldbmodulesdir="${SAMBA_LDB_MODULESDIR}" \
			--with-lockdir="${_LOCKDIR}" \
			--with-logfilebase="${_LOGDIR}" \
			--with-modulesdir="${SAMBA_MODULESDIR}" \
			--with-pammodulesdir="${_PAMDIR}" \
			--with-piddir="${_RUNDIR}" \
			--with-pkgconfigdir="${_PKGCONFIGDIR}" \
			--with-privatedir="${_PRIVATEDIR}" \
			--with-privatelibdir="${SAMBA_LIBDIR}/private" \
			--with-privileged-socket-dir="${_RUNDIR}" \
			--with-sockets-dir="${_RUNDIR}" \
			--with-statedir="${_LOCKDIR}"
CONFIGURE_ARGS+=	${_BUNDLED_LIBS:D--bundled-libraries="${_BUNDLED_LIBS:Q:C|(\\\\ )+|,|g:S|\\||g}"} \
			${_PRIVATE_LIBS:D--private-libraries="${_PRIVATE_LIBS:Q:C|(\\\\ )+|,|g:S|\\||g}"} \
			${_SHARED_MODULES:D--with-shared-modules="${_SHARED_MODULES:C|-|_|:Q:C|(\\\\ )+|,|g:S|\\||g}"} \
			${PORT_OPTIONS:MAVAHI:C/.+/--enable-avahi/} \
			${WITH_DEBUG:D --verbose --enable-debug} \
			--disable-ctdb-tests \
			--disable-rpath \
			--disable-spotlight \
			--enable-pthreadpool \
			--with-acl-support \
			--with-iconv \
			--with-libarchive \
			--with-libiconv="${ICONV_PREFIX}" \
			--with-pam \
			--with-regedit \
			--with-sendfile-support \
			--with-winbind \
			--without-fake-kaserver \
			--without-gettext \
			--without-lttng \
			--without-systemd

CONFIGURE_ENV=	PTHREAD_LDFLAGS="-lpthread" \
		PYTHONHASHSEED=1

FORTIFY_UNSAFE=	1
MAKE_ARGS=	${WITH_DEBUG:D --verbose}
MAKE_ENV=	PYTHONHASHSEED=1 \
		RPCGEN_CPP="${CPP}"
TEST_ENV=	MD5SUM=${MD5} \
		PYTHON="${PYTHON_CMD}" \
		PYTHONDONTWRITEBYTECODE=1 \
		SHA1SUM=/sbin/sha1 \
		SHA256SUM=${SHA256}

CFLAGS+=	${_CFLAGS_${CHOSEN_COMPILER_TYPE}}
.ifnmake portclippy
_CFLAGS_clang=	-fno-color-diagnostics
.endif
CONFIGURE_ENV+=	NOCOLOR=yes \
		WAF_LOG_FORMAT='%(c1)s%(zone)s%(c2)s %(message)s'
MAKE_ENV+=	NOCOLOR=yes \
		WAF_LOG_FORMAT='%(c1)s%(zone)s%(c2)s %(message)s'
CFLAGS_amd64+=	-fno-omit-frame-pointer
DEBUG_FLAGS?=	-g -ggdb3 -O0
LDFLAGS+=	-Wl,--undefined-version

CONFLICTS_INSTALL=	ldb2[0-9]-* samba4*

ETCDIR=		${PREFIX}/etc
SUB_FILES=	pkg-message README.FreeBSD
SUB_LIST=	${_SAMBA_SUB}

PLIST?=		${PKGDIR}/pkg-plist
PLIST_DIRS=	${_MODULE_CLASSES:S|^|${SAMBA_MODULESDIR}/|} \
		${SAMBA_MODULESDIR}
PLIST_FILES+=	${_SHARED_MODULES:C|_|/|:C|-|_|:S|^|${SAMBA_MODULESDIR}/|:S|$|.so|}
PLIST_SUB=	${_SAMBA_SUB}
PORTDOCS=	README.FreeBSD

OPTIONS_DEFINE=			AD_DC ADS CLUSTER CUPS DOCS FAM GPGME LDAP \
				MANPAGES PROFILE PYTHON3 QUOTAS SYSLOG UTMP
OPTIONS_DEFAULT=		AD_DC ADS AVAHI DOCS FAM FRUIT GSSAPI_BUILTIN \
				LDAP MANPAGES PROFILE PYTHON3 QUOTAS SYSLOG \
				UTMP
OPTIONS_GROUP=			BUNDLED_DEPS DEVELOPMENT VFS
OPTIONS_GROUP_BUNDLED_DEPS=	BUNDLED_CMOCKA BUNDLED_TALLOC BUNDLED_TDB \
				BUNDLED_TEVENT
OPTIONS_GROUP_DEVELOPMENT=	DEVELOPER MEMORY_DEBUG TEST
OPTIONS_GROUP_VFS=		FRUIT GLUSTERFS
OPTIONS_SINGLE=			GSSAPI ZEROCONF
OPTIONS_SINGLE_GSSAPI=		GSSAPI_BUILTIN GSSAPI_MIT
OPTIONS_SINGLE_ZEROCONF=	AVAHI MDNSRESPONDER ZEROCONF_NONE
OPTIONS_SUB=			yes

ADS_DESC=		Active Directory client
AD_DC_DESC=		Active Directory Domain Controller(implies PYTHON3)
BUNDLED_CMOCKA_DESC=	Bundle cmocka instead of depending on a standalone port
BUNDLED_DEPS_DESC=	Bundled dependencies
BUNDLED_TALLOC_DESC=	Bundle talloc instead of depending on a standalone port
BUNDLED_TDB_DESC=	Bundle TDB instead of depending on a standalone port
BUNDLED_TEVENT_DESC=	Bundle Tevent instead of depending on a standalone port
CLUSTER_DESC=		Clustering support
DEVELOPER_DESC=		With developer framework
DEVELOPMENT_DESC=	Testing, debugging, and development
FAM_DESC=		File Alteration Monitor
FRUIT_DESC=		MacOSX and TimeMachine support
GLUSTERFS_DESC=		GlusterFS support
GPGME_DESC=		GpgME support
GSSAPI_BUILTIN_DESC=	GSSAPI support via bundled Heimdal
LDAP_DESC=		LDAP client
MEMORY_DEBUG_DESC=	Debug memory allocator
PROFILE_DESC=		Profiling data
QUOTAS_DESC=		Disk quota support
UTMP_DESC=		UTMP accounting
VFS_DESC=		VFS modules
ZEROCONF_DESC=		Zero configuration networking
ZEROCONF_NONE_DESC=	Zeroconf support is absent

ADS_IMPLIES=		LDAP
ADS_CONFIGURE_WITH=	ads
ADS_VARS=		_SHARED_MODULES+="idmap_ad idmap_rfc2307 nss-info_template nss-info_rfc2307 nss-info_sfu nss-info_sfu20"

AD_DC_IMPLIES=		ADS PYTHON3
AD_DC_BUILD_DEPENDS=	${_LMDB_DEPENDS}
AD_DC_RUN_DEPENDS=	${_LMDB_DEPENDS}
AD_DC_CONFIGURE_OFF=	--without-ad-dc \
			--without-ldb-lmdb
AD_DC_VARS=		PLIST+=${PKGDIR}/pkg-plist.ad_dc
AD_DC_BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dnspython>=2.2.1:dns/py-dnspython@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}markdown>=3.3.7:textproc/py-markdown@${PY_FLAVOR}
AD_DC_RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dnspython>=2.2.1:dns/py-dnspython@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}markdown>=3.3.7:textproc/py-markdown@${PY_FLAVOR}

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_CONFIGURE_ENABLE=	avahi
AVAHI_VARS=		_SAMBA_SERVICES+=avahi_daemon

BUNDLED_CMOCKA_BUILD_DEPENDS_OFF=	cmocka>=1.1.3:sysutils/cmocka
BUNDLED_CMOCKA_TEST_DEPENDS_OFF=	cmocka>=1.1.3:sysutils/cmocka
BUNDLED_CMOCKA_CONFLICTS_INSTALL=	cmocka-1.*
BUNDLED_CMOCKA_VARS=			_BUNDLED_LIB_REPLACE=replace \
					_BUNDLED_LIBS+=cmocka
BUNDLED_CMOCKA_VARS_OFF=		_BUNDLED_LIBS+=!cmocka

BUNDLED_TALLOC_BUILD_DEPENDS_OFF=	talloc244>=2.4.4:devel/talloc244
BUNDLED_TALLOC_RUN_DEPENDS_OFF=		talloc244>=2.4.4:devel/talloc244
BUNDLED_TALLOC_CONFLICTS_INSTALL=	talloc-* talloc2*
BUNDLED_TALLOC_VARS=			_BUNDLED_LIB_REPLACE=replace \
					_BUNDLED_LIBS+=talloc
BUNDLED_TALLOC_VARS_OFF=		_BUNDLED_LIBS+=!talloc

BUNDLED_TDB_BUILD_DEPENDS_OFF=	tdb1415>=1.4.15:databases/tdb1415
BUNDLED_TDB_RUN_DEPENDS_OFF=	tdb1415>=1.4.15:databases/tdb1415
BUNDLED_TDB_CONFLICTS_INSTALL=	tdb-* tdb1*
BUNDLED_TDB_VARS=		_BUNDLED_LIB_REPLACE=replace \
				_BUNDLED_LIBS+=tdb
BUNDLED_TDB_VARS_OFF=		_BUNDLED_LIBS+=!tdb

BUNDLED_TEVENT_BUILD_DEPENDS_OFF=	tevent017>=0.17.1:devel/tevent017
BUNDLED_TEVENT_RUN_DEPENDS_OFF=		tevent017>=0.17.1:devel/tevent017
BUNDLED_TEVENT_CONFLICTS_INSTALL=	tevent-* tevent0*
BUNDLED_TEVENT_VARS=			_BUNDLED_LIB_REPLACE=replace \
					_BUNDLED_LIBS+=tevent
BUNDLED_TEVENT_VARS_OFF=		_BUNDLED_LIBS+=!tevent

CLUSTER_LIB_DEPENDS=	libpcap.so:net/libpcap
CLUSTER_CONFIGURE_WITH=	cluster-support
CLUSTER_VARS=		PLIST+=${PKGDIR}/pkg-plist.cluster

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_CONFIGURE_ENABLE=	cups iprint

DEVELOPER_BUILD_DEPENDS=	${_GDB_CMD}:devel/gdb \
				${_LMDB_DEPENDS}
DEVELOPER_RUN_DEPENDS=		${_LMDB_DEPENDS}
DEVELOPER_TEST_DEPENDS=		${_GDB_CMD}:devel/gdb
DEVELOPER_CONFIGURE_ON=		--abi-check-disable \
				--enable-developer \
				--enable-selftest
DEVELOPER_CONFIGURE_ENV=	WAF_CMD_FORMAT=string
DEVELOPER_VARS=			_SHARED_MODULES+="auth_skel pdb_test gpext_security gpext_registry gpext_scripts perfcount_test vfs_fake_dfq vfs_skel_opaque vfs_skel_transparent vfs_shadow_copy_test vfs_fake_acls vfs_nfs4acl_xattr vfs_error_inject vfs_delay_inject"
DEVELOPER_VARS_OFF=		_GDB_CMD=true

FAM_LIB_DEPENDS=	libfam.so.0:devel/gamin
FAM_CONFIGURE_WITH=	fam

FRUIT_PREVENTS=		ZEROCONF_NONE
FRUIT_PREVENTS_MSG=	MacOSX support requires Zeroconf(AVAHI or \
			MDNSRESPONDER)
FRUIT_PLIST_FILES=	%%MANPAGES%%share/man/man8/vfs_fruit.8.gz
FRUIT_VARS=		_SHARED_MODULES+=vfs_fruit

GLUSTERFS_LIB_DEPENDS=		libglusterfs.so:net/glusterfs
GLUSTERFS_CONFIGURE_ENABLE=	glusterfs
GLUSTERFS_PLIST_FILES=		%%MANPAGES%%share/man/man8/vfs_glusterfs.8.gz
GLUSTERFS_VARS=			_SHARED_MODULES+=vfs_glusterfs

GPGME_LIB_DEPENDS=	libgpgme.so:security/gpgme
GPGME_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gpg>=2.0.0:security/py-gpg@${PY_FLAVOR}
GPGME_CONFIGURE_WITH=	gpgme

GSSAPI_BUILTIN_USES=	bison

GSSAPI_MIT_USES=		bison gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	--with-experimental-mit-ad-dc \
				--with-system-mitkdc=${GSSAPIBASEDIR}/sbin/krb5kdc \
				--with-system-mitkrb5
GSSAPI_MIT_PLIST_FILES=		${SAMBA_MODULESDIR}/krb5/winbind_krb5_localauth.so \
				%%AD_DC%%${SAMBA_LIBDIR}/krb5/plugins/kdb/samba.so \
				%%MANPAGES%%share/man/man8/winbind_krb5_localauth.8.gz

LDAP_USES=		ldap
LDAP_CONFIGURE_WITH=	ldap
LDAP_VARS=		_SHARED_MODULES+=idmap_ldap

MANPAGES_BUILD_DEPENDS=		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
				xsltproc:textproc/libxslt
MANPAGES_CONFIGURE_ENV_OFF=	XSLTPROC="false"

MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder
MDNSRESPONDER_VARS=		_SAMBA_SERVICES+=mdnsd

# FreeBSD 14+ uses jemalloc as the base system allocator.
# The devel/jemalloc port is gone and base does not install public headers.
MEMORY_DEBUG_CONFIGURE_ENV=	ADDITIONAL_CFLAGS="-DENABLE_JEMALLOC"

PROFILE_CONFIGURE_WITH=	profiling-data

PYTHON3_USES=		python
PYTHON3_USES_OFF=	python:build,test
PYTHON3_CONFIGURE_ON=	--nopycache
PYTHON3_CONFIGURE_OFF=	--disable-python
PYTHON3_MAKE_ENV=	PYTHONDONTWRITEBYTECODE=1
PYTHON3_VARS=		_BUNDLED_LIBS+="pyldb pyldb-util" \
			PLIST+=${PKGDIR}/pkg-plist.python

QUOTAS_CONFIGURE_WITH=	quotas

SYSLOG_CONFIGURE_WITH=	syslog

TEST_BUILD_DEPENDS=	${_ISO8601_DEPENDS}
TEST_RUN_DEPENDS=	${_ISO8601_DEPENDS}

UTMP_CONFIGURE_WITH=	utmp

ZEROCONF_NONE_MAKE_ENV=	ZEROCONF=none

.ifnmake portclippy
.  if !defined(WANT_EXP_MODULES) || empty(WANT_EXP_MODULES)
WANT_EXP_MODULES=	vfs_cacheprime
.  endif
.endif

_GDB_CMD=	${LOCALBASE}/bin/gdb

_ISO8601_DEPENDS=		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${PY_FLAVOR}
_JANSSON_DEPENDS=		jansson>=2.10:devel/jansson
_LIBARCHIVE_DEPENDS=		libarchive>=3.1.2:archivers/libarchive
_TASN1_DEPENDS=			libtasn1>=3.8:security/libtasn1
.if ${WANT_EXP_MODULES:Mvfs_snapper}
_VFS_SNAPPER_LIB_DEPENDS=	libdbus-1.so:devel/dbus \
				libdbus-glib-1.so:devel/dbus-glib
.endif

_BUNDLED_LIBS=	!libarchive com_err ${_BUNDLED_LIB_replace}

_MODULE_CLASSES=	auth bind9 gensec gpext idmap ldb nss_info pdb \
			perfcount process_model service vfs
_PRIVATE_LIBS=		!ldb
_SHARED_MODULES+=	${WANT_EXP_MODULES} krb5_async_dns_krb5_locator \
			krb5_winbind_krb5_locator idmap_nss idmap_autorid \
			idmap_rid idmap_hash idmap_tdb idmap_tdb2 idmap_script \
			nss-info_hash vfs_freebsd vfs_acl_tdb vfs_acl_xattr \
			vfs_aio_fork vfs_aio_pthread vfs_audit vfs_cap \
			vfs_catia vfs_commit vfs_crossrename vfs_default_quota \
			vfs_dirsort vfs_expand_msdfs vfs_extd_audit \
			vfs_fake_perms vfs_full_audit vfs_linux_xfs_sgid \
			vfs_media_harmony vfs_offline vfs_preopen vfs_readahead \
			vfs_readonly vfs_recycle vfs_shadow_copy \
			vfs_shadow_copy2 vfs_shell_snap vfs_streams_depot \
			vfs_streams_xattr vfs_syncops vfs_time_audit \
			vfs_unityed_media vfs_virusfilter vfs_widelinks \
			vfs_worm vfs_xattr_tdb vfs_zfsacl

_SAMBA_MAJVERNAME=	samba4
_SAMBA_SUB=		PKGCONFIGDIR=${_PKGCONFIGDIR_REL} \
			SAMBA4_LOGDIR="${_LOGDIR}" SAMBA4_RUNDIR="${_RUNDIR}" \
			SAMBA4_LOCKDIR="${_LOCKDIR}" \
			SAMBA4_LIBDIR="${SAMBA_LIBDIR}" \
			SAMBA4_MODULEDIR="${SAMBA_MODULESDIR}" \
			SAMBA_LDB_MODULESDIR="${SAMBA_LDB_MODULESDIR}" \
			SAMBA4_BINDDNSDIR="${_BINDDNSDIR}" \
			SAMBA4_PRIVATEDIR="${_PRIVATEDIR}" \
			SAMBA4_CONFIG="${_SAMBA_CONFIG}" \
			SAMBA4_SERVICES="${_SAMBA_SERVICES}"

_SAMBA_CONFIG=	smb4.conf

_BINDDNSDIR=		${_LOCKDIR}/bind-dns
_LOCALSTATEDIR=		${_VARDIR}
_LOCKDIR=		${_VARDIR}/db/${_SAMBA_MAJVERNAME}
_LOGDIR=		${_VARDIR}/log/${_SAMBA_MAJVERNAME}
_PAMDIR=		${PREFIX}/lib
_PKGCONFIGDIR=		${PREFIX}/${_PKGCONFIGDIR_REL}
_PKGCONFIGDIR_REL=	libdata/pkgconfig
_PRIVATEDIR=		${_LOCKDIR}/private
_RUNDIR=		${_VARDIR}/run/${_SAMBA_MAJVERNAME}
_VARDIR?=		${VARDIR:U/var}


.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON3}
_BUNDLED_LIBS+=	${"${PORT_OPTIONS:MBUNDLED_TALLOC}" == "BUNDLED_TALLOC":?:!}pytalloc-util \
		${"${PORT_OPTIONS:MBUNDLED_TEVENT}" == "BUNDLED_TEVENT":?:!}pytevent \
		${"${PORT_OPTIONS:MBUNDLED_TDB}" == "BUNDLED_TDB":?:!}pytdb
.endif

# Only for 64-bit architectures
.if ${ARCH} != armv6 && ${ARCH} != armv7 && ${ARCH} != i386 && ${ARCH} != \
	powerpc && ${ARCH} != powerpcspe
.       if (${PORT_OPTIONS:MAD_DC} || ${PORT_OPTIONS:MDEVELOPER})
# LMDB
_LMDB_DEPENDS=	lmdb0>=0.9.16:databases/lmdb0
PLIST_FILES+=	${SAMBA_LDB_MODULESDIR}/mdb.so \
		${SAMBA_LIBDIR}/private/libldb-mdb-int-private-samba.so
.       endif
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
	@[ ! -d ${STAGEDIR}${PYTHON_SITELIBDIR} ] || \
		(${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/samba/third_party && \
		${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -type d -name __pycache__ -exec ${RM} -r {} +)
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

	${RLN} ${STAGEDIR}${PREFIX}/libexec/ctdb/statd_callout ${STAGEDIR}${PREFIX}/etc/ctdb/statd-callout

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
