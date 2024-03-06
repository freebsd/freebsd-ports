PORTNAME=	mmc-utils
DISTVERSION=	20230807
PORTREVISION=	1
DISTVERSIONSUFFIX=	-${MMC_GITSHASH}
CATEGORIES=	sysutils
MASTER_SITES=	https://git.kernel.org/pub/scm/utils/mmc/mmc-utils.git/snapshot/${MMC_GITHASH}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	marius@FreeBSD.org
COMMENT=	Userspace tools for MMC/SD devices
WWW=		https://www.kernel.org/doc/html/latest/driver-api/mmc/mmc-tools.html

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	multi

IGNORE_DragonFly=	only supported on FreeBSD
CFLAGS+=	-DVERSION='\"${MMC_GITSHASH}\"'
MMC_GITHASH=	613495ecaca97a19fa7f8f3ea23306472b36453c
MMC_GITSHASH=	${MMC_GITHASH:C/^(........).*/\1/}
PLIST_FILES=	share/man/man1/mmc.1.gz sbin/mmc
USES=		gmake
WRKSRC=		${WRKDIR}/${MMC_GITHASH}

post-patch:
.for i in Makefile mmc_cmds.c mmc.c man/mmc.1
	@${REINPLACE_CMD} -Ee 's|^(override CFLAGS.*)\$$\(AM_CFLAGS\) |\1|; \
		s|path/to|dev|g; s|mmcblk|mmcsd|g' ${WRKSRC}/${i}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mmc ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/mmc.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
