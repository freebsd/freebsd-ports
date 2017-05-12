# Created by: Marius Strobl <marius@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mmc-utils
PORTVERSION=	20170320
DISTVERSIONSUFFIX=	-37c86e60
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/marius

MAINTAINER=	marius@FreeBSD.org
COMMENT=	Userspace tools for MMC/SD devices

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	multi

USES=		gmake tar:bzip2

PLIST_FILES=	man/man1/mmc.1.gz sbin/mmc

MMC_GITURL=	git://git.kernel.org/pub/scm/linux/kernel/git/cjb/mmc-utils.git

.include <bsd.port.pre.mk>

.if (${OPSYS} == FreeBSD && \
	(${OSVERSION} < 1003514 || \
	(${OSVERSION} > 1100000 && ${OSVERSION} < 1100513) || \
	(${OSVERSION} > 1200000 && ${OSVERSION} < 1200025))) || \
	${OPSYS} == DragonFly
IGNORE=		only supported on recent OS versions
.endif

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
		-C ${WRKSRC}/.. --exclude .git .
	@${MAKE} makesum
	@${MAKE} clean

.include <bsd.port.post.mk>
