# Created by: Alexey Zaytsev
# $FreeBSD$

PORTNAME=	gkrellmwho2
PORTVERSION=	0.2.8
PORTREVISION=	12
CATEGORIES=	sysutils
MASTER_SITES=	http://shisha.spb.ru/ \
		http://users.podolsk.ru/c104598/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays logged in users

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig
USES=		pkgconfig

ALL_TARGET=

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/configure ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/gkrellmwho2.so ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins/

.include <bsd.port.mk>
