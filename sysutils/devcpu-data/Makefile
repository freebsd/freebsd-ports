# Created by: stas
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	1.7
CATEGORIES=	sysutils
MASTER_SITES=	http://downloadmirror.intel.com/26156/eng/:intel \
		http://www.amd64.org/microcode/:amd
PKGNAMEPREFIX=	devcpu-
DISTFILES=	microcode-20160714.tgz:intel amd-ucode-2014-12-01.tar.bz2:amd

MAINTAINER=	clarkjc@runbox.com
COMMENT=	Intel and AMD CPUs microcode updates

LICENSE=	EULA
LICENSE_NAME=	Intel Software License Agreement
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell

NO_WRKSUBDIR=	yes

ONLY_FOR_ARCHS=	i386 amd64

DATADIR=	${PREFIX}/share/cpucontrol

USE_RC_SUBR=	microcode_update

post-extract:
	${CP} -p ${FILESDIR}/Makefile ${FILESDIR}/ucode-tool.c ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/mcodes/* ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
