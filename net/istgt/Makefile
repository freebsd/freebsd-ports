# New ports collection makefile for:	istgt
# Date created:		2009-02-23
# Whom:			Daisuke Aoyama <aoyama@peach.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	istgt
PORTVERSION=	20090223
CATEGORIES=	net
MASTER_SITES=	http://www.peach.ne.jp/archives/istgt/

MAINTAINER=	aoyama@peach.ne.jp
COMMENT=	An iSCSI target for FreeBSD 7.x with ZFS

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

GNU_CONFIGURE=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
