# New ports collection makefile for:	samba
# Version required:			2.0.0
# Date created:				11th Feb 1995
# Whom:					gpalmer
#
# $Id: Makefile,v 1.29 1999/01/18 02:34:03 hosokawa Exp $
#

DISTNAME=	samba-2.0.0
#PKGNAME=	samba-2.0.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitcon.no/.7/unix/networking/samba/   \
		ftp://samba.anu.edu.au/pub/samba/

MAINTAINER=	hosokawa@jp.FreeBSD.org

Y2K=		http://us1.samba.org/samba/docs/sambay2k.html

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
CONFIGURE_ARGS=	--prefix=${PREFIX} --libdir=${SAMBA_CONFDIR} \
		--localstatedir=${VARDIR} --with-swatdir=${PREFIX}/share/swat
WRKSRC=		${WRKDIR}/${DISTNAME}/source

MAN1=		nmblookup.1 smbstatus.1 smbclient.1 smbrun.1 smbtar.1 \
		testparm.1 testprns.1 make_smbcodepage.1
MAN5=		smb.conf.5 smbpasswd.5 lmhosts.5
MAN7=		samba.7
MAN8=		smbd.8 nmbd.8 smbpasswd.8 swat.8 \
		smbmount.8 smbumount.8 smbmnt.8

post-install:
	${MKDIR} ${PREFIX}/share/examples/samba
	${CP} -rp ${WRKDIR}/${DISTNAME}/examples/* ${PREFIX}/share/examples/samba
	@if [ ! -f ${STARTUP_SCRIPT} ]; then				\
		${ECHO} "Installing ${STARTUP_SCRIPT} startup file." ;	\
		${INSTALL_SCRIPT} ${FILESDIR}/samba.sh.sample 		\
			${STARTUP_SCRIPT} ;				\
	fi
	@test -d ${SAMBA_SPOOL} || ${MKDIR} ${SAMBA_SPOOL} && chmod 1777 ${SAMBA_SPOOL}
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
		chown root.wheel ${SAMBA_PRIVATE} ;			\
	fi
	chmod 700 ${SAMBA_PRIVATE}
	if [ ! -f ${SAMBA_PRIVATE}/smbpasswd ] ; then			\
		${CAT} /etc/passwd | ${PREFIX}/bin/make_smbpasswd > ${SAMBA_PRIVATE}/smbpasswd ; \
		chmod 600 ${SAMBA_PRIVATE}/smbpasswd ;			\
	fi
	chmod 500 ${SAMBA_PRIVATE}
	chown root.wheel ${PREFIX}/bin/smbpasswd
	chmod 111 ${PREFIX}/bin/smbpasswd

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/samba
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${PREFIX}/share/doc/samba
	for i in ${WRKDIR}/${DISTNAME}/README				\
			${WRKDIR}/${DISTNAME}/COPYING			\
			${WRKDIR}/${DISTNAME}/WHATSNEW.txt		\
			${WRKDIR}/${DISTNAME}/Roadmap			\
			${WRKDIR}/${DISTNAME}/Manifest			\
			${WRKDIR}/${DISTNAME}/docs/*.reg		\
			${WRKDIR}/${DISTNAME}/docs/THANKS		\
			${WRKDIR}/${DISTNAME}/docs/announce		\
			${WRKDIR}/${DISTNAME}/docs/history		\
			${WRKDIR}/${DISTNAME}/docs/textdocs/* ; do	\
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba ;		\
	done
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/swat/README ${PREFIX}/share/doc/samba/README.swat
	${MKDIR} ${PREFIX}/share/doc/samba/faq
	for i in ${WRKDIR}/${DISTNAME}/docs/faq/* ; do			\
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba/faq ;	\
	done
.endif

.include <bsd.port.mk>
