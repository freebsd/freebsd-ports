PORTNAME=	openseachest
PORTVERSION=	21.06.21
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Utilities for managing storage devices

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		dos2unix gmake
ALL_TARGET=	release

DOS2UNIX_FILES=	src/openseachest_util_options.c

USE_GITHUB=	yes
GH_ACCOUNT=	Seagate
GH_PROJECT=	openSeaChest
GH_TUPLE=	Seagate:opensea-common:dc89150:common/opensea-common \
		Seagate:opensea-operations:cfd7678:operations/opensea-operations \
		Seagate:opensea-transport:a2ea73c:transport/opensea-transport \
		Seagate:wingetopt:1b5b5ad:wingetopt/wingetopt
BUILD_WRKSRC=	${WRKSRC}/Make/gcc
INSTALL_WRKSRC=	${WRKSRC}/Make/gcc
CFLAGS+=	-Wall -c -std=gnu99
MAKE_JOBS_UNSAFE=	yes
EXES=		openSeaChest_Basics openSeaChest_Configure openSeaChest_Erase \
		openSeaChest_Firmware openSeaChest_FormatUnit \
		openSeaChest_GenericTests openSeaChest_Info openSeaChest_Logs \
		openSeaChest_NVMe openSeaChest_PassthroughTest \
		openSeaChest_PowerControl openSeaChest_Security \
		openSeaChest_SMART openSeaChest_ZBD
.for file in ${EXES}
PLIST_FILES+=	bin/${file}
.endfor

.include <bsd.port.pre.mk>

do-install:
.for exefile in ${EXES}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/openseachest_exes/${exefile} ${STAGEDIR}${PREFIX}/bin/
.endfor

.include <bsd.port.post.mk>
