# New ports collection makefile for:	samba
# Version required:			1.9.18
# Date created:				11th Feb 1995
# Whom:					gpalmer
#
# $Id: Makefile,v 1.27 1998/08/28 02:07:45 hosokawa Exp $
#

DISTNAME=	samba-1.9.18p10
PKGNAME=	samba-1.9.18.10
CATEGORIES=	net
MASTER_SITES=	ftp://samba.anu.edu.au/pub/samba/

MAINTAINER=	hosokawa@jp.FreeBSD.ORG

Y2K=		http://us1.samba.org/samba/docs/sambay2k.html

WRKSRC=		${WRKDIR}/${DISTNAME}/source
MAN1=		smbstatus.1 smbclient.1 smbrun.1 smbtar.1 testparm.1 testprns.1 make_smbcodepage.1
MAN5=		smb.conf.5
MAN7=		samba.7
MAN8=		smbd.8 nmbd.8 smbpasswd.8

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/samba.sh.sample
SAMPLE_CONFIG=	${PREFIX}/etc/smb.conf.default
SAMBA_SPOOL=	/var/spool/samba
XSAMBA_SPOOL=	\/var\/spool\/samba
SAMBA_LOGDIR=	/var/log
XSAMBA_LOGDIR=	\/var\/log
SAMBA_PRIVATE=	${PREFIX}/private

SAMBA_DOCS=${WRKDIR}/${DISTNAME}/docs/INSTALL.sambatar \
	${WRKDIR}/${DISTNAME}/docs/THANKS \
	${WRKDIR}/${DISTNAME}/docs/history \
	${WRKDIR}/${DISTNAME}/docs/announce \
	${WRKDIR}/${DISTNAME}/docs/PROJECTS \
	${WRKDIR}/${DISTNAME}/docs/SMBTAR.notes

post-install:
	${MKDIR} ${PREFIX}/share/examples/samba
	${CP} -rp ${WRKDIR}/${DISTNAME}/examples/* ${PREFIX}/share/examples/samba
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/samba/faq
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${PREFIX}/share/doc/samba
	for i in ${SAMBA_DOCS} ${WRKDIR}/${DISTNAME}/docs/*.txt		\
			${WRKDIR}/${DISTNAME}/docs/*.reg		\
			${WRKDIR}/${DISTNAME}/docs/*.htm		\
			${WRKDIR}/${DISTNAME}/*.txt			\
			${WRKDIR}/${DISTNAME}/README			\
			${WRKDIR}/${DISTNAME}/docs/README.* ; do	\
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba ;		\
	done
	for i in ${WRKDIR}/${DISTNAME}/docs/faq/* ; do			\
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba/faq ;	\
	done
.endif
	@if [ ! -f ${STARTUP_SCRIPT} ]; then				\
		${ECHO} "Installing ${STARTUP_SCRIPT} startup file." ;	\
		${INSTALL_SCRIPT} ${FILESDIR}/samba.sh.sample 		\
			${STARTUP_SCRIPT} ;				\
	fi
	@test -d ${SAMBA_SPOOL} || ${MKDIR} ${SAMBA_SPOOL} && chmod 1777 ${SAMBA_SPOOL}
	@if [ ! -f ${SAMPLE_CONFIG} ]; then				\
		${SED} -e 's/__SAMBA_SPOOL__/${XSAMBA_SPOOL}/'		\
		    -e 's/__LOGDIR__/${XSAMBA_LOGDIR}/' 		\
			${FILESDIR}/smb.conf.default			\
			> ${SAMPLE_CONFIG} ;				\
	fi
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/source/mksmbpasswd.sh ${PREFIX}/bin
	if [ ! -d ${SAMBA_PRIVATE} ] ; then				\
		${MKDIR} ${SAMBA_PRIVATE} ;				\
		chown root.wheel ${SAMBA_PRIVATE} ;			\
	fi
	chmod 700 ${SAMBA_PRIVATE}
	if [ ! -f ${SAMBA_PRIVATE}/smbpasswd ] ; then			\
		${CAT} /etc/passwd | ${PREFIX}/bin/mksmbpasswd.sh > ${SAMBA_PRIVATE}/smbpasswd ; \
		chmod 600 ${SAMBA_PRIVATE}/smbpasswd ;			\
	fi
	chmod 500 ${SAMBA_PRIVATE}
	chown root.wheel ${PREFIX}/bin/smbpasswd
	chmod 111 ${PREFIX}/bin/smbpasswd

.include <bsd.port.mk>
