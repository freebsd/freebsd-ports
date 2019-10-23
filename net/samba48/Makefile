# Created by: timur@FreeBSD.org
# $FreeBSD$

PORTNAME=			${SAMBA4_BASENAME}48
PORTVERSION=			${SAMBA4_VERSION}
PORTREVISION=			4
CATEGORIES?=			net
MASTER_SITES=			SAMBA/samba/stable SAMBA/samba/rc
DISTNAME=			${SAMBA4_DISTNAME}

MAINTAINER=			timur@FreeBSD.org
COMMENT=			Free SMB/CIFS and AD/DC server and client for Unix

LICENSE=			GPLv3+
LICENSE_FILE=			${WRKSRC}/COPYING

IGNORE_NONTHREAD_PYTHON=	needs port lang/python${PYTHON_SUFFIX} to be build with THREADS support
DEPRECATED=			not supported by the upstream
EXPIRATION_DATE=		2019-12-15

CONFLICTS_INSTALL?=		samba4-4.0.* samba4[1-79]-4.* p5-Parse-Pidl-4.*

EXTRA_PATCHES+=			${PATCHDIR}/0001-Zfs-provision-1.patch:-p1
EXTRA_PATCHES+=			${PATCHDIR}/0001-Freenas-master-mdns-fixes-22.patch:-p1
EXTRA_PATCHES+=			${PATCHDIR}/0001-audit.patch:-p1
EXTRA_PATCHES+=			${PATCHDIR}/0001-bug-228462.patch:-p1

SAMBA4_BASENAME=		samba
SAMBA4_PORTNAME=		${SAMBA4_BASENAME}4
SAMBA4_VERSION=			4.8.12
SAMBA4_DISTNAME=		${SAMBA4_BASENAME}-${SAMBA4_VERSION:S|.p|pre|:S|.r|rc|:S|.t|tp|:S|.a|alpha|}

WRKSRC?=			${WRKDIR}/${DISTNAME}

.if !defined(SAMBA4_SUBPORT)
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
SAMBA4_MODULEDIR=		${PREFIX}/lib/shared-modules
SAMBA4_INCLUDEDIR=		${PREFIX}/include/${SAMBA4_PORTNAME}
SAMBA4_CONFDIR=			${PREFIX}/etc
SAMBA4_CONFIG=			smb4.conf

CONFIGURE_ARGS+=		--mandir="${MANPREFIX}/man" \
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
CONFIGURE_ENV+=			PTHREAD_LDFLAGS="-lpthread"

USES=				compiler:c++11-lang cpe iconv gettext-runtime \
				localbase:ldflags perl5 pkgconfig shebangfix \
				ssl waf
USE_PERL5=			build
USE_LDCONFIG=			${SAMBA4_LIBDIR} ${SAMBA4_LIBDIR}/private
WAF_CMD=			buildtools/bin/waf
CONFIGURE_LOG=			bin/config.log

PKGCONFIGDIR?=			${PREFIX}/libdata/pkgconfig
PKGCONFIGDIR_REL?=		${PKGCONFIGDIR:S,^${PREFIX}/,,}
PLIST_SUB+=			PKGCONFIGDIR=${PKGCONFIGDIR_REL}
SUB_LIST+=			PKGCONFIGDIR=${PKGCONFIGDIR_REL}
##############################################################################
# Options
OPTIONS_SUB=			yes

OPTIONS_DEFINE=			AD_DC ADS DEBUG DOCS FAM LDAP \
				QUOTAS SYSLOG UTMP PROFILE
# Make those default options
OPTIONS_DEFAULT:=		${OPTIONS_DEFINE} GSSAPI_BUILTIN
# This shouldn't be default in the release
OPTIONS_DEFINE+=		DEVELOPER MANDOC

OPTIONS_DEFINE_amd64=		AESNI
OPTIONS_DEFAULT_amd64=		AESNI

