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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Microsoft Lit to HTML and Open eBooks converter

BROKEN=		unfetchable

PATCH_WRKSRC=	${WRKSRC}/${PORTNAME}${MAJ_VER}${MIN_VER}
NO_WRKSUBDIR=	yes

MAJ_VER=	1
MIN_VER=	8

PLIST_FILES=	bin/clit

USES=	dos2unix gmake zip

post-extract:
	cd ${WRKSRC} && ${BZIP2_CMD} -dc "${DISTDIR}/ltm-0.33.tar.bz2" | \
		${TAR} -xf -

do-build:
	cd ${WRKSRC}/libtommath-0.33 && \
	${SETENV} ${MAKE_ENV} ${MAKE} -f makefile  libtommath.a
	cd ${WRKSRC}/lib &&  ${SETENV} ${MAKE_ENV} ${MAKE_CMD} -f Makefile all
	cd ${WRKSRC}/${PORTNAME}${MAJ_VER}${MIN_VER} &&  \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} -f Makefile all

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}${MAJ_VER}${MIN_VER}/clit \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
