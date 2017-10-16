# Created by: stas
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://downloadmirror.intel.com/26925/eng/:intel \
		http://www.amd64.org/microcode/:amd
PKGNAMEPREFIX=	devcpu-
DISTFILES=	microcode-20170707.tgz:intel amd-ucode-2014-12-01.tar.bz2:amd

MAINTAINER=	clarkjc@runbox.com
COMMENT=	Intel and AMD CPUs microcode updates

LICENSE=	EULA
LICENSE_NAME=	Intel Software License Agreement
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

NO_ARCH=	yes
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