OPTIONS_DEFINE+=		CLUSTER CUPS GLUSTERFS GPGME NTVFS SPOTLIGHT
#OPTIONS_DEFINE+=		MEMORY_DEBUG

OPTIONS_SINGLE=			GSSAPI
# GSSAPI_HEIMDAL
OPTIONS_SINGLE_GSSAPI=		GSSAPI_BUILTIN GSSAPI_MIT

OPTIONS_RADIO=			DNS ZEROCONF
OPTIONS_RADIO_DNS=		NSUPDATE BIND911 BIND913 BIND914
OPTIONS_RADIO_ZEROCONF=		MDNSRESPONDER AVAHI
##############################################################################
AD_DC_DESC=			Active Directory Domain Controller
ADS_DESC=			Active Directory client(implies LDAP)
AESNI_DESC=			Accelerated AES crypto functions(amd64 only)
CLUSTER_DESC=			Clustering
DEVELOPER_DESC=			With developer framework(implies NTVFS)
FAM_DESC=			File Alteration Monitor
GPGME_DESC=			GpgME
GLUSTERFS_DESC=			GlusterFS
LDAP_DESC=			LDAP client
LIBZFS_DESC=			LibZFS
SPOTLIGHT_DESC=			Spotlight
MANDOC_DESC=			Build manpages from DOCBOOK templates
MEMORY_DEBUG_DESC=		Debug memory allocation
NTVFS_DESC=			Build *DEPRECATED* NTVFS file server
PICKY_DEVELOPER_DESC=		Treat compiler warnings as errors(implies DEVELOPER)
PROFILE_DESC=			Profiling data
QUOTAS_DESC=			Disk quota
UTMP_DESC=			UTMP accounting

GSSAPI_BUILTIN_DESC=		GSSAPI support via bundled Heimdal

