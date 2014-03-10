# Created by: Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
# $FreeBSD$

PORTNAME=	clit
PORTVERSION=	${MAJ_VER}.${MIN_VER}
CATEGORIES=	textproc
MASTER_SITES=	http://www.convertlit.com/:clit \
		http://T32.TecNik93.com/FreeBSD/ports/${PORTNAME}/sources/:clit \
		http://T32.TecNik93.com/FreeBSD/ports/${PORTNAME}/sources/:ltm
DISTFILES=	clit${MAJ_VER}${MIN_VER}src.zip:clit \
		ltm-0.33.tar.bz2:ltm
EXTRACT_ONLY=	clit${MAJ_VER}${MIN_VER}src.zip

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Microsoft Lit to HTML and Open eBooks converter

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}${MAJ_VER}${MIN_VER}
NO_WRKSUBDIR=	yes

MAJ_VER=	1
MIN_VER=	8

PLIST_FILES=	bin/clit

USES=	dos2unix gmake zip

post-extract:
	cd ${WRKDIR} && ${BZIP2_CMD} -dc "${DISTDIR}/ltm-0.33.tar.bz2" | \
		${TAR} -xf -

do-build:
	cd ${WRKDIR}/libtommath-0.33 && \
	${SETENV} ${MAKE_ENV} ${MAKE} -f makefile  libtommath.a
	cd ${WRKDIR}/lib &&  ${SETENV} ${MAKE_ENV} ${GMAKE} -f Makefile all
	cd ${WRKDIR}/${PORTNAME}${MAJ_VER}${MIN_VER} &&  \
		${SETENV} ${MAKE_ENV} ${GMAKE} -f Makefile all

do-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME}${MAJ_VER}${MIN_VER}/clit \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
