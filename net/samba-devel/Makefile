# New ports collection makefile for:	samba
# Date created:				11th Feb 1995
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME=	samba
PORTVERSION=	3.0.2a
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://us3.samba.org/samba/ftp/%SUBDIR%/
MASTER_SITE_SUBDIR=	. rc old-versions
#DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free SMB and CIFS client and server for UNIX

CONFLICTS=	ja-samba-2.* samba-3.* sharity-light-1.*

USE_BZIP2=	yes
USE_SIZE=	yes
USE_RC_SUBR=	yes

.if !defined(WITHOUT_CUPS)
WITH_CUPS=	yes
.else
CONFIGURE_ARGS+=	--enable-cups=no
.endif

.if defined(WITH_CUPS)
LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib
.endif

# directories
VARDIR=		/var
SAMBA_SPOOL=	${VARDIR}/spool/samba
SAMBA_LOCKDIR?=	${VARDIR}/lock
SAMBA_LOGDIR?=	${VARDIR}/log
SAMBA_PRIVATE?=	${PREFIX}/private
SAMBA_CONFDIR?=	${PREFIX}/etc
# sample files
STARTUP_SCRIPT=	${LOCALBASE}/etc/rc.d/samba.sh.sample
SAMPLE_CONFIG=	${SAMBA_CONFDIR}/smb.conf.default
DOCSDIR=	${PREFIX}/share/doc/samba

NO_LATEST_LINK=	yes
USE_AUTOCONF=	yes
WANT_AUTOCONF_VER=	253
CONFIGURE_ARGS=	--libdir=${SAMBA_CONFDIR} \
		--localstatedir=${VARDIR} --with-swatdir=${PREFIX}/share/swat \
		--with-sambabook=${PREFIX}/share/swat/using_samba \
		--with-lockdir=${SAMBA_LOCKDIR} \
		--with-privatedir=${SAMBA_PRIVATE} \
		--exec-prefix=${PREFIX} --with-pam --without-manpages-langs \
		--with-piddir=${VARDIR}/run --with-logfilebase=${SAMBA_LOGDIR} \
		--with-configdir=${SAMBA_CONFDIR}

PLIST_SUB=	SAMBA_CONFDIR=${SAMBA_CONFDIR} \
		SAMBA_LOCKDIR=${SAMBA_LOCKDIR} \
		SAMBA_SPOOL=${SAMBA_SPOOL} \
		PYTHON_VERSION=${PYTHON_VERSION}

.if defined(WITH_PYTHON)
USE_PYTHON=	2.1+
CONFIGURE_ARGS+=	--with-python
PLIST_SUB+=	PYTHON=""
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_LDAP_COMPAT)
.ifndef(WITH_LDAP)
USE_OPENLDAP_VER?=	21
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib
.endif
CONFIGURE_ARGS+=	--with-ldapsam
.endif

.if defined(WITH_LDAP)
.ifndef(WITH_LDAP_COMPAT)
USE_OPENLDAP_VER?=	21
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib
.endif
CONFIGURE_ARGS+=	--with-ldap
.endif

.if defined(WITH_LDAP) && defined(WITH_LDAP_COMPAT)
USE_OPENLDAP_VER?=	21
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib
.endif

.if defined(WITH_ADS)
.ifndef(KRB5_HOME)
BROKEN=		"Needs KRB5_HOME=/path/to/Kerberos5_prefix"
.endif
.ifndef(WITH_LDAP) && !defined(WITH_LDAP_COMPAT)
BROKEN=		"Needs WITH_LDAP=yes or WITH_LDAP_COMPAT=yes"
.endif
CONFIGURE_ARGS+=	--with-ads
.endif

.if defined(WITH_SYSLOG)
CONFIGURE_ARGS+=	--with-syslog
.endif

.if defined(WITH_QUOTAS)
CONFIGURE_ARGS+=	--with-quotas
.endif

.if defined(WITH_SYS_QUOTAS)
CONFIGURE_ARGS+=	--with-sys-quotas
.endif

.if defined(WITH_UTMP)
CONFIGURE_ARGS+=	--with-utmp
.endif

.if defined(WITH_MSDFS)
CONFIGURE_ARGS+=	--with-msdfs
.endif

.if defined(WITH_WINBIND)
CONFIGURE_ARGS+=	--with-winbind
PLIST_SUB+=	WINBINDD=""
.else
CONFIGURE_ARGS+=	--without-winbind
PLIST_SUB+=	WINBINDD="@comment "
.endif

