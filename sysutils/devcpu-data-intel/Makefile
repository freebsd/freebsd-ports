PORTNAME=	data
DISTVERSIONPREFIX=	microcode-
DISTVERSION=	20220207
CATEGORIES=	sysutils
PKGNAMEPREFIX=	devcpu-
PKGNAMESUFFIX=	-intel

MAINTAINER=	sbruno@FreeBSD.org
COMMENT=	Intel CPU microcode updates

LICENSE=	EULA
LICENSE_NAME=	Intel Software License Agreement
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386

USES=		cpe
CPE_PART=	o
CPE_VENDOR=	intel
CPE_PRODUCT=	microcode
USE_GITHUB=	yes
GH_ACCOUNT=	intel
GH_PROJECT=	Intel-Linux-Processor-Microcode-Data-Files

DATADIR=	${PREFIX}/share/cpucontrol
FWDIR=		/boot/firmware
NO_ARCH=	yes

NO_WRKSUBDIR=	yes

post-extract:
	${CP} -p ${FILESDIR}/Makefile ${FILESDIR}/ucode-split.c ${WRKSRC}
	${REINPLACE_CMD} 's|%%GH_TAGNAME%%|${GH_TAGNAME}|g' ${WRKSRC}/Makefile
	${CAT} ${WRKSRC}/Intel-Linux-Processor-Microcode-Data-Files-${GH_TAGNAME}/intel-ucode/* \
	  ${WRKSRC}/Intel-Linux-Processor-Microcode-Data-Files-${GH_TAGNAME}/intel-ucode-with-caveats/* \
	  > ${WRKSRC}/intel-ucode.bin

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/mcodes/* ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${FWDIR}
	${INSTALL_DATA} ${WRKSRC}/intel-ucode.bin ${STAGEDIR}${FWDIR}/

.include <bsd.port.mk>
