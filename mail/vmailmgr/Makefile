# New ports collection makefile for:	vmailmgr
# Date created:         24.Sep.2003
# Whom:                 patrick@rinke-bochum.de
#
# $FreeBSD$
#

PORTNAME=	vmailmgr
PORTVERSION=	0.96.9
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.vmailmgr.org/current/

MAINTAINER=	patrick@rinke-bochum.de
COMMENT=	Virtual MAIL ManaGeR for virtual mailboxes and domains

RUN_DEPENDS=	/var/qmail/bin/qmail-start:${PORTSDIR}/mail/qmail \
		unixserver:${PORTSDIR}/sysutils/ucspi-unix

HAS_CONFIGURE=yes

SVC_DIR=	"/var/qmail/service/vmailmgrd"

MAN1=		checkvpw.1 vauthenticate.1 vpasswd2cdb.1 vrehash.1 \
		listvdomain.1 vadduser.1 vchattr.1 vchforwards.1 \
		vcheckquota.1 vdeliver.1 vdeluser.1 vpasswd.1
MAN7=		vmailmgr.7
MAN8=		vmailmgrd.8

post-install:
	${MKDIR} ${PREFIX}/etc/vmailmgr
	${CP} ${WRKSRC}/scripts/autoresponder.sh ${PREFIX}/etc/vmailmgr/vdeliver-postdeliver
	${ECHO_CMD} "default" >${PREFIX}/etc/vmailmgr/default-username
	${MKDIR} ${SVC_DIR}/log
	${CP} ${WRKSRC}/scripts/vmailmgrd.run ${SVC_DIR}/run
	${CP} ${WRKSRC}/scripts/vmailmgrd-log.run ${SVC_DIR}/log/run

.include <bsd.port.mk>
