# New ports collection makefile for:	samba
# Date created:				11th Feb 1995
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME=	samba
PORTVERSION=	2.2.12
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SAMBA}
MASTER_SITE_SUBDIR=	. old-versions

.if defined(WITH_JAIL)
# This patch was originally created by Gerhard Sittig <Gerhard.Sittig@gmx.net>
# See PR ports/22316
# Reworked/updated and portsified by anders@FreeBSD.org, 2003-11-08
PATCH_SITES+=	ftp://totem.fix.no/pub/mirrors/misc/:smbjail \
		ftp://ftp.nuug.no/pub/anders/distfiles/:smbjail
PATCHFILES+=	samba-2.2.10-freebsd-jail-patch-20040806.gz:smbjail
.endif
.if defined(WITH_BROWSING_HACKS)
PATCH_SITES+=	http://cell.sick.ru/~glebius/patches/ \
		http://people.FreeBSD.org/~glebius/
PATCHFILES+=	samba-2.2.9-browsing-hacks.diff
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free SMB and CIFS client and server for UNIX

FORBIDDEN=	http://vuxml.FreeBSD.org/3b3676be-52e1-11d9-a9e7-0001020eed82.html
EXPIRATION_DATE=2006-08-20

CONFLICTS=	ja-samba-2.* samba-3.* sharity-light-1.*
USE_SUBMAKE=	YES
USE_GMAKE=	YES
USE_AUTOTOOLS=	autoconf:213 libtool:15

# directories
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

AUDIT?=		"@comment "
RECYCLE?=	"@comment "
LIBSAMBA?=	"@comment "
BUILD_VFS?=	"@comment "
WINBIND?=	"@comment "
WINBIND_NSS?=	"@comment "
WINBIND_AUTH_CHALLENGE?=	"@comment "

.if defined(WITH_AUDIT)
AUDIT=		""
LIBSAMBA=	""
BUILD_VFS=	""
.endif

.if defined(WITH_RECYCLE)
RECYCLE=	""
LIBSAMBA=	""
BUILD_VFS=	""
.endif

VARDIR=		/var
SAMBA_SPOOL=	${VARDIR}/spool/samba
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		CAT="${CAT}" \
		SAMBA_OPTIONS="${SAMBA_OPTIONS}" \
		REALCURDIR="${.CURDIR}"

SAMBA_LOGDIR?=	${VARDIR}/log
SAMBA_PRIVATE?=	${PREFIX}/private
SAMBA_CONFDIR?=	${PREFIX}/etc
SAMBA_VFSDIR?=	${PREFIX}/lib/samba

# sample files
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/samba.sh.sample
SAMPLE_CONFIG=	${SAMBA_CONFDIR}/smb.conf.default

CONFIGURE_ARGS=	--libdir=${SAMBA_CONFDIR} \
		--localstatedir=${VARDIR} --with-swatdir=${PREFIX}/share/swat \
		--with-sambabook=${PREFIX}/share/swat/using_samba \
		--with-lockdir=${VARDIR}/lock --with-privatedir=${SAMBA_PRIVATE} \
		--with-pam --with-piddir=${VARDIR}/run \
		--with-logfilebase=${SAMBA_LOGDIR}

.include <bsd.port.pre.mk>

CONFIGURE_ENV+=	TESTDIR=/tmp

.if defined(WITH_SYSLOG)
CONFIGURE_ARGS+=	--with-syslog
.endif

.if defined(WITH_SSL)
CONFIGURE_ARGS+=	--with-ssl --with-sslinc=/usr/include/openssl --with-ssllib=/usr/lib
.endif

.if defined(WITH_QUOTAS)
CONFIGURE_ARGS+=	--with-quotas
.endif

.if defined(WITH_UTMP)
CONFIGURE_ARGS+=	--with-utmp
.endif

.if defined(WITH_MSDFS)
CONFIGURE_ARGS+=	--with-msdfs
.endif

