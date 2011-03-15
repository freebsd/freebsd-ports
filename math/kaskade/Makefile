# New ports collection makefile for:	Kaskade
# Date created:		19 Sept. 1997
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	kaskade
PORTVERSION=	3.2.1
PORTREVISION=	5
CATEGORIES=	math science
MASTER_SITES=	ftp://ftp.zib.de/pub/kaskade/3.x/
DISTNAME=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adaptive linear scalar elliptic and parabolic problem solver

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_FORTRAN=	yes
FORTRANLIBS=	-lgfortranbegin -lgfortran
GCCLIBDIR=	-L`${CAT} ${WRKSRC}/LIBDIR` -L`${CAT} ${WRKSRC}/LIBDIR`/../../..

USE_XORG=	x11
GNU_CONFIGURE=	yes

BROKEN=		Fails to compile with GCC 4.3

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

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif
.endif

.include <bsd.port.post.mk>
