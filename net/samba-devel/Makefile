# New ports collection makefile for:	samba
# Version required:			1.9.17p4
# Date created:				11th Feb 1995
# Whom:					gpalmer
#
# $Id: Makefile,v 1.3 1997/10/15 09:02:45 max Exp $
#

DISTNAME=	samba-1.9.17p4
PKGNAME=	ja-samba-1.9.17.4
CATEGORIES=	japanese net
MASTER_SITES=	ftp://samba.anu.edu.au/pub/samba/

MAINTAINER=	hosokawa@jp.FreeBSD.ORG

WRKSRC=		${WRKDIR}/${DISTNAME}/source
MAN1=		smbstatus.1 smbclient.1 smbrun.1 smbtar.1 testparm.1 testprns.1
MAN5=		smb.conf.5
MAN7=		samba.7
MAN8=		smbd.8 nmbd.8 smbpasswd.8

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/samba.sh.sample
SAMPLE_CONFIG=	${PREFIX}/etc/smb.conf.sample
SAMBA_SPOOL=	/var/spool/samba
XSAMBA_SPOOL=	\/var\/spool\/samba
SAMBA_LOGDIR=	/var/log
XSAMBA_LOGDIR=	\/var\/log

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/samba/faq
	for i in ${WRKDIR}/${DISTNAME}/docs/*.txt ${WRKDIR}/${DISTNAME}/docs/README* ; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba ; \
	done
	for i in ${WRKDIR}/${DISTNAME}/docs/faq/* ; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba/faq ; \
	done
.endif
	@if [ ! -f ${STARTUP_SCRIPT} ]; then				\
		${ECHO} "Installing ${STARTUP_SCRIPT} startup file." ;	\
		${ECHO} '#!/bin/sh' > ${STARTUP_SCRIPT} ;			\
		${ECHO} 'smbd=${PREFIX}/sbin/smbd' >> ${STARTUP_SCRIPT} ;\
		${ECHO} 'nmbd=${PREFIX}/sbin/nmbd' >> ${STARTUP_SCRIPT} ;\
		${ECHO} 'if [ -f $$smbd ]; then' >> ${STARTUP_SCRIPT} ;	\
		${ECHO} "	${ECHO} -n ' Samba'" >> ${STARTUP_SCRIPT} ;\
		${ECHO} '	$$smbd -D' >> ${STARTUP_SCRIPT} ;	\
		${ECHO} '	$$nmbd -D' >> ${STARTUP_SCRIPT} ;	\
		${ECHO} "fi" >> ${STARTUP_SCRIPT} ;			\
		chmod 755 ${STARTUP_SCRIPT} ;				\
		chown bin.bin ${STARTUP_SCRIPT};			\
	fi
	@test -d ${SAMBA_SPOOL} || ${MKDIR} ${SAMBA_SPOOL} && chmod 1777 ${SAMBA_SPOOL}
	@if [ ! -f ${SAMPLE_CONFIG} ]; then				\
		${SED} -e 's/__SAMBA_SPOOL__/${XSAMBA_SPOOL}/'		\
		    -e 's/__LOGDIR__/${XSAMBA_LOGDIR}/' 		\
			${FILESDIR}/smb.conf.sample			\
			> ${SAMPLE_CONFIG} ;				\
	fi

.include <bsd.port.mk>
