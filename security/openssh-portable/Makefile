# New ports collection makefile for: openssh
# Date created:  18 Mar 1999
# Whom:   dwcjr@inethouston.net
#
# $FreeBSD$
#

PORTNAME=	openssh
PORTVERSION=	3.0.2p1
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.openbsd.org/pub/OpenBSD/OpenSSH/portable/ \
		ftp://ftp.op.net/pub/OpenBSD/OpenSSH/portable/ \
		ftp://carroll.cac.psu.edu/pub/OpenBSD/OpenSSH/portable/
PKGNAMESUFFIX=	-portable

MAINTAINER=	dinoex@FreeBSD.org

MAN1=	sftp.1 ssh-add.1 ssh-agent.1 ssh-keygen.1 ssh-keyscan.1 scp.1 ssh.1
MLINKS=	ssh.1 slogin.1
MAN8=	sftp-server.8 sshd.8

CRYPTOLIBS=	-L${OPENSSLLIB} -lcrypto
USE_OPENSSL=	YES
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?=	--prefix=${PREFIX} --with-md5-passwords
CLEAN=		etc/ssh_config etc/sshd_config etc/moduli \
		etc/ssh_host_key etc/ssh_host_key.pub \
		etc/ssh_host_dsa_key etc/ssh_host_dsa_key.pub \
		etc/ssh_host_rsa_key etc/ssh_host_rsa_key.pub

.if exists(/usr/include/security/pam_modules.h)
CONFIGURE_ARGS+=	--with-pam
.endif

.if exists(/usr/include/tcpd.h)
CONFIGURE_ARGS+=	--with-tcp-wrappers
.endif

.if defined(OPENSSH_OVERWRITE_BASE)
PKGNAMESUFFIX=	-overwrite-base
PREFIX=		/usr
MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS+=	--mandir=${MANPREFIX}/man \
		--sysconfdir=/etc/ssh --localstatedir=/var
.endif

.if defined(BATCH)
EXTRA_PATCHES+=		${FILESDIR}/batch.patch
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
