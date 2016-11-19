# $FreeBSD$

PORTNAME=		${SAMBA_BASENAME}36
PORTVERSION=		3.6.25
PORTREVISION?=		3
CATEGORIES?=		net
MASTER_SITES=		SAMBA/samba SAMBA/samba/stable SAMBA/samba/pre
DISTNAME=		${SAMBA_BASENAME}-${PORTVERSION:S|.p|pre|:S|.r|rc|:S|.t|tp|:S|.a|alpha|}
PATCH_SITES=		https://www.samba.org/samba/ftp/patches/security/
PATCHFILES=		samba-3.6.25-security-2015-12-16.patch:-p1

MAINTAINER?=		timur@FreeBSD.org
COMMENT?=		Free SMB and CIFS client and server for Unix

LICENSE=		GPLv3
LICENSE_FILE=		${WRKDIR}/${DISTNAME}/COPYING

CONFLICTS?=		*samba3[2-5]-3.*

DEPRECATED=		not supported by the upstream

# Additional patches from Sernet.de
PATCH_STRIP=		-p1
EXTRA_PATCHES=		${PATCHDIR}/sernet.patch

SAMBA_BASENAME=		samba
CPE_VENDOR=		samba
CPE_PRODUCT=		samba

EXAMPLESDIR=		${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
PATCH_WRKSRC=		${WRKDIR}/${DISTNAME}
WRKSRC=			${WRKDIR}/${DISTNAME}/source3
IPATHS=			-I${WRKDIR}/${DISTNAME}/source3/m4 -I${WRKDIR}/${DISTNAME}/m4 -I${WRKDIR}/${DISTNAME}/lib/replace -I${WRKDIR}/${DISTNAME}/source4
AUTOHEADER_ARGS=	${IPATHS}
AUTOCONF_ARGS=		${IPATHS}

GNU_CONFIGURE=		yes
USES=			cpe execinfo gmake iconv pkgconfig shebangfix
SHEBANG_FILES=		../examples/LDAP/convertSambaAccount \
			../examples/LDAP/get_next_oid \
			../examples/LDAP/ol-schema-migrate.pl \
			../examples/ad-bench/ad-bench.sh \
			../examples/misc/adssearch.pl \
			../examples/misc/check_multiple_LDAP_entries.pl \
			../examples/misc/cldap.pl \
			../examples/printing/smbprint \
			../examples/scripts/idmap/idmap_nis.sh \
			../examples/scripts/printing/cups/smbaddprinter.pl \
			../examples/scripts/printing/cups/smbdelprinter.pl \
			../examples/scripts/shares/perl/modify_samba_config.pl \
			../examples/scripts/users_and_groups/adduserstogroups.pl \
			../examples/scripts/users_and_groups/createdomobj.pl
USE_AUTOTOOLS=		autoconf autoheader
USE_LDCONFIG=		${SAMBA_LIBDIR}
# pkg-config is used to find talloc
PKGCONFIGDIR?=		${PREFIX}/libdata/pkgconfig
PKGCONFIGDIR_REL?=	${PKGCONFIGDIR:S|^${PREFIX}/||}
# directories
VARDIR?=		/var
SAMBA_SPOOL?=		${VARDIR}/spool/${SAMBA_BASENAME}
SAMBA_LOGDIR=		${VARDIR}/log/${SAMBA_BASENAME}
SAMBA_RUNDIR=		${VARDIR}/run/${SAMBA_BASENAME}
SAMBA_LOCKDIR?=		${VARDIR}/db/${SAMBA_BASENAME}
SAMBA_CONFIG?=		smb.conf
SAMBA_CONFDIR?=		${PREFIX}/etc
RC_DIR=			${PREFIX}/etc/rc.d
SAMBA_SWATDIR=		${PREFIX}/share/swat
SAMBA_LIBDIR=		${PREFIX}/lib
SAMBA_MODULEDIR=	${SAMBA_LIBDIR}/${SAMBA_BASENAME}
SAMBA_INCLUDEDIR=	${PREFIX}/include/${SAMBA_BASENAME}
SAMBA_PRIVATEDIR?=	${SAMBA_CONFDIR}/${SAMBA_BASENAME}

CONFIGURE_ARGS+=	--exec-prefix="${PREFIX}" \
			--sysconfdir="${SAMBA_CONFDIR}" \
			--with-configdir="${SAMBA_CONFDIR}" \
			--includedir="${SAMBA_INCLUDEDIR}" \
			--datadir="${DATADIR}" \
			--with-swatdir="${SAMBA_SWATDIR}" \
			--libdir="${SAMBA_LIBDIR}" \
			--with-pammodulesdir="${SAMBA_LIBDIR}" \
			--with-modulesdir="${SAMBA_MODULEDIR}" \
			--localstatedir="${VARDIR}" \
			--with-piddir="${SAMBA_RUNDIR}" \
			--with-ncalrpcdir="${SAMBA_RUNDIR}/ncalrpc" \
			--with-nmbdsocketdir="${SAMBA_RUNDIR}/nmbd" \
			--with-lockdir="${SAMBA_LOCKDIR}" \
			--with-statedir="${SAMBA_LOCKDIR}" \
			--with-cachedir="${SAMBA_LOCKDIR}" \
			--with-privatedir="${SAMBA_PRIVATEDIR}" \
			--with-logfilebase="${SAMBA_LOGDIR}"

CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

CONFIGURE_ENV+=		PTHREAD_LDFLAGS="-lpthread"
# XXX: Temporary hack for RELENG6
CONFIGURE_ENV+=		ac_cv_header_sys_mount_h=yes
# XXX: readdir test fails on ZFS, bringing unusable replacement code
CONFIGURE_ENV+=		libreplace_cv_READDIR_NEEDED=no
# tdb
BUILD_DEPENDS+=		tdb>=1.2.6:databases/tdb
RUN_DEPENDS+=		tdb>=1.2.6:databases/tdb
CONFIGURE_ARGS+=	--without-libtdb --enable-external-libtdb
# talloc
BUILD_DEPENDS+=		talloc>=2.0.1:devel/talloc
RUN_DEPENDS+=		talloc>=2.0.1:devel/talloc
CONFIGURE_ARGS+=	--without-libtalloc --enable-external-libtalloc
# tevent
BUILD_DEPENDS+=		tevent>=0.9.11:devel/tevent
RUN_DEPENDS+=		tevent>=0.9.11:devel/tevent
CONFIGURE_ARGS+=	--without-libtevent --enable-external-libtevent
# These options are common for all (sub)ports
CONFIGURE_ARGS+=	${ICONV_CONFIGURE_BASE} \
			--disable-as-needed

.if !defined(SAMBA_SUBPORT)
OPTIONS_DEFINE=		ACL_SUPPORT ADS AIO_SUPPORT AVAHI CUPS DNSUPDATE \
			DOCS EXAMPLES EXP_MODULES FAM IPV6 LDAP \
			MAX_DEBUG PAM_SMBPASS POPT PTHREADPOOL QUOTAS \
			SMBTORTURE SWAT SYSLOG UTMP WINBIND
OPTIONS_RADIO=		GSSAPI
OPTIONS_RADIO_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE

OPTIONS_DEFAULT=	ACL_SUPPORT AIO_SUPPORT CUPS LDAP POPT PTHREADPOOL \
			WINBIND GSSAPI_NONE

ACL_SUPPORT_DESC=	ACL support

ADS_DESC=		Active Directory support
ADS_CONFIGURE_ON=	--with-ads --with-krb5="${GSSAPIBASEDIR}"
ADS_CONFIGURE_OFF=	--without-ads --without-krb5

AIO_SUPPORT_DESC=	Asyncronous IO support
DNSUPDATE_DESC=		Dynamic DNS update(require ADS)
EXP_MODULES_DESC=	Experimental modules

GSSAPI_BASE_DESC=	Use Heimdal in base
GSSAPI_BASE_USES=	gssapi
GSSAPI_HEIMDAL_DESC=	Use Heimdal from ports
GSSAPI_HEIMDAL_USES=	gssapi:heimdal,flags
GSSAPI_MIT_DESC=	Use MIT Kerberos V5
GSSAPI_MIT_USES=	gssapi:mit,flags
GSSAPI_NONE_DESC=	No Kerberos support

MAX_DEBUG_DESC=		Maximum debugging
PAM_SMBPASS_DESC=	PAM authentication via passdb backends
POPT_DESC=		System-wide POPT library
PTHREADPOOL_DESC=	Pthread pool
QUOTAS_DESC=		Disk quota support
SMBTORTURE_DESC=	smbtorture
SWAT_DESC=		SWAT WebGUI
UTMP_DESC=		UTMP accounting support
WINBIND_DESC=		WinBIND support

# !SAMBA_SUBPORT
.endif

.include <bsd.port.options.mk>

# There are reports that on ARM PIE makes binaries to core dump(#149186)
.if ${ARCH} == "arm"
CONFIGURE_ARGS+=	--disable-pie
.endif

.if defined(SAMBA_SUBPORT)
# Switch off all extra functionality
CONFIGURE_ARGS+=	--disable-cups --disable-fam --without-winbind \
			--without-syslog --without-quotas --without-utmp \
			--without-pam --without-pam_smbpass \
			--without-aio-support --with-included-popt
.else
# Samba server itself
USE_RC_SUBR=		${SAMBA_BASENAME}
SUB_FILES=		pkg-message smb.conf.sample

PLIST=			${WRKDIR}/.PLIST
# We don't (yet) have clustered FS for cluster support
CONFIGURE_ARGS+=	--with-pam --with-readline=/usr \
			--with-included-iniparser \
			--with-sendfile-support \
			--enable-largefile \
			--without-cluster-support \
			--without-libsmbclient \
			--without-libaddns \
			--without-libnetapi \
			--without-libsmbsharemodes

.if ! ${PORT_OPTIONS:MIPV6}
CONFIGURE_ENV+=		libreplace_cv_HAVE_IPV6=no
.endif

.if ${PORT_OPTIONS:MLDAP}
SAMBA_WANT_LDAP=	yes
.endif

.if ${PORT_OPTIONS:MCUPS}
LIB_DEPENDS+=		libcups.so:print/cups
CONFIGURE_ARGS+=	--enable-cups --enable-iprint
SUB_LIST+=		CUPS=""
.else
CONFIGURE_ARGS+=	--disable-cups --disable-iprint
SUB_LIST+=		CUPS="@comment "
.endif

.if ${PORT_OPTIONS:MMAX_DEBUG}
CPPFLAGS+=		-g
LDFLAGS+=		-g
LIB_DEPENDS+=		libdmalloc.so:devel/dmalloc
CONFIGURE_ARGS+=	--enable-debug
#			--enable-socket-wrapper --enable-nss-wrapper \
#			--enable-developer --enable-krb5developer \
#			--enable-dmalloc --with-profiling-data

CONFIGURE_ARGS+=	--with-smbtorture4-path=${WRKDIR}/${DISTNAME}/source4/torture
.else
CONFIGURE_ARGS+=	--disable-debug \
			--disable-socket-wrapper --disable-nss-wrapper \
			--disable-developer --disable-krb5developer \
			--disable-dmalloc --without-profiling-data
.endif

.if ${PORT_OPTIONS:MSYSLOG}
CONFIGURE_ARGS+=	--with-syslog
.else
CONFIGURE_ARGS+=	--without-syslog
.endif

.if ${PORT_OPTIONS:MQUOTAS}
CONFIGURE_ARGS+=	--with-quotas
.else
CONFIGURE_ARGS+=	--without-quotas
.endif

.if ${PORT_OPTIONS:MUTMP}
CONFIGURE_ARGS+=	--with-utmp
.else
CONFIGURE_ARGS+=	--without-utmp
.endif

.if ${PORT_OPTIONS:MWINBIND}
CONFIGURE_ARGS+=	--with-winbind
PLIST_SUB+=		WINBIND=""
SUB_LIST+=		WINBIND=""
.else
CONFIGURE_ARGS+=	--without-winbind
PLIST_SUB+=		WINBIND="@comment "
SUB_LIST+=		WINBIND="@comment "
.endif

.if ${PORT_OPTIONS:MSWAT}
CONFIGURE_ARGS+=	--enable-swat
PLIST_SUB+=		SWAT=""
.else
CONFIGURE_ARGS+=	--disable-swat
PLIST_SUB+=		SWAT="@comment "
.endif
# Add some shared modules
.if ${PORT_OPTIONS:MEXP_MODULES}
.	if !defined(WANT_EXP_MODULES) || empty(WANT_EXP_MODULES)
WANT_EXP_MODULES=	idmap_tdb2 idmap_ad idmap_adex idmap_hash idmap_rid \
			charset_weird
.		if ! ${PORT_OPTIONS:MMAX_DEBUG}
WANT_EXP_MODULES+=	rpc_echo
.		endif
WANT_EXP_MODULES+=	vfs_cacheprime vfs_catia vfs_commit vfs_dirsort \
			vfs_readahead vfs_streams_depot vfs_syncops
.	endif
.endif

.if ${PORT_OPTIONS:MFAM}
USES+=			fam
WANT_EXP_MODULES+=	vfs_notify_fam
CONFIGURE_ARGS+=	--enable-fam
.else
CONFIGURE_ARGS+=	--disable-fam
.endif

.if ${PORT_OPTIONS:MACL_SUPPORT}
CONFIGURE_ARGS+=	--with-acl-support
WANT_EXP_MODULES+=	vfs_zfsacl
LIB_DEPENDS+=		libsunacl.so:sysutils/libsunacl
.else
CONFIGURE_ARGS+=	--without-acl-support
.endif

.if ${PORT_OPTIONS:MAIO_SUPPORT}
CONFIGURE_ARGS+=	--with-aio-support
.else
CONFIGURE_ARGS+=	--without-aio-support
.endif

.if ${PORT_OPTIONS:MPAM_SMBPASS}
CONFIGURE_ARGS+=	--with-pam_smbpass
PLIST_SUB+=		SMBPASS=""
.else
CONFIGURE_ARGS+=	--without-pam_smbpass
PLIST_SUB+=		SMBPASS="@comment "
.endif

.if ${PORT_OPTIONS:MDNSUPDATE}
.	if ! ${PORT_OPTIONS:MADS}
IGNORE=			dynamic DNS updates require ADS support. Disable DNSUPDATE support
.	endif
LIB_DEPENDS+=		libuuid.so:misc/e2fsprogs-libuuid
CONFIGURE_ARGS+=	--with-dnsupdate
.else
CONFIGURE_ARGS+=	--without-dnsupdate
.endif

.if ${PORT_OPTIONS:MAVAHI}
CPPFLAGS+=		`pkg-config --cflags avahi-client`
CONFIGURE_ENV+=		DNSSD_LIBS="`pkg-config --libs avahi-client`"
LIB_DEPENDS+=		libavahi-client.so:net/avahi-app
CONFIGURE_ARGS+=	--enable-avahi
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

.if ${PORT_OPTIONS:MPTHREADPOOL}
CONFIGURE_ARGS+=	--enable-pthreadpool
.else
CONFIGURE_ARGS+=	--disable-pthreadpool
.endif

.if ${PORT_OPTIONS:MPOPT}
LIB_DEPENDS+=		libpopt.so:devel/popt
CONFIGURE_ARGS+=	--without-included-popt
.else
CONFIGURE_ARGS+=	--with-included-popt
.endif

.if ${PORT_OPTIONS:MSMBTORTURE}
PLIST_SUB+=		SMBTORTURE=""
.else
PLIST_SUB+=		SMBTORTURE="@comment "
.endif
# !SAMBA_SUBPORT
.endif

###
### Common part for port and it's subports
###

.if ${PORT_OPTIONS:MADS}
.	if ${PORT_OPTIONS:MGSSAPI_NONE}
# Kerberos5 is necessary for ADS
IGNORE=	ADS support requires GSSAPI_BASE, GSSAPI_HEIMDAL, or GSSAPI_MIT
.	endif
SAMBA_WANT_LDAP=	yes
.endif

.if defined(SAMBA_WANT_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if defined(WANT_EXP_MODULES) && !empty(WANT_EXP_MODULES)
CONFIGURE_ARGS+=	--with-shared-modules="${WANT_EXP_MODULES:Q:C/(\\\\ )+/,/g}"
.endif

.include <bsd.port.pre.mk>

post-patch:
		@${REINPLACE_CMD} -e 's|%%SAMBA_CONFIG%%|${SAMBA_CONFIG}|g' \
		    ${WRKSRC}/Makefile.in
		@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		    ${WRKSRC}/configure.in ${WRKSRC}/m4/aclocal.m4
		${REINPLACE_CMD} -e '\|^Libs:|d; s|^#Libs:|Libs:|g' \
		    ${WRKSRC}/pkgconfig/*.pc.in
###
### end of common part
###

.if !defined(SAMBA_SUBPORT)
# Samba server only
SAMBA_MAN1=	dbwrap_tool.1 findsmb.1 \
		log2pcap.1 nmblookup.1 ntlm_auth.1 profiles.1 rpcclient.1 \
		sharesec.1 smbcacls.1 smbclient.1 smbcontrol.1 smbcquotas.1 \
		smbget.1 smbstatus.1 smbtar.1 smbtree.1 testparm.1 vfstest.1
SAMBA_MAN5=	lmhosts.5 smb.conf.5 smbgetrc.5 smbpasswd.5
SAMBA_MAN7=	samba.7
SAMBA_MAN8=	eventlogadm.8 net.8 nmbd.8 pdbedit.8 smbd.8 smbpasswd.8 \
		smbspool.8 idmap_nss.8 idmap_tdb.8 idmap_tdb2.8 \
		vfs_acl_tdb.8 vfs_acl_xattr.8 \
		vfs_audit.8 vfs_cap.8 vfs_default_quota.8 vfs_extd_audit.8 \
		vfs_fake_perms.8 vfs_full_audit.8 vfs_netatalk.8 \
		vfs_preopen.8 \
		vfs_readahead.8 vfs_readonly.8 vfs_recycle.8 vfs_shadow_copy.8 \
		vfs_shadow_copy2.8 vfs_smb_traffic_analyzer.8 \
		vfs_streams_xattr.8 vfs_xattr_tdb.8

.if ${PORT_OPTIONS:MWINBIND}
SAMBA_MAN1+=	wbinfo.1
SAMBA_MAN5+=	pam_winbind.conf.5
SAMBA_MAN7+=	winbind_krb5_locator.7
SAMBA_MAN8+=	pam_winbind.8 winbindd.8
.endif

.if ${PORT_OPTIONS:MSWAT}
SAMBA_MAN8+=	swat.8
.endif

.if ${PORT_OPTIONS:MFAM}
SAMBA_MAN8+=	vfs_notify_fam.8
.endif

.if ${PORT_OPTIONS:MPTHREADPOOL}
SAMBA_MAN8+=	vfs_aio_pthread.8
.endif

.if defined(SAMBA_WANT_LDAP)
SAMBA_MAN8+=	idmap_ldap.8
.endif

.if !empty(WANT_EXP_MODULES:Midmap_ad)
SAMBA_MAN8+=	idmap_ad.8
.endif

.if !empty(WANT_EXP_MODULES:Midmap_adex)
SAMBA_MAN8+=	idmap_adex.8
.endif

.if !empty(WANT_EXP_MODULES:Midmap_hash)
SAMBA_MAN8+=	idmap_hash.8
.endif

.if !empty(WANT_EXP_MODULES:Midmap_rid)
SAMBA_MAN8+=	idmap_rid.8
.endif

.if !empty(WANT_EXP_MODULES:Mvfs_cacheprime)
SAMBA_MAN8+=	vfs_cacheprime.8
.endif

.if !empty(WANT_EXP_MODULES:Mvfs_catia)
SAMBA_MAN8+=	vfs_catia.8
.endif

.if !empty(WANT_EXP_MODULES:Mvfs_commit)
SAMBA_MAN8+=	vfs_commit.8
.endif

.if !empty(WANT_EXP_MODULES:Mvfs_dirsort)
SAMBA_MAN8+=	vfs_dirsort.8
.endif

.if !empty(WANT_EXP_MODULES:Mvfs_streams_depot)
SAMBA_MAN8+=	vfs_streams_depot.8
.endif

SAMBA_SUB=	SAMBA_LOGDIR="${SAMBA_LOGDIR}" \
		SAMBA_LOCKDIR="${SAMBA_LOCKDIR}" \
		SAMBA_CONFDIR="${SAMBA_CONFDIR}" \
		SAMBA_CONFIG="${SAMBA_CONFIG}" \
		SAMBA_RUNDIR="${SAMBA_RUNDIR}" \
		SAMBA_SWATDIR="${SAMBA_SWATDIR}" \
		SAMBA_SPOOL="${SAMBA_SPOOL}" \
		SAMBA_PRIVATEDIR="${SAMBA_PRIVATEDIR}" \
		PKGCONFIGDIR="${PKGCONFIGDIR_REL}"

PLIST_SUB+=	${SAMBA_SUB}
SUB_LIST+=	${SAMBA_SUB}

ALL_TARGET=	all
.if ${PORT_OPTIONS:MSMBTORTURE}
ALL_TARGET+=	smbtorture
.endif

# What will be installed
INSTALL_TARGET=	installservers installbin installscripts installdat \
		installmodules installlibs

.if ${PORT_OPTIONS:MSWAT}
INSTALL_TARGET+=installswat
.endif

post-configure:
# It's in another port
	@${RM} ${WRKDIR}/${DISTNAME}/docs/htmldocs/manpages/libsmbclient.7.html
	@${RM} -r ${WRKDIR}/${DISTNAME}/examples/libsmbclient

pre-install:
	-@${FIND} "${STAGEDIR}${SAMBA_MODULEDIR}" -type f -o -type l 2>/dev/null | ${SORT} | ${SED} -E 's|^${STAGEDIR}${PREFIX}/?||;' > ${WRKDIR}/.PLIST.exclude
	@${CAT} ${PKGDIR}/pkg-plist > ${PLIST}
.if ${PORT_OPTIONS:MSWAT}
	@${CAT} ${PKGDIR}/pkg-plist.swat >> ${PLIST}
.endif

post-install:
	@${RM} ${STAGEDIR}/${PREFIX}/bin/findsmb
.for sect in 1 3 5 7 8
	@${MKDIR} ${STAGEDIR}${MAN${sect}PREFIX}/man/man${sect}
.	for man in ${SAMBA_MAN${sect}}
	    @${INSTALL_MAN} "${WRKDIR}/${DISTNAME}/docs/manpages/${man}" "${STAGEDIR}${MAN${sect}PREFIX}/man/man${sect}"
	    ${ECHO_CMD} "man/man${sect}/${man}.gz" >> ${TMPPLIST}
.	endfor
.endfor
# Put examples in place
	@${MKDIR} "${STAGEDIR}${EXAMPLESDIR}"
	@${CP} -Rp ${WRKDIR}/${DISTNAME}/examples/* "${STAGEDIR}${EXAMPLESDIR}"
.if ${PORT_OPTIONS:MPAM_SMBPASS}
	@${MKDIR} "${STAGEDIR}${EXAMPLESDIR}/pam_smbpass"
	@${CP} -Rp ${WRKSRC}/pam_smbpass/samples/* "${STAGEDIR}${EXAMPLESDIR}/pam_smbpass"
.endif
	${INSTALL_DATA} "${WRKDIR}/smb.conf.sample" "${STAGEDIR}${EXAMPLESDIR}/${SAMBA_CONFIG}.sample"
	${INSTALL_DATA} "${WRKDIR}/smb.conf.sample" "${STAGEDIR}${SAMBA_CONFDIR}/${SAMBA_CONFIG}.sample"
	${INSTALL_SCRIPT} "${WRKSRC}/script/mksmbpasswd.sh" "${STAGEDIR}${PREFIX}/bin/make_smbpasswd"
# Winbind
.if ${PORT_OPTIONS:MWINBIND}
	${INSTALL_PROGRAM} "${WRKDIR}/${DISTNAME}/nsswitch/nss_winbind.so" "${STAGEDIR}${SAMBA_LIBDIR}/nss_winbind.so.1"
	${INSTALL_PROGRAM} "${WRKDIR}/${DISTNAME}/nsswitch/nss_wins.so" "${STAGEDIR}${SAMBA_LIBDIR}/nss_wins.so.1"
	${INSTALL_PROGRAM} "${WRKSRC}/bin/pam_winbind.so" "${STAGEDIR}${SAMBA_LIBDIR}"
.endif
.if ${PORT_OPTIONS:MPAM_SMBPASS}
	${INSTALL_PROGRAM} "${WRKSRC}/bin/pam_smbpass.so" "${STAGEDIR}${SAMBA_LIBDIR}"
.endif
# smbtorture
.if ${PORT_OPTIONS:MSMBTORTURE}
	${INSTALL_PROGRAM} "${WRKSRC}/bin/smbtorture" "${STAGEDIR}${PREFIX}/bin"
.endif
# Lib
	@${FIND} "${STAGEDIR}${SAMBA_MODULEDIR}" -type f -o -type l | ${SED} -E 's|^${STAGEDIR}${PREFIX}/?||;' | ${EGREP} -F -v -f ${WRKDIR}/.PLIST.exclude | ${SORT} >> ${TMPPLIST}
	@for d in `${FIND} "${STAGEDIR}${SAMBA_MODULEDIR}" -type d | ${SORT} -r | ${SED} -E 's|^${STAGEDIR}${PREFIX}/?||;'`; do \
	    ${ECHO_CMD} "@unexec rmdir >/dev/null 2>&1 \"%D/$$d\" || true" >> ${TMPPLIST}; \
	done
# Documentation
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${CP} -Rp "${WRKDIR}/${DISTNAME}/docs/registry" "${STAGEDIR}${DOCSDIR}"
.	for f in Samba3-ByExample.pdf Samba3-HOWTO.pdf Samba3-Developers-Guide.pdf
	    @${INSTALL_DATA} "${WRKDIR}/${DISTNAME}/docs/${f}" "${STAGEDIR}${DOCSDIR}"
.	endfor
.	for f in README COPYING MAINTAINERS.txt PFIF.txt Manifest Roadmap \
		WHATSNEW.txt docs/THANKS docs/history
	    @${INSTALL_DATA} "${WRKDIR}/${DISTNAME}/${f}" "${STAGEDIR}${DOCSDIR}"
.	endfor
	@${INSTALL_DATA} "${FILESDIR}/README.FreeBSD" "${STAGEDIR}${DOCSDIR}"
.endif
# Run post-install script
.for dir in ${SAMBA_SPOOL} ${SAMBA_LOGDIR} ${SAMBA_RUNDIR} ${SAMBA_LOCKDIR} ${SAMBA_PRIVATEDIR}
	@${MKDIR} "${STAGEDIR}${dir}"
.endfor
	@${CHMOD} 1777 ${STAGEDIR}${SAMBA_SPOOL}
	@${CHMOD} 0700 ${STAGEDIR}${SAMBA_PRIVATEDIR}
	@${CAT} ${PKGMESSAGE}

.if ${PORT_OPTIONS:MMAX_DEBUG}
test:
	(cd ${WRKSRC} && ${MAKE_CMD} test_nss_modules test_pam_modules && ${MAKE_CMD} test)
.endif
# !SAMBA_SUBPORT
.endif

.include <bsd.port.post.mk>
