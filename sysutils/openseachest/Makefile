# $FreeBSD$

PORTNAME=	openseachest
PORTVERSION=	20.02.28
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Utilities for managing storage devices

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		gmake
ALL_TARGET=	release

USE_GITHUB=	yes
GH_ACCOUNT=	Seagate
GH_PROJECT=	openSeaChest
GH_TUPLE=	Seagate:opensea-common:deae6bc:common/opensea-common \
		Seagate:opensea-operations:f1e05ee:operations/opensea-operations \
		Seagate:opensea-transport:16f85f2:transport/opensea-transport \
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