BIND911_DESC=			Use Bind 9.11 as AD DC DNS server frontend
BIND913_DESC=			Use Bind 9.13 as AD DC DNS server frontend
BIND914_DESC=			Use Bind 9.14 as AD DC DNS server frontend
NSUPDATE_DESC=			Use samba NSUPDATE utility for AD DC
##############################################################################
# XXX: Unconditional dependencies which can't be switched off(if present in
# the system)
# Readline(sponsored by Python)
# XXX: USES=readline pollutes CPPFLAGS, so we explicitly put dependency
LIB_DEPENDS+=			libreadline.so.8:devel/readline
# popt
LIB_DEPENDS+=			libpopt.so:devel/popt
# inotify
LIB_DEPENDS+=			libinotify.so:devel/libinotify
# GNUTLS
LIB_DEPENDS+=			libgnutls.so:security/gnutls
# NFS4 ACL glue
LIB_DEPENDS+=			libsunacl.so:sysutils/libsunacl
# Jansson
BUILD_DEPENDS+=			jansson>=2.10:devel/jansson
RUN_DEPENDS+=			jansson>=2.10:devel/jansson
# External Samba dependencies
# Needed for IDL compiler
BUILD_DEPENDS+=			p5-Parse-Yapp>=0:devel/p5-Parse-Yapp
# Libarchive
SAMBA4_BUNDLED_LIBS+=		!libarchive
BUILD_DEPENDS+=			libarchive>=3.1.2:archivers/libarchive
RUN_DEPENDS+=			libarchive>=3.1.2:archivers/libarchive
### Bundled libraries
SAMBA4_BUNDLED_CMOCKA?=		no
SAMBA4_BUNDLED_TALLOC?=		yes
SAMBA4_BUNDLED_TEVENT?=		yes
SAMBA4_BUNDLED_TDB?=		yes
SAMBA4_BUNDLED_LDB?=		yes
# cmocka
.if defined(SAMBA4_BUNDLED_CMOCKA) && ${SAMBA4_BUNDLED_CMOCKA} == yes
SAMBA4_BUNDLED_LIBS+=		cmocka
SAMBA4_BUILTIN_LIBS+=		cmocka
CONFLICTS+=			cmocka-1.*
PLIST_SUB+=			SAMBA4_BUNDLED_CMOCKA=""
SUB_LIST+=			SAMBA4_BUNDLED_CMOCKA=""
.else
SAMBA4_BUNDLED_LIBS+=		!cmocka
BUILD_DEPENDS+=			cmocka>=1.1.1:sysutils/cmocka
RUN_DEPENDS+=			cmocka>=1.1.1:sysutils/cmocka
PLIST_SUB+=			SAMBA4_BUNDLED_CMOCKA="@comment "
SUB_LIST+=			SAMBA4_BUNDLED_CMOCKA="@comment "
.endif
# talloc
.if defined(SAMBA4_BUNDLED_TALLOC) && ${SAMBA4_BUNDLED_TALLOC} == yes
SAMBA4_BUNDLED_LIBS+=		talloc
SAMBA4_BUILTIN_LIBS+=		talloc
CONFLICTS+=			talloc1-2.*
PLIST_SUB+=			SAMBA4_BUNDLED_TALLOC=""
SUB_LIST+=			SAMBA4_BUNDLED_TALLOC=""
.else
SAMBA4_BUNDLED_LIBS+=		!talloc
BUILD_DEPENDS+=			talloc1>=2.1.14:devel/talloc1
RUN_DEPENDS+=			talloc1>=2.1.14:devel/talloc1
PLIST_SUB+=			SAMBA4_BUNDLED_TALLOC="@comment "
SUB_LIST+=			SAMBA4_BUNDLED_TALLOC="@comment "
.endif
# tevent
.if defined(SAMBA4_BUNDLED_TEVENT) && ${SAMBA4_BUNDLED_TEVENT} == yes
SAMBA4_BUNDLED_LIBS+=		tevent
SAMBA4_BUILTIN_LIBS+=		tevent
CONFLICTS+=			tevent1-0.*
PLIST_SUB+=			SAMBA4_BUNDLED_TEVENT=""
SUB_LIST+=			SAMBA4_BUNDLED_TEVENT=""
.else
SAMBA4_BUNDLED_LIBS+=		!tevent
BUILD_DEPENDS+=			tevent1>=0.9.37:devel/tevent1
RUN_DEPENDS+=			tevent1>=0.9.37:devel/tevent1
PLIST_SUB+=			SAMBA4_BUNDLED_TEVENT="@comment "
SUB_LIST+=			SAMBA4_BUNDLED_TEVENT="@comment "
.endif
# tdb
.if defined(SAMBA4_BUNDLED_TDB) && ${SAMBA4_BUNDLED_TDB} == yes
SAMBA4_BUNDLED_LIBS+=		tdb
SAMBA4_BUILTIN_LIBS+=		tdb
CONFLICTS+=			tdb1-1.*
PLIST_SUB+=			SAMBA4_BUNDLED_TDB=""
SUB_LIST+=			SAMBA4_BUNDLED_TDB=""
.else
SAMBA4_BUNDLED_LIBS+=		!tdb
BUILD_DEPENDS+=			tdb1>=1.3.15:databases/tdb1
RUN_DEPENDS+=			tdb1>=1.3.15:databases/tdb1
PLIST_SUB+=			SAMBA4_BUNDLED_TDB="@comment "
SUB_LIST+=			SAMBA4_BUNDLED_TDB="@comment "
.endif
# ldb
.if defined(SAMBA4_BUNDLED_LDB) && ${SAMBA4_BUNDLED_LDB} == yes
SAMBA4_BUNDLED_LDB=		yes
SAMBA4_BUNDLED_LIBS+=		ldb
SAMBA4_BUILTIN_LIBS+=		ldb
CONFLICTS+=			ldb-1.* ldb1[23]-1.*
PLIST_SUB+=			SAMBA4_BUNDLED_LDB=""
SUB_LIST+=			SAMBA4_BUNDLED_LDB=""
.else
SAMBA4_BUNDLED_LIBS+=		!ldb
BUILD_DEPENDS+=			ldb13>=1.3.8:databases/ldb13
RUN_DEPENDS+=			ldb13>=1.3.8:databases/ldb13
PLIST_SUB+=			SAMBA4_BUNDLED_LDB="@comment "
SUB_LIST+=			SAMBA4_BUNDLED_LDB="@comment "
.endif

