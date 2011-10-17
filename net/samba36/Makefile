# New ports collection makefile for:	samba36
# Date created:				1 May 2011
# Whom:					timur@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		${SAMBA_BASENAME}36
PORTVERSION=		3.6.0
PORTREVISION?=		1
CATEGORIES?=		net
MASTER_SITES=		${MASTER_SITE_SAMBA}
MASTER_SITE_SUBDIR=	. old-versions rc pre
DISTNAME=		${SAMBA_BASENAME}-${PORTVERSION:S|.p|pre|:S|.r|rc|:S|.t|tp|:S|.a|alpha|}

MAINTAINER?=		timur@FreeBSD.org
COMMENT?=		A free SMB and CIFS client and server for UNIX

CONFLICTS?=		*samba3[2-5]-3.*
# Additional patches from Sernet.de
PATCH_STRIP=		-p1
EXTRA_PATCHES=		${PATCHDIR}/sernet.patch

LICENSE=		GPLv3
LICENSE_FILE=		${WRKDIR}/${DISTNAME}/COPYING

SAMBA_BASENAME=		samba

LATEST_LINK=		${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
EXAMPLESDIR=		${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
PATCH_WRKSRC=		${WRKDIR}/${DISTNAME}
WRKSRC=			${WRKDIR}/${DISTNAME}/source3
IPATHS=			-I${WRKDIR}/${DISTNAME}/source3/m4 -I${WRKDIR}/${DISTNAME}/m4 -I${WRKDIR}/${DISTNAME}/lib/replace -I${WRKDIR}/${DISTNAME}/source4
AUTOHEADER_ARGS=	${IPATHS}
AUTOCONF_ARGS=		${IPATHS}

USE_GMAKE=		yes
USE_ICONV=		yes
GNU_CONFIGURE=		yes
USE_AUTOTOOLS=		autoconf autoheader
USE_LDCONFIG=		${SAMBA_LIBDIR}

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
			--with-modulesdir="${SAMBA_MODULEDIR}" \
			--with-pammodulesdir="${SAMBA_LIBDIR}" \
			--localstatedir="${VARDIR}" \
			--with-piddir="${SAMBA_RUNDIR}" \
			--with-ncalrpcdir="${SAMBA_RUNDIR}/ncalrpc" \
			--with-lockdir="${SAMBA_LOCKDIR}" \
			--with-statedir="${SAMBA_LOCKDIR}" \
			--with-cachedir="${SAMBA_LOCKDIR}" \
			--with-privatedir="${SAMBA_PRIVATEDIR}" \
			--with-logfilebase="${SAMBA_LOGDIR}"

CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

CONFIGURE_ENV+=		LDFLAGS="${LDFLAGS}" \
			PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
			PTHREAD_LDFLAGS="${PTHREAD_LIBS}"
# pkg-config is used to find talloc
PKGCONFIGDIR?=		${PREFIX}/libdata/pkgconfig
PKGCONFIGDIR_REL?=	${PKGCONFIGDIR:S|^${PREFIX}/||}

PKG_CONFIG?=		${LOCALBASE}/bin/pkg-config
CONFIGURE_ENV+=		PKG_CONFIG="${PKG_CONFIG}"
BUILD_DEPENDS+=		${PKG_CONFIG}:${PORTSDIR}/devel/pkg-config
# Let process generate meaningful backtrace on a core dump
LIB_DEPENDS+=		execinfo.1:${PORTSDIR}/devel/libexecinfo
# tdb
BUILD_DEPENDS+=		tdb>=1.2.6:${PORTSDIR}/databases/tdb
RUN_DEPENDS+=		tdb>=1.2.6:${PORTSDIR}/databases/tdb
CONFIGURE_ARGS+=	--without-libtdb --enable-external-libtdb
# talloc
BUILD_DEPENDS+=		talloc>=2.0.1:${PORTSDIR}/devel/talloc
RUN_DEPENDS+=		talloc>=2.0.1:${PORTSDIR}/devel/talloc
CONFIGURE_ARGS+=	--without-libtalloc --enable-external-libtalloc
# These options are common for all (sub)ports
CONFIGURE_ARGS+=	--with-libiconv="${LOCALBASE}"

.if !defined(SAMBA_SUBPORT)
OPTIONS=	LDAP		"With LDAP support" on \
		ADS		"With Active Directory support" off \
		CUPS		"With CUPS printing support" on \
		WINBIND		"With WinBIND support" on \
		SWAT		"With SWAT WebGUI" off \
		ACL_SUPPORT	"With ACL support" off \
		AIO_SUPPORT	"With Asyncronous IO support" off \
		FAM_SUPPORT	"With File Alteration Monitor" off \
		SYSLOG		"With Syslog support" off \
		QUOTAS		"With Disk quota support" off \
		UTMP		"With UTMP accounting support" off \
		PAM_SMBPASS	"With PAM authentication vs passdb backends" off \
		DNSUPDATE	"With dynamic DNS update(require ADS)" off \
		AVAHI		"With Bonjour service discovery support" off \
		EXP_MODULES	"With experimental modules" off \
		POPT		"With system-wide POPT library" on \
		IPV6		"With IPv6 support" on \
		MAX_DEBUG	"With maximum debugging" off \
		SMBTORTURE	"With smbtorture" off
# !SAMBA_SUBPORT
.endif

.include <bsd.port.options.mk>

# XXX
.if ${OSVERSION} >= 701000 && ${OSVERSION} < 702000
IGNORE=			databases/tdb crashes on FreeBSD 7.1. Please, consider upgrading to 7.2 or higher
.endif
# There are reports that on ARM PIE makes binaries to core dump(#149186)
.if ${ARCH} == "arm"
CONFIGURE_ARGS+=	--disable-pie
.endif

.if defined(SAMBA_SUBPORT)
# Switch off all extra functionality
CONFIGURE_ARGS+=	--disable-cups --disable-fam --without-winbind \
			--without-syslog --without-quotas --without-utmp \
			--without-pam --without-pam_smbpass \
			--without-aio-support
# Dirty hack to work around usage of OPTIONS in slave ports
.	if exists(${.CURDIR}/Makefile.inc)
.		include "${.CURDIR}/Makefile.inc"
.	endif
.else
# Samba server itself
USE_RC_SUBR=		${SAMBA_BASENAME}
SUB_FILES=		pkg-install pkg-message pkg-deinstall smb.conf.sample

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

# XXX: Temporary hack for RELENG6
CONFIGURE_ENV+=		ac_cv_header_sys_mount_h=yes
.if !defined(WITH_IPV6)
CONFIGURE_ENV+=		libreplace_cv_HAVE_IPV6=no
.endif

.if !defined(WITHOUT_LDAP)
SAMBA_WANT_LDAP=	yes
.endif

.if !defined(WITHOUT_CUPS)
LIB_DEPENDS+=		cups.2:${PORTSDIR}/print/cups-client
CONFIGURE_ARGS+=	--enable-cups --enable-iprint
SUB_LIST+=		CUPS=""
.else
CONFIGURE_ARGS+=	--disable-cups --disable-iprint
SUB_LIST+=		CUPS="@comment "
.endif

.if defined(WITH_MAX_DEBUG)
CPPFLAGS+=		-g
LDFLAGS+=		-g
LIB_DEPENDS+=		dmalloc.1:${PORTSDIR}/devel/dmalloc
CONFIGURE_ARGS+=	--enable-debug \
			--enable-socket-wrapper --enable-nss-wrapper \
			--enable-developer --enable-krb5developer \
			--enable-dmalloc --with-profiling-data

CONFIGURE_ARGS+=	--with-smbtorture4-path=${WRKDIR}/${DISTNAME}/source4/torture
.else
CONFIGURE_ARGS+=	--disable-debug \
			--disable-socket-wrapper --disable-nss-wrapper \
			--disable-developer --disable-krb5developer \
			--disable-dmalloc --without-profiling-data
.endif

.if defined(WITH_SYSLOG)
CONFIGURE_ARGS+=	--with-syslog
.else
CONFIGURE_ARGS+=	--without-syslog
.endif

.if defined(WITH_QUOTAS)
CONFIGURE_ARGS+=	--with-quotas
.else
CONFIGURE_ARGS+=	--without-quotas
.endif

.if !defined(WITHOUT_UTMP)
CONFIGURE_ARGS+=	--with-utmp
.else
CONFIGURE_ARGS+=	--without-utmp
.endif

.if !defined(WITHOUT_WINBIND)
CONFIGURE_ARGS+=	--with-winbind
PLIST_SUB+=		WINBIND=""
SUB_LIST+=		WINBIND=""
.else
CONFIGURE_ARGS+=	--without-winbind
PLIST_SUB+=		WINBIND="@comment "
SUB_LIST+=		WINBIND="@comment "
.endif

.if !defined(WITHOUT_SWAT)
CONFIGURE_ARGS+=	--enable-swat
PLIST_SUB+=		SWAT=""
.else
CONFIGURE_ARGS+=	--disable-swat
PLIST_SUB+=		SWAT="@comment "
.endif
# Add some shared modules
.if defined(WITH_EXP_MODULES)
.	if !defined(WANT_EXP_MODULES) || empty(WANT_EXP_MODULES)
WANT_EXP_MODULES=	idmap_tdb2 idmap_ad idmap_adex idmap_hash idmap_rid \
			charset_weird
.		if !defined(WITH_MAX_DEBUG)
WANT_EXP_MODULES+=	rpc_echo
.		endif
WANT_EXP_MODULES+=	vfs_cacheprime vfs_catia vfs_commit vfs_dirsort \
			vfs_readahead vfs_streams_depot vfs_syncops
.	endif
.endif

.if defined(WITH_FAM_SUPPORT)
USE_FAM=		yes
WANT_EXP_MODULES+=	vfs_notify_fam
CONFIGURE_ARGS+=	--enable-fam
.else
CONFIGURE_ARGS+=	--disable-fam
.endif

.if defined(WITH_ACL_SUPPORT)
CONFIGURE_ARGS+=	--with-acl-support
.	if ${OSVERSION} > 800000
WANT_EXP_MODULES+=	vfs_zfsacl
LIB_DEPENDS+=		sunacl.1:${PORTSDIR}/sysutils/libsunacl
.	endif
.else
CONFIGURE_ARGS+=	--without-acl-support
.endif

.if defined(WITH_AIO_SUPPORT)
.if ${OSVERSION} < 700055
IGNORE=			an AIO support requires 7.0-RELEASE or later. Disable AIO support
.endif
CONFIGURE_ARGS+=	--with-aio-support
.else
CONFIGURE_ARGS+=	--without-aio-support
.endif

.if defined(WITH_PAM_SMBPASS)
CONFIGURE_ARGS+=	--with-pam_smbpass
PLIST_SUB+=		SMBPASS=""
.else
CONFIGURE_ARGS+=	--without-pam_smbpass
PLIST_SUB+=		SMBPASS="@comment "
.endif

.if defined(WITH_DNSUPDATE)
.	if !defined(WITH_ADS)
IGNORE=			dynamic DNS updates require ADS support. Disable DNSUPDATE support
.	endif
LIB_DEPENDS+=		uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid
CONFIGURE_ARGS+=	--with-dnsupdate
.else
CONFIGURE_ARGS+=	--without-dnsupdate
.endif

.if defined(WITH_AVAHI)
CPPFLAGS+=		`${PKG_CONFIG} --cflags avahi-client`
DNSSD_LIBS=		`${PKG_CONFIG} --libs avahi-client`
LIB_DEPENDS+=		avahi-client.3:${PORTSDIR}/net/avahi-app
CONFIGURE_ARGS+=	--enable-avahi
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

.if !defined(WITHOUT_POPT)
LIB_DEPENDS+=		popt.0:${PORTSDIR}/devel/popt
CONFIGURE_ARGS+=	--without-included-popt
.else
CONFIGURE_ARGS+=	--with-included-popt
.endif

#--enable-pthreadpool

.if defined(WITH_SMBTORTURE)
PLIST_SUB+=		SMBTORTURE=""
.else
PLIST_SUB+=		SMBTORTURE="@comment "
.endif
# !SAMBA_SUBPORT
.endif

###
### Common part for port and it's subports
###

.if defined(WITH_ADS)
SAMBA_WANT_LDAP=	yes
SAMBA_WANT_KRB5=	yes
CONFIGURE_ARGS+=	--with-ads
.else
CONFIGURE_ARGS+=	--without-ads
.endif
# Kerberos5 is necessary for ADS
.if defined(SAMBA_WANT_KRB5)
.if defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libgssapi_krb5.so)
CONFIGURE_ARGS+=	--with-krb5="${KRB5_HOME}"
.elif defined(HEIMDAL_HOME) && exists(${HEIMDAL_HOME}/lib/libgssapi.so)
CONFIGURE_ARGS+=	--with-krb5="${HEIMDAL_HOME}"
.elif exists(/usr/lib/libkrb5.so) && exists(/usr/bin/krb5-config)
CONFIGURE_ARGS+=	--with-krb5="/usr"
.else
LIB_DEPENDS+=		krb5:${PORTSDIR}/security/heimdal
CONFIGURE_ARGS+=	--with-krb5="${LOCALBASE}"
.endif
.else
CONFIGURE_ARGS+=	--without-krb5
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
###
### end of common part
###

.if !defined(SAMBA_SUBPORT)
# Samba server only
MAN1=		findsmb.1 \
		ldbadd.1 ldbdel.1 ldbedit.1 ldbmodify.1 ldbrename.1 ldbsearch.1 \
		log2pcap.1 nmblookup.1 ntlm_auth.1 profiles.1 rpcclient.1 \
		sharesec.1 smbcacls.1 smbclient.1 smbcontrol.1 smbcquotas.1 \
		smbget.1 smbstatus.1 smbtar.1 smbtree.1 testparm.1 vfstest.1
MAN3=		ldb.3
MAN5=		lmhosts.5 smb.conf.5 smbgetrc.5 smbpasswd.5
MAN7=		samba.7
MAN8=		eventlogadm.8 net.8 nmbd.8 pdbedit.8 smbd.8 smbpasswd.8 \
		smbspool.8 idmap_nss.8 idmap_tdb.8 idmap_tdb2.8 \
		vfs_acl_tdb.8 vfs_acl_xattr.8 \
		vfs_audit.8 vfs_cap.8 vfs_default_quota.8 vfs_extd_audit.8 \
		vfs_fake_perms.8 vfs_full_audit.8 vfs_netatalk.8 \
		vfs_preopen.8 \
		vfs_readahead.8 vfs_readonly.8 vfs_recycle.8 vfs_shadow_copy.8 \
		vfs_shadow_copy2.8 vfs_smb_traffic_analyzer.8 \
		vfs_streams_xattr.8 vfs_xattr_tdb.8

.if !defined(WITHOUT_WINBIND)
MAN1+=		wbinfo.1
MAN5+=		pam_winbind.conf.5
MAN7+=		winbind_krb5_locator.7
MAN8+=		pam_winbind.8 winbindd.8
.endif

.if !defined(WITHOUT_SWAT)
MAN8+=		swat.8
.endif

.if defined(WITH_FAM_SUPPORT)
MAN8+=		vfs_notify_fam.8
.endif

.if defined(SAMBA_WANT_LDAP)
MAN8+=		idmap_ldap.8
.endif

.if !empty(WANT_EXP_MODULES:Midmap_ad)
MAN8+=		idmap_ad.8
.endif

.if !empty(WANT_EXP_MODULES:Midmap_adex)
MAN8+=		idmap_adex.8
.endif

.if !empty(WANT_EXP_MODULES:Midmap_hash)
MAN8+=		idmap_hash.8
.endif

.if !empty(WANT_EXP_MODULES:Midmap_rid)
MAN8+=		idmap_rid.8
.endif

.if !empty(WANT_EXP_MODULES:Mvfs_cacheprime)
MAN8+=		vfs_cacheprime.8
.endif

.if !empty(WANT_EXP_MODULES:Mvfs_catia)
MAN8+=		vfs_catia.8
.endif

.if !empty(WANT_EXP_MODULES:Mvfs_commit)
MAN8+=		vfs_commit.8
.endif

.if !empty(WANT_EXP_MODULES:Mvfs_dirsort)
MAN8+=		vfs_dirsort.8
.endif

.if !empty(WANT_EXP_MODULES:Mvfs_streams_depot)
MAN8+=		vfs_streams_depot.8
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
.if defined(WITH_SMBTORTURE)
ALL_TARGET+=	smbtorture
.endif

# What will be installed
INSTALL_TARGET=	installservers installbin installscripts installdat \
		installmodules installlibs

.if !defined(WITHOUT_SWAT)
INSTALL_TARGET+=installswat
.endif

.if defined(OPTIONS)
pre-fetch:
	@${ECHO_MSG} "===>  -------------------------------------------"
	@${ECHO_MSG} "===>  Run 'make config' to (re)configure the port"
	@${ECHO_MSG} "===>  -------------------------------------------"
.endif

pre-configure:
	@${FIND} ${WRKDIR}/${DISTNAME} -type d | ${XARGS} ${CHMOD} u+w,a+rx
	@${FIND} ${WRKDIR}/${DISTNAME} -type f | ${XARGS} ${CHMOD} u+w,a+r

post-configure:
# It's in another port
	@${RM} -f ${WRKDIR}/${DISTNAME}/docs/htmldocs/manpages/libsmbclient.7.html
	@${RM} -rf ${WRKDIR}/${DISTNAME}/examples/libsmbclient

pre-install:
	-@${FIND} "${SAMBA_MODULEDIR}" -type f -o -type l 2>/dev/null | ${SORT} | ${SED} -E 's|^${PREFIX}/?||;' > ${WRKDIR}/.PLIST.exclude
	@${CAT} ${PKGDIR}/pkg-plist > ${PLIST}
.if !defined(WITHOUT_SWAT)
	@${CAT} ${PKGDIR}/pkg-plist.swat >> ${PLIST}
.endif

post-install:
.for sect in 1 3 5 7 8
	@${MKDIR} ${MAN${sect}PREFIX}/man/man${sect}
.	for man in ${MAN${sect}}
	    @${INSTALL_MAN} "${WRKDIR}/${DISTNAME}/docs/manpages/${man}" "${MAN${sect}PREFIX}/man/man${sect}"
.	endfor
.endfor
# Put examples in place
	@${MKDIR} "${EXAMPLESDIR}"
	@${CP} -Rp ${WRKDIR}/${DISTNAME}/examples/* "${EXAMPLESDIR}"
.if defined(WITH_PAM_SMBPASS)
	@${MKDIR} "${EXAMPLESDIR}/pam_smbpass"
	@${CP} -Rp ${WRKSRC}/pam_smbpass/samples/* "${EXAMPLESDIR}/pam_smbpass"
.endif
	${INSTALL_DATA} "${WRKDIR}/smb.conf.sample" "${EXAMPLESDIR}/${SAMBA_CONFIG}.sample"
	${INSTALL_SCRIPT} "${WRKSRC}/script/mksmbpasswd.sh" "${PREFIX}/bin/make_smbpasswd"
# Winbind
.if !defined(WITHOUT_WINBIND)
	${INSTALL_PROGRAM} "${WRKDIR}/${DISTNAME}/nsswitch/nss_winbind.so" "${SAMBA_LIBDIR}/nss_winbind.so.1"
	${INSTALL_PROGRAM} "${WRKDIR}/${DISTNAME}/nsswitch/nss_wins.so" "${SAMBA_LIBDIR}/nss_wins.so.1"
	${INSTALL_PROGRAM} "${WRKSRC}/bin/pam_winbind.so" "${SAMBA_LIBDIR}"
.endif
.if defined(WITH_PAM_SMBPASS)
	${INSTALL_PROGRAM} "${WRKSRC}/bin/pam_smbpass.so" "${SAMBA_LIBDIR}"
.endif
# smbtorture
.if defined(WITH_SMBTORTURE)
	${INSTALL_PROGRAM} "${WRKSRC}/bin/smbtorture" "${PREFIX}/bin"
.endif
# Lib
	@${FIND} "${SAMBA_MODULEDIR}" -type f -o -type l | ${SED} -E 's|^${PREFIX}/?||;' | ${EGREP} -F -v -f ${WRKDIR}/.PLIST.exclude | ${SORT} >> ${TMPPLIST}
	@for d in `${FIND} "${SAMBA_MODULEDIR}" -type d | ${SORT} -r`; do \
	    ${ECHO_CMD} "@unexec ${RMDIR} \"$$d\" 2>/dev/null || true" >> ${TMPPLIST}; \
	done
# Documentation
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -Rp "${WRKDIR}/${DISTNAME}/docs/registry" "${DOCSDIR}"
.	for f in Samba3-ByExample.pdf Samba3-HOWTO.pdf Samba3-Developers-Guide.pdf
	    @${INSTALL_DATA} "${WRKDIR}/${DISTNAME}/docs/${f}" "${DOCSDIR}"
.	endfor
.	for f in README COPYING MAINTAINERS.txt PFIF.txt Manifest Roadmap \
		WHATSNEW.txt docs/THANKS docs/history
	    @${INSTALL_DATA} "${WRKDIR}/${DISTNAME}/${f}" "${DOCSDIR}"
.	endfor
	@${INSTALL_DATA} "${FILESDIR}/README.FreeBSD" "${DOCSDIR}"
# !NOPORTDOCS
.endif
# Run post-install script
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.if defined(WITH_MAX_DEBUG)
test:
	(cd ${WRKSRC} && ${GMAKE} test_nss_modules test_pam_modules && ${GMAKE} test)
.endif
# !SAMBA_SUBPORT
.endif

.include <bsd.port.post.mk>
