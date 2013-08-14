# Created by: keith@FreeBSD.org
# $FreeBSD$

PORTNAME=	gap
PORTVERSION=	4.6.3.${GAP_DISTDATE}
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.gap-system.org/pub/gap/gap46/tar.bz2/ \
		ftp://ftp.stack.nl/pub/users/johans/gap/ \
		ftp://ftp.gap-system.org/pub/gap/gap46/old/
DISTNAME=	${GAP_VERSION}p${PORTVERSION:R:E}_${GAP_DISTTIME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GAP is a system for computational discrete algebra

USE_BZIP2=	yes
USES=		gmake
GNU_CONFIGURE=	yes
ALL_TARGET=	default

MAKE_JOBS_UNSAFE=yes

GAP_VERSION=	${PORTNAME}${PORTVERSION:R:R:S/./r/}	# gap4r5
GAP_DISTTIME=	2013_03_18-17_40
GAP_DISTDATE=	${GAP_DISTTIME:C/-.*//:S/_//g}
GAP_LIBDIR=	${PREFIX}/lib/${GAP_VERSION}
WRKSRC=		${WRKDIR}/${GAP_VERSION}
PLIST_FILES=	bin/gap

do-install:
	(${SED} -e "s:GAP_DIR=.*:GAP_DIR=${GAP_LIBDIR}:g" -e "s:GAP_PRG=.*:GAP_PRG=gap:g" ${WRKSRC}/bin/gap.sh > ${PREFIX}/bin/gap; \
	${CHMOD} 755 ${PREFIX}/bin/gap; )
	@${MKDIR} ${GAP_LIBDIR} ${GAP_LIBDIR}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/*/gap ${GAP_LIBDIR}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/*/gac ${GAP_LIBDIR}/bin
	@${INSTALL_DATA} ${WRKSRC}/sysinfo.gap ${GAP_LIBDIR}
.for subdir in doc etc grp lib pkg prim small trans tst
	@${CP} -R ${WRKSRC}/${subdir} ${GAP_LIBDIR}/
.endfor

post-install:
	@${FIND} ${GAP_LIBDIR} -type d -empty -delete
	@${FIND} ${GAP_LIBDIR} ! -type d | \
		${SED} 's,${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${GAP_LIBDIR} -type d -depth | \
		${SED} 's,${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
