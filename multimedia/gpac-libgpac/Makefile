# New ports collection makefile for:	gpac-libm4systems
# Date created:		2005-05-04
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gpac-libm4systems
DISTVERSION=	0.3.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gpac
DISTNAME=	gpac-${DISTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Gpac MPEG-4 Systems library and headers

WRKSRC=		${WRKDIR}/gpac
ALL_TARGET=	lib
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

BUILD_WRKSRC=	${WRKSRC}/M4Systems
INSTALL_WRKSRC=	${WRKSRC}/bin/gcc

CONFIGURE_ARGS=	--cc="${CC}" \
		--extra-cflags="${CFLAGS} ${PTHREAD_CFLAGS} -fPIC" \
		--extra-ldflags="${LDFLAGS} ${PTHREAD_LDFLAGS}"

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' \
		${WRKSRC}/include/gpac/m4_config.h
	@${RM} -f ${WRKSRC}/include/gpac/m4_config.h.bak
	@${REINPLACE_CMD} -e 's|||' \
		${WRKSRC}/include/gpac/m4_descriptors.h \
		${WRKSRC}/M4Systems/authoring/TextImport.c
	@${RM} -f ${WRKSRC}/include/gpac/m4_descriptors.h.bak
.endif
	${CHMOD} +x ${WRKSRC}/configure

do-install:
	${MKDIR} ${PREFIX}/include/gpac
	cd ${WRKSRC}/include/gpac && ${FIND} . | \
		${CPIO} -vpdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/include/gpac
	${INSTALL_DATA} ${INSTALL_WRKSRC}/libm4systems.so ${PREFIX}/lib
	${INSTALL_DATA} ${INSTALL_WRKSRC}/libm4systems_static.a ${PREFIX}/lib

.include <bsd.port.post.mk>
