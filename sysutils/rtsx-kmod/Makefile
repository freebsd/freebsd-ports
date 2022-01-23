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
GH_TAGNAME=	2.0l

OPTIONS_DEFINE=	MMCCAM

MMCCAM_DESC=	Build for MMCCAM-enabled kernel
MMCCAM_CFLAGS=	-DRTSX_CAM

PLIST_FILES=	${KMODDIR}/rtsx.ko

.include <bsd.port.mk>