.if defined(KRB5_HOME) && exists(${KRB5_HOME})
CONFIGURE_ARGS+=	--with-krb5=${KRB5_HOME}
.else
CONFIGURE_ARGS+=	--with-krb5=no
.endif

.if defined(WITH_ACL_SUPPORT)
.if ${OSVERSION} < 500018
BROKEN=	"Requires a recent FreeBSD 5.0-CURRENT"
.else
CONFIGURE_ARGS+=	--with-acl-support
.endif
.endif

.if defined(WITH_LIBICONV)
.if exists(${LOCALBASE}/lib/libbiconv.so)
BROKEN=		"installed iconv-2.* port let's the character conversion capabilities detection fail. please deinstall it first if you want to use this feature"
.endif
.else
USE_ICONV=	yes
CONFIGURE_ARGS+=	--with-libiconv
.endif

.if defined(WITHOUT_POPT)
CONFIGURE_ARGS+=	--with-included-popt
.else
LIB_DEPENDS+=	popt.0:${PORTSDIR}/devel/popt
.endif

.if defined(WITH_READLINE)
CONFIGURE_ARGS+=	--with-readline
.endif

# experimantal SAM backends

.if defined(WITH_MYSQLSAM) && defined(WITH_POSTGRESQLSAM) && defined(WITH_XMLSAM)
USE_MYSQL?=	40
LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql-client \
		xml2.5:${PORTSDIR}/textproc/libxml2
CONFIGURE_ARGS+=	--with-expsam=mysql,pgsql,xml
PLIST_SUB+=	MYSQLSAM="" \
		POSTGRESQLSAM="" \
		XMLSAM=""
.endif
.if !defined(WITH_XMLSAM) && defined(WITH_MYSQLSAM) && defined(WITH_POSTGRESQLSAM)
USE_MYSQL?=	40
LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql-client
CONFIGURE_ARGS+=	--with-expsam=mysql,pgsql
PLIST_SUB+=	MYSQLSAM="" \
		POSTGRESQLSAM="" \
		XMLSAM="@comment "
.endif
.if !defined(WITH_POSTGRESQLSAM) && defined(WITH_MYSQLSAM) && defined(WITH_XMLSAM)
USE_MYSQL?=	40
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
CONFIGURE_ARGS+=	--with-expsam=mysql,xml
PLIST_SUB+=	MYSQLSAM="" \
		POSTGRESQLSAM="@comment " \
		XMLSAM=""
.endif
.if !defined(WITH_XMLSAM) && !defined(WITH_POSTGRESQLSAM) && defined(WITH_MYSQLSAM)
USE_MYSQL?=	40
CONFIGURE_ARGS+=	--with-expsam=mysql
PLIST_SUB+=	MYSQLSAM="" \
		POSTGRESQLSAM="@comment " \
		XMLSAM="@comment "
.endif
.if !defined(WITH_MYSQLSAM) && defined(WITH_POSTGRESQLSAM) && defined(WITH_XMLSAM)
LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql-client \
		xml2.5:${PORTSDIR}/textproc/libxml2
CONFIGURE_ARGS+=	--with-expsam=pgsql,xml
PLIST_SUB+=	MYSQLSAM="@comment " \
		POSTGRESQLSAM="" \
		XMLSAM=""
.endif
.if !defined(WITH_XMLSAM) && !defined(WITH_MYSQLSAM) && defined(WITH_POSTGRESQLSAM)
LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql-client
CONFIGURE_ARGS+=	--with-expsam=pgsql
PLIST_SUB+=	MYSQLSAM="@comment " \
		POSTGRESQLSAM="" \
		XMLSAM="@comment "
.endif
.if !defined(WITH_POSTGRESQLSAM) && !defined(WITH_MYSQLSAM) && defined(WITH_XMLSAM)
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
CONFIGURE_ARGS+=	--with-expsam=xml
PLIST_SUB+=	MYSQLSAM="@comment " \
		POSTGRESQLSAM="@comment " \
		XMLSAM=""
.endif
.if !defined(WITH_POSTGRESQLSAM) && !defined(WITH_MYSQLSAM) && !defined(WITH_XMLSAM)
PLIST_SUB+=	MYSQLSAM="@comment " \
		POSTGRESQLSAM="@comment " \
		XMLSAM="@comment "
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/source

