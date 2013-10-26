# Created by: Michael Neumann <mneumann@ntecs.de>
# $FreeBSD$

PORTNAME=	algae
PORTVERSION=	4.3.6
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programming language for numerical analysis

LICENSE=	GPLv2

USE_FORTRAN=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf

ALGAE_VERSION=	${PORTVERSION}
PLIST_SUB=	ALGAE_VERSION=${ALGAE_VERSION}

LDFLAGS+=	-L`${CAT} ${WRKSRC}/LIBDIR`/../../.. -L`${CAT} ${WRKSRC}/LIBDIR` -L${LOCALBASE}/lib
FORTRANLIBS=	gfortranbegin gfortran

MAN1=		${PORTNAME}.1
INFO=		${PORTNAME}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,<malloc\.h>,<stdlib.h>,' \
		${WRKSRC}/src/mem.h \
		${WRKSRC}/superlu/sp_coletree.c \
		${WRKSRC}/superlu/util.h
	@${REINPLACE_CMD} -e 's,%%FORTRANLIBS%%,${FORTRANLIBS},' \
		${WRKSRC}/configure.in

pre-configure:
	@${DIRNAME} `${F77} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		does not compile on ${ARCH}
.endif

.include <bsd.port.post.mk>
