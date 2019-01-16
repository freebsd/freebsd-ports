# Created by: stas
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	1.21
CATEGORIES=	sysutils
MASTER_SITES=	https://downloadmirror.intel.com/28039/eng/:intel \
		LOCAL/sbruno:amd
PKGNAMEPREFIX=	devcpu-
DISTFILES=	microcode-20180807.tgz:intel \
		amd64-microcode.20181214.tar.xz:amd

MAINTAINER=	sbruno@FreeBSD.org
COMMENT=	Intel and AMD CPUs microcode updates

LICENSE=	EULA
LICENSE_NAME=	Intel Software License Agreement
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/share/cpucontrol
FWDIR=		/boot/firmware

USE_RC_SUBR=	microcode_update

post-extract:
	${CP} -p ${FILESDIR}/Makefile ${FILESDIR}/ucode-split.c ${WRKSRC}
	${CAT} ${WRKSRC}/intel-ucode/* ${WRKSRC}/intel-ucode-with-caveats/* > ${WRKSRC}/intel-ucode.bin

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/microcode_amd.bin ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/microcode_amd_fam15h.bin ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/microcode_amd_fam16h.bin ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/microcode_amd_fam17h.bin ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/mcodes/* ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${FWDIR}
	${INSTALL_DATA} ${WRKSRC}/intel-ucode.bin ${STAGEDIR}${FWDIR}/

.include <bsd.port.mk>
