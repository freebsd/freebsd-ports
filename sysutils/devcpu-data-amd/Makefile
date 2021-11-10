PORTNAME=	data
PORTVERSION=	20211109
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/sbruno
PKGNAMEPREFIX=	devcpu-
PKGNAMESUFFIX=	-amd
DISTNAME=	amd64-microcode.${PORTVERSION}

MAINTAINER=	sbruno@FreeBSD.org
COMMENT=	AMD CPUs microcode updates

LICENSE=	EULA
LICENSE_NAME=	Advanced Micro Devices License Agreement
LICENSE_FILE=	${FILESDIR}/LICENSE.amd-ucode
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386

USES=		tar:xz

NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/share/cpucontrol

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/microcode_amd.bin ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/microcode_amd_fam15h.bin ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/microcode_amd_fam16h.bin ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/microcode_amd_fam17h.bin ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/microcode_amd_fam19h.bin ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
