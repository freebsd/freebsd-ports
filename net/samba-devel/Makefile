# New ports collection makefile for:	samba
# Date created:				11th Feb 1995
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME=	samba
PORTVERSION=	3.0.3.p2
PORTREVISION?=	0
PORTEPOCH?=	1
CATEGORIES?=	net
MASTER_SITES=	${MASTER_SITE_SAMBA}
MASTER_SITE_SUBDIR=	pre rc .
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/pre/:S/.r/rc/}

MAINTAINER?=	timur@gnu.org
COMMENT?=	A free SMB and CIFS client and server for UNIX

CONFLICTS?=	ja-samba-2.* samba-2.* sharity-light-1.* samba-libsmbclient-3.*

USE_BZIP2=	yes
USE_ICONV=	yes
# directories
VARDIR=		${DESTDIR}/var
SAMBA_SPOOL?=	${VARDIR}/spool/samba
SAMBA_LOGDIR=	${VARDIR}/log/samba
SAMBA_RUNDIR=	${VARDIR}/run
SAMBA_PRIVATE?=	${PREFIX}/private
SAMBA_CONFDIR?=	${PREFIX}/etc
SAMBA_SWATDIR=	${PREFIX}/share/swat
SAMBA_LIBDIR=	${PREFIX}/lib
RC_DIR?=	${SAMBA_CONFDIR}/rc.d
SAMBA_CONFIG=	${SAMBA_CONFDIR}/smb.conf

CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib

CONFIGURE_ARGS+=--exec-prefix=${PREFIX} \
		--localstatedir=${VARDIR} \
		--with-configdir=${SAMBA_CONFDIR} \
		--with-libdir=${SAMBA_LIBDIR}/samba \
		--with-swatdir=${SAMBA_SWATDIR} \
		--with-lockdir=${SAMBA_SPOOL} --with-piddir=${SAMBA_RUNDIR} \
		--with-privatedir=${SAMBA_PRIVATE} \
		--with-logfilebase=${SAMBA_LOGDIR} \
		--with-manpages-langs=en

CONFIGURE_ARGS+=--with-libiconv=${LOCALBASE}

WRKSRC=		${WRKDIR}/${DISTNAME}/source

# SUBPORTS end here
.if defined(SAMBA_SUBPORT)
.include <bsd.port.mk>
.else

NO_LATEST_LINK=	yes
INSTALLS_SHLIB=	yes
USE_RC_SUBR=	yes
USE_AUTOCONF_VER=	253

OPTIONS=	CUPS		"With CUPS printing support" on \
		LDAP		"With LDAP support" on \
		ADS		"With Active Directory support" on \
		WINBIND		"With WinBIND support" on \
		ACL_SUPPORT	"With ACL support" off \
		SYSLOG		"With Syslog support" off \
		QUOTAS		"With Quota support" off \
		UTMP		"With UTMP support" on \
		MSDFS		"With MSDFS support" off \
		SAM_XML		"With XML smbpasswd backend" off \
		SAM_MYSQL	"With MYSQL smbpasswd backend" off \
		SAM_PGSQL	"With PostgreSQL smbpasswd backend" off \
		SAM_OLD_LDAP	"With Samba2.x LDAP smbpasswd backend" off \
		PAM_SMBPASS	"With SMB PAM module" off \
		CRACKLIB	"With Cracklib password verification" off \
		PYTHON		"With Python experimental bindings" off \
		POPT		"With installed POPT library" on

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--with-pam --with-readline --with-sendfile-support \
			--with-libsmbclient

.if defined(WITH_PYTHON)
USE_PYTHON=		2.1+
# Hack to make it work with OPTIONS. Breaks portlint
.include "${PORTSDIR}/Mk/bsd.python.mk"
CONFIGURE_ARGS+=	--with-python
PLIST_SUB+=		PYTHON="" \
			PYTHON_VERSION=${PYTHON_VERSION}
