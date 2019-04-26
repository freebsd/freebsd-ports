# Created by: timur@FreeBSD.org
# $FreeBSD$

PORTNAME?=			${SAMBA4_BASENAME}46
PORTVERSION?=			${SAMBA4_VERSION}
PORTREVISION?=			2
CATEGORIES?=			net
MASTER_SITES=			SAMBA/samba/stable SAMBA/samba/rc
DISTNAME=			${SAMBA4_DISTNAME}

MAINTAINER?=			timur@FreeBSD.org
COMMENT?=			Free SMB/CIFS and AD/DC server and client for Unix

LICENSE=			GPLv3+
LICENSE_FILE=			${WRKSRC}/COPYING

BROKEN_powerpc64=		fails to compile: unrecognized command line option "-Wno-format-truncation"

IGNORE_NONTHREAD_PYTHON=	needs port lang/python${PYTHON_SUFFIX} to be build with THREADS support

CONFLICTS_INSTALL?=		samba4-4.0.* samba4[1-57-9]-4.* p5-Parse-Pidl-4.*

SAMBA4_BASENAME=		samba
SAMBA4_PORTNAME=		${SAMBA4_BASENAME}4
SAMBA4_VERSION=			4.6.16
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
				--with-privatedir="${SAMBA4_PRIVATEDIR}" \
				--with-logfilebase="${SAMBA4_LOGDIR}"
# Flags
CONFIGURE_ENV+=			PTHREAD_LDFLAGS="-lpthread"

USES=				cpe compiler waf pkgconfig perl5 python:2.7 \
				readline iconv shebangfix
USE_PERL5=			build
USE_LDCONFIG=			${SAMBA4_LIBDIR}
WAF_CMD=			buildtools/bin/waf
CONFIGURE_LOG=			bin/config.log

PKGCONFIGDIR?=			${PREFIX}/libdata/pkgconfig
PKGCONFIGDIR_REL?=		${PKGCONFIGDIR:S,^${PREFIX}/,,}
PLIST_SUB+=			PKGCONFIGDIR=${PKGCONFIGDIR_REL}
##############################################################################
# Options
OPTIONS_SUB=			yes

OPTIONS_DEFINE=			ADS AD_DC CUPS \
				DOCS FAM LDAP \
				QUOTAS SYSLOG UTMP

OPTIONS_DEFAULT:=		${OPTIONS_DEFINE}

AD_DC_DESC=			Active Directory Domain Controller support
ADS_DESC=			Active Directory client support(implies LDAP)
EXP_MODULES_DESC=		Experimental modules(WANT_EXP_MODULES)
FAM_DESC=			File Alteration Monitor support
LDAP_DESC=			LDAP client support
PAM_SMBPASS_DESC=		PAM authentication via passdb backends
QUOTAS_DESC=			Disk quota support
UTMP_DESC=			UTMP accounting support
##############################################################################
OPTIONS_DEFINE+=		CUPS DEBUG DEVELOPER MANPAGES EXP_MODULES NTVFS

DEVELOPER_DESC=			With development support(implies NTVFS)
MANPAGES_DESC=			Build manpages from DOCBOOK templates
NTVFS_DESC=			Build *DEPRECATED* NTVFS file server

OPTIONS_RADIO=			DNS ZEROCONF
OPTIONS_RADIO_DNS=		NSUPDATE BIND911
OPTIONS_RADIO_ZEROCONF=		AVAHI MDNSRESPONDER

