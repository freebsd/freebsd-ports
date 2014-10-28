# Created by: Andrey Fesenko <andrey@bsdnir.info>
# $FreeBSD$

PORTNAME=	emkatic
PORTVERSION=	0.17
CATEGORIES=	russian emulators
MASTER_SITES=	SF/${PORTNAME}/eMKatic%20Source
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	andrey@bsdnir.info
COMMENT=	Emulator of Elektronika RPN programmable calculator series

LICENSE=	GPLv3 # or later
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	lazbuild:${PORTSDIR}/editors/lazarus \
		fpcres:${PORTSDIR}/lang/fpc-utils

USE_FPC=	yes

PROJECT_FILE=	emkatic.lpi
LAZARUS_VER=	1.2.4
LAZBUILD_CMD=	${LOCALBASE}/bin/lazbuild -d --pcp=${WRKSRC}/tmppcp
LAZARUS_DIR=	${LOCALBASE}/share/lazarus-${LAZARUS_VER}
BUILD_MODE=	SrcDist

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=		PORTAUDIO
OPTIONS_DEFAULT=	PORTAUDIO

PORTAUDIO_RUN_DEPENDS=	${LOCALBASE}/lib/portaudio2/libportaudio.so.2:${PORTSDIR}/audio/portaudio2

do-build:
	@cd ${WRKSRC} && \
		${LAZBUILD_CMD} --bm="${BUILD_MODE}" --lazarusdir=${LAZARUS_DIR} ${PROJECT_FILE}

do-install:
	@cd ${WRKSRC} && \
		${INSTALL_PROGRAM} emkatic ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