.else
CONFIGURE_ARGS+=	--without-python
PLIST_SUB+=		PYTHON="@comment "
.endif

.if defined(WITH_CUPS)
LIB_DEPENDS+=		cups.2:${PORTSDIR}/print/cups-base
CONFIGURE_ARGS+=	--enable-cups
CUPS=			cups
.else
CONFIGURE_ARGS+=	--disable-cups
CUPS=			""
.endif

.if defined(WITH_SYSLOG)
CONFIGURE_ARGS+=	--with-syslog
.else
CONFIGURE_ARGS+=	--without-syslog
.endif

.if defined(WITH_QUOTAS)
CONFIGURE_ARGS+=	--with-quotas
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
.if ${OSVERSION} >= 500112
WITH_WINBIND_NSS=	yes
.endif
.else
CONFIGURE_ARGS+=	--without-winbind
PLIST_SUB+=		WINBIND="@comment "
.endif

.if defined(WITH_WINBIND_NSS)
PLIST_SUB+=		WINBIND_NSS=""
.else
PLIST_SUB+=		WINBIND_NSS="@comment "
.endif

.if !defined(WITHOUT_ADS)
WANT_LDAP=		yes
WANT_KRB5=		yes
CONFIGURE_ARGS+=	--with-ads
.else
CONFIGURE_ARGS+=	--without-ads
.endif

.if !defined(WITHOUT_LDAP)
WANT_LDAP=		yes
.endif

# SAM
.if defined(WITH_SAM_XML)
#USE_GNOME=		libxml2
LIB_DEPENDS+=		xml2.5:${PORTSDIR}/textproc/libxml2
CONFIGURE_ARGS+=	--with-xml-prefix=${LOCALBASE}
WANT_EXPSAM_MODULES+=	xml
PLIST_SUB+=		SAMXML=""
.else
PLIST_SUB+=		SAMXML="@comment "
.endif

.if defined(WITH_SAM_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql-prefix=${LOCALBASE}
WANT_EXPSAM_MODULES+=	mysql
PLIST_SUB+=		SAMMYSQL=""
.else
PLIST_SUB+=		SAMMYSQL="@comment "
.endif

.if defined(WITH_SAM_PGSQL)
LIB_DEPENDS+=		pq.3:${PORTSDIR}/databases/postgresql-client
CONFIGURE_ARGS+=	--with-pgsql-prefix=${LOCALBASE}
WANT_EXPSAM_MODULES+=	pgsql
PLIST_SUB+=		SAMPGSQL=""
.else
PLIST_SUB+=		SAMPGSQL="@comment "
.endif

.if defined(WITH_SAM_OLD_LDAP)
WANT_LDAP=		yes
CONFIGURE_ARGS+=	--with-ldapsam
.else
CONFIGURE_ARGS+=	--without-ldapsam
.endif

.if defined(WANT_EXPSAM_MODULES) && !empty(WANT_EXPSAM_MODULES)
WANT_EXPSAM_MODULES!=	${ECHO_CMD} ${WANT_EXPSAM_MODULES} | ${SED} -e 's/ /,/g'
CONFIGURE_ARGS+=	--with-expsam=${WANT_EXPSAM_MODULES}
.endif
# SAM

# Kerberos5 is necessary for ADS
.if defined(WANT_KRB5)
# Relay on PATH
KRB5_PREFIX!=		krb5-config --prefix
.if defined(KRB5_PREFIX) && !empty (KRB5_PREFIX)
CONFIGURE_ARGS+=	--with-krb5=${KRB5_PREFIX}
.elif defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libgssapi_krb5.a)
CONFIGURE_ARGS+=	--with-krb5=${KRB5_HOME}
.elif defined(HEIMDAL_HOME) && exists(${HEIMDAL_HOME}/lib/libgssapi.a)
CONFIGURE_ARGS+=	--with-krb5=${HEIMDAL_HOME}
.elif ( defined(MAKE_KERBEROS5) || ${OSVERSION} > 500105 ) && exists(/usr/lib/libkrb5.a)
CONFIGURE_ARGS+=	--with-krb5=${DESTDIR}/usr
.else
#BROKEN=		"Kerberos5 is necessary for ADS support. Please, install either Heimdal or MIT-Kerberos"
LIB_DEPENDS+=		krb5.19:${PORTSDIR}/security/heimdal
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

