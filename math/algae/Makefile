# New ports collection makefile for:    algae
# Date created:         18 May 2003
# Whom:                 Michael Neumann <mneumann@ntecs.de>
#
# $FreeBSD$
#

PORTNAME=	algae
PORTVERSION=	4.3.6
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A programming language for numerical analysis

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:262

ALGAE_VERSION=	${PORTVERSION}
PLIST_SUB=	ALGAE_VERSION=${ALGAE_VERSION}

MAN1=	algae.1
INFO=	algae

USE_FORTRAN=	yes
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L`${CAT} ${WRKSRC}/LIBDIR`/../../.. -L`${CAT} ${WRKSRC}/LIBDIR` -L${LOCALBASE}/lib"
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

.if ${ARCH} == "alpha" || ${ARCH} == "sparc64"
BROKEN=		Configure fails on alpha and sparc64
.endif

.include <bsd.port.post.mk>
