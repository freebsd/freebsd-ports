# ex:ts=8
# Ports collection makefile for:	it++
# Date created:			Apr 3, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	it++
PORTVERSION=	3.8.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	itpp
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mathematical, signal processing and communication library

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
BLAS=           -lblas
.endif

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	opt
USE_GMAKE=	yes
USE_FORTRAN=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|sparc|__sparc__|" \
		-e "s|alpha|__alpha__|" ${WRKSRC}/include/base/machdep.h
	@${REINPLACE_CMD} -e "s|[$$]{it_dir}|${LOCALBASE}|g" ${WRKSRC}/configure

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/it-config ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libit++.a ${PREFIX}/lib
	${CP} -R ${WRKSRC}/include ${PREFIX}/include/it++
	${FIND} ${PREFIX}/include/it++ -name \*.orig -delete

.include <bsd.port.post.mk>
