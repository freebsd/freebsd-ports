# $FreeBSD$

PORTNAME=	rtsx
DISTVERSION=	${GH_TAGNAME}
PORTEPOCH=	1
CATEGORIES=	sysutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	FreeBSD driver for Realtec card readers

LICENSE=	BSD2CLAUSE

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	hlh-restart
GH_TAGNAME=	1.0-BETA1

OPTIONS_DEFINE=	INVERSION

INVERSION_DESC=		Invert codes for card detection and read-only switch
INVERSION_CFLAGS=	-DRTSX_INVERSION

PLIST_FILES=	${KMODDIR}/rtsx.ko

.include <bsd.port.mk>
