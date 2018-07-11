# Created by: stas
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	1.18
CATEGORIES=	sysutils
MASTER_SITES=	https://downloadmirror.intel.com/27945/eng/:intel \
		LOCAL/sbruno:amd
PKGNAMEPREFIX=	devcpu-
DISTFILES=	microcode-20180703.tgz:intel \
		amd64-microcode.20180525.tar.xz:amd

MAINTAINER=	sbruno@freebsd.org
COMMENT=	Intel and AMD CPUs microcode updates

LICENSE=	EULA
LICENSE_NAME=	Intel Software License Agreement
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/share/cpucontrol

USE_RC_SUBR=	microcode_update

post-extract:
	${CP} -p ${FILESDIR}/Makefile ${FILESDIR}/ucode-split.c ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/microcode_amd.bin ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/microcode_amd_fam15h.bin ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/microcode_amd_fam16h.bin ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/microcode_amd_fam17h.bin ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/mcodes/* ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
