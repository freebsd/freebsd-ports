# New ports collection makefile for:    pgpsendmail
# Version required:     1.4
# Date created:         20 Jan 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.8 1995/09/23 17:13:54 ache Exp $
#

DISTNAME=       PGPsendmail-v1.4
PKGNAME=	pgpsendmail-1.4
CATEGORIES=	mail
MASTER_SITES=   ftp://ftp.dhp.com/pub/crypto/pgp/PGPsendmail/

MAINTAINER=     ache@FreeBSD.ORG

BUILD_DEPENDS += pgp:${PORTSDIR}/security/pgp

WRKSRC=         ${WRKDIR}/pgpsendmail
INSTALL_TARGET= all_install

.include <bsd.port.mk>