.if (defined(SAMBA4_BUNDLED_TALLOC)  && ${SAMBA4_BUNDLED_TEVENT} == yes) \
	|| (defined(SAMBA4_BUNDLED_TDB) && ${SAMBA4_BUNDLED_TDB} == yes) \
	|| (defined(SAMBA4_BUNDLED_LDB) && ${SAMBA4_BUNDLED_LDB} == yes) \
	|| (defined(SAMBA4_BUNDLED_TEVENT) && ${SAMBA4_BUNDLED_TEVENT} == yes)
SAMBA4_BUNDLED_LIBS+=		replace
SAMBA4_BUILTIN_LIBS+=		replace
.endif
# Don't use external libcom_err
SAMBA4_BUNDLED_LIBS+=		com_err
# Set the test environment variables
TEST_USES=			python
TEST_ENV+=			PYTHON="${PYTHON_CMD}" \
				SHA1SUM=/sbin/sha1 \
				SHA256SUM=/sbin/sha256 \
				MD5SUM=/sbin/md5
TEST_DEPENDS+=			bash:shells/bash \
				tshark:net/tshark
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
				--enable-gnutls \
				--with-libarchive \
				--with-acl-support \
				--with-sendfile-support \
				--disable-ctdb-tests \
				${ICONV_CONFIGURE_BASE}
##############################################################################
BIND911_RUN_DEPENDS=		bind911>=9.11.0.0:dns/bind911
BIND913_RUN_DEPENDS=		bind913>=9.13.0.0:dns/bind913
BIND914_RUN_DEPENDS=		bind914>=9.14.0.0:dns/bind914
NSUPDATE_RUN_DEPENDS=		samba-nsupdate:dns/samba-nsupdate

AVAHI_CONFIGURE_ENABLE=		avahi
AVAHI_LIB_DEPENDS=		libavahi-client.so:net/avahi-app
AVAHI_VARS=			SAMBA4_SERVICES+=avahi_daemon

MDNSRESPONDER_CONFIGURE_ENABLE=	dnssd
MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder
MDNSRESPONDER_VARS=		SAMBA4_SERVICES+=mdnsd
##############################################################################
DEBUG_CONFIGURE_ON=		--verbose --enable-debug
DEBUG_MAKE_ARGS=		--verbose
DEBUG_FLAGS=			-g -ggdb3 -O0

MEMORY_DEBUG_IMPLIES=		DEBUG
MEMORY_DEBUG_CONFIGURE_ENV=	ADDITIONAL_CFLAGS="-DENABLE_JEMALLOC `pkg-config --cflags jemalloc`" ADDITIONAL_LDFLAGS="`pkg-config --libs jemalloc`"
MEMORY_DEBUG_LIB_DEPENDS=	libjemalloc.so.2:devel/jemalloc
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=194046
GDB_CMD?=			${LOCALBASE}/bin/gdb
# https://bugzilla.samba.org/show_bug.cgi?id=8969
PICKY_DEVELOPER_IMPLIES=	DEVELOPER
PICKY_DEVELOPER_CONFIGURE_ON=	--picky-developer