.if defined(WITH_PAM_SMBPASS)
CONFIGURE_ARGS+=	--with-pam_smbpass
PLIST_SUB+=		SMBPASS=""
.else
CONFIGURE_ARGS+=	--without-pam_smbpass
PLIST_SUB+=		SMBPASS="@comment "
.endif

.if defined(WITH_CRACKLIB)
LIB_DEPENDS+=		crack.1:${PORTSDIR}/security/cracklib
CONFIGURE_ARGS+=	--with-cracklib=${LOCALBASE}/libdata/cracklib/pw_dict
.else
CONFIGURE_ARGS+=	--without-cracklib
.endif

.if defined(WITH_ACL_SUPPORT)
.if ${OSVERSION} < 500018
BROKEN=			"Requires FreeBSD 5.x at least after 20010326"
.else
CONFIGURE_ARGS+=	--with-acl-support
.endif
.endif

.if !defined(WITHOUT_POPT)
LIB_DEPENDS+=		popt.0:${PORTSDIR}/devel/popt
.else
CONFIGURE_ARGS+=	--with-included-popt
.endif

MLINKS=		samba.7 Samba.7
MAN1=		findsmb.1 nmblookup.1 log2pcap.1 rpcclient.1 \
		smbget.1 smbcacls.1 smbclient.1 smbcontrol.1 smbsh.1 \
		smbstatus.1 smbtar.1 testparm.1 testprns.1 vfstest.1 \
		ntlm_auth.1 profiles.1 smbcquotas.1 smbtree.1
MAN5=		lmhosts.5 smb.conf.5 smbpasswd.5
MAN7=		samba.7
MAN8=		nmbd.8 smbd.8 net.8 pdbedit.8 smbpasswd.8 smbspool.8 \
		swat.8 tdbdump.8 tdbbackup.8
.if !defined(WITHOUT_WINBIND)
MAN1+=		wbinfo.1
MAN8+=		winbindd.8
.endif

.if !defined(WITHOUT_WINBIND)
WINBIND_FILTER=		${SED} -e 's|%%WINBIND%%||g'
.else
WINBIND_FILTER=		${GREP} -v '^%%WINBIND%%'
.endif

PLIST_SUB+=		RC_DIR=${RC_DIR} \
			SAMBA_SPOOL=${SAMBA_SPOOL} \
			SAMBA_LOGDIR=${SAMBA_LOGDIR}

RC_SCRIPTS_SUB=		PREFIX=${PREFIX} \
			RC_SUBR=${RC_SUBR} \
			RC_DIR=${RC_DIR} \
			CUPS=${CUPS} \
			SAMBA_CONFIG=${SAMBA_CONFIG} \
			SAMBA_SPOOL=${SAMBA_SPOOL} \
			SAMBA_RUNDIR=${SAMBA_RUNDIR}

