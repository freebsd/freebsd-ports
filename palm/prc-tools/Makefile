# New ports collection makefile for:	Palm OS PRC-tools
# Date created:		Mar 22 2000
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	prc-tools
PORTVERSION=	2.0
CATEGORIES=	palm
MASTER_SITES=	http://www.palmos.com/dev/tech/tools/gcc/dist/

MAINTAINER=	kuriyama@FreeBSD.org

BUILD_DEPENDS=	${PREFIX}/bin/m68k-palmos-gcc:${PORTSDIR}/palm/prc-tools-gcc \
		${LOCALBASE}/palmdev/sdk-3.5/include/Core/System/NetMgr.h:${PORTSDIR}/palm/palmos-sdk

RESTRICTED=	Required port is restricted.
USE_BISON=	YES
USE_GMAKE=	YES
PREFIX=		${LOCALBASE}/pilot
WRKSRC=		${WRKDIR}/build
ALL_TARGET=	all-target
INSTALL_TARGET=	install-target
HAS_CONFIGURE=	YES
CONFIGURE_SCRIPT=	../prc-tools-2.0/configure
CONFIGURE_ARGS=	--target=m68k-palmos --enable-languages=c,c++ \
		--sharedstatedir=${LOCALBASE}/palmdev --prefix=${PREFIX} \
		--with-build-sdk=3.5
CONFIGURE_ENV=	PATH=${PATH}:${PREFIX}/bin
MAKE_ENV=	PATH=${PATH}:${PREFIX}/bin

pre-patch:
	${MKDIR} ${WRKSRC}/empty

.include <bsd.port.mk>
