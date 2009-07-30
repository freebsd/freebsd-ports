# New ports collection makefile for:	gap
# Date created:				28 Apr, 2002
# Whom:					keith@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gap
PORTVERSION=	4.4.12.${GAP_PKGDATE}
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.gap-system.org/pub/gap/gap4/tar.bz2/ \
		ftp://ftp.stack.nl/pub/users/johans/gap/ \
		ftp://ftp.gap-system.org/pub/gap/gap4/old/
DISTFILES=	packages-${GAP_PKGTIME}.tar.bz2 \
		gap4r4p12.tar.bz2 \
		xtom1r1p4.tar.bz2
DIST_SUBDIR=	gap

MAINTAINER=	johans@stack.nl
COMMENT=	GAP is a system for computational discrete algebra

OPTIONS=	COMPRESSED_TOMLIB	"Compress tomlib files"		On \
		ACE			"Build binaries for ace"	Off \
		COHOMOLO		"Build binaries for cohomolo"	Off \
		EDIM			"Build binaries for edim"	Off \
		EXAMPLE			"Build binaries for example"	Off \
		KBMAG			"Build binaries for kbmag"	Off \
		PARGAP			"Build binaries for pargap"	Off \
		XGAP			"Build binaries for xgap"	Off
#		GRAPE			"Build binaries for grape"	Off

#todo anupq fplsa/guava/nq (malloc.h build error) qaos

.include <bsd.port.pre.mk>

GAP_VERSION=	gap4r4
GAP_PKGTIME=	2009_07_22-15_24_UTC
GAP_PKGDATE=	${GAP_PKGTIME:C/-.*//:S/_//g}
GAP_WRKSRC=	${WRKSRC}/${GAP_VERSION}
GAP_LIBDIR=	${PREFIX}/lib/${GAP_VERSION}
PLIST_FILES=	bin/gap

do-extract:
	(${MKDIR} ${WRKSRC}; \
	cd ${WRKSRC}; \
	${TAR} xyf ${DISTDIR}/${DIST_SUBDIR}/gap4r4p12.tar.bz2; \
	${TAR} xyf ${DISTDIR}/${DIST_SUBDIR}/xtom1r1p4.tar.bz2 ; \
	cd ${GAP_WRKSRC}/pkg; \
	${TAR} xyf ${DISTDIR}/${DIST_SUBDIR}/packages-${GAP_PKGTIME}.tar.bz2 )

post-patch:
	@${REINPLACE_CMD} -e "/^CC=/d" ${GAP_WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s/@CC@/@BASECC@/" ${GAP_WRKSRC}/sysinfo.in

do-configure:
	(cd ${GAP_WRKSRC}; ./configure)

do-build:
	(cd ${GAP_WRKSRC}; make COPTS="${CFLAGS}")

post-build:
.if defined(WITH_COMPRESSED_TOMLIB)
	(cd ${GAP_WRKSRC}/pkg/tomlib/data; ${SH} -c 'for i in *; do ${GZIP_CMD} $${i};done' )
.endif
.if defined(WITH_ACE)
	(cd ${GAP_WRKSRC}/pkg/ace; ./configure ../..; make )
.endif
.if defined(WITH_COHOMOLO)
	(cd ${GAP_WRKSRC}/pkg/cohomolo; ./configure ../..; make )
.endif
.if defined(WITH_EDIM)
	(cd ${GAP_WRKSRC}/pkg/edim; ./configure ../..; make )
.endif
.if defined(WITH_EXAMPLE)
	(cd ${GAP_WRKSRC}/pkg/example; ./configure ../..; make )
.endif
#.if defined(WITH_GRAPE)
#	(cd ${GAP_WRKSRC}/pkg/grape; ./configure ../..; make linux-gcc )
#.endif
.if defined(WITH_KBMAG)
	(cd ${GAP_WRKSRC}/pkg/kbmag; ./configure ../..; make )
.endif
.if defined(WITH_OPENMATH)
	(cd ${GAP_WRKSRC}/pkg/openmath/OMCv1.3c/src/; ./configure; make; cd ../..; ./configure ../../; make )
.endif
.if defined(WITH_PARGAP)
	(cd ${GAP_WRKSRC}/pkg/pargap; ./configure ../..; make )
.endif
.if defined(WITH_XGAP)
	(cd ${GAP_WRKSRC}/pkg/xgap; ./configure ; make )
.endif

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
