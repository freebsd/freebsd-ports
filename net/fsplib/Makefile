# New ports collection makefile for:	fsplib
# Date created:				15 Jan 2005
# Whom:					X
#
# $FreeBSD$

PORTNAME=	fsplib
PORTVERSION=	0.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fsp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library implementing FSP protocol

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons

PLIST_FILES=	include/fsplib.h lib/libfsp.a
NO_WRKSUBDIR=	yes

do-build:
	@cd ${WRKSRC} && scons prefix=${PREFIX}

do-install:
	@cd ${WRKSRC} && scons prefix=${PREFIX} install
	${FIND} ${PREFIX}/include/  -name .sconsign -exec ${RM} {} \;
	${FIND} ${PREFIX}/lib/  -name .sconsign -exec ${RM} {} \;

.include <bsd.port.mk>
