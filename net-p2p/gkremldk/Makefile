# New ports collection makefile for:	GKrellM MLDonkey plugin
# Date created:		Sat Mar 25 05:17:51 UTC 2006
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkremldk
PORTVERSION=	0.9.8
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.tof2k.com/gkremldk/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}
EXTRACT_SUFX=	.tbz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shows current mldonkey donwload/upload rates and allows setting them

LICENSE=	GPLv2

BUILD_DEPENDS=	\
		${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf
USE_PKGCONFIG=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_JOBS_SAFE=	yes

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|^(LFLAGS).*|\1 = ${LDFLAGS} ${PTHREAD_LIBS} -L${LOCALBASE}/lib|' \
		-e 's|-lpthread|${PTHREAD_LIBS}|' \
		-e 's|(-fPIC)|\1 ${CFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include|' \
		${WRKSRC}/Makefile.in

do-install:
	@${MKDIR} ${PREFIX}/libexec/gkrellm2/plugins
	@${INSTALL_DATA} ${WRKSRC}/gkremldk.so \
		${PREFIX}/libexec/gkrellm2/plugins

.include <bsd.port.mk>
