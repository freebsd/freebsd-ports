# Created by: Rink Springer <rink@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cromwell
PORTVERSION=	20060308
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://rink.nu/downloads/xbox/
DISTNAME=	cromwell-snapshot-${PORTVERSION}

# cromwell-ufs:  suppor for reading kernels directly from UFS partitions
# cromwell-kenv: support for passing kenv(1) options by putting
#                'append foo1=bar1,foo2=bar2' in the linuxboot.cfg entry
# cromwell-gcc4: adds missing prototypes so it will compile using gcc 4
# cromwell-gcc4-2: fixes a problem with a pointer size in gcc 4
PATCH_SITES=		http://rink.nu/downloads/xbox-patches/
PATCHFILES=		cromwell-ufs.diff cromwell-kenv.diff cromwell-gcc4.diff
PATCHFILES+=		cromwell-gcc4-2.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=	rink@FreeBSD.org
COMMENT=	Linux (and FreeBSD :-) BIOS images for the Microsoft Xbox

USE_PERL5_BUILD=	yes

SUB_FILES=	pkg-message

PLIST_DIRS=		%%DATADIR%%
PLIST_FILES=		%%DATADIR%%/cromwell.bin \
			%%DATADIR%%/cromwell_1024.bin \
			%%DATADIR%%/ethboot \
			%%DATADIR%%/xromwell.xbe

# Xbox is an i386 box, mostly
ONLY_FOR_ARCHS=		i386

WRKSRC=			${WRKDIR}/cromwell
USE_BZIP2=		yes
USES=			gmake
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,perl,${PERL},g' \
			  -e 's,^CC.=,CC ?=,' \
			  -e 's,CFLAGS=,CFLAGS+=,' \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/cromwell/image/cromwell.bin		${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/cromwell/image/cromwell_1024.bin	${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/cromwell/boot_eth/ethboot		${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/cromwell/xbe/xromwell.xbe		${DATADIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