.if defined(WITH_INCLUDED_POPT)
CONFIGURE_ARGS+=	--with-included-popt
.else
LIB_DEPENDS+=	popt.0:${PORTSDIR}/devel/popt
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-ldapsam
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib
.endif

.if !defined(WITHOUT_CUPS)
WITH_CUPS=	yes
.endif

.if defined(WITH_WINBIND)
CONFIGURE_ARGS+=	--with-winbind
WINBIND=	""
.else
CONFIGURE_ARGS+=	--without-winbind
.endif

.if defined(WITH_WINBIND_NSS)
.if ${OSVERSION} < 500112
BROKEN=		NSS modules only supported on FreeBSD 5.1 or later
.else
WINBIND_NSS=	""
.endif
.endif

.if defined(WITH_WINBIND_AUTH_CHALLENGE)
CONFIGURE_ARGS+=	--with-winbind-auth-challenge
WINBIND_AUTH_CHALLENGE=	""
.endif

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.samba

post-patch:
	${FIND} ${PATCH_WRKSRC} -type f -name '*.orig' -exec ${RM} {} \;
	${FIND} ${PATCH_WRKSRC} -type f -empty -exec ${RM} {} \;
	${CP} ${FILESDIR}/winbind_nss_bsd.c ${WRKSRC}/nsswitch/
	${CHMOD} a+x ${WRKSRC}/../examples/VFS/configure

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if defined(WITH_CUPS)
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-cups
.endif

.if defined(KRB5_HOME) && exists(${KRB5_HOME})
CONFIGURE_ARGS+=	--with-krb5=${KRB5_HOME}
.endif

.if defined(WITH_ACL_SUPPORT)
.if ${OSVERSION} < 500018
BROKEN=	"ACL support requires a recent FreeBSD 5.0-CURRENT"
.else
CONFIGURE_ARGS+=	--with-acl-support
.endif
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/source
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}

LIBTOOLFILES=		${WRKSRC}/aclocal.m4

MAN1=		findsmb.1 make_smbcodepage.1 rpcclient.1 make_unicodemap.1 \
		nmblookup.1 smbcacls.1 smbclient.1 smbcontrol.1 \
		smbsh.1 smbstatus.1 smbtar.1 testparm.1 \
		testprns.1 wbinfo.1
MAN5=		lmhosts.5 smb.conf.5 smbpasswd.5
MAN7=		samba.7
MAN8=		nmbd.8 pdbedit.8 smbd.8 smbmnt.8 smbmount.8 \
		smbpasswd.8 smbspool.8 smbumount.8 swat.8 winbindd.8

SED_PLIST=	${SED} -e 's!${PREFIX}!%D!g'

PLIST_SUB=	AUDIT=${AUDIT} \
		RECYCLE=${RECYCLE} \
		LIBSAMBA=${LIBSAMBA} \
		BUILD_VFS=${BUILD_VFS} \
		WINBIND=${WINBIND} \
		WINBIND_NSS=${WINBIND_NSS} \
		WINBIND_AUTH_CHALLENGE=${WINBIND_AUTH_CHALLENGE}

.if defined(WITH_RECYCLE) || defined(WITH_AUDIT)
post-build:
	cd ${WRKDIR}/${DISTNAME}/examples/VFS; \
		LIBTOOL=${LIBTOOL} ./configure;${GMAKE}; \
		${RM} -f config.cache config.log config.status
.endif

pre-build:
	${RM} -fr ${WRKSRC}/include/proto.h
	(cd ${WRKSRC} && make proto)
	${SED} -e 's!%%PREFIX%%!${PREFIX}!' \
		${FILESDIR}/samba.sh.sample > ${WRKDIR}/samba.sh.sample

post-install:
.if defined(WITH_WINBIND_NSS)
	${INSTALL_PROGRAM} ${WRKSRC}/nsswitch/libnss_winbind.so ${PREFIX}/lib/nss_winbind.so.1
