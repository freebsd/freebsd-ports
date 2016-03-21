# $FreeBSD$

PORTNAME=	relaunchd
PORTVERSION=	0.4.2
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	mark@heily.com
COMMENT=	Service management daemon similar to Darwin's launchd(8)

LICENSE=	ISCL

LIB_DEPENDS=	libucl.so:${PORTSDIR}/textproc/libucl

HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	--mandir=${PREFIX}/man
USE_GITHUB=	YES
GH_ACCOUNT=	mheily

.include <bsd.port.mk>
