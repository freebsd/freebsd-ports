# New ports collection makefile for:	gap
# Date created:				28 Apr, 2002
# Whom:					keith@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gap
PORTVERSION=	4.3
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-gap.dcs.st-and.ac.uk/pub/gap/gap4/
DISTFILES=	gap4r3.tar.gz \
		accpkg4r3.tar.gz deppkg4r3.tar.gz xtom4r3.tar.gz
DIST_SUBDIR=	gap

MAINTAINER=	keith@FreeBSD.org

NO_CDROM=	"Don't sell for profit."

.include <bsd.port.pre.mk>

do-extract:
	(${MKDIR} ${WRKSRC}; \
	cd ${WRKSRC}; \
	${TAR} xzf ${DISTDIR}/${DIST_SUBDIR}/gap4r3.tar.gz; \
	${TAR} xzf ${DISTDIR}/${DIST_SUBDIR}/xtom4r3.tar.gz ; \
	cd ${WRKSRC}/gap4r3/pkg; \
	${TAR} xzf ${DISTDIR}/${DIST_SUBDIR}/accpkg4r3.tar.gz; \
	${TAR} xzf ${DISTDIR}/${DIST_SUBDIR}/deppkg4r3.tar.gz )

do-configure:
	(cd ${WRKSRC}/gap4r3; ./configure)

do-build:
	(cd ${WRKSRC}/gap4r3; make)

do-install:
	(${SED} -e "s:GAP_DIR=.*:GAP_DIR=${PREFIX}/lib/gap4r3:g" -e "s:GAP_PRG=.*:GAP_PRG=gap:g" ${WRKSRC}/gap4r3/bin/gap.sh > ${PREFIX}/bin/gap; \
	${CHMOD} 755 ${PREFIX}/bin/gap; )
	@${MKDIR} ${PREFIX}/lib/gap4r3 ${PREFIX}/lib/gap4r3/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/gap4r3/bin/*/gap ${PREFIX}/lib/gap4r3/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/gap4r3/bin/*/gac ${PREFIX}/lib/gap4r3/bin
.for subdir in doc etc grp lib pkg prim small trans tst
	@${CP} -R ${WRKSRC}/gap4r3/${subdir} ${PREFIX}/lib/gap4r3/
.endfor

.include <bsd.port.post.mk>
