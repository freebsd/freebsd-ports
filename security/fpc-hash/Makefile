# New ports collection makefile for:	fpc-md5
# Date created: 			8 February 2004
# Whom: 				John Merryweather Cooper
#
# $FreeBSD$
#

PORTNAME=	md5
PORTVERSION=	1.0.10
CATEGORIES=	security lang
MASTER_SITES=	http://www.borgsdemons.com/distfiles/
PKGNAMEPREFIX=	fpc-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Pascal unit for MD5 hash routines

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes
ONLY_FOR_ARCHS=	i386

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MAKE_ENV+=	PATH=${LOCALBASE}/bin:$$PATH \
		FPC=${LOCALBASE}/bin/ppc386 \
		INSTALL_BASEDIR=${PREFIX}/lib/fpc/${PORTVERSION} \
		INSTALL_BINDIR=${PREFIX}/bin \
		GCCLIBDIR=/usr/lib \
		RELEASE=1

post-patch:
# change to alter amount of optimization
	@${FIND} ${WRKDIR}/packages/base/md5 -name "Makefile*" | \
		${XARGS} ${REINPLACE_CMD} 's|-OG2p3|-OG2p1|g'

do-build:
	@${SETENV} ${MAKE_ENV} ${GMAKE} -C \
		${WRKDIR}/packages/base/md5 all

do-install:
	@${SETENV} ${MAKE_ENV} ${GMAKE} -C \
		${WRKDIR}/packages/base/md5 install

.include <bsd.port.mk>
