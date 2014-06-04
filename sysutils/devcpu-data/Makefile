# Created by: stas
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://downloadmirror.intel.com/22508/eng/:intel \
		http://pkgs.fedoraproject.org/repo/pkgs/microcode_ctl/amd-ucode-2012-09-10.tar/559bc355d3799538584add80df2996f0/:amd \
# Defunct:	http://www.amd64.org/index.php?id=50&file=amd-ucode-2012-09-10.tar
PKGNAMEPREFIX=	devcpu-
DISTFILES=	microcode-20130222.tgz:intel amd-ucode-2012-09-10.tar:amd

MAINTAINER=	clarkjc@runbox.com
COMMENT=	Intel and AMD CPUs microcode updates

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
