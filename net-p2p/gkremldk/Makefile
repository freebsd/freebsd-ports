# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

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

USES=		pkgconfig tar:bzip2
USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|^(LFLAGS).*|\1 = ${LDFLAGS} -lpthread -L${LOCALBASE}/lib|' \
		-e 's|(-fPIC)|\1 ${CFLAGS} -I${LOCALBASE}/include|' \
		${WRKSRC}/Makefile.in

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins
	@${INSTALL_DATA} ${WRKSRC}/gkremldk.so \
		${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins

.include <bsd.port.mk>
