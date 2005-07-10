# Ports collection makefile for:  smtpd
# Date created:			06 Feb 1998
# Whom:				Joao Carlos Mendes Luis <jonny@jonny.eng.br>
#
# $FreeBSD$
#

PORTNAME=	smtpd
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	mail security
MASTER_SITES=	http://ftp.rge.com/pub/mail/smtpd/ \
		http://www.netsw.org/net/ip/firewall/proxy/smtpd/ \
		ftp://ftp.obtuse.com/pub/smtpd/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	patch-smtpd-2.0-RBL.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Obtuse smtpd/smtpfwdd, part of the Juniper firewall toolkit

#  Directory where smtpd will chroot to, and put the received mail
#  If you change it here, change also patches/patch-aa
SPOOLBASE=	/var/smtpd

post-patch:
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.tmp
	@${SED} s+!!SPOOLBASE!!+${SPOOLBASE}+g < ${WRKSRC}/Makefile.tmp \
	                                    > ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${PREFIX}/share/doc/smtpd
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/smtpd

	@${ECHO_CMD} "Creating spool directories..."
	@${MKDIR} ${SPOOLBASE}
	@${CHOWN} root:uucp ${SPOOLBASE}
	@${CHMOD} 0710 ${SPOOLBASE}

	@${MKDIR} ${SPOOLBASE}/mqueue
	@${CHOWN} uucp:uucp ${SPOOLBASE}/mqueue
	@${CHMOD} 0700 ${SPOOLBASE}/mqueue

	@${MKDIR} ${SPOOLBASE}/etc
	@${CHOWN} root:uucp ${SPOOLBASE}/etc
	@${CHMOD} 0710 ${SPOOLBASE}/etc
.if !defined(BATCH)
	@${CP} -p /etc/resolv.conf ${SPOOLBASE}/etc
	@${CP} -p /etc/localtime ${SPOOLBASE}/etc
.endif

	@${ECHO_CMD} "Copying examples..."
	@${INSTALL} ${COPY} -g uucp -o root -m 0640		\
		${WRKSRC}/antirelay_check_rules_example	\
		${SPOOLBASE}/etc/antirelay_check_rules.example
	@${INSTALL} ${COPY} -g uucp -o root -m 0640		\
		${WRKSRC}/antispam_check_rules.example	\
		${SPOOLBASE}/etc
	@${INSTALL} ${COPY} -g uucp -o root -m 0640		\
		${WRKSRC}/smtpd_check_rules.example	\
		${SPOOLBASE}/etc

	@${ECHO_CMD} "Creating startup file..."
	@${SED} s+!!PREFIX!!+${PREFIX}+		\
		< ${FILESDIR}/smtpd.sh		\
		> ${PREFIX}/etc/rc.d/smtpd.sh
	@${CHMOD} 0700 ${PREFIX}/etc/rc.d/smtpd.sh
	@${CHOWN} 0:0 ${PREFIX}/etc/rc.d/smtpd.sh

	@${ECHO_CMD} "Done!"

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
