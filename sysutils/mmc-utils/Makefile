# Created by: Marius Strobl <marius@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mmc-utils
PORTVERSION=	20191004
DISTVERSIONSUFFIX=	-73d6c59a
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/marius

MAINTAINER=	marius@FreeBSD.org
COMMENT=	Userspace tools for MMC/SD devices

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	multi

IGNORE_DragonFly=	only supported on FreeBSD

USES=		gmake tar:bzip2

PLIST_FILES=	man/man1/mmc.1.gz sbin/mmc

MMC_GITURL=	git://git.kernel.org/pub/scm/linux/kernel/git/cjb/mmc-utils.git

post-patch:
.for i in Makefile mmc_cmds.c mmc.c man/mmc.1
	@${REINPLACE_CMD} -e 's|^AM_CFLAGS|#^|; s|path/to|dev|g;\
		s|mmcblk|mmcsd|g' ${WRKSRC}/${i}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mmc ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/mmc.1 ${STAGEDIR}${PREFIX}/man/man1

maintainer-fetch:
	@${MAKE} clean
	@${MKDIR} ${WRKSRC}
	@git clone ${MMC_GITURL} ${WRKSRC}
	@cd ${WRKSRC} && git reset --hard ${DISTVERSIONSUFFIX:S|^-||}
	@${TAR} -cyf ${_DISTDIR:S|/$||}/${DISTFILES:M${PORTNAME}-*} \
		-C ${WRKSRC}/.. --exclude .git* .
	@${MAKE} makesum
	@${MAKE} clean

.include <bsd.port.mk>