MAN1=		findsmb.1 nmblookup.1 log2pcap.1 smbget.1 \
		rpcclient.1 smbcacls.1 smbclient.1 smbcontrol.1 smbsh.1 \
		smbstatus.1 smbtar.1 testparm.1 testprns.1 wbinfo.1 vfstest.1 \
		editreg.1 ntlm_auth.1 profiles.1 smbcquotas.1 smbtree.1
MAN5=		lmhosts.5 smb.conf.5 smbpasswd.5
MAN7=		samba.7
MAN8=		nmbd.8 smbd.8 smbmnt.8 smbmount.8 net.8 pdbedit.8 mount.cifs.8 \
		smbpasswd.8 smbspool.8 smbumount.8 swat.8 winbindd.8 \
		tdbdump.8 tdbbackup.8

pre-configure:
	@${ECHO_MSG} "->"
	@${ECHO_MSG} "-> you can enable or disable some features by defining following variables."
	@${ECHO_MSG} "->"
.ifndef(WITH_LDAP)
	@${ECHO_MSG} "-> WITH_LDAP		(ldap passdb backend, also needed by ADS)"
.endif
.ifndef(WITH_LDAP_COMPAT)
	@${ECHO_MSG} "-> WITH_LDAP_COMPAT	(ldap passdb backend 2.2.x compatible)"
.endif
.ifndef(WITH_ADS)
	@${ECHO_MSG} "-> WITH_ADS		(Active Directory CLIENT support, needs LDAP and KRB5)"
.endif
.ifndef(KRB5_HOME)
	@${ECHO_MSG} "-> KRB5_HOME		(path to Kerberos5, needed by ADS)"
.endif
.ifndef(WITH_QUOTAS)
	@${ECHO_MSG} "-> WITH_QUOTAS		(quota support)"
.endif
.ifndef(WITH_SYS_QUOTAS)
	@${ECHO_MSG} "-> WITH_SYS_QUOTAS	(new sys_quota support)"
.endif
.ifndef(WITH_ACL_SUPPORT)
	@${ECHO_MSG} "-> WITH_ACL_SUPPORT	(access control list support, requires FreeBSD-5.x)"
.endif
.ifndef(WITH_SYSLOG)
	@${ECHO_MSG} "-> WITH_SYSLOG		(enable syslog logging)"
.endif
.ifndef(WITH_UTMP)
	@${ECHO_MSG} "-> WITH_UTMP		(utmp logging)"
.endif
.ifndef(WITH_WINBIND)
	@${ECHO_MSG} "-> WITH_WINBIND		(build winbind daemon)"
.endif
.ifndef(WITH_MSDFS)
	@${ECHO_MSG} "-> WITH_MSDFS		(enable MicroSoft Distributed FileSystem capabilities)"
.endif
.ifndef(WITH_LIBICONV)
	@${ECHO_MSG} "-> WITH_LIBICONV	(enable character set conversion capabilities)"
.endif
.ifndef(WITH_READLINE)
	@${ECHO_MSG} "-> WITH_READLINE	(enable readline support)"
.endif
.ifndef(WITH_PYTHON)
	@${ECHO_MSG} "-> WITH_PYTHON		(build python libraries)"
.endif
.ifndef(WITH_MYSQLSAM)
	@${ECHO_MSG} "-> WITH_MYSQLSAM	(enable EXPERIMENTAL mysql - SAM backend)"
.endif
.ifndef(WITH_POSTGRESQLSAM)
	@${ECHO_MSG} "-> WITH_POSTGRESQLSAM	(enable EXPERIMENTAL postgresql - SAM backend)"
.endif
.ifndef(WITH_XMLSAM)
	@${ECHO_MSG} "-> WITH_XMLSAM		(enable EXPERIMENTAL xml - SAM backend)"
.endif
.ifndef(WITHOUT_CUPS)
	@${ECHO_MSG} "-> WITHOUT_CUPS		(disable CUPS printing support)"
.endif
.ifndef(WITHOUT_POPT)
	@${ECHO_MSG} "-> WITHOUT_POPT		(use the samba included popt library)"
.endif
	@${ECHO_MSG} "->"
	@${ECHO_MSG} "-> look in the Makefile for more tuneable variables."
	@${ECHO_MSG} "->"