DEVELOPER_IMPLIES=		NTVFS
DEVELOPER_CONFIGURE_ON=		--enable-developer --enable-selftest --abi-check-disable
DEVELOPER_BUILD_DEPENDS=	${GDB_CMD}:devel/gdb
DEVELOPER_TEST_DEPENDS=		${GDB_CMD}:devel/gdb
DEVELOPER_VARS_OFF=		GDB_CMD=true
# XXX: Mostly used in conjuction with the DEVELOPER option, don't enable it
# if you don't know what you are doing
NTVFS_CONFIGURE_WITH=		ntvfs-fileserver
NTVFS_PLIST_FILES=		lib/shared-modules/service/smb.so \
				lib/samba4/private/libntvfs-samba4.so
##############################################################################
CLUSTER_CONFIGURE_WITH=		cluster-support

CUPS_CONFIGURE_ENABLE=		cups iprint
CUPS_LIB_DEPENDS=		libcups.so:print/cups
# https://bugzilla.samba.org/show_bug.cgi?id=9545
FAM_USES=			fam
FAM_CONFIGURE_WITH=		fam

GLUSTERFS_CONFIGURE_ENABLE=	glusterfs
GLUSTERFS_LIB_DEPENDS=		libglusterfs.so:net/glusterfs
GLUSTERFS_VARS=			SAMBA4_MODULES+=vfs_glusterfs

GPGME_CONFIGURE_WITH=		gpgme
GPGME_LIB_DEPENDS=		libgpgme.so:security/gpgme

PROFILE_CONFIGURE_WITH=		profiling-data

QUOTAS_CONFIGURE_WITH=		quotas

SPOTLIGHT_CONFIGURE_ENABLE=	spotlight
SPOTLIGHT_BUILD_DEPENDS=	tracker>=1.4.1:sysutils/tracker
SPOTLIGHT_RUN_DEPENDS=		tracker>=1.4.1:sysutils/tracker
SPOTLIGHT_USES=			bison
SPOTLIGHT_USE=			gnome=glib20

SYSLOG_CONFIGURE_WITH=		syslog

UTMP_CONFIGURE_WITH=		utmp

AD_DC_CONFIGURE_OFF=		--without-ad-dc

ADS_IMPLIES=			LDAP
ADS_CONFIGURE_WITH=		ads dnsupdate

LDAP_CONFIGURE_WITH=		ldap
LDAP_CONFIGURE_ON=		--with-openldap=${LOCALBASE}
LDAP_USE=			OPENLDAP=yes
LDAP_VARS=			SAMBA4_MODULES+=idmap_ldap

GSSAPI_MIT_CONFIGURE_ON=	--with-system-mitkrb5 ${GSSAPIBASEDIR} \
				--with-system-mitkdc=${GSSAPIBASEDIR}/sbin/krb5kdc \
				--with-experimental-mit-ad-dc
GSSAPI_MIT_USES=		gssapi:mit

LIBZFS_CONFIGURE_WITH=		libzfs
LIBZFS_VARS=			SAMBA4_MODULES+=vfs_zfs_space

MANDOC_BUILD_DEPENDS=		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
				xsltproc:textproc/libxslt
MANDOC_CONFIGURE_ENV_OFF=	XSLTPROC="true"
# !SAMBA4_SUBPORT
.endif

##############################################################################
.include <bsd.port.options.mk>
##############################################################################

.if !defined(SAMBA4_SUBPORT)

.if !defined(WANT_EXP_MODULES) || empty(WANT_EXP_MODULES)
WANT_EXP_MODULES=		vfs_cacheprime
.endif

.if ${WANT_EXP_MODULES:Mvfs_snapper}
# snapper needs dbus
LIB_DEPENDS+=			libdbus-1.so:devel/dbus
LIB_DEPENDS+=			libdbus-glib-1.so:devel/dbus-glib
.endif

SAMBA4_MODULES+=		vfs_freebsd

SAMBA4_MODULES+=		idmap_nss idmap_autorid idmap_rid idmap_hash idmap_tdb idmap_tdb2 idmap_script nss-info_hash
# List of extra modules taken from RHEL build
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=197320
.if ${PORT_OPTIONS:MADS}
SAMBA4_MODULES+=		idmap_ad idmap_rfc2307 nss-info_template nss-info_rfc2307 nss-info_sfu nss-info_sfu20
.endif

