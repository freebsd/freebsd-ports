# ex:ts=8
# Ports collection makefile for:	it++
# Date created:			Apr 3, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	it++
PORTVERSION=	4.0.6
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF/itpp/itpp/${PORTVERSION}
DISTNAME=	itpp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mathematical, signal processing and communication library

DEPRECATED=	fails to compile with up-to-date compilers, nobody really interested to maintain this
EXPIRATION_DATE=2009-08-20

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
BLAS=		-lblas
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-lapack --without-fft
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_FORTRAN=	yes
MAN1=		itpp-config.1

post-patch:
	@${REINPLACE_CMD} -e "s|[$$]{it_dir}|${LOCALBASE}|g" ${WRKSRC}/configure

post-install:
	@${RM} -f ${PREFIX}/lib/libitpp.la \
	          ${PREFIX}/lib/pkgconfig/itpp.pc
	@-${RMDIR} ${PREFIX}/lib/pkgconfig

.include <bsd.port.post.mk>
