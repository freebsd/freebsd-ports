# New ports collection makefile for:	gap
# Date created:				28 Apr, 2002
# Whom:					keith@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gap
PORTVERSION=	4.4.3
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-gap.dcs.st-and.ac.uk/pub/gap/gap4/
MASTER_SITES=	ftp://ftp.gap-system.org/pub/gap/gap4/tar.bz2/
DISTFILES=	gap4r4p3.tar.bz2 xtom1r1.tar.bz2 \
		packages-2004_11_17-15_41_UTC.tar.bz2
DIST_SUBDIR=	gap

MAINTAINER=	johans@stack.nl
COMMENT=	GAP is a system for computational discrete algebra

.include <bsd.port.pre.mk>

GAP_VERSION=	gap4r4
GAP_WRKSRC=	${WRKSRC}/${GAP_VERSION}
GAP_LIBDIR=	${PREFIX}/lib/${GAP_VERSION}
PLIST_SUB=	GAP_LIBDIR=lib/${GAP_VERSION}

do-extract:
	(${MKDIR} ${WRKSRC}; \
	cd ${WRKSRC}; \
	${TAR} xyf ${DISTDIR}/${DIST_SUBDIR}/gap4r4p3.tar.bz2; \
	${TAR} xyf ${DISTDIR}/${DIST_SUBDIR}/xtom1r1.tar.bz2 ; \
	cd ${GAP_WRKSRC}/pkg; \
	${TAR} xyf ${DISTDIR}/${DIST_SUBDIR}/packages-2004_11_17-15_41_UTC.tar.bz2 )

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
.for subdir in doc etc grp lib pkg prim small trans tst
	@${CP} -R ${GAP_WRKSRC}/${subdir} ${GAP_LIBDIR}/
.endfor

.include <bsd.port.post.mk>