.endif
.if defined(WITH_AUDIT) || defined(WITH_RECYCLE)
	@test -d ${SAMBA_VFSDIR} || ${MKDIR} ${SAMBA_VFSDIR}
.if defined(WITH_AUDIT)
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/examples/VFS/audit.so ${SAMBA_VFSDIR}
.endif
.if defined(WITH_RECYCLE)
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/examples/VFS/recycle/recycle.so ${SAMBA_VFSDIR}
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/examples/VFS/recycle/recycle.conf \
		${SAMBA_CONFDIR}/recycle.conf.default
.endif
.endif
	${MKDIR} ${PREFIX}/share/examples/samba
	-${RM} -f ${WRKDIR}/${DISTNAME}/examples/libsmbclient/*.o
	${CP} -rp ${WRKDIR}/${DISTNAME}/examples/* ${PREFIX}/share/examples/samba
.if defined(WITH_AUDIT) || defined(WITH_RECYCLE)
#	@${RM} -rf ${PREFIX}/share/examples/samba/VFS/.libs
	${FIND} ${PREFIX}/share/examples/samba/VFS -type d -name ".libs" | ${XARGS} ${RM} -r
	@for ifile in audit.o audit.so recycle/recycle.o recycle/recycle.so skel.o skel.so ; do \
		${RM} ${PREFIX}/share/examples/samba/VFS/$${ifile} ; \
	done
.endif
	@if [ ! -f ${STARTUP_SCRIPT} ]; then				\
		${ECHO} "Installing ${STARTUP_SCRIPT} startup file." ;	\
		${INSTALL_SCRIPT} ${WRKDIR}/samba.sh.sample 		\
			${STARTUP_SCRIPT} ;				\
	fi
	@test -d ${SAMBA_SPOOL} || ${MKDIR} ${SAMBA_SPOOL} && ${CHMOD} 1777 ${SAMBA_SPOOL}
	@if [ ! -f ${SAMPLE_CONFIG} ]; then				\
		${SED} -e 's!%%SAMBA_SPOOL%%!${SAMBA_SPOOL}!'		\
			-e 's!%%SAMBA_LOGDIR%%!${SAMBA_LOGDIR}!'	\
			-e 's!%%SAMBA_CONFDIR%%!${SAMBA_CONFDIR}!'	\
			-e 's!%%SAMBA_VFSDIR%%!${SAMBA_VFSDIR}!'	\
			${FILESDIR}/smb.conf.default			\
			> ${SAMPLE_CONFIG} ;				\
	fi
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/source/script/mksmbpasswd.sh ${PREFIX}/bin/make_smbpasswd
	if [ ! -d ${SAMBA_PRIVATE} ] ; then				\
		${MKDIR} ${SAMBA_PRIVATE} ;				\
		${CHOWN} root:wheel ${SAMBA_PRIVATE} ;			\
	fi
	${CHMOD} 700 ${SAMBA_PRIVATE}
	if [ ! -f ${SAMBA_PRIVATE}/smbpasswd.default ] ; then		\
		${CAT} /etc/passwd | ${GREP} -v "^#" | ${PREFIX}/bin/make_smbpasswd > ${SAMBA_PRIVATE}/smbpasswd.default ; \
		${CHMOD} 600 ${SAMBA_PRIVATE}/smbpasswd.default ;	\
	fi
	if [ ! -f ${SAMBA_PRIVATE}/smbpasswd ] ; then			\
		${CP} -p ${SAMBA_PRIVATE}/smbpasswd.default ${SAMBA_PRIVATE}/smbpasswd ; \
		${CHMOD} 600 ${SAMBA_PRIVATE}/smbpasswd ;		\
	fi
	${CHMOD} 500 ${SAMBA_PRIVATE}
	${CHOWN} root:wheel ${PREFIX}/bin/smbpasswd
	${CHMOD} 111 ${PREFIX}/bin/smbpasswd
	${ECHO_CMD} "@exec ${TEST} -d ${SAMBA_SPOOL} || ${MKDIR} ${SAMBA_SPOOL} && ${CHMOD} 1777 ${SAMBA_SPOOL}" | ${SED_PLIST} >> ${TMPPLIST}
	${ECHO_CMD} "@unexec ${RM} -rf ${SAMBA_SPOOL}" | ${SED_PLIST} >> ${TMPPLIST}
	${ECHO_CMD} "@exec ${MKDIR} -m 500 ${SAMBA_PRIVATE}" | ${SED_PLIST} >> ${TMPPLIST}
	${ECHO_CMD} "@exec ${CHOWN} root:wheel ${SAMBA_PRIVATE}" | ${SED_PLIST} >> ${TMPPLIST}
	${ECHO_CMD} "@exec ${CAT} /etc/passwd | ${GREP} -v "^#" | ${PREFIX}/bin/make_smbpasswd > ${SAMBA_PRIVATE}/smbpasswd.default" | ${SED_PLIST} >> ${TMPPLIST}
	${ECHO_CMD} "@exec ${TEST} -e ${SAMBA_PRIVATE}/smbpasswd || ${CP} -p ${SAMBA_PRIVATE}/smbpasswd.default ${SAMBA_PRIVATE}/smbpasswd" | ${SED_PLIST} >> ${TMPPLIST}
	${ECHO_CMD} "@exec ${CHMOD} 600 ${SAMBA_PRIVATE}/smbpasswd*" | ${SED_PLIST} >> ${TMPPLIST}
	${ECHO_CMD} "@unexec /usr/bin/cmp -s ${SAMBA_PRIVATE}/smbpasswd ${SAMBA_PRIVATE}/smbpasswd.default && ${RM} -f ${SAMBA_PRIVATE}/smbpasswd || ${TRUE}" | ${SED_PLIST} >> ${TMPPLIST}
	${ECHO_CMD} "@unexec ${RM} -f ${SAMBA_PRIVATE}/smbpasswd.default" | ${SED_PLIST} >> ${TMPPLIST}
	${ECHO_CMD} "@unexec ${RMDIR} ${SAMBA_PRIVATE} || (${ECHO_CMD} \"Warning: If you will *NOT* use this package anymore,\" && ${ECHO_CMD} \"         please remove ${SAMBA_PRIVATE} and its contents manually.\")" | ${SED_PLIST} >> ${TMPPLIST}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${DOCSDIR}
	for i in ${WRKDIR}/${DISTNAME}/README				\
			${WRKDIR}/${DISTNAME}/COPYING			\
			${WRKDIR}/${DISTNAME}/Manifest			\
			${WRKDIR}/${DISTNAME}/Roadmap			\
			${WRKDIR}/${DISTNAME}/WHATSNEW.txt		\
			${WRKDIR}/${DISTNAME}/docs/THANKS		\
			${WRKDIR}/${DISTNAME}/docs/announce		\
			${WRKDIR}/${DISTNAME}/docs/history ; do		\
		${INSTALL_DATA} $$i ${DOCSDIR} ;		\
	done
	for i in faq htmldocs textdocs Registry ; do			\
		${MKDIR} ${DOCSDIR}/$$i ;		\
		for j in ${WRKDIR}/${DISTNAME}/docs/$$i/* ; do		\
			if [ $$j != ${WRKDIR}/${DISTNAME}/docs/htmldocs/using_samba ] ; then \
				if [ $$j != ${WRKDIR}/${DISTNAME}/docs/textdocs/outdated ] ; then \
					${INSTALL_DATA} $$j ${DOCSDIR}/$$i ;\
				fi; \
			fi; \
		done							\
	done
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/swat/README ${DOCSDIR}/README.swat
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
