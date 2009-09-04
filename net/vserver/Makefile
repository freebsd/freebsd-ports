# New ports collection makefile for:	vserver
# Date created:				10. Jan 06
# Whom:					Andreas Wetzel <mickey@netassembly.de>
#
# $FreeBSD$
#

PORTNAME=	vserver
PORTVERSION=	2.43c
CATEGORIES=	net
MASTER_SITES=	http://www.enforcer.cc/vchat/filez/

MAINTAINER=	mickey@enforcer.cc
COMMENT=	Server software of the VChat conference system

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix="${PREFIX}" --mandir="${PREFIX}/man"
USE_RC_SUBR=	vserver

MAN8=		vchatctl.8 vserver.8

VCHATUSER=	vchat
VCHATGROUP=	vchat

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST+=	VCHATUSER=${VCHATUSER} \
		VCHATGROUP=${VCHATGROUP}

PLIST_FILES=	sbin/vserver sbin/vchatctl \
		"@dirrmtry etc/vchat"

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
