# New ports collection makefile for:	samba
# Date created:				11th Feb 1995
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME=	samba
PORTVERSION=	3.0.0
PORTEPOCH=	1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://us3.samba.org/samba/ftp/%SUBDIR%/
MASTER_SITE_SUBDIR=	. rc
#DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	dwcjr@FreeBSD.org
COMMENT=	A free SMB and CIFS client and server for UNIX

CONFLICTS=	ja-samba-2.* samba-3.* samba-libsmbclient-3.* sharity-light-1.*

USE_BZIP2=	yes

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
SAMBA_LOGDIR=	${VARDIR}/log
SAMBA_PRIVATE=	${PREFIX}/private
SAMBA_CONFDIR=	${PREFIX}/etc
# sample files
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/samba.sh.sample
SAMPLE_CONFIG=	${SAMBA_CONFDIR}/smb.conf.default
DOCSDIR=	${PREFIX}/share/doc/samba

NO_LATEST_LINK=	yes
USE_AUTOCONF=	yes
WANT_AUTOCONF_VER=	253
CONFIGURE_ARGS+=--libdir=${SAMBA_CONFDIR} \
		--localstatedir=${VARDIR} --with-swatdir=${PREFIX}/share/swat \
		--with-sambabook=${PREFIX}/share/swat/using_samba \
		--with-lockdir=${VARDIR}/lock --with-privatedir=${SAMBA_PRIVATE} \
		--exec-prefix=${PREFIX} --with-pam --without-manpages-langs \
		--with-piddir=${VARDIR}/run --with-logfilebase=${VARDIR}/log

.include <bsd.port.pre.mk>

.if defined(WITH_QUOTAS)
CONFIGURE_ARGS+=	--with-quotas
.endif

.if defined(WITH_UTMP)
CONFIGURE_ARGS+=	--with-utmp
.endif

.if defined(WITH_MSDFS)
CONFIGURE_ARGS+=	--with-msdfs
.endif

.if defined(WITH_WINBIND)
CONFIGURE_ARGS+=	--with-winbind
.endif

.if defined(WITH_WINBIND_AUTH_CHALLENGE)
CONFIGURE_ARGS+=	--with-winbind-auth-challenge
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
LIB_DEPENDS+=		iconv.3:${PORTSDIR}/converters/libiconv
CONFIGURE_ARGS+=	--with-libiconv
.endif

.if defined(WITHOUT_POPT)
CONFIGURE_ARGS+=	--with-included-popt
.else
LIB_DEPENDS+=		popt.0:${PORTSDIR}/devel/popt
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/source

MAN1=		findsmb.1 nmblookup.1 log2pcap.1 \
		rpcclient.1 smbcacls.1 smbclient.1 smbcontrol.1 smbsh.1 \
		smbstatus.1 smbtar.1 testparm.1 testprns.1 wbinfo.1 vfstest.1 \
		editreg.1 ntlm_auth.1 profiles.1 smbcquotas.1 smbtree.1
MAN5=		lmhosts.5 smb.conf.5 smbpasswd.5
MAN7=		samba.7 Samba.7
MAN8=		nmbd.8 smbd.8 smbmnt.8 smbmount.8 net.8 pdbedit.8 mount.cifs.8 \
		smbpasswd.8 smbspool.8 smbumount.8 swat.8 winbindd.8 tdbbackup.8

post-install:
	${MKDIR} ${PREFIX}/share/examples/samba
	${CP} -rp ${WRKDIR}/${DISTNAME}/examples/* ${PREFIX}/share/examples/samba
	@if [ ! -f ${STARTUP_SCRIPT} ]; then				\
		${ECHO} "Installing ${STARTUP_SCRIPT} startup file." ;	\
		${INSTALL_SCRIPT} ${FILESDIR}/samba.sh.sample 		\
			${STARTUP_SCRIPT} ;				\
	fi
	@test -d ${SAMBA_SPOOL} || ${MKDIR} ${SAMBA_SPOOL} && ${CHMOD} 1777 ${SAMBA_SPOOL}
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
	${ECHO_CMD} "@unexec ${ECHO_CMD} \"Warning: If you will *NOT* use this package anymore, please remove %D/private/smbpasswd manually.\"" >> ${TMPPLIST}
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
					${INSTALL_DATA} $$j ${DOCSDIR}/$$i ;\
				fi; \
			fi; \
		done							\
	done
.endif

.include <bsd.port.post.mk>