pre-fetch:
	@${ECHO_MSG} "===>  -------------------------------------------"
	@${ECHO_MSG} "===>  Run 'make config' to (re)configure the port"
	@${ECHO_MSG} "===>  -------------------------------------------"

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
.if defined(WITH_PYTHON)
	@${MKDIR} ${PREFIX}/lib/${PYTHON_VERSION}/site-packages
	@${CP} -R ${WRKSRC}/build/lib.*/samba ${PREFIX}/lib/${PYTHON_VERSION}/site-packages
	@${MKDIR} ${EXAMPLESDIR}/python
	@${CP} -Rp ${WRKSRC}/python/examples/* ${EXAMPLESDIR}/python
.endif
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
	    ${FILESDIR}/samba.sh.sample | ${WINBIND_FILTER} > ${WRKDIR}/samba.sh
	${INSTALL_SCRIPT} ${WRKDIR}/samba.sh ${RC_DIR}/samba.sh
	@test -d ${SAMBA_SPOOL} || ${MKDIR} ${SAMBA_SPOOL} && ${CHMOD} 0755 ${SAMBA_SPOOL}
	@test -d ${SAMBA_LOGDIR} || ${MKDIR} ${SAMBA_LOGDIR}
	${SED}  -e 's!%%SAMBA_SPOOL%%!${SAMBA_SPOOL}!'			\
		-e 's!%%SAMBA_LOGDIR%%!${SAMBA_LOGDIR}!'		\
		-e 's!%%SAMBA_CONFDIR%%!${SAMBA_CONFDIR}!'		\
		${FILESDIR}/smb.conf.default				\
		> ${SAMBA_CONFIG}.default ;					\
	${INSTALL_SCRIPT} ${WRKSRC}/script/mksmbpasswd.sh ${PREFIX}/bin/make_smbpasswd
	if [ ! -d ${SAMBA_PRIVATE} ] ; then				\
		${MKDIR} ${SAMBA_PRIVATE} ;				\
		${CHOWN} root:wheel ${SAMBA_PRIVATE} ;			\
	fi
	${CHMOD} 700 ${SAMBA_PRIVATE}
.if defined(PACKAGE_BUILDING)
	@${ECHO_CMD} "@exec ${MKDIR} ${SAMBA_PRIVATE} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHMOD} 700 ${SAMBA_PRIVATE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RM} -rf ${SAMBA_PRIVATE}" >> ${TMPPLIST}
.else
	@${ECHO_CMD} "@unexec ${ECHO_CMD} \"Warning: If you will *NOT* use this package anymore, please remove %D/private/* manually.\"" >> ${TMPPLIST}
.endif
.if !defined(WITHOUT_WINBIND)
.if defined(WITH_WINBIND_NSS)
	${INSTALL_PROGRAM} ${WRKSRC}/nsswitch/nss_winbind.so ${SAMBA_LIBDIR}/nss_winbind.so.1
	${INSTALL_PROGRAM} ${WRKSRC}/nsswitch/nss_wins.so ${SAMBA_LIBDIR}/nss_wins.so.1
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/nsswitch/pam_winbind.so ${SAMBA_LIBDIR}
.endif
.if defined(WITH_PAM_SMBPASS)
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/pam_smbpass.so ${SAMBA_LIBDIR}
.endif
	-@${LN} -snf libsmbclient.so.0 ${SAMBA_LIBDIR}/libsmbclient.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${DOCSDIR}
	for i in ${WRKDIR}/${DISTNAME}/README				\
			${WRKDIR}/${DISTNAME}/COPYING			\
			${WRKDIR}/${DISTNAME}/Manifest			\
			${WRKDIR}/${DISTNAME}/Read-Manifest-Now		\
			${WRKDIR}/${DISTNAME}/Roadmap			\
			${WRKDIR}/${DISTNAME}/WHATSNEW.txt		\
			${WRKDIR}/${DISTNAME}/docs/THANKS		\
			${WRKDIR}/${DISTNAME}/docs/history ; do		\
		${INSTALL_DATA} $$i ${DOCSDIR} ;			\
	done
	for i in faq Registry htmldocs htmldocs/images ; do		\
		${MKDIR} ${DOCSDIR}/$$i ;				\
		for j in ${WRKDIR}/${DISTNAME}/docs/$$i/* ; do		\
		    if [ -f $$j ]; then					\
		    	${INSTALL_DATA} $$j ${DOCSDIR}/$$i ;		\
		    fi; 						\
		done							\
	done
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

.endif