post-install:
.if defined(WITH_PYTHON)
	@if [ ! -d ${PREFIX}/lib/${PYTHON_VERSION}/site-packages ]; then \
		${MKDIR} ${PREFIX}/lib/${PYTHON_VERSION}/site-packages ; \
	fi
	${CP} -r ${WRKSRC}/build/lib.*/samba \
		${PREFIX}/lib/${PYTHON_VERSION}/site-packages/
.endif
	${MKDIR} ${PREFIX}/share/examples/samba
	${CP} -rp ${WRKDIR}/${DISTNAME}/examples/* ${PREFIX}/share/examples/samba
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" -e "s|%%SAMBA_CONFDIR%%|${SAMBA_CONFDIR}|g" \
		-e "s|%%RC_SUBR%%|${RC_SUBR}|g" < \
		${FILESDIR}/samba.sh.sample > ${WRKDIR}/samba.sh.sample
	@if [ ! -f ${STARTUP_SCRIPT} ]; then				\
		${ECHO} "Installing ${STARTUP_SCRIPT} startup file." ;	\
		${INSTALL_SCRIPT} ${WRKDIR}/samba.sh.sample 		\
			${STARTUP_SCRIPT} ;				\
	fi
	@test -d ${SAMBA_SPOOL} || ${MKDIR} ${SAMBA_SPOOL} && ${CHMOD} 1777 ${SAMBA_SPOOL}
	@test -d ${SAMBA_LOCKDIR} || ${MKDIR} ${SAMBA_LOCKDIR} && ${CHMOD} 0755 ${SAMBA_LOCKDIR}
	@if [ ! -f ${SAMPLE_CONFIG} ]; then				\
		${SED} -e 's!%%SAMBA_SPOOL%%!${SAMBA_SPOOL}!'		\
			-e 's!%%SAMBA_LOGDIR%%!${SAMBA_LOGDIR}!'	\
			-e 's!%%SAMBA_CONFDIR%%!${SAMBA_CONFDIR}!'	\
			${FILESDIR}/smb.conf.default			\
			> ${SAMPLE_CONFIG} ;				\
	fi
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/source/script/mksmbpasswd.sh ${PREFIX}/bin/make_smbpasswd
	if [ ! -d ${SAMBA_PRIVATE} ] ; then				\
		${MKDIR} ${SAMBA_PRIVATE} ;				\
		${CHOWN} root:wheel ${SAMBA_PRIVATE} ;			\
	fi
	${CHMOD} 700 ${SAMBA_PRIVATE}
	if [ ! -f ${SAMBA_PRIVATE}/smbpasswd ] ; then			\
		${CAT} /etc/passwd | ${GREP} -v "^#" | ${PREFIX}/bin/make_smbpasswd > ${SAMBA_PRIVATE}/smbpasswd ; \
		${CHMOD} 600 ${SAMBA_PRIVATE}/smbpasswd ;			\
	fi
	${CHMOD} 500 ${SAMBA_PRIVATE}
	${CHOWN} root:wheel ${PREFIX}/bin/smbpasswd
	${CHMOD} 111 ${PREFIX}/bin/smbpasswd
.if defined(PACKAGE_BUILDING)
	${ECHO_CMD} "private/smbpasswd" >> ${TMPPLIST}
	${ECHO_CMD} "@dirrm private" >> ${TMPPLIST}
.else
	${ECHO_CMD} "@unexec ${ECHO_CMD} \"Warning: If you will *NOT* use this package anymore, please remove ${SAMBA_PRIVATE}/smbpasswd manually.\"" >> ${TMPPLIST}
.endif

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
		${INSTALL_DATA} $$i ${DOCSDIR} ;		\
	done
	for i in faq htmldocs Registry ; do			\
		${MKDIR} ${DOCSDIR}/$$i ;		\
		for j in ${WRKDIR}/${DISTNAME}/docs/$$i/* ; do		\
			if [ $$j != ${WRKDIR}/${DISTNAME}/docs/htmldocs/using_samba ] ; then \
				if [ $$j != ${WRKDIR}/${DISTNAME}/docs/textdocs/outdated ] ; then \
					if [ $$j != ${WRKDIR}/${DISTNAME}/docs/htmldocs/images ] ; then \
						${INSTALL_DATA} $$j ${DOCSDIR}/$$i ;\
					fi; \
				fi; \
			fi; \
		done							\
	done
.endif

.include <bsd.port.post.mk>
