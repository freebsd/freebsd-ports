# New ports collection makefile for:	Kaskade
# Date created:		19 Sept. 1997
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	kaskade
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	math science
MASTER_SITES=	ftp://ftp.zib.de/pub/kaskade/3.x/
DISTNAME=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adaptive linear scalar elliptic and parabolic problem solver

WANT_FORTRAN=	yes #dummy but future use
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
F77=		gfortran42
FORTRANLIBS=	-lgfortranbegin -lgfortran
GCCLIBDIR=	-L`${CAT} ${WRKSRC}/LIBDIR` -L`${CAT} ${WRKSRC}/LIBDIR`/../../..

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

DIST_SUBDIR=	kaskade
WRKSRC=		${WRKDIR}/3.2.1

pre-configure:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	${CP} ${FILESDIR}/configure ${WRKSRC}
	@${DIRNAME} `${F77} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR
	@${REINPLACE_CMD} "s+%%F77%%+${F77}+" ${WRKSRC}/sources/configure
	@${REINPLACE_CMD} -e "s+%%GCCLIBDIR%%+${GCCLIBDIR}+" -e "s+%%FORTRANLIBS%%+${FORTRANLIBS}+" ${WRKSRC}/sources/makefile.in
	@${REINPLACE_CMD} "s+%%F77%%+${F77}+" ${WRKSRC}/minigraph/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/data/*.cmd ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/data/*.dat ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/data/*.ex ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/data/*.geo ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/data/kaskade.init ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/data/*.mat ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
