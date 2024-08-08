PORTNAME=	openseachest
DISTVERSIONPREFIX=	v
DISTVERSION=	23.12
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Utilities for managing storage devices
WWW=		https://github.com/Seagate/openSeaChest

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		dos2unix gmake
DOS2UNIX_FILES=	src/openseachest_util_options.c
USE_GITHUB=	yes
GH_ACCOUNT=	Seagate
GH_PROJECT=	openSeaChest
GH_TUPLE=	Seagate:opensea-common:fb04a1a:common/subprojects/opensea-common \
		Seagate:opensea-operations:3dffce6:operations/subprojects/opensea-operations \
		Seagate:opensea-transport:443c719:transport/subprojects/opensea-transport \
		Seagate:wingetopt:c68019b:wingetopt/subprojects/wingetopt

MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	release

CFLAGS+=	-Wall -c -std=gnu99
BUILD_WRKSRC=	${WRKSRC}/Make/gcc
INSTALL_WRKSRC=	${WRKSRC}/Make/gcc

EXES=		openSeaChest_Basics openSeaChest_Configure openSeaChest_Erase \
		openSeaChest_Firmware openSeaChest_Format openSeaChest_GenericTests \
		openSeaChest_Info openSeaChest_Logs openSeaChest_NVMe \
		openSeaChest_PassthroughTest openSeaChest_PowerControl \
		openSeaChest_Security openSeaChest_SMART openSeaChest_ZBD
.for file in ${EXES}
PLIST_FILES+=	bin/${file}
.endfor

do-install:
.for exefile in ${EXES}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/openseachest_exes/${exefile} ${STAGEDIR}${PREFIX}/bin/
.endfor

.include <bsd.port.mk>
