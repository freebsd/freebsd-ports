# New ports collection makefile for:   clit
# Date created:        2005-01-11
# Whom:                Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$
#

PORTNAME=	clit
PORTVERSION=	${MAJ_VER}.${MIN_VER}
CATEGORIES=	textproc
MASTER_SITES=	http://www.convertlit.com/\
		http://math.libtomcrypt.org/files/:ltm
DISTFILES=	clit${MAJ_VER}${MIN_VER}src.zip \
		ltm-0.33.tar.bz2:ltm
EXTRACT_ONLY=	clit${MAJ_VER}${MIN_VER}src.zip

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	Microsoft Lit to HTML and Open eBooks converter

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}${MAJ_VER}${MIN_VER}
NO_WRKSUBDIR=	yes

MAJ_VER=	1
MIN_VER=	8

PLIST_FILES=	bin/clit

USE_ZIP=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes

post-extract:
	cd ${WRKDIR} && ${BZIP2_CMD} -dc "${DISTDIR}/ltm-0.33.tar.bz2" | \
		${TAR} -xf -

post-patch:
	@${FIND} ${WRKDIR} -name *.c -or -name *.h | ${XARGS} ${REINPLACE_CMD} -e 's|||'

do-build:
	cd ${WRKDIR}/libtommath-0.33 && \
	${SETENV} ${MAKE_ENV} ${MAKE} -f makefile  libtommath.a
	cd ${WRKDIR}/lib &&  ${SETENV} ${MAKE_ENV} ${GMAKE} -f Makefile all
	cd ${WRKDIR}/${PORTNAME}${MAJ_VER}${MIN_VER} &&  \
		${SETENV} ${MAKE_ENV} ${GMAKE} -f Makefile all

do-install:
	@${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME}${MAJ_VER}${MIN_VER}/clit \
		${LOCALBASE}/bin

.include <bsd.port.mk>