.if ${PORT_OPTIONS:MDEVELOPER}
SAMBA4_MODULES+=		auth_skel pdb_test gpext_security gpext_registry gpext_scripts perfcount_test \
				vfs_fake_dfq vfs_skel_opaque vfs_skel_transparent vfs_shadow_copy_test vfs_fake_acls \
				vfs_nfs4acl_xattr vfs_error_inject vfs_delay_inject
.endif
# Python bindings
.if defined(NO_PYTHON)
USES+=				python:2.7,build,test
CONFIGURE_ARGS+=		--disable-python
PLIST_SUB+=			SAMBA4_PYTHON2="@comment "
SUB_LIST+=			SAMBA4_PYTHON2="@comment "
.else
USES+=				python:2.7
PLIST_SUB+=			SAMBA4_PYTHON2=""
SUB_LIST+=			SAMBA4_PYTHON2=""

.if !defined(SAMBA4_BUNDLED_TALLOC)
SAMBA4_BUNDLED_LIBS+=		!pytalloc-util
.else
SAMBA4_BUNDLED_LIBS+=		pytalloc-util
.endif

.if !defined(SAMBA4_BUNDLED_TEVENT)
SAMBA4_BUNDLED_LIBS+=		!pytevent
.else
SAMBA4_BUNDLED_LIBS+=		pytevent
.endif

.if !defined(SAMBA4_BUNDLED_TDB)
SAMBA4_BUNDLED_LIBS+=		!pytdb
.else
SAMBA4_BUNDLED_LIBS+=		pytdb
.endif

.if !defined(SAMBA4_BUNDLED_LDB)
SAMBA4_BUNDLED_LIBS+=		!pyldb !pyldb-util
.else
SAMBA4_BUNDLED_LIBS+=		pyldb pyldb-util
.endif
# External Python modules
BUILD_DEPENDS+=			${PYTHON_PKGNAMEPREFIX}dnspython>=1.15.0:dns/py-dnspython@${PY_FLAVOR}
RUN_DEPENDS+=			${PYTHON_PKGNAMEPREFIX}dnspython>=1.15.0:dns/py-dnspython@${PY_FLAVOR}

