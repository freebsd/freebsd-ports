# New ports collection makefile for:	samba
# Date created:				11th Feb 1995
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME=		samba
PORTVERSION?=		3.0.23b
PORTREVISION?=		0
PORTEPOCH?=		1
CATEGORIES?=		net
MASTER_SITES=		${MASTER_SITE_SAMBA}
MASTER_SITE_SUBDIR=	. old-versions rc pre
DISTNAME=		${PORTNAME}-${PORTVERSION:S/.p/pre/:S/.r/rc/}

MAINTAINER?=		timur@gnu.org
COMMENT?=		A free SMB and CIFS client and server for UNIX

CONFLICTS?=		ja-samba-2.* ja-samba-3.* samba-2.* sharity-light-1.*

USE_ICONV=		yes
USE_FAM=		yes
GNU_CONFIGURE=		yes
USE_AUTOTOOLS=		autoconf:259 autoheader:259

LATEST_LINK?=		${PKGNAMEPREFIX}${PORTNAME}3${PKGNAMESUFFIX}
EXAMPLESDIR=		${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
WRKSRC=			${WRKDIR}/${DISTNAME}/source

# directories
VARDIR=			${DESTDIR}/var
SAMBA_SPOOL?=		${VARDIR}/spool/samba
SAMBA_LOGDIR=		${VARDIR}/log/samba
SAMBA_RUNDIR=		${VARDIR}/run
SAMBA_LOCKDIR?=		${VARDIR}/db/samba
SAMBA_PRIVATE?=		${PREFIX}/private
SAMBA_CONFDIR?=		${PREFIX}/etc
SAMBA_SWATDIR=		${PREFIX}/share/swat
SAMBA_LIB=		lib
SAMBA_LIBDIR=		${PREFIX}/${SAMBA_LIB}
RC_DIR=			${PREFIX}/etc/rc.d
SAMBA_CONFIG=		${SAMBA_CONFDIR}/smb.conf

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

CONFIGURE_ARGS+=	--exec-prefix=${PREFIX} \
			--localstatedir=${VARDIR} \
		        --with-configdir=${SAMBA_CONFDIR} \
			--with-pammodulesdir=${SAMBA_LIBDIR} \
	    		--with-libdir=${SAMBA_LIBDIR}/samba \
			--with-swatdir=${SAMBA_SWATDIR} \
			--with-piddir=${SAMBA_RUNDIR} \
			--with-lockdir=${SAMBA_LOCKDIR} \
			--with-privatedir=${SAMBA_PRIVATE} \
			--with-logfilebase=${SAMBA_LOGDIR}

CONFIGURE_ARGS+=	--with-libiconv=${LOCALBASE}

.if !defined(SAMBA_SUBPORT)
# Samba server itself
OPTIONS=	LDAP		"With LDAP support" on \
		ADS		"With Active Directory support" off \
		CUPS		"With CUPS printing support" on \
		WINBIND		"With WinBIND support" on \
		ACL_SUPPORT	"With ACL support" off \
		AIO_SUPPORT	"With experimental AIO support" off \
		SYSLOG		"With Syslog support" off \
		QUOTAS		"With Quota support" off \
		UTMP		"With UTMP support" on \
		MSDFS		"With MSDFS support" off \
		SMBSH		"With SMBSH wrapper for UNIX commands" off \
		PAM_SMBPASS	"With PAM authentication against passdb backends" off \
		EXP_MODULES	"With experimental module(s)" off \
		POPT		"With system-wide POPT library" on
.endif

.include <bsd.port.pre.mk>

.if defined(SAMBA_SUBPORT)
# Switch off all extra functionality
CONFIGURE_ARGS+=	--disable-cups --without-winbind --without-syslog \
			--without-quotas --without-utmp --without-ldapsam \
			--without-pam --without-pam_smbpass \
			--without-aio-support

# Dirty hack to work around usage of OPTIONS in slave ports
.if exists(${.CURDIR}/Makefile.inc)
.include "${.CURDIR}/Makefile.inc"
.endif

.else
# Samba server itself
USE_RC_SUBR=		samba
SUB_FILES=		smb.conf.sample

CONFIGURE_ARGS+=	--with-pam --with-readline --with-sendfile-support \
			--without-libsmbclient --without-libmsrpc \
			--without-libsmbsharemodes --without-python \
			--with-included-iniparser

.if !defined(WITHOUT_CUPS)
LIB_DEPENDS+=		cups.2:${PORTSDIR}/print/cups-base
CONFIGURE_ARGS+=	--enable-cups
CUPSD=			cupsd
.else
CONFIGURE_ARGS+=	--disable-cups
CUPSD=			""
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

.if defined(WITHOUT_UTMP)
CONFIGURE_ARGS+=	--without-utmp
.endif

.if defined(WITH_MSDFS)
CONFIGURE_ARGS+=	--with-msdfs
.endif

.if !defined(WITHOUT_WINBIND)
CONFIGURE_ARGS+=	--with-winbind
PLIST_SUB+=		WINBIND=""
SUB_LIST+=		WINBIND=""
.if ${OSVERSION} >= 500112
WITH_WINBIND_NSS=	yes
.endif
.else
CONFIGURE_ARGS+=	--without-winbind
PLIST_SUB+=		WINBIND="@comment "
SUB_LIST+=		WINBIND="@comment "
.endif

.if defined(WITH_WINBIND_NSS)
PLIST_SUB+=		WINBIND_NSS=""
.else
PLIST_SUB+=		WINBIND_NSS="@comment "
.endif

.if !defined(WITHOUT_LDAP)
WANT_LDAP=		yes
.endif

.if defined(WITH_EXP_MODULES)
.if !defined(WANT_EXP_MODULES) || empty(WANT_EXP_MODULES)
WANT_EXP_MODULES=	rpc_echo idmap_ad idmap_rid charset_weird
.endif
WANT_EXP_MODULES!=	${ECHO_CMD} ${WANT_EXP_MODULES} | ${SED} -E 's/ +/,/g'
CONFIGURE_ARGS+=	--with-shared-modules=${WANT_EXP_MODULES}
.endif

.if defined(WITH_PAM_SMBPASS)
CONFIGURE_ARGS+=	--with-pam_smbpass
PLIST_SUB+=		SMBPASS=""
.else
CONFIGURE_ARGS+=	--without-pam_smbpass
PLIST_SUB+=		SMBPASS="@comment "
.endif

.if defined(WITH_ACL_SUPPORT)
.if ${OSVERSION} < 500018
BROKEN=			ACL support requires FreeBSD 5.x at least after 20010326
.else
CONFIGURE_ARGS+=	--with-acl-support
.endif
.endif

.if defined(WITH_SMBSH)
IGNORE=			broken IPC and code
CONFIGURE_ARGS+=	 --with-smbwrapper
PLIST_SUB+=		SMBSH=""
.else
PLIST_SUB+=		SMBSH="@comment "
.endif

.if defined(WITH_AIO_SUPPORT)
IGNORE=			broken kernel API until now (7-CURRENT)
CONFIGURE_ARGS+=	--with-aio-support
.endif

.if !defined(WITHOUT_POPT)
LIB_DEPENDS+=		popt.0:${PORTSDIR}/devel/popt
.else
CONFIGURE_ARGS+=	--with-included-popt
.endif
# !SAMBA_SUBPORT
.endif

###
### Common part for port and it's subports
###
# For 4.8 - 4.11 combination of Kerberos and OpenLDAP is broken
# due the conflict between system and OpenSSL port libcrypto libraries
.if ${OSVERSION} > 470103 && ${OSVERSION} < 500000
.if defined(WITH_ADS)
IGNORE=			broken dependency between OpenSSL, OpenLDAP and Heimdal for FreeBSD 4.x. Disable ADS support
.endif
WITHOUT_ADS=		on
.endif

.if !defined(WITHOUT_ADS)
WANT_LDAP=		yes
WANT_KRB5=		yes
CONFIGURE_ARGS+=	--with-ads
.else
CONFIGURE_ARGS+=	--without-ads
.endif
# Kerberos5 is necessary for ADS
.if defined(WANT_KRB5)
.if defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libgssapi_krb5.a)
CONFIGURE_ARGS+=	--with-krb5=${KRB5_HOME}
.elif defined(HEIMDAL_HOME) && exists(${HEIMDAL_HOME}/lib/libgssapi.a)
CONFIGURE_ARGS+=	--with-krb5=${HEIMDAL_HOME}
.elif exists(${DESTDIR}/usr/lib/libkrb5.a) && exists(${DESTDIR}/usr/bin/krb5-config)
CONFIGURE_ARGS+=	--with-krb5=${DESTDIR}/usr
.else
LIB_DEPENDS+=		krb5:${PORTSDIR}/security/heimdal
CONFIGURE_ARGS+=	--with-krb5=${LOCALBASE}
.endif
.else
CONFIGURE_ARGS+=	--without-krb5
.endif

