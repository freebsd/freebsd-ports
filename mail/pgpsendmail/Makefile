# New ports collection makefile for:    pgpsendmail
# Version required:     1.4
# Date created:         20 Jan 1995
# Whom:                 ache
#
# $FreeBSD$
#

DISTNAME=       PGPsendmail-v1.4
PKGNAME=	pgpsendmail-1.4
CATEGORIES=	mail
MASTER_SITES=   ftp://ftp.dhp.com/pub/crypto/pgp/PGPsendmail/

MAINTAINER=     ache@FreeBSD.org

BUILD_DEPENDS += pgp:${PORTSDIR}/security/pgp

WRKSRC=         ${WRKDIR}/pgpsendmail
INSTALL_TARGET= all_install
MAN1=		pgppipe.1 sendpgppass.1
MAN8=		pgpsendmail.8 pgpdaemon.8

.include <bsd.port.mk>