BUILD_DEPENDS+=			${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${PY_FLAVOR}
RUN_DEPENDS+=			${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${PY_FLAVOR}
.endif

.if defined(WANT_EXP_MODULES) && !empty(WANT_EXP_MODULES)
SAMBA4_MODULES+=		${WANT_EXP_MODULES}
.endif

.if defined(SAMBA4_BUNDLED_LIBS) && !empty(SAMBA4_BUNDLED_LIBS)
CONFIGURE_ARGS+=		--bundled-libraries="${SAMBA4_BUNDLED_LIBS:Q:C|(\\\\ )+|,|g:S|\\||g}"
CONFIGURE_ARGS+=		--builtin-libraries="${SAMBA4_BUILTIN_LIBS:Q:C|(\\\\ )+|,|g:S|\\||g}"
.endif

.if defined(SAMBA4_MODULES) && !empty(SAMBA4_MODULES)
CONFIGURE_ARGS+=		--with-shared-modules="${SAMBA4_MODULES:C|-|_|:Q:C|(\\\\ )+|,|g:S|\\||g}"
.endif
# XXX: Hack for nss-info_* -> nss_info/* modules
# Add selected modules to the plist
.for module in ${SAMBA4_MODULES}
PLIST_FILES+=			lib/shared-modules/${module:C|_|/|:C|-|_|}.so
.endfor
# !SAMBA4_SUBPORT
.endif

##############################################################################
.include <bsd.port.pre.mk>
##############################################################################

.if !defined(SAMBA4_SUBPORT)
# Require llvm 4.0 and AMD64
.if ${PORT_OPTIONS:MAESNI} && ${ARCH} == "amd64"
CONFIGURE_ARGS+=		--accel-aes=intelaesni
PLIST_FILES+=			lib/samba4/private/libaesni-intel-samba4.so
.else
CONFIGURE_ARGS+=		--accel-aes=none
.endif

.if ${PORT_OPTIONS:MGSSAPI_MIT}
PLIST_FILES+=			lib/shared-modules/krb5/winbind_krb5_localauth.so \
				man/man8/winbind_krb5_localauth.8.gz
.       if ${PORT_OPTIONS:MAD_DC}
PLIST_FILES+=			lib/samba4/krb5/plugins/kdb/samba.so
.       endif
.endif
# for libexecinfo: (so that __builtin_frame_address() finds the top of the stack)
CFLAGS_amd64+=			-fno-omit-frame-pointer
# No fancy color error messages
CONFIGURE_ENV+=			NOCOLOR=yes WAF_LOG_FORMAT='%(c1)s%(zone)s%(c2)s %(message)s'
MAKE_ENV+=			NOCOLOR=yes WAF_LOG_FORMAT='%(c1)s%(zone)s%(c2)s %(message)s'
.if ${CHOSEN_COMPILER_TYPE} == clang
CFLAGS+=			-fno-color-diagnostics
.endif
# Allow rpcgen ti find proper CPP
MAKE_ENV+=			RPCGEN_CPP="${CPP}"
#.if ${readline_ARGS} == port
#CFLAGS+=			-D_FUNCTION_DEF
#.endif
# Make sure that the right version of Python is used by the tools
# https://bugzilla.samba.org/show_bug.cgi?id=7305
SHEBANG_FILES=			${PATCH_WRKSRC}/source4/scripting/bin/* ${PATCH_WRKSRC}/selftest/*

SAMBA4_SUB=			SAMBA4_LOGDIR="${SAMBA4_LOGDIR}" \
				SAMBA4_RUNDIR="${SAMBA4_RUNDIR}" \
				SAMBA4_LOCKDIR="${SAMBA4_LOCKDIR}" \
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
				@${REINPLACE_CMD} -e '1s|/bin/bash|/bin/sh|' \
					 ${PATCH_WRKSRC}/ctdb/tools/onnode

# Use threading (or multiprocessing) but not thread (renamed in python 3+).
pre-configure:
.if ! ${PORT_OPTIONS:MAD_DC} && ${PORT_OPTIONS:MNTVFS}
				@${ECHO_CMD}; \
				${ECHO_MSG} "===>  NTVFS option requires AD_DC to be set"; \
				${ECHO_CMD}; \
				${FALSE}
.endif
				@if ! ${PYTHON_CMD} -c "import multiprocessing;" 2>/dev/null; then \
					${ECHO_CMD}; \
					${ECHO_MSG} "===>  ${PKGNAME} "${IGNORE_NONTHREAD_PYTHON:Q}.; \
					${ECHO_CMD}; \
					${FALSE}; \
				fi

pre-build-MANDOC-off:
				${MKDIR} ${BUILD_WRKSRC}/bin/default/docs-xml/
				${CP} -rp ${BUILD_WRKSRC}/docs/manpages ${BUILD_WRKSRC}/bin/default/docs-xml/
.for man in			libcli/nbt/man/nmblookup4.1 \
				librpc/tools/ndrdump.1 \
				source4/lib/registry/man/regdiff.1 \
				source4/lib/registry/man/regpatch.1 \
				source4/lib/registry/man/regshell.1 \
				source4/lib/registry/man/regtree.1 \
				source4/scripting/man/samba_gpoupdate.8 \
				source4/torture/man/gentest.1 \
				source4/torture/man/locktest.1 \
				source4/torture/man/masktest.1 \
				source4/torture/man/smbtorture.1 \
				source4/utils/man/ntlm_auth4.1 \
				source4/utils/man/oLschema2ldif.1 \
				lib/tdb/man/tdbdump.8 \
				lib/tdb/man/tdbbackup.8 \
				lib/tdb/man/tdbtool.8 \
				lib/talloc/man/talloc.3 \
				lib/tdb/man/tdbrestore.8 \
				lib/ldb/man/ldb.3 \
				lib/ldb/man/ldbadd.1 \
				lib/ldb/man/ldbsearch.1 \
				lib/ldb/man/ldbmodify.1 \
				lib/ldb/man/ldbrename.1 \
				lib/ldb/man/ldbdel.1 \
				lib/ldb/man/ldbedit.1
					${MKDIR} `dirname ${BUILD_WRKSRC}/bin/default/${man}`
					${INSTALL_MAN} ${FILESDIR}/man/`basename ${man}` ${BUILD_WRKSRC}/bin/default/${man}
.endfor
.if ${PORT_OPTIONS:MCLUSTER}
				${MKDIR} ${BUILD_WRKSRC}/bin/default/ctdb/
.	for man in		ctdb_diagnostics.1 ctdb.1 ctdbd_wrapper.1 ctdbd.1 \
				ltdbtool.1 onnode.1 ping_pong.1 ctdbd.conf.5 \
				ctdb.7 ctdb-statistics.7 ctdb-tunables.7
					${INSTALL_MAN} ${FILESDIR}/man/${man} ${BUILD_WRKSRC}/bin/default/ctdb/
.	endfor
.endif

post-install-rm-junk:
.if defined(NO_PYTHON)
				${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/samba/third_party/dns \
					 ${STAGEDIR}${PYTHON_SITELIBDIR}/samba/third_party/iso8601
.endif

post-install-fix-manpages:
.for f in vfs_aio_linux.8 vfs_btrfs.8 vfs_ceph.8 vfs_gpfs.8
				${RM} ${STAGEDIR}${PREFIX}/man/man8/${f}
.endfor
.if defined(SAMBA4_BUNDLED_LDB) && ${SAMBA4_BUNDLED_LDB} == yes
.	for f in ldbadd.1 ldbdel.1 ldbedit.1 ldbmodify.1 ldbrename.1 ldbsearch.1
				${MV} ${STAGEDIR}${PREFIX}/man/man1/${f} ${STAGEDIR}${PREFIX}/man/man1/samba-${f}
.	endfor
.endif
.if defined(SAMBA4_BUNDLED_TDB) && ${SAMBA4_BUNDLED_TDB} == yes
.	for f in tdbbackup.8 tdbdump.8 tdbrestore.8 tdbtool.8
				${MV} ${STAGEDIR}${PREFIX}/man/man8/${f} ${STAGEDIR}${PREFIX}/man/man8/samba-${f}
.	endfor
.endif

post-install: post-install-rm-junk post-install-fix-manpages
				${LN} -sf smb.conf.5.gz ${STAGEDIR}${PREFIX}/man/man5/smb4.conf.5.gz
# Run post-install script
.for dir in			${SAMBA4_LOGDIR} ${SAMBA4_RUNDIR} ${SAMBA4_LOCKDIR} ${SAMBA4_MODULEDIR}
					${INSTALL} -d -m 0755 "${STAGEDIR}${dir}"
.endfor
				${INSTALL} -d -m 0750 "${STAGEDIR}${SAMBA4_BINDDNSDIR}"
				${INSTALL} -d -m 0750 "${STAGEDIR}${SAMBA4_PRIVATEDIR}"
.for dir in			auth bind9 gensec gpext idmap ldb nss_info pdb perfcount process_model service vfs
					${INSTALL} -d -m 0755 "${STAGEDIR}${SAMBA4_MODULEDIR}/${dir}"
.endfor

post-install-DOCS-on:
				${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in			${PORTDOCS}
				${INSTALL_DATA} ${WRKDIR}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

# !SAMBA4_SUBPORT
.endif

.include <bsd.port.post.mk>
