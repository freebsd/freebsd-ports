# Ports collection makefile for:  smtpd
# Version required:		2.0
# Date created:			06 Feb 1998
# Whom:				Joao Carlos Mendes Luis <jonny@jonny.eng.br>
#
# $Id: Makefile,v 1.1.1.1 1998/03/01 01:58:51 obrien Exp $
#

DISTNAME=      smtpd-2.0
CATEGORIES=    mail security
MASTER_SITES=  ftp://ftp.obtuse.com/pub/smtpd/

PATCH_SITES=   ${MASTER_SITES}
PATCHFILES=    patch-smtpd-2.0-RBL.gz

MAINTAINER=    jonny@jonny.eng.br

#  Directory where smtpd will chroot to, and put the received mail
#  If you change it here, change also patches/patch-aa
SPOOLBASE=	/var/smtpd

post-patch:
	@mv ${WRKSRC}/Makefile ${WRKSRC}/Makefile.tmp
	@sed s+!!SPOOLBASE!!+${SPOOLBASE}+g < ${WRKSRC}/Makefile.tmp \
	                                    > ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${PREFIX}/share/doc/smtpd
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/smtpd

	@${ECHO} "Creating spool directories..."
	@${MKDIR} ${SPOOLBASE}
	@chown root.uucp ${SPOOLBASE}
	@chmod 0710 ${SPOOLBASE}

	@${MKDIR} ${SPOOLBASE}/mqueue
	@chown uucp.uucp ${SPOOLBASE}/mqueue
	@chmod 0700 ${SPOOLBASE}/mqueue

	@${MKDIR} ${SPOOLBASE}/etc
	@chown root.uucp ${SPOOLBASE}/etc
	@chmod 0710 ${SPOOLBASE}/etc
.if !defined(BATCH)
	@${CP} -p /etc/resolv.conf ${SPOOLBASE}/etc
	@${CP} -p /etc/localtime ${SPOOLBASE}/etc
.endif

	@${ECHO} "Copying examples..."
	@${INSTALL} ${COPY} -g uucp -o root -m 0640		\
		${WRKSRC}/antirelay_check_rules_example	\
		${SPOOLBASE}/etc/antirelay_check_rules.example
	@${INSTALL} ${COPY} -g uucp -o root -m 0640		\
		${WRKSRC}/antispam_check_rules.example	\
		${SPOOLBASE}/etc
	@${INSTALL} ${COPY} -g uucp -o root -m 0640		\
		${WRKSRC}/smtpd_check_rules.example	\
		${SPOOLBASE}/etc

	@${ECHO} "Creating startup file..."
	@sed s+!!PREFIX!!+${PREFIX}+		\
		< ${FILESDIR}/smtpd.sh		\
		> ${PREFIX}/etc/rc.d/smtpd.sh
	@chmod 0700 ${PREFIX}/etc/rc.d/smtpd.sh
	@chown 0.0 ${PREFIX}/etc/rc.d/smtpd.sh

	@${ECHO} "Done!"

	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