BIND911_DESC=			Use Bind 9.11 as AD DC DNS server frontend
NSUPDATE_DESC=			Use samba NSUPDATE utility for AD DC
# XXX: Unconditional dependencies which can't be switched off(if present in the system)
# popt
LIB_DEPENDS+=			libpopt.so:devel/popt
# inotify
LIB_DEPENDS+=			libinotify.so:devel/libinotify
# GNUTLS
LIB_DEPENDS+=			libgnutls.so:security/gnutls
# NFS4 ACL glue
LIB_DEPENDS+=			libsunacl.so:sysutils/libsunacl
# Libarchive
BUILD_DEPENDS+=			libarchive>=3.1.2:archivers/libarchive
RUN_DEPENDS+=			libarchive>=3.1.2:archivers/libarchive
# External Samba dependencies
# Needed for IDL compiler
BUILD_DEPENDS+=			p5-Parse-Yapp>=0:devel/p5-Parse-Yapp
# External Python modules
BUILD_DEPENDS+=			${PYTHON_PKGNAMEPREFIX}dnspython>=1.9.4:dns/py-dnspython@${PY_FLAVOR}
RUN_DEPENDS+=			${PYTHON_PKGNAMEPREFIX}dnspython>=1.9.4:dns/py-dnspython@${PY_FLAVOR}
PLIST_SUB+=			PY_DNSPYTHON="@comment "
#
BUILD_DEPENDS+=			${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${PY_FLAVOR}
RUN_DEPENDS+=			${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${PY_FLAVOR}
PLIST_SUB+=			PY_ISO8601="@comment "
# talloc
BUILD_DEPENDS+=			talloc>=2.1.9:devel/talloc
RUN_DEPENDS+=			talloc>=2.1.9:devel/talloc
SAMBA4_BUNDLED_LIBS+=		!talloc
# tevent
BUILD_DEPENDS+=			tevent>=0.9.34:devel/tevent
RUN_DEPENDS+=			tevent>=0.9.34:devel/tevent
SAMBA4_BUNDLED_LIBS+=		!tevent
# tdb
BUILD_DEPENDS+=			tdb>=1.3.12:databases/tdb
RUN_DEPENDS+=			tdb>=1.3.12:databases/tdb
SAMBA4_BUNDLED_LIBS+=		!tdb
# ldb
BUILD_DEPENDS+=			ldb>=1.1.29:databases/ldb
RUN_DEPENDS+=			ldb>=1.1.29:databases/ldb
SAMBA4_BUNDLED_LIBS+=		!ldb
# Don't use external libcom_err, cmocka
SAMBA4_BUNDLED_LIBS+=		com_err,cmocka

CONFIGURE_ARGS+=		\
				--with-pam \
				--with-iconv \
				--with-winbind \
				--disable-rpath \
				--without-gettext \
				--enable-pthreadpool \
				--with-acl-support \
				--with-sendfile-support \
				${ICONV_CONFIGURE_BASE}

BIND911_RUN_DEPENDS=		bind911>=9.11.0.0:dns/bind911
NSUPDATE_RUN_DEPENDS=		samba-nsupdate:dns/samba-nsupdate

DEBUG_CONFIGURE_ON=		--verbose --enable-debug
DEBUG_MAKE_ARGS=		--verbose
DEBUG_VARS=			WITH_DEBUG=yes

# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=194046
GDB_CMD?=			${LOCALBASE}/bin/gdb
# https://bugzilla.samba.org/show_bug.cgi?id=8969
DEVELOPER_IMPLIES=		NTVFS
DEVELOPER_BUILD_DEPENDS=	${GDB_CMD}:devel/gdb
DEVELOPER_RUN_DEPENDS=		${GDB_CMD}:devel/gdb
DEVELOPER_CONFIGURE_ON=		--enable-developer --enable-selftest --abi-check-disable
DEVELOPER_VARS_OFF=		GDB_CMD=true
# XXX: Mostly used in conjuction with DEVELOPER option, don't enable it if you don't know what you are doing
NTVFS_CONFIGURE_WITH=		ntvfs-fileserver
##############################################################################
AVAHI_CONFIGURE_ENABLE=		avahi
AVAHI_LIB_DEPENDS=		libavahi-client.so:net/avahi-app

MDNSRESPONDER_CONFIGURE_ENABLE=	dnssd
MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder

CUPS_CONFIGURE_ENABLE=		cups iprint
CUPS_LIB_DEPENDS=		libcups.so:print/cups

# https://bugzilla.samba.org/show_bug.cgi?id=9545
FAM_USES=			fam
FAM_CONFIGURE_WITH=		fam

QUOTAS_CONFIGURE_WITH=		quotas

SYSLOG_CONFIGURE_WITH=		syslog

UTMP_CONFIGURE_WITH=		utmp

AD_DC_CONFIGURE_OFF=		--without-ad-dc

#NTVFS_PREVENTS=			AD_DC
#NTVFS_PREVENTS_MSG=		NTVFS needs AD_DC

ADS_IMPLIES=			LDAP
ADS_CONFIGURE_WITH=		ads dnsupdate

LDAP_CONFIGURE_WITH=		ldap
LDAP_USE=			OPENLDAP=yes
LDAP_VARS=			SAMBA4_MODULES+=idmap_ldap

MANPAGES_BUILD_DEPENDS=		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
				xsltproc:textproc/libxslt
MANPAGES_CONFIGURE_ENV_OFF=	XSLTPROC="true"

# !SAMBA4_SUBPORT
.endif

##############################################################################
.include <bsd.port.options.mk>
##############################################################################

.if !defined(SAMBA4_SUBPORT)

.if ${PORT_OPTIONS:MEXP_MODULES}
.	if !defined(WANT_EXP_MODULES) || empty(WANT_EXP_MODULES)
WANT_EXP_MODULES=		vfs_cacheprime
.	endif
.endif

SAMBA4_MODULES+=		idmap_nss idmap_autorid idmap_rid idmap_hash idmap_tdb idmap_tdb2 idmap_script nss-info_hash
# List of extra modules taken from RHEL build
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=197320
.if ${PORT_OPTIONS:MADS}
SAMBA4_MODULES+=		idmap_ad idmap_rfc2307 nss-info_template nss-info_rfc2307 nss-info_sfu nss-info_sfu20
.endif

.if ${PORT_OPTIONS:MDEVELOPER}
SAMBA4_MODULES+=		auth_skel pdb_test gpext_security gpext_registry gpext_scripts perfcount_test \
				vfs_fake_dfq vfs_skel_opaque vfs_skel_transparent vfs_shadow_copy_test vfs_fake_acls \
				vfs_nfs4acl_xattr vfs_error_inject
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
PLIST_FILES+=			lib/shared-modules/${module:C|_|/|:C|-|_|}.so
.endfor
# !SAMBA4_SUBPORT
.endif

##############################################################################
.include <bsd.port.pre.mk>
##############################################################################

.if !defined(SAMBA4_SUBPORT)
SAMBA4_SUB=			SAMBA4_LOGDIR="${SAMBA4_LOGDIR}" \
				SAMBA4_RUNDIR="${SAMBA4_RUNDIR}" \
				SAMBA4_LOCKDIR="${SAMBA4_LOCKDIR}" \
				SAMBA4_MODULEDIR="${SAMBA4_MODULEDIR}" \
				SAMBA4_PRIVATEDIR="${SAMBA4_PRIVATEDIR}" \
				SAMBA4_CONFDIR="${SAMBA4_CONFDIR}" \
				SAMBA4_CONFIG="${SAMBA4_CONFIG}"

PLIST_SUB+=			${SAMBA4_SUB}
SUB_LIST+=			${SAMBA4_SUB}

USE_RC_SUBR=			samba_server
SUB_FILES=			pkg-message README.FreeBSD
# Make sure that the right version of Python is used by the tools
# https://bugzilla.samba.org/show_bug.cgi?id=7305
SHEBANG_FILES=			${PATCH_WRKSRC}/source4/scripting/bin/*
# No fancy color error messages

# for libexecinfo: (so that __builtin_frame_address() finds the top of the stack)
.if ${ARCH} == "amd64"
CFLAGS+=			-fno-omit-frame-pointer
.endif
.if ${CHOSEN_COMPILER_TYPE} == clang
CFLAGS+=			-fno-color-diagnostics
.endif
.if ${readline_ARGS} == port
CFLAGS+=			-D_FUNCTION_DEF
.endif
CONFIGURE_ENV+=			NOCOLOR=yes WAF_LOG_FORMAT='%(c1)s%(zone)s%(c2)s %(message)s'
MAKE_ENV+=			NOCOLOR=yes WAF_LOG_FORMAT='%(c1)s%(zone)s%(c2)s %(message)s'

SAMBA_MAN1+=			dbwrap_tool.1 findsmb.1 gentest.1 locktest.1 \
				log2pcap.1 masktest.1 mvxattr.1 ndrdump.1 nmblookup.1 \
				nmblookup4.1 ntlm_auth.1 oLschema2ldif.1 \
				profiles.1 regdiff.1 regpatch.1 regshell.1 \
				regtree.1 rpcclient.1 sharesec.1 smbcacls.1 \
				smbclient.1 smbcontrol.1 smbcquotas.1 smbget.1 \
				smbstatus.1 smbtar.1 smbtorture.1 smbtree.1 \
				testparm.1 vfstest.1 wbinfo.1

SAMBA_MAN5+=			lmhosts.5 smbgetrc.5 smbpasswd.5 pam_winbind.conf.5 \
				smb.conf.5

SAMBA_MAN7+=			libsmbclient.7 samba.7 winbind_krb5_locator.7

SAMBA_MAN8+=			cifsdd.8 eventlogadm.8 idmap_ad.8 idmap_autorid.8 idmap_hash.8 \
				idmap_ldap.8 idmap_nss.8 idmap_rfc2307.8 idmap_rid.8 idmap_script.8 \
				idmap_tdb.8 idmap_tdb2.8 net.8 nmbd.8 pam_winbind.8 pdbedit.8 \
				samba-regedit.8 samba-tool.8 samba.8 smbd.8 smbpasswd.8 \
				smbspool_krb5_wrapper.8 smbspool.8 smbta-util.8 vfs_acl_tdb.8 vfs_acl_xattr.8 \
				vfs_aio_fork.8 vfs_aio_linux.8 vfs_aio_pthread.8 \
				vfs_audit.8 vfs_cacheprime.8 vfs_cap.8 vfs_catia.8 vfs_ceph.8 \
				vfs_commit.8 vfs_crossrename.8 vfs_default_quota.8 \
				vfs_dirsort.8 vfs_extd_audit.8 vfs_fake_perms.8 vfs_fileid.8 \
				vfs_fruit.8 vfs_full_audit.8 vfs_glusterfs.8 vfs_gpfs.8 vfs_media_harmony.8 \
				vfs_netatalk.8 vfs_offline.8 vfs_prealloc.8 \
				vfs_preopen.8 vfs_readahead.8 vfs_readonly.8 \
				vfs_recycle.8 vfs_scannedonly.8 vfs_shadow_copy.8 \
				vfs_shadow_copy2.8 vfs_snapper.8 vfs_smb_traffic_analyzer.8 \
				vfs_streams_depot.8 vfs_streams_xattr.8 vfs_syncops.8 vfs_time_audit.8 \
				vfs_tsmsm.8 vfs_worm.8 vfs_xattr_tdb.8 winbindd.8 \
				vfs_linux_xfs_sgid.8 vfs_btrfs.8 vfs_shell_snap.8 vfs_unityed_media.8 vfs_zfsacl.8

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
				@if ! ${PYTHON_CMD} -c "import multiprocessing;" 2>/dev/null; then \
					${ECHO_CMD}; \
					${ECHO_MSG} "===>  ${PKGNAME} "${IGNORE_NONTHREAD_PYTHON:Q}.; \
					${ECHO_CMD}; \
					${FALSE}; \
				fi

pre-build-MANPAGES-off:
.for man in			libcli/nbt/man/nmblookup4.1 \
				librpc/tools/ndrdump.1 \
				source4/lib/registry/man/regdiff.1 \
				source4/lib/registry/man/regpatch.1 \
				source4/lib/registry/man/regshell.1 \
				source4/lib/registry/man/regtree.1 \
				source4/torture/man/gentest.1 \
				source4/torture/man/locktest.1 \
				source4/torture/man/masktest.1 \
				source4/torture/man/smbtorture.1 \
				source4/utils/man/ntlm_auth4.1 \
				source4/utils/man/oLschema2ldif.1
					-@${MKDIR} `dirname ${BUILD_WRKSRC}/bin/default/${man}`
					${INSTALL_MAN} ${FILESDIR}/man/`basename ${man}` ${BUILD_WRKSRC}/bin/default/${man}
.endfor
				-@${MKDIR} ${BUILD_WRKSRC}/bin/default/docs-xml/manpages
.for man in			${SAMBA_MAN1} ${SAMBA_MAN5} ${SAMBA_MAN7} ${SAMBA_MAN8}
					-${INSTALL_MAN} ${BUILD_WRKSRC}/docs/manpages/${man} ${BUILD_WRKSRC}/bin/default/docs-xml/manpages
.endfor

post-install:
				${LN} -sf smb.conf.5.gz ${STAGEDIR}${PREFIX}/man/man5/smb4.conf.5.gz
# Run post-install script
.for dir in			${SAMBA4_LOGDIR} ${SAMBA4_RUNDIR} ${SAMBA4_LOCKDIR} ${SAMBA4_MODULEDIR}
					${INSTALL} -d -m 0755 "${STAGEDIR}${dir}"
.endfor
				${INSTALL} -d -m 0700 "${STAGEDIR}${SAMBA4_PRIVATEDIR}"
.for dir in			auth bind9 gensec gpext idmap ldb nss_info pdb perfcount process_model service vfs
					${INSTALL} -d -m 0755 "${STAGEDIR}${SAMBA4_MODULEDIR}/${dir}"
.endfor

post-install-DOCS-on:
				${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in			${PORTDOCS}
				${INSTALL_DATA} ${WRKDIR}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.if ${PORT_OPTIONS:MDEVELOPER}
test: build
				@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${INSTALL_WRKSRC}/${WAF_CMD} ${MAKE_ARGS} $@)
.endif

# !SAMBA4_SUBPORT
.endif

.include <bsd.port.post.mk>
