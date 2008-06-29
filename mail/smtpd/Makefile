# Ports collection makefile for:  smtpd
# Date created:			06 Feb 1998
# Whom:				Joao Carlos Mendes Luis <jonny@jonny.eng.br>
#
# $FreeBSD$
#

PORTNAME=	smtpd
PORTVERSION=	2.0
PORTREVISION=	4
CATEGORIES=	mail security
MASTER_SITES=	http://www.netsw.org/net/ip/firewall/proxy/smtpd/

PATCH_SITES=	ftp://ftp.42.org/pub/OLD/p/ \
		ftp://ftp.cdpa.nsysu.edu.tw/BSD/NetBSD/packages/distfiles/
PATCHFILES=	patch-smtpd-2.0-RBL.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Obtuse smtpd/smtpfwdd, part of the Juniper firewall toolkit

USE_RC_SUBR=	smtpd
SUB_FILES=	pkg-message
SPOOLBASE?=	/var/smtpd
PLIST_SUB+=	SPOOLBASE=${SPOOLBASE}
SUB_LIST+=	SPOOLBASE=${SPOOLBASE}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

	@${ECHO_CMD} "Creating spool directories..."
	@${INSTALL} -d -o root -g uucp -m 710 ${SPOOLBASE}
	@${INSTALL} -d -o uucp -g uucp -m 700 ${SPOOLBASE}/mqueue
	@${INSTALL} -d -o root -g uucp -m 710 ${SPOOLBASE}/etc
.if !defined(BATCH)
	@${INSTALL_DATA} /etc/resolv.conf ${SPOOLBASE}/etc
	@${INSTALL_DATA} /etc/localtime ${SPOOLBASE}/etc
.endif
	@${ECHO_CMD} "Copying examples..."
	@${INSTALL_DATA} ${WRKSRC}/antirelay_check_rules_example \
		${SPOOLBASE}/etc/antirelay_check_rules.example
	@${INSTALL_DATA} ${WRKSRC}/antispam_check_rules.example ${SPOOLBASE}/etc
	@${INSTALL_DATA} ${WRKSRC}/smtpd_check_rules.example ${SPOOLBASE}/etc
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