.if defined(WANT_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if !defined(SAMBA_SUBPORT)
# Samba server itself
MAN1=		findsmb.1 log2pcap.1 nmblookup.1 ntlm_auth.1 profiles.1 \
		rpcclient.1 smbcacls.1 smbclient.1 smbcontrol.1 smbcquotas.1 \
		smbget.1 smbstatus.1 smbtar.1 smbtree.1 testparm.1 vfstest.1
MAN5=		lmhosts.5 smb.conf.5 smbgetrc.5 smbpasswd.5
MAN7=		samba.7
MAN8=		net.8 nmbd.8 pdbedit.8 smbd.8 smbpasswd.8 smbspool.8 \
		swat.8 tdbbackup.8 tdbdump.8
.if defined(WITH_SMBSH)
MAN1+=		smbsh.1
.endif
.if !defined(WITHOUT_WINBIND)
MAN1+=		wbinfo.1
MAN7+=		pam_winbind.7
MAN8+=		winbindd.8
.endif

PLIST_SUB+=		RC_DIR=${RC_DIR} \
			SAMBA_LOGDIR=${SAMBA_LOGDIR} \
			SAMBA_LOCKDIR=${SAMBA_LOCKDIR} \
			SAMBA_CONFIG=${SAMBA_CONFIG}

SUB_LIST+=		CUPSD=${CUPSD} \
			SAMBA_CONFDIR=${SAMBA_CONFDIR} \
			SAMBA_CONFIG=${SAMBA_CONFIG} \
			SAMBA_LOGDIR=${SAMBA_LOGDIR} \
			SAMBA_RUNDIR=${SAMBA_RUNDIR} \
			SAMBA_LOCKDIR=${SAMBA_LOCKDIR} \
			SAMBA_SPOOL=${SAMBA_SPOOL}

PLIST_SUB+=		SMBSH="@comment "
pre-fetch:
	@${ECHO_MSG} "===>  -------------------------------------------"
	@${ECHO_MSG} "===>  Run 'make config' to (re)configure the port"
	@${ECHO_MSG} "===>  -------------------------------------------"

post-patch:
	@${RM} -rf ${WRKDIR}/${DISTNAME}/examples/LDAP/smbldap-tools-*
	@${RM} -rf ${WRKDIR}/${DISTNAME}/examples/libsmbclient
	@${RM} -rf ${WRKDIR}/${DISTNAME}/examples/libmsrpc
	@${RM} -rf ${WRKDIR}/${DISTNAME}/swat/lang
	@${RM} -f ${WRKDIR}/${DISTNAME}/docs/htmldocs/manpages/libsmbclient.7.html
	@${FIND} ${WRKSRC} -name CVS -o -name .cvsignore | ${XARGS} ${RM}
	@${FIND} ${WRKDIR}/${DISTNAME} -type d | ${XARGS} ${CHMOD} u+w,a+rx
	@${FIND} ${WRKDIR}/${DISTNAME} -type f | ${XARGS} ${CHMOD} u+w,a+r

pre-install:
	-@${FIND} ${SAMBA_LIBDIR}/samba -type f 2>/dev/null | ${SORT} | ${SED} -E 's|^${PREFIX}/?||;' >> ${WRKDIR}/.PLIST.exclude

post-install:
.for sect in 1 5 7 8
	@${MKDIR} ${MAN${sect}PREFIX}/man/man${sect}
.for man in ${MAN${sect}}
	@${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/manpages/${man} ${MAN${sect}PREFIX}/man/man${sect}
.endfor
.endfor
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -Rp ${WRKDIR}/${DISTNAME}/examples/* ${EXAMPLESDIR}
.if defined(WITH_PAM_SMBPASS)
	@${MKDIR} ${EXAMPLESDIR}/pam_smbpass
	@${CP} -Rp ${WRKSRC}/pam_smbpass/samples/* ${EXAMPLESDIR}/pam_smbpass
.endif
	${INSTALL_DATA} ${WRKDIR}/smb.conf.sample ${SAMBA_CONFDIR}
	@if [ ! -f ${SAMBA_CONFIG} ]; then \
		${INSTALL_DATA} ${WRKDIR}/smb.conf.sample ${SAMBA_CONFIG} ; \
	fi
	${INSTALL_SCRIPT} ${WRKSRC}/script/mksmbpasswd.sh ${PREFIX}/bin/make_smbpasswd
.if !defined(WITHOUT_WINBIND)
.if defined(WITH_WINBIND_NSS)
	${INSTALL_PROGRAM} ${WRKSRC}/nsswitch/nss_winbind.so ${SAMBA_LIBDIR}/nss_winbind.so.1
	${INSTALL_PROGRAM} ${WRKSRC}/nsswitch/nss_wins.so ${SAMBA_LIBDIR}/nss_wins.so.1
	@${ECHO_CMD} "${SAMBA_LIB}/nss_winbind.so.1" >> ${TMPPLIST};
	@${ECHO_CMD} "${SAMBA_LIB}/nss_wins.so.1" >> ${TMPPLIST};
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pam_winbind.so ${SAMBA_LIBDIR}
	@${ECHO_CMD} "${SAMBA_LIB}/pam_winbind.so" >> ${TMPPLIST};
.endif
.if defined(WITH_PAM_SMBPASS)
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pam_smbpass.so ${SAMBA_LIBDIR}
	@${ECHO_CMD} "${SAMBA_LIB}/pam_smbpass.so" >> ${TMPPLIST};
.endif
# smbwrapper.so
.if defined(WITH_SMBSH)
	${INSTALL_PROGRAM} ${WRKSRC}/bin/smbsh ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/smbwrapper.so ${SAMBA_LIBDIR}/samba
.endif
# Lib
	@${FIND} ${SAMBA_LIBDIR}/samba -type f | ${SED} -E 's|^${PREFIX}/?||;' | ${EGREP} -F -v -f ${WRKDIR}/.PLIST.exclude | ${SORT} >> ${TMPPLIST}
	@for d in `${FIND} ${SAMBA_LIBDIR}/samba -type d | ${SORT} -r`; do \
	    ${ECHO_CMD} "@unexec ${RMDIR} $$d 2>/dev/null || true" >> ${TMPPLIST}; \
	done
# Spool
	@test -d ${SAMBA_SPOOL} || ${MKDIR} ${SAMBA_SPOOL} &&		\
	    ${CHMOD} 1777 ${SAMBA_SPOOL} && ${CHOWN} root:wheel ${SAMBA_SPOOL}
	@${ECHO_CMD} "@exec ${MKDIR} ${SAMBA_SPOOL} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHMOD} 1777 ${SAMBA_SPOOL}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHOWN} root:wheel ${SAMBA_SPOOL}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RM} -rf ${SAMBA_SPOOL}" >> ${TMPPLIST}
# Logdir
	@test -d ${SAMBA_LOGDIR} || ${MKDIR} ${SAMBA_LOGDIR} &&		\
	    ${CHMOD} 0755 ${SAMBA_LOGDIR} && ${CHOWN} root:wheel ${SAMBA_LOGDIR}
	@${ECHO_CMD} "@exec ${MKDIR} ${SAMBA_LOGDIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHMOD} 0755 ${SAMBA_LOGDIR}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHOWN} root:wheel ${SAMBA_LOGDIR}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} ${SAMBA_LOGDIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${ECHO_CMD} \"Warning: If you will *NOT* use this package anymore, please remove ${SAMBA_LOGDIR}/* manually.\"" >> ${TMPPLIST}
# Lockdir
	@test -d ${SAMBA_LOCKDIR} || ${MKDIR} ${SAMBA_LOCKDIR} &&	\
	    ${CHMOD} 0755 ${SAMBA_LOCKDIR} && ${CHOWN} root:wheel ${SAMBA_LOCKDIR}
	@${ECHO_CMD} "@exec ${MKDIR} ${SAMBA_LOCKDIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHMOD} 0755 ${SAMBA_LOCKDIR}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHOWN} root:wheel ${SAMBA_LOCKDIR}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec for f in connections.tdb locking.tdb messages.tdb sessionid.tdb unexpected.tdb brlock.tdb namelist.debug; do ${RM} -f ${SAMBA_LOCKDIR}/\$${f}; done" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} ${SAMBA_LOCKDIR} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${ECHO_CMD} \"Warning: If you will *NOT* use this package anymore, please remove ${SAMBA_LOCKDIR}/* manually.\"" >> ${TMPPLIST}
# Private
	@test -d ${SAMBA_PRIVATE} || ${MKDIR} ${SAMBA_PRIVATE} &&	\
	    ${CHMOD} 700 ${SAMBA_PRIVATE} && ${CHOWN} root:wheel ${SAMBA_PRIVATE}
	@${ECHO_CMD} "@exec ${MKDIR} ${SAMBA_PRIVATE} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHMOD} 700 ${SAMBA_PRIVATE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHOWN} root:wheel ${SAMBA_PRIVATE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} ${SAMBA_PRIVATE} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${ECHO_CMD} \"Warning: If you will *NOT* use this package anymore, please remove ${SAMBA_PRIVATE}/* manually.\"" >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -Rp ${WRKDIR}/${DISTNAME}/docs/registry ${DOCSDIR}
.for f in Samba3-ByExample.pdf Samba3-HOWTO.pdf Samba3-Developers-Guide.pdf
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/docs/${f} ${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${DOCSDIR}
.for f in README COPYING Manifest Read-Manifest-Now Roadmap \
		WHATSNEW.txt docs/THANKS docs/history
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/${f} ${DOCSDIR}
.endfor
# !NOPORTDOCS
.endif
	@${CAT} ${PKGMESSAGE}
# !SAMBA_SUBPORT
.endif

.include <bsd.port.post.mk>
