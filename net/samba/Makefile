# New ports collection makefile for:	samba
# Date created:				11th Feb 1995
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME=	samba
PORTVERSION=	2.0.8
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.samba.org/pub/samba/%SUBDIR%/ \
		ftp://ring.asahi-net.or.jp/pub/net/samba/%SUBDIR%/ \
		ftp://samba.anu.edu.au/pub/samba/%SUBDIR%/ \
		ftp://de.samba.org/pub/mirror/samba/%SUBDIR%/ \
		ftp://se.samba.org/pub/samba/%SUBDIR%/ \
		ftp://ftp.sunet.se/pub/unix/utilities/samba/%SUBDIR%/
MASTER_SITE_SUBDIR= . old-versions old

MAINTAINER=	dwcjr@inethouston.net

# directories
VARDIR=		/var
SAMBA_SPOOL=	${VARDIR}/spool/samba
SAMBA_LOGDIR=	${VARDIR}/log
SAMBA_PRIVATE=	${PREFIX}/private
SAMBA_CONFDIR=	${PREFIX}/etc
# sample files
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/samba.sh.sample
SAMPLE_CONFIG=	${SAMBA_CONFDIR}/smb.conf.default

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	 --libdir=${SAMBA_CONFDIR} \
		--localstatedir=${VARDIR} --with-swatdir=${PREFIX}/share/swat \
		--with-sambabook=${PREFIX}/share/swat/using_samba \
		--with-lockdir=${VARDIR}/spool/lock \
		--with-privatedir=${SAMBA_PRIVATE}

.if defined(KRB5_HOME) && exists(${KRB5_HOME})
CONFIGURE_ARGS+=--with-krb5=${KRB5_HOME}
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/source

MAN1=		nmblookup.1 smbstatus.1 smbclient.1 smbrun.1 smbtar.1 \
		testparm.1 testprns.1 make_smbcodepage.1 smbsh.1 \
		make_unicodemap.1
MAN5=		smb.conf.5 smbpasswd.5 lmhosts.5
MAN7=		samba.7
MAN8=		smbd.8 nmbd.8 smbpasswd.8 swat.8 smbspool.8 \
		smbmount.8 smbumount.8 smbmnt.8

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
		${CHOWN} root.wheel ${SAMBA_PRIVATE} ;			\
	fi
	${CHMOD} 700 ${SAMBA_PRIVATE}
	if [ ! -f ${SAMBA_PRIVATE}/smbpasswd ] ; then			\
		${CAT} /etc/passwd | ${GREP} -v "^#" | ${PREFIX}/bin/make_smbpasswd > ${SAMBA_PRIVATE}/smbpasswd ; \
		${CHMOD} 600 ${SAMBA_PRIVATE}/smbpasswd ;			\
	fi
	${CHMOD} 500 ${SAMBA_PRIVATE}
	${CHOWN} root.wheel ${PREFIX}/bin/smbpasswd
	${CHMOD} 111 ${PREFIX}/bin/smbpasswd
.if defined(PACKAGE_BUILDING)
	${ECHO} "private/smbpasswd" >> ${TMPPLIST}
	${ECHO} "@dirrm private" >> ${TMPPLIST}
.else
	${ECHO} "@unexec echo \"Warning: If you will *NOT* use this package anymore, please remove %D/private/smbpasswd manually.\"" >> ${TMPPLIST}
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/samba
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${PREFIX}/share/doc/samba
	for i in ${WRKDIR}/${DISTNAME}/README				\
			${WRKDIR}/${DISTNAME}/COPYING			\
			${WRKDIR}/${DISTNAME}/Manifest			\
			${WRKDIR}/${DISTNAME}/Read-Manifest-Now		\
			${WRKDIR}/${DISTNAME}/Roadmap			\
			${WRKDIR}/${DISTNAME}/WHATSNEW.txt		\
			${WRKDIR}/${DISTNAME}/docs/*.reg		\
			${WRKDIR}/${DISTNAME}/docs/THANKS		\
			${WRKDIR}/${DISTNAME}/docs/announce		\
			${WRKDIR}/${DISTNAME}/docs/history ; do		\
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba ;		\
	done
	for i in faq htmldocs textdocs yodldocs ; do			\
		${MKDIR} ${PREFIX}/share/doc/samba/$$i ;		\
		for j in ${WRKDIR}/${DISTNAME}/docs/$$i/* ; do		\
			if [ $$j != ${WRKDIR}/${DISTNAME}/docs/htmldocs/using_samba ] ; then \
				${INSTALL_DATA} $$j ${PREFIX}/share/doc/samba/$$i ;\
			fi; \
		done							\
	done
	${MKDIR} ${PREFIX}/share/doc/samba
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/swat/README ${PREFIX}/share/doc/samba/README.swat
.endif

.include <bsd.port.mk>
