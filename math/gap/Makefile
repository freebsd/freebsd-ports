# New ports collection makefile for:	gap
# Date created:				28 Apr, 2002
# Whom:					keith@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gap
PORTVERSION=	4.4.4.20050214
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.gap-system.org/pub/gap/gap4/tar.bz2/:new \
		ftp://ftp.gap-system.org/pub/gap/gap4/old/:old
DISTFILES=	packages-2005_02_14-19_42_UTC.tar.bz2:new \
		gap4r4p4.tar.bz2:new \
		xtom1r1.tar.bz2:new
DIST_SUBDIR=	gap

MAINTAINER=	johans@stack.nl
COMMENT=	GAP is a system for computational discrete algebra

.include <bsd.port.pre.mk>

GAP_VERSION=	gap4r4
GAP_WRKSRC=	${WRKSRC}/${GAP_VERSION}
GAP_LIBDIR=	${PREFIX}/lib/${GAP_VERSION}
PLIST_FILES=	bin/gap

do-extract:
	(${MKDIR} ${WRKSRC}; \
	cd ${WRKSRC}; \
	${TAR} xyf ${DISTDIR}/${DIST_SUBDIR}/gap4r4p4.tar.bz2; \
	${TAR} xyf ${DISTDIR}/${DIST_SUBDIR}/xtom1r1.tar.bz2 ; \
	cd ${GAP_WRKSRC}/pkg; \
	${TAR} xyf ${DISTDIR}/${DIST_SUBDIR}/packages-2005_02_14-19_42_UTC.tar.bz2 )

do-configure:
	(cd ${GAP_WRKSRC}; ./configure)

do-build:
	(cd ${GAP_WRKSRC}; make)

do-install:
	(${SED} -e "s:GAP_DIR=.*:GAP_DIR=${GAP_LIBDIR}:g" -e "s:GAP_PRG=.*:GAP_PRG=gap:g" ${GAP_WRKSRC}/bin/gap.sh > ${PREFIX}/bin/gap; \
	${CHMOD} 755 ${PREFIX}/bin/gap; )
	@${MKDIR} ${GAP_LIBDIR} ${GAP_LIBDIR}/bin
	@${INSTALL_PROGRAM} ${GAP_WRKSRC}/bin/*/gap ${GAP_LIBDIR}/bin
	@${INSTALL_SCRIPT} ${GAP_WRKSRC}/bin/*/gac ${GAP_LIBDIR}/bin
	@${INSTALL_DATA} ${GAP_WRKSRC}/sysinfo.gap ${GAP_LIBDIR}
.for subdir in doc etc grp lib pkg prim small trans tst
	@${CP} -R ${GAP_WRKSRC}/${subdir} ${GAP_LIBDIR}/
.endfor

post-install:
	@${FIND} ${GAP_LIBDIR} -type d -empty -delete
	@${FIND} ${GAP_LIBDIR} ! -type d | \
		${SED} 's,${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${GAP_LIBDIR} -type d -depth | \
		${SED} 's,${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
