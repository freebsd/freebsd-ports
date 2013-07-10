# Created by: Michael Neumann <mneumann@ntecs.de>
# $FreeBSD$

PORTNAME=	algae
PORTVERSION=	4.3.6
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programming language for numerical analysis

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf

ALGAE_VERSION=	${PORTVERSION}
PLIST_SUB=	ALGAE_VERSION=${ALGAE_VERSION}

MAN1=	algae.1
INFO=	algae

MAKE_JOBS_UNSAFE=	yes
USE_FORTRAN=	yes
LDFLAGS+=	-L`${CAT} ${WRKSRC}/LIBDIR`/../../.. -L`${CAT} ${WRKSRC}/LIBDIR` -L${LOCALBASE}/lib
FORTRANLIBS=	gfortranbegin gfortran

post-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,g' \
		${WRKSRC}/src/mem.h \
		${WRKSRC}/superlu/sp_coletree.c \
		${WRKSRC}/superlu/util.h

	@${REINPLACE_CMD} -e 's,%%FORTRANLIBS%%,${FORTRANLIBS},g' \
		${WRKSRC}/configure.in

pre-configure:
	@${DIRNAME} `${F77} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.include <bsd.port.post.mk>
