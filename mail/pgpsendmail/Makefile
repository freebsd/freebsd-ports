# New ports collection makefile for:    pgpsendmail
# Date created:         20 Jan 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	pgpsendmail
PORTVERSION=	1.4
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.dhp.com/pub/crypto/pgp/PGPsendmail/
DISTNAME=	PGPsendmail-v${PORTVERSION}

MAINTAINER=	ache@FreeBSD.org
COMMENT=	PGP sign/encrypt/decrypt messages automatically

BUILD_DEPENDS+=	pgp:${PORTSDIR}/security/pgp

WRKSRC=		${WRKDIR}/pgpsendmail
INSTALL_TARGET=	all_install
MAN1=		pgppipe.1 sendpgppass.1
MAN8=		pgpsendmail.8 pgpdaemon.8

.include <bsd.port.mk>
