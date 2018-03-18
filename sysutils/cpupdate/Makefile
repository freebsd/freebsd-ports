# Created by: Eugene Grosbein <eugen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cpupdate
DISTVERSION=	g20180302
CATEGORIES=	sysutils

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	CPU microcode update utility for x86

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	specific to x86 processors

SUB_FILES=	pkg-message
SUB_LIST=	CPM_DIR=${CPM_DIR} INTEL_DIR=${INTEL_DIR}

USE_GITHUB=	yes
GH_ACCOUNT=	kernschmelze
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	58bc0ca

PLIST_FILES=	bin/${PORTNAME} man/man8/${PORTNAME}.8.gz

CPM_ACCOUNT=	platomav
CPM_PROJECT=	CPUMicrocodes
CPM_TAGNAME=	2ece631

OPTIONS_DEFINE=	CPM INTEL
CPM_DESC=	Download platomav/CPUMicrocodes collection
CPM_GH_ACCOUNT=	${CPM_ACCOUNT}:cpm
CPM_GH_PROJECT=	${CPM_PROJECT}:cpm
CPM_GH_TAGNAME=	${CPM_TAGNAME}:cpm
CPM_DIR=${WRKDIR}/${CPM_PROJECT}-${CPM_TAGNAME}

INTEL_PACK=		microcode-20180312.tgz
INTEL_DESC=		Download Intel microcode pack ${INTEL_PACK}
INTEL_MASTER_SITES=	https://downloadmirror.intel.com/27591/eng/:intel
INTEL_DISTFILES=	${INTEL_PACK}:intel
INTEL_DIR=		${WRKDIR}/intel-ucode

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
